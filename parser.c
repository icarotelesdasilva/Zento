#include "parser.h"
#include <stdio.h>
#include "lexer.h"

void processar_token(Token token) {


	switch (token.tipo) {
        case TOKEN_IMPRIMIR:
            printf("%s", token.valor);
            break;
            
        case TOKEN_LER:
            printf("%s", token.valor);
            break;

        case TOKEN_DESCONHECIDO:
        default:
            printf("Erro: Comando desconhecido ou inválido.\n");
            break;
    }
}