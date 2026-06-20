const github = require('@actions/github');
const Anthropic = require('@anthropic-ai/sdk');

async function run() {
  try {
    const token = process.env.GITHUB_TOKEN;
    const anthropicKey = process.env.ANTHROPIC_API_KEY;
    
    if (!token || !anthropicKey) {
      console.log("Missing GITHUB_TOKEN or ANTHROPIC_API_KEY");
      return;
    }

    const octokit = github.getOctokit(token);
    const context = github.context;
    const anthropic = new Anthropic({ apiKey: anthropicKey });

    if (!context.payload.pull_request) {
      console.log("Not a PR event, skipping.");
      return;
    }

    const owner = context.repo.owner;
    const repo = context.repo.repo;
    const pull_number = context.payload.pull_request.number;

    // 1. Get the PR diff
    const { data: diff } = await octokit.rest.pulls.get({
      owner,
      repo,
      pull_number,
      mediaType: { format: 'diff' }
    });

    // 2. Build the prompt
    const prompt = `
You are a strict C++ Code Reviewer. 
Review the following Git diff for naming convention violations.
Rules:
- Local variables: l prefix + camelCase
- Class/Struct member variables: m prefix + camelCase
- Pointer variables: Ptr suffix
- Input parameters: in prefix
- Output parameters: out prefix
- In/out parameters: io prefix
- Global functions: PascalCase
- Static/Helper functions: camelCase
- Classes/Methods/Structs: PascalCase
- Enums: PascalCase type, UPPERCASE values
- Constants/#defines: UPPERCASE_WITH_UNDERSCORES
- Header files: PascalCase + .hpp
- Source files: PascalCase + .cpp

Diff:
${diff}

List the exact violations found:
`;

    // 3. Call Anthropic
    console.log("Sending diff to Anthropic API...");
    const msg = await anthropic.messages.create({
      model: "claude-3-7-sonnet-20250219",
      max_tokens: 2000,
      messages: [{ role: "user", content: prompt }]
    });

    const reviewText = msg.content[0].text;
    console.log("Received review from Anthropic");

    // 4. Post comment on PR
    await octokit.rest.issues.createComment({
      owner,
      repo,
      issue_number: pull_number,
      body: "### 🤖 Anthropic SDK Custom Review\n\n" + reviewText
    });

    console.log("Comment posted successfully.");
  } catch (error) {
    console.error("Error running review:", error);
  }
}

run();
