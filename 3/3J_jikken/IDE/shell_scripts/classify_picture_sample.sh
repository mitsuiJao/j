#!/bin/bash

#作業用ディレクトリの指定
target_dir="./test_text_files_"

#findをかけるディレクトリの指定
#検索結果を絞り込む
#さらにパイプで読み込む
find "${ta} -mindepth 1 -maxdepth 1 -name wh read path; 
    echo "${path}"

    file=$(basename "${p}") #ファイル名の抽出

    year=${file:0:4}
    month=${}
    day=${}

    dir="${year}/${}-${}${}" #パスの作成

    echo "mkdir -p \"${dir}\""
    mkdir - "${dir}" #ディレクトリの作成

    echo "cp \"${file}\" \"${dir}\""
     "${p}" "${d}/" #ファイルのコピーまたは移動
done
