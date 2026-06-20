cmake_minimum_required(VERSION 3.10)
project(ClearingEngineSimulation VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(ClearingEngineSimulation
    src/main.cpp
    src/util/DateUtil.cpp
    src/account/Account.cpp
    src/clearing/clearingEngine.cpp
)
