cmake_minimum_required(VERSION 3.20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/testfolder")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
add_subdirectory(googletest)

add_executable(runAllTests

    tests.cpp
    Action.cpp
    Stats.cpp
    Enemy.cpp
    Player.cpp
    Item.cpp
    inventory.cpp
)

target_link_libraries(runAllTests gmock gtest gtest_main)
