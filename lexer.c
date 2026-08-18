#include "lexer.h"
#include <stdio.h>
#include <string.h>

Token analisar_linha(char *linha) {
    Token token;
    token.tipo = TOKEN_DESCONHECIDO;
    memset(token.valor, 0, sizeof(token.valor));

    linha[strcspn(linha, "\r\n")] = '\0';

    if (strncmp(linha, "imprimir", 8) == 0) {
        token.tipo = TOKEN_IMPRIMIR;
        
        char *inicio = strchr(linha, '(');
        if (inicio != NULL) {
            inicio++; // Pula o '('
            char *fim = strchr(inicio, ')');
            if (fim != NULL) {
                int tamanho = fim - inicio;
                if (tamanho > 0 && tamanho < sizeof(token.valor)) {
                    strncpy(token.valor, inicio, tamanho);
                    token.valor[tamanho] = '\0'; 
                }
            }
        }
    } 
    else if (strncmp(linha, "ler", 3) == 0) {
        token.tipo = TOKEN_LER;
        
        char *inicio = strchr(linha, '(');
        if (inicio != NULL) {
            inicio++;
            char *fim = strchr(inicio, ')');
            if (fim != NULL) {
                int tamanho = fim - inicio;
                if (tamanho > 0 && tamanho < sizeof(token.valor)) {
                    strncpy(token.valor, inicio, tamanho);
                    token.valor[tamanho] = '\0';
                }
            }
        }
    }

    return token;
}