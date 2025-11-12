cmake_minimum_required(VERSION 3.10)
project(algorithm-practice)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 生成 compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 包含头文件目录
include_directories(lib)

# 自动查找所有 cpp 文件
file(GLOB_RECURSE SOURCES "src/*.cpp")

# 为每个 cpp 文件创建可执行文件
foreach(SOURCE ${SOURCES})
    get_filename_component(NAME ${SOURCE} NAME_WE)
    add_executable(${NAME} ${SOURCE})
    set_target_properties(${NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
endforeach()