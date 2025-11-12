#!/bin/bash

# 处理 'clean' 指令
if [ "$1" == "clean" ]; then
    echo "正在清理 bin 目录..."
    if [ -d "bin" ] && [ "$(ls -A bin)" ]; then
        rm -f bin/*
        echo "清理完成。"
    else
        echo "bin 目录为空或不存在，无需清理。"
    fi
    exit 0
fi

SOURCE_FILE=""

# 如果提供了源文件路径
if [ "$#" -eq 1 ]; then
    SOURCE_FILE=$1
# 如果没有提供路径，则自动查找
elif [ "$#" -eq 0 ]; then
    # 在当前目录和 src 目录中查找 .cpp 文件
    cpp_files=(*.cpp src/*.cpp)
    
    # 过滤掉不存在的文件（当某个模式没有匹配时，glob本身会作为字符串返回）
    valid_files=()
    for file in "${cpp_files[@]}"; do
        if [ -e "$file" ]; then
            valid_files+=("$file")
        fi
    done

    file_count=${#valid_files[@]}

    if [ "$file_count" -eq 1 ]; then
        SOURCE_FILE="${valid_files[0]}"
        echo "自动找到源文件: $SOURCE_FILE"
    elif [ "$file_count" -eq 0 ]; then
        echo "错误: 在当前目录或 'src' 目录中未找到 C++ 源文件。"
        echo "用法: $0 [源文件路径 | clean]"
        exit 1
    else
        echo "错误: 找到多个 C++ 源文件，请指定一个:"
        printf "%s\n" "${valid_files[@]}"
        exit 1
    fi
else
    echo "用法: $0 [源文件路径 | clean]"
    exit 1
fi

# 检查源文件是否存在
if [ ! -f "$SOURCE_FILE" ]; then
    echo "错误: 源文件 '$SOURCE_FILE' 不存在。"
    exit 1
fi

# 设置输出目录和文件名
OUTPUT_DIR="bin"
# 从源文件名中提取基本名称（不含扩展名）
BASENAME=$(basename "$SOURCE_FILE" .cpp)
OUTPUT_FILE="$OUTPUT_DIR/$BASENAME"

# 如果输出目录不存在，则创建它
mkdir -p "$OUTPUT_DIR"

# 编译 C++ 文件，包含 lib 目录作为头文件搜索路径
echo "正在编译: $SOURCE_FILE"
g++ -std=c++23 -Ilib -o "$OUTPUT_FILE" "$SOURCE_FILE"

# 检查编译是否成功
if [ $? -eq 0 ]; then
    echo "编译成功！"
    echo "可执行文件位于: $OUTPUT_FILE"
else
    echo "编译失败。"
    exit 1
fi