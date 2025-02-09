/*
Uma aliteração ocorre quando duas ou mais palavras consecutivas de um texto possuem a mesma letra inicial (ignorando maiúsculas e minúsculas). Sua tarefa é desenvolver um programa que identifique, a partir de uma sequência de palavras, 
o número de aliterações que essa sequência possui.

Entrada
A entrada contém diversos casos de testes. Cada caso é expresso como um texto em uma única linha, contendo de 1 a 100 palavras separadas por um único espaço, cada palavra tendo de 1 a 50 letras minúsculas ou maiúsculas ('A'-'Z','a'-'z'). A entrada termina em EOF.

Saída
Para cada caso de teste imprima o número de aliterações existentes no texto informado, conforme exemplos abaixo.
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char linha[5051];  

    // Loop para ler cada linha até EOF
    while (fgets(linha, sizeof(linha), stdin) != NULL) {
        // Remove o caractere de nova linha ('\n') se presente
        size_t len = strlen(linha);
        if (len > 0 && linha[len - 1] == '\n') {
            linha[len - 1] = '\0';
        }

        // Transforma todas as letras em maiúsculas
        for (int i = 0; i < len; i++) {
            linha[i] = toupper(linha[i]);
        }

        int aliteracao = 0;
        int palavra = 0;
        char letra = '\0';

        for (int j = 0; j < len; j++) {
            if (j == 0) {
                letra = linha[j];
            } else if (linha[j] == ' ' && j + 1 < len) {
                j++;
                if (letra == linha[j]) {
                    palavra++;
                    if (palavra == 1) {
                        aliteracao++;
                    }
                } else {
                    palavra = 0;
                    letra = linha[j];
                }
            }
        }

        printf("%d\n", aliteracao);
    }

    return 0;
}