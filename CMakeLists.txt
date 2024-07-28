cmake_minimum_required(VERSION 3.21)
project(GameProject VERSION 0.1 DESCRIPTION "A game project using SimpleEngine" LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

# Fetch and make SimpleEngine available using FetchContent
FetchContent_Declare(
  SimpleEngine
  GIT_REPOSITORY https://github.com/kafkaphoenix/SimpleEngine.git
  GIT_TAG main
)

FetchContent_MakeAvailable(SimpleEngine)

# Specify the source files
set(SOURCE_FILES src/main.cpp)

# Create the executable
add_executable(GameProject ${SOURCE_FILES})

# Link against the SimpleEngine library
target_link_libraries(GameProject PRIVATE SimpleEngine)

# Include directories for SimpleEngine
target_include_directories(GameProject PRIVATE ${simpleengine_SOURCE_DIR}/include)