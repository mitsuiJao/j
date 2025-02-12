#!/bin/bash

#作業用ディレクトリの指定
target_dir="test_text_files_2"

#findをかけるディレクトリの指定
#検索結果を絞り込む
#さらにパイプで読み込む
find "${target_dir}" -mindepth 1 -maxdepth 1 -name '*.txt' | while read path; 
do
    echo "${path}"

    file=$(basename "${path}") #ファイル名の抽出

	# {var: offset: length}
    year=${file:0:4}
    month=${file:4:2}
    day=${file:6:2}

    dir="${year}/${year}-${month}${day}" #パスの作成

    echo "mkdir -p \"${dir}\""
    mkdir -p "${dir}" #ディレクトリの作成

    echo "cp \"${file}\" \"${dir}\""
    cp "${path}" "${dir}/" #ファイルのコピーまたは移動
done
