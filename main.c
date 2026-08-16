#include "lexer.h"
#include "parser.h"
#include "stdio.h"

char linha[256];

 int main() {

FILE *arquivo = fopen("arquivo.teste", "r");

if (arquivo == NULL) {


	printf("Arquivo não encontrado.");
}


while (fgets(linha, sizeof(linha), arquivo) != NULL) {
Token token = analisar_linha(linha);
        processar_token(token);
    }

    fclose(arquivo);
    return 0;
}