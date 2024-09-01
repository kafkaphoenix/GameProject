cmake_minimum_required(VERSION 3.14)
project(GameProject VERSION 1.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_SHARED_LIBS "Build with engine as a shared library" OFF)

include(FetchContent)
FetchContent_Declare(
    game_engine
    GIT_REPOSITORY https://github.com/kafkaphoenix/GameEngine.git
    GIT_TAG        v1.1.0
)

FetchContent_GetProperties(game_engine)
if(NOT game_engine_POPULATED)
  FetchContent_Populate(game_engine)
  set(BUILD_SHARED_LIBS ${BUILD_SHARED_LIBS} CACHE INTERNAL "" FORCE)
  add_subdirectory(${game_engine_SOURCE_DIR} ${game_engine_BINARY_DIR})
endif()

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE GameEngine)
