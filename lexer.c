#include "lexer.h"
#include "stdio.h"
#include "string.h"

Token analisar_linha(char *linha) {

	Token token;

	token.tipo = TOKEN_DESCONHECIDO;

	memset(token.valor, 0, sizeof(token.valor));

linha[strcspn(linha, "\r\n")] = '\0';

	if (strncmp(linha, "imprimir", 8) == 0) {
        token.tipo = TOKEN_IMPRIMIR;
        
        char *inicio = strchr(linha, '(');
        if (inicio != NULL) {
            inicio++;
            char *fim = strchr(inicio, ')');
            if (fim != NULL) {
                *fim = '\0';
                strncpy(token.valor, inicio, sizeof(token.valor) - 1);
            }	
        }
    }

    return token;
}