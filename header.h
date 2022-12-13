#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <windows.h>
#include <locale.h>
#include <stdbool.h>
#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

struct produto
{
    int codigo;                             //Structs
    char nome[26];
    float preço;
    int estoque;

    struct ponto * proximo;
}

typedef struct produto produto_cadastro;

typedef struct
{
    cadastro_produto * inicial;

}lista;

void exibir(produto_cadastro *no);                  //funções principais
void atualizar(produto_cadastro *no);
void excluir(lista *l);
void salvar(produto_cadastro *no);
void ler(produto_cadastro *no);
void realizar_venda(produto_cadastro *no);
void relatorio();
void limpar_lista(produto_cadastro *no);
void ler (produto_cadastro *no);

void inserir(produto_cadastro **lista, char *test_name, int *teste_codigo, float *preco, int *estoque);
void find_nome(produto_cadastro *no, char *name_testP, int *P_exist);
void find_codigo(produto_cadastro *no, int *P_exist, int *p_codigo_test);

void volta(void);
void sair(void);
void berenice(void);


#endif // HEADER_H_INCLUDED
