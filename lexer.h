	#ifndef LEXER_H
	#define LEXER_H

typedef  enum {

	TOKEN_IMPRIMIR,
	TOKEN_LER,
	TOKEN_DESCONHECIDO,
	TOKEN_EOF,


}token_type;

typedef struct {
    token_type tipo;
    char valor[256];
} Token;

Token analisar_linha(char *linha);

#endif