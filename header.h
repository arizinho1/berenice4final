#include <stdio.h>
#include <stdlib.h>
//#include <string>
#include <windows.h>
#include <locale.h>
#include <stdbool.h>
#ifndef HEADER_H_INCLUDED

struct produto
{
    int codigo;                             //Structs
    char nome[26];
    float preco;
    int estoque;

    struct ponto * proximo;
};

typedef struct produto cadastro_produto;

typedef struct
{
    cadastro_produto * inicial;

} listaa;

void exibir(cadastro_produto *no);                  //funções principais
void atualizar(cadastro_produto *no);
void excluir(listaa *l);
void salvar(cadastro_produto *no);
void ler(cadastro_produto *no);
void realizar_venda(cadastro_produto *no);
void relatorio();
void limpar_listaa(cadastro_produto *no);
void ler (cadastro_produto *no);

void inserir(cadastro_produto **listaa, char *test_name, int *teste_codigo, float *preco, int *estoque);
void find_nome(cadastro_produto *no, char *name_testP, int *P_exist);
void find_codigo(cadastro_produto *no, int *P_exist, int *p_codigo_test);

void volta(void);
void sair(void);
void menu();


#endif HEADER_H_INCLUDED
