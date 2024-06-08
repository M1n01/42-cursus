#!/bin/bash

# コンパイル
make -j

# 引数生成
args=$(jot -r 3000 1 100000 | tr '\n' ' ')

# 実行
./PmergeMe $args

# 比較ファイル作成
echo $args | tr ' ' '\n' | sort -n | tr '\n' ' ' > sort.txt

# 比較関数
compare_files() {
    diff "$1" sort.txt
    if [ $? -eq 0 ]; then
        echo -e "\033[32mOK: $1\033[0m"
    else
        echo -e "\033[31mFAILURE: $1\033[0m"
    fi
}

# 比較実行
compare_files retVec.txt
compare_files retList.txt

# 一時ファイルの削除
rm retVec.txt retList.txt sort.txt