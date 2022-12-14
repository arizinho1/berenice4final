#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
    int menu_opc, vendas_opc, continuar, opc, cadastro_opc, existe, estoque, linhas, teste_codigo;
    float preco;
    char teste_nome[26];
    char menulista[3][40] = {"Produtos", "Realizar vendas", "Sair"};
    char menulista2[7][40] = {"Exibir Estoque", "Cadastrar Produtos", "Atualizar Produtos", "Excluir Produtos", "Salvar", "Ler", "Voltar"};

    listaa l;
    cadastro_produto * listaa = NULL;
    l.inicial = listaa;

    while(true)
    {
        system("cls || clear");
        //berenice();
        //menu_opc = menu(10, 10, 5, menulista)

        switch(menu_opc)
        {
        case 1:
            setlocale(LC_ALL, "");
            while(true)
            {
                system("cls || clear");
                // berenice();
                //opc = menu(10, 10, 5, menulista2)
                switch(opc)
                {
                case 1:
                    exibir(listaa);
                    break;
                case 2:
                    while(1)
                    {
                        do
                        {
                            system("cls || clear");
                            existe =0;

                            find_nome(listaa, &teste_nome, &existe);

                            find_codigo(listaa, &existe, &teste_codigo);

                            if(existe==1)
                            {
                                printf("\n\n\t\tProduto ja cadastrado!");
                                Sleep(1000);
                            }
                        }
                        while(existe==1);

                        do
                        {
                            preco = 0;
                            estoque = 0;

                            printf("\n\n\t\tDigite o preco do item: \n");
                            scanf("%f", &preco);

                            printf("\n\n\t\tDigite a quantidade para o estoque:");
                            scanf("%f", &estoque);

                            if(preco < 0 || estoque < 0)
                            {
                                printf("\n\n\t\tValor inválido para preco ou estoque!\n");
                            }
                        }
                        while(preco < 0 || estoque < 0);

                        inserir(&listaa, &teste_nome, &teste_codigo, &preco, &estoque);

                        printf("\n\n\t\tDeseja cadastrar outro item?\n\n\t\t -- 1 -- Sim   -- Outro valor -- Não\n");
                        scanf("%i", &cadastro_opc);

                        if(cadastro_opc != 1)
                        {
                            break;
                        }
                    }
                    system("cls || clear");
                    exibir(listaa);
                    break;


                case 3:
                    atualizar(listaa);
                    break;


                case 4:
                    excluir(&listaa);
                    break;

                case 5:
                    salvar(&listaa);
                    break;

                case 6:
                    ler(listaa);
                    break;

                case 7:
                    break;
                }
                if (opc == 0)
                {
                    break;
                }
                //linhaCol (1,1);
            }
        case 2:
            do
            {
                //textColor(LIGHTGREEN, _BLACK);
                system("cls || clear");
                //PADARIA();
                printf("\n\n\n\t\t\tESCOLHA UMA DAS OPÇÕES:\n\n\t\t\t-- 1 --Realizar Vendas \n\n\t\t\t-- 2 --Relatório De Vendas \n\n\t\t\t-- 3 -- Voltar. \n\n");
                scanf("%d", &vendas_opc);

                switch(vendas_opc)
                {
                case 1:
                    realizar_venda(listaa);
                    break;

                case 2:
                    relatorio();
                    break;

                case 3:
                    voltar();
                    break;

                default:
                    opc_invalida();
                    break;
                }
                break;
            }
            while(vendas_opc != 3);
            break;

        case 3:
            sair();
            break;
        }

        if (menu_opc==0)
        {
            break;
        }

        if (menu_opc==3)
        {
            break;
        }
        //linhaCol(1,1);
    }
    //textColor(WHITE, _BLACK);
    //linhaCol(24,1);
    printf("");
    return 0;
}
