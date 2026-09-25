cmake_minimum_required(VERSION 3.16)

project(myapp CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)   # 生成 compile_commands.json

# include(FetchContent)

# FetchContent_Declare(
#     mylib
#     SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../cpp-lib-template  # 指向 engine 源码目录
# )

# FetchContent_MakeAvailable(mylib)

# ---- 你的可执行文件 ----
add_executable(${PROJECT_NAME} src/main.cpp)
# 链接 外部库（会自动带上头文件路径和系统依赖）
# target_link_libraries(${PROJECT_NAME} PRIVATE mylib::core)

# ---- 编译器警告 ----
if(MSVC)
    add_compile_options(/W4 /permissive-)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
endif()

