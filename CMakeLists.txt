cmake_minimum_required(VERSION 3.20)

project(SillyVideo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(rot)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/Animator.cpp
    src/SafePath.cpp
    src/Snowflake.cpp
    src/SnowflakeSystem.cpp
    src/Stickman.cpp
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        include
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        ROT
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets
)