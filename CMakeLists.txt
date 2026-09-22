cmake_minimum_required(VERSION 3.16)
project(myapp CXX)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)   # 生成 compile_commands.json

# ---- 配置 GLFW（vendored）----
set(BUILD_SHARED_LIBS OFF)
set(GLFW_BUILD_DOCS     OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_DOCS     OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS    OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL        OFF CACHE BOOL "" FORCE)
add_subdirectory(vendor/glfw)

# ---- 你的可执行文件 ----
add_executable(app src/main.cpp)
target_link_libraries(app PRIVATE glfw)

# ---- 编译器警告 ----
if(MSVC)
    add_compile_options(/W4 /permissive-)
else()
    target_compile_options(app PRIVATE -Wall -Wextra -Wpedantic)
endif()

# 链接 GLFW（会自动带上头文件路径和系统依赖）
target_link_libraries(app PRIVATE glfw)
