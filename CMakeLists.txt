cmake_minimum_required(VERSION 3.21)
project(GameProject VERSION 0.1 DESCRIPTION "A game project using SimpleEngine" LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include CPM.cmake
set(CPM_DOWNLOAD_LOCATION "${CMAKE_BINARY_DIR}/cpm")
if (NOT EXISTS ${CPM_DOWNLOAD_LOCATION}/CPM.cmake)
    file(DOWNLOAD https://github.com/cpm-cmake/CPM.cmake/releases/latest/download/CPM.cmake
        ${CPM_DOWNLOAD_LOCATION}/CPM.cmake)
endif()
include(${CPM_DOWNLOAD_LOCATION}/CPM.cmake)

# Fetch SimpleEngine using CPM.cmake
CPMAddPackage(
    NAME SimpleEngine
    GITHUB_REPOSITORY user/SimpleEngine
    GIT_TAG main # Replace with the appropriate branch or tag
)

# Specify the source files
set(SOURCE_FILES src/main.cpp)

# Create the executable
add_executable(GameProject ${SOURCE_FILES})

# Link against the SimpleEngine library
target_link_libraries(GameProject PRIVATE SimpleEngine)
