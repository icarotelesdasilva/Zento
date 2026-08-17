#include "parser.h"
#include <stdio.h>
#include "lexer.h"

void processar_token(Token token) {


	switch (token.tipo) {
        case TOKEN_IMPRIMIR:
            printf("%s\n", token.valor);
            break;
            
        case TOKEN_LER:
            break;
            
        case TOKEN_DESCONHECIDO:
        default:
            printf("Erro: Comando desconhecido ou inválido.\n");
            break;
    }
}
