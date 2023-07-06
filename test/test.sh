#!/bin/bash

# Pasta onde estão os arquivos de teste.
TESTS_FOLDER="./test_files"

# Pasta onde vai a saida de erro do programa.
RESULTS_FOLDER="./result_files"

# Pasta onde ficam os resultados do valgrind.
VALGRIND_FOLDER="./valgrind_result"

# Pasta onde estão os resultados esperados.
EXPECTED_FOLDER="./expected"

PROGRAM="../miniRT"



# Mensagem utilizada pra verificar se não houve vazamentos.
FREE_LEAKS_IDENTIFY_MSG="All heap blocks were freed -- no leaks are possible"

# Limite de tempo pro timeout.
TIME_LIMIT=2



# Text Colors.
GREEN_COLOR="\033[0;32m"

RED_COLOR="\033[0;31m"

WHITE_COLOR="\033[0m"



# Verify if needs clean
if [ "$1" == "clean" ]; then
  echo "Cleaning result folder: $RESULTS_FOLDER"
  rm -rf "$RESULTS_FOLDER"/*
  rm -rf "$VALGRIND_FOLDER"/*
  exit 0
fi


# Loop de testes.
for file in "$TESTS_FOLDER"/*; do
  if [ -f "$file" ]; then
    echo "Executing miniRT with the file: $file"

    # Executa o programa normalmente e salva os resultados na pasta RESULTS_FOLDER.
    "timeout" "$TIME_LIMIT" "$PROGRAM" "$file" 2> "$RESULTS_FOLDER/$(basename "$file")" >/dev/null


    # Compara o conteudo salvo no arquivo em RESULTS_FOLDER, com seu respectivo arquivo na pasta EXPECTED_FOLDER.
    if diff "$RESULTS_FOLDER/$(basename "$file")" "$EXPECTED_FOLDER/$(basename "$file")" >/dev/null ; then
      echo -e  "EXPECTED RESULT: " "$GREEN_COLOR" "OK" "$WHITE_COLOR"
    else
      echo -e  "EXPECTED RESULT: " "$RED_COLOR" "KO" "$WHITE_COLOR"
    fi


    # Executa o programa dessa vez com valgrind e salva em um arquivo na pasta VALGRIND_FOLDER.
    "timeout" "$TIME_LIMIT" "valgrind" "$PROGRAM" "$file" 2> "$VALGRIND_FOLDER/$(basename "$file")" >/dev/null


    # Verifica no arquivo de resultados do valgrind se existe a frase FREE_LEAKS_IDENTIFY_MSG, que demonstra que não houveram vazamentos.
    if grep -q "$FREE_LEAKS_IDENTIFY_MSG" "$VALGRIND_FOLDER/$(basename "$file")"; then
      echo -e "$GREEN_COLOR" "NO LEAKS" "$WHITE_COLOR"
    else
      echo -e "$RED_COLOR" "LEAKS" "$WHITE_COLOR"

    fi
  fi
done
