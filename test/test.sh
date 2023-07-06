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


# Contagem do numero de testes e de testes passados
TEST_COUNT=0
PASSED_TESTS_COUNT=0
LEAKS=0


# Mensagem utilizada pra verificar se não houve vazamentos.
FREE_LEAKS_IDENTIFY_MSG="All heap blocks were freed -- no leaks are possible"

# Limite de tempo pro timeout.
TIME_LIMIT=1.2



# Text Colors.
GREEN_COLOR="\033[0;32m"

RED_COLOR="\033[0;31m"

WHITE_COLOR="\033[0m"

YELLOW_COLOR="\033[0;33m"

# Função para criar uma pasta se ela não existir.
create_folder_if_not_exists() {
  if [ ! -d "$1" ]; then
    echo "Creating folder: $1"
    mkdir -p "$1"
  fi
}

# Verifica e cria as pastas necessárias.
create_folder_if_not_exists "$RESULTS_FOLDER"
create_folder_if_not_exists "$VALGRIND_FOLDER"

# Verifica se a pasta de resultados esperados existe.
if [ ! -d "$EXPECTED_FOLDER" ]; then
  echo "Error: Expected folder not found: $EXPECTED_FOLDER"
  exit 1
fi

if [ ! -d "$TESTS_FOLDER" ]; then
  echo "Error: rests folder not found: $TESTS_FOLDER"
  exit 1
fi


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

    TEST_COUNT=$((TEST_COUNT + 1))
  
    # Executa o programa normalmente e salva os resultados na pasta RESULTS_FOLDER.
    "timeout" "$TIME_LIMIT" "$PROGRAM" "$file" 2> "$RESULTS_FOLDER/$(basename "$file")" >/dev/null


    # Compara o conteudo salvo no arquivo em RESULTS_FOLDER, com seu respectivo arquivo na pasta EXPECTED_FOLDER.
    if diff "$RESULTS_FOLDER/$(basename "$file")" "$EXPECTED_FOLDER/$(basename "$file")" >/dev/null ; then
      echo -e  "EXPECTED RESULT: " "$GREEN_COLOR" "OK" "$WHITE_COLOR"

      PASSED_TESTS_COUNT=$((PASSED_TESTS_COUNT + 1))

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
      LEAKS=$((LEAKS + 1))
    fi
  fi
  echo
done

# Mensagens
TESTS_COUNT_MSG="Resultado dos Testes: $PASSED_TESTS_COUNT/$TEST_COUNT" 
LEAKS_COUNT_MSG="Testes com Vazamentos: $LEAKS/$TEST_COUNT"

OK_MSG="Tudo Perfeito e sem Vazamentos :D"
STILL_MSG="Quase lá :D"
KO_MSG="Ainda não T-T"

# Verifica se todos os testes foram aprovados e não houve vazamentos
if [ "$PASSED_TESTS_COUNT" -eq "$TEST_COUNT" ] && [ "$LEAKS" -eq "0" ] ; then
  echo -e "$GREEN_COLOR" "$TESTS_COUNT_MSG" "$WHITE_COLOR"
  echo -e "$GREEN_COLOR" "$LEAKS_COUNT_MSG" "$WHITE_COLOR"
  echo -e "$GREEN_COLOR" "$OK_MSG" "$WHITE_COLOR"
elif [ "$PASSED_TESTS_COUNT" -eq "$TEST_COUNT" ] ; then
  echo -e "$YELLOW_COLOR" "$TESTS_COUNT_MSG" "$WHITE_COLOR"
  echo -e "$YELLOW_COLOR" "$LEAKS_COUNT_MSG" "$WHITE_COLOR"
  echo -e "$YELLOW_COLOR" "$STILL_MSG" "$WHITE_COLOR"
elif [ "$LEAKS" -eq "0" ] ; then
  echo -e "$YELLOW_COLOR" "$TESTS_COUNT_MSG" "$WHITE_COLOR"
  echo -e "$YELLOW_COLOR" "$LEAKS_COUNT_MSG" "$WHITE_COLOR"
  echo -e "$YELLOW_COLOR" "Pelo menos não tem vazamentos..." "$WHITE_COLOR"
else
  echo -e "$RED_COLOR" "$TESTS_COUNT_MSG" "$WHITE_COLOR"
  echo -e "$RED_COLOR" "$LEAKS_COUNT_MSG" "$WHITE_COLOR"
  echo -e "$RED_COLOR" "$KO_MSG" "$WHITE_COLOR"
fi
