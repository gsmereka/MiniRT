#!/bin/bash

test_folder="./test_files"

result_folder="./result_files"

program="../miniRT"

time_limit=1.5

# Verify if needs clean
if [ "$1" == "clean" ]; then
  echo "Cleaning result folder: $result_folder"
  rm -rf "$result_folder"/*
  exit 0
fi

for file in "$test_folder"/*; do
  if [ -f "$file" ]; then
    echo "Execute miniRT with the file: $file"

    "timeout" "$time_limit" "valgrind" "$program" "$file" 2> "$result_folder/$(basename "$file")"
    echo "Completed."
  fi
done
