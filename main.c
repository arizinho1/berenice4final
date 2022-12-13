#include <stdio.h>
#include <stdlib.h>

int main()
{
    int menu_opc, vendas_opc, continuar, opc, cadastro_opc, existe, estoque, linhas, teste_codigo;
    float preço;
    char teste_nome[26];
    char menu_lista[3][40] = {"Produtos", "Realizar vendas", "Sair"};
    char menu_lista2[7][40] = {"Exibir Estoque", "Cadastrar Produtos", "Atualizar Produtos", "Excluir Produtos", "Salvar", "Ler", "Voltar"};

    lista l;
    produto_cadastro * lista = NULL;
    l.inicial = lista;

    while(true)
    {
        system("cls || clear");
        berenice();
        //menu_opc = menu(10, 10, 5, menu_lista)

        switch(menu_opc)
        {
        case 1:
            setlocale(LC_ALL, "");
            while(true)
            {
                system("cls || clear");
                berenice();
                opc = menu(10, 10, 5, menu_lista2)
                switch(opc)
                {
                case 1:
                    exibir(lista);
                    break;
                case 2:
                    while(1)
                    {
                        do
                        {
                            system("cls || clear");
                            existe =0;

                            find_nome(lista, &teste_nome, &existe);

                            find_codigo(lista, &existe, &teste_codigo);

                            if(existe==1)
                            {
                                printf("\n\n\t\tProduto ja cadastrado!");
                                Sleep(1000);
                            }
                        }
                        while(existe==1);

                        do
                        {
                            preço = 0;
                            estoque = 0;

                            printf("\n\n\t\tDigite o preço do item: \n");
                            scanf("%f", &preço)

                            printf("\n\n\t\tDigite a quantidade para o estoque:");
                            scanf("%f", &estoque);

                            if(preço < 0 || estoque < 0)
                            {
                                printf("\n\n\t\tValor inválido para preço ou estoque!\n");
                            }
                        }
                        while(preço < 0 || estoque < 0);

                        inserir(&lista, &teste_nome, &teste_codigo, &preço, &estoque);

                        printf("\n\n\t\tDeseja cadastrar outro item?\n\n\t\t -- 1 -- Sim   -- Outro valor -- Não\n");
                        scanf("%i", *cadastro_opc);

                        if(cadastro_opc != 1)
                        {
                            break;
                        }
                    }
                    system("cls || clear");
                    exibir(lista);
                    break;


                case 3:
                    atualizar(lista);
                    break;


                case 4:
                    excluir(&lista);
                    break;

                case 5:
                    salvar(&lista);
                    break;

                case 6:
                    ler(lista);
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
                    realizar_venda(lista);
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

void exibir(produto_cadastro *no)
{
    system("cls || clear");
    textColor(LIGHTGREEN, _BLACK);

    if (no == NULL)
    {
        system("cls || clear");
        printf("\n\n\n\t\t\tLista vazia!");
        printf("\n\n\n\n");
        system("pause");
        return 0;
    }
    else
    {
        while(no != NULL)
        {
            printf("\n\n\n======================================================");
            printf("\n\n\t\tItem: %s                      Codigo: %d\n\nValor: %.2f                      Estoque: %d", no->nome, no->codigo, no->preço, no->estoque);
            printf("\n\n\n======================================================");
            no = no->proximo;
        }
        printf("\n\n\n");
        system("pause");
    }
}


void inserir(produto_cadastro **lista, char *test_name, int *teste_codigo, float *preço, int *estoque)
{
    //textColor(LIGHTGREEN, _BLACK);
    cadastro_produto *aux, *novo = calloc(1,sizeof(produto_cadastro));

    if(novo)
    {
        strcpy(novo->nome, test_name);
        novo->codigo = *teste_codigo;
        novo->preço = *preço;
        novo->estoque = *estoque;
        novo->proximo = NULL;

        // é o primeiro?
        if(*lista == NULL)
        {
            *lista = novo;
        }
        else
        {
            aux = *lista;
            while(aux->proximo)
                aux = aux->proximo;
            aux->proximo = novo;
        }
    }
    else
    {
        printf("\n\n\t\t\tErro ao alocar memoria!\n\n");
        system("pause");
    }
}

void find_codigo(produto_cadastro *no, int *P_exist, int *p_codigo_test)
{
    produto_cadastro *aux;
    aux = no;
    //textColor(LIGHTGREEN, _BLACK);
    do
    {
        *p_codigo_test = 0;
        printf("\n\n\t\t\tDigite o código do item: \n");
        scanf("%d", &*p_codigo_test);

        if(*p_codigo_test <=0)
        {
            printf("\n\n\n\t\t\tO CÓDIGO DEVE SER MAIOR QUE ZERO!\n");
        }
    }
    while(*p_codigo_test <=0);

    while(aux)
    {
        if(*p_codigo_test == aux->codigo)
        {
            *P_exist=1;
            break;
        }
        else
        {
            aux=aux->proximo;
        }
    }
}

void find_nome(produto_cadastro *no, char *name_testP, int *P_exist/, char name_testP/)
{
    produto_cadastro *aux;
    aux = no;
    char nome[2] = "";

    textColor(LIGHTGREEN, _BLACK);
    do{
    printf("\n\n\t\t\tDigite o nome do item: \n");
    fflush(stdin);
    gets(name_testP);

    if(strcmp(name_testP, nome) == 0)
    {
        system("cls || clear");
        printf("\n\n\n\t\t\tO NOME NÃO PODE SER VAZIO!");
        Sleep(1000);
        system("cls || clear");
    }
    }while(strcmp(name_testP, nome) == 0);

    while(aux)
    {
        if(strcmp(aux->nome, name_testP) == 0)
        {
            *p_existe=1;
            break;
        }
        aux = aux->proximo;
    }
}

void atualizar(produto_cadastro *no)
{
    //textColor(LIGHTGREEN, _BLACK);
    int inexistente, teste_codigo, existe, continuar;
    int opc,quant;
    char nome[26];
    float valor;
    produto_cadastro *aux;
    aux = no;

    do
    {
        existe = 0;
        if(no == NULL)
        {
            system("cls || clear");
            printf("\n\n\n\t\t\tLISTA VAZIA");
            Sleep(1000);
            break;
        }
        exibir(no);
        teste_codigo = 0;
        printf("\n\n\t\t\tDigite o código do item: \n");
        scanf("%d", &teste_codigo);

        while(aux)
        {
            if(teste_codigo == aux->codigo)
            {
                existe = 1;
                break;
            }
            else
            {
                aux=aux->proximo;
            }
        }
        if(existe==1)
        {
            printf("============================================\n");
            printf("\tItem: %s \tCodigo: %d \tPreço: %.2f \tEstoque: %d\n", aux->nome, aux->codigo, aux->preço, aux->estoque);
            printf("============================================\n");

            printf("\n\n\n\t 1 - Atualizar valor \n"
                   "\t 2 - Atualizar estoque \n"
                   "\t 3  <  CANCELAR  >\n\n"

                   "\t Selecione uma das opções: \n\n");
            scanf("%i",&opc);

            valor = aux->preço; //passando o valor de pntr[i].valor a nossa váriavel local valor
            quant = aux->estoque; //passando o valor de pntr[i].quant a nossa váriavel local quant

            switch(opc)
            {
            case 1:
                printf("\t Digite o novo valor do produto: \n\n");
                scanf("%f",&aux->preço);

                if(aux->preço <= 0) //Se valor for menor que zero
                {
                    printf("\t Valor deve ser maior que 0 \n\n");
                    aux->preço = valor; //pntr[i].valor está recebendo o valor
                    inexistente++; //
                }
                break;

            case 2:
                printf("\t Digite a nova quantidade do produto: \n\n");
                scanf("%i",&aux->estoque);
                getchar();

                if(aux->estoque <= 0)
                {
                    printf("\t Quantidade deve ser maior que zero! \n\n");
                    aux->estoque = quant;
                    inexistente++;
                }
                break;

            case 3:
                voltar();
                break;

            default:
                opc_invalida();
                break;
            }
            if(inexistente <= 0 && opc != 3)
            {
                printf("\t Valores Atualizados: \n\n");
                printf("============================================\n");
                printf("\tItem: %s \tCodigo: %d \tPreço: %.2f \tEstoque: %d\n", aux->nome, aux->codigo, aux->preço, aux->estoque);
                printf("============================================\n");

                printf("\t Deseja mesmo atualizar: [4] - Sim ou [0] - Não \n\n");
                scanf("%d",&opc);
                getchar();
            }
            if(opc == 0)
            {
                aux->preco = valor;
                aux->estoque = quant;
                printf("\t Alterações não salvas \n\n");
            }
        }
        else
        {
            printf("\t Produto não localizado \n\n");
            Sleep(1000);
            break;
        }
        system("cls || clear");
        printf("\n\n\n\t\t\tDeseja atualizar outro item?\n\n\n\t\t< 1 > SIM.       < Outro valor > NÃO.\n\n");
        scanf("%i", &continuar);
    }
    while(continuar == 1);
}

void excluir(lista *l) /////////////////////PAREI AKI
{
    int continuar = 1, cod, confirm_Excluir, nao_Excl = 0;
    cadastro_produto *auxRemover = NULL;
    cadastro_produto *aux;
    aux = l->inicial;

    do
    {
        if(aux == NULL)
        {
            system("cls || clear");
            printf("\n\n\n\t\t\tLISTA VAZIA");
            Sleep(1000);
            break;
        }
        exibir(aux);

        printf("\t Digite o código do produto que deseja excluir: \n\n");
        scanf("%d",&cod);

        while(aux != NULL)
        {
            // Se encontrar o valor, pare o loop
            if(aux->codigo == cod)
            {
                if(aux == l->inicial)
                {
                    system("cls || clear");
                    printf("\n\n\t\tO ITEM QUE DESEJA EXCLUIR É: %s", aux->nome);
                    printf("\n\n\t\tTEM CERTEZA QUE DESEJA EXCLUIR ELE DA LISTA?\n\n\t\t< 1 > SIM.  < OUTRO VALOR > NÃO.\n");
                    scanf("%d", &confirm_Excluir);
                    if(confirm_Excluir == 1)
                    {
                        l->inicial = aux->proximo;
                        free(aux);
                        goto end;
                    }
                    else
                    {
                        nao_Excl = 1;
                        break;
                    }
                }
                break;
            }
            auxRemover = aux;
            aux = aux->proximo;
        }
        // Se encontrou algum valor
        if(aux != NULL)
        {
            if(nao_Excl == 1)
            {
                break;
            }
            system("cls || clear");
            printf("\n\n\t\tO ITEM QUE DESEJA EXCLUIR É: %s", aux->nome);
            printf("\n\n\t\tTEM CERTEZA QUE DESEJA EXCLUIR ELE DA LISTA?\n\n\t\t< 1 > SIM.  < OUTRO VALOR > NÃO.\n");
            scanf("%d", &confirm_Excluir);

            if(confirm_Excluir == 1)
            {
            if(auxRemover == NULL)
                aux = aux->proximo;
            else
                auxRemover->proximo = aux->proximo;
            free(aux);
            }
            else
            {
                break;
            }
        }
end:
        continuar = 2;
    }
    while(continuar == 1);
}




















    return 0;
}
