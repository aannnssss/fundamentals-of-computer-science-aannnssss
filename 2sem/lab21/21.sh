#!/bin/bash

count_lines() {
    local file_path="$1"
    local num_lines=$(wc -l < "$file_path")
    total_lines=$((total_lines + num_lines))
}

process_directory() {
    local path="$1"
    for file_path in "$path"/*; do
        if [[ -d "$file_path" ]]; then
            process_directory "$file_path"
        elif [[ -f "$file_path" && ($file_path == *".h" || $file_path == *".cpp") ]]; then
            count_lines "$file_path"
        fi
    done
}

total_lines=0

read -p "Enter the directory or put ?: " path

if [[ "$path" == "?" ]]; then
    path="/home/ann/Загрузки/bashpy"
fi

process_directory "$path"

echo "$total_lines "
