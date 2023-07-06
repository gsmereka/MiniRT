#!/bin/bash

test_folder="./test_files"

result_folder="./result_files"

valgrind_folder="./valgrind_result"

program="../miniRT"

free_leaks_msg="All heap blocks were freed -- no leaks are possible"

time_limit=2

green_color="\033[0;32m"

red_color="\033[0;31m"

white_color="\033[0m"

# Verify if needs clean
if [ "$1" == "clean" ]; then
  echo "Cleaning result folder: $result_folder"
  rm -rf "$result_folder"/*
  exit 0
fi

for file in "$test_folder"/*; do
  if [ -f "$file" ]; then
    echo "Executing miniRT with the file: $file"

    "timeout" "$time_limit" "$program" "$file" 2> "$result_folder/$(basename "$file")" 1> "log.txt"
  
    "timeout" "$time_limit" "valgrind" "$program" "$file" 2> "$valgrind_folder/$(basename "$file")" 1> "log.txt"

    if grep -q "$free_leaks_msg" "$valgrind_folder/$(basename "$file")"; then
      echo -e "$green_color" "NO LEAKS" "$white_color"
    else
      echo -e "$red_color" "LEAKS" "$white_color"
    fi
  fi
done
