#include <stdlib.h>

void sair()
{
    system("cls || clear");
    printf("\n\n\t\tSaindo...");
    Sleep(1000);
}

void voltar()
{
    system("cls || clear");
    printf("\n\n\t\tVoltando...");
    Sleep(1000);

}

void opc_invalida()
{
    system("cls || clear");
    printf("\n\n\t\tOpcao invalida!");
    Sleep(1000);
}

void menu()
{
    do
    {
        setlocale(LC_ALL, "Portuguese");

        menuPrincipal();

        printf("\nDigite a opção desejada: ");
        scanf("%i", &opcao);

        switch(opcao)
        {
        case 1:
            do
            {
                transicao(250);

                menuProdutos();
                scanf("%d", &opcao);
                getchar();

                transicao(250);

                switch(opcao)
                {
                case 0: // Retorna ao menu principal
                    break;

                case 1: // Exibe os itens em estoque
                    if(listaVazia(&listaProdutos) == 0)
                    {
                        printf("\nO estoque de produtos está atualmente vazio...\n");
                    }
                    else
                    {
                        visualizarEstoque(&listaProdutos);
                    }
                    printf("\n");
                    transicao(1000);
                    // pausar exibe a mensagem "pressione qualquer tecla para continuar..."
                    // pausar();
                    break;

                case 2:
                    //cadastrarProduto(&listaProdutos);

                    printf("Quantos produtos gostaria de inserir? ");
                    scanf("%d", &quantidade);
                    getchar();

                    do
                    {
                        if(quantidade <= 0)
                        {
                            printf("\nQuantidade deve ser maior que zero. Digite uma quantidade válida: ");
                            scanf("%d", &quantidade);
                            getchar();
                        }
                    }
                    while(quantidade <= 0);

                    for(int i = 0; i < quantidade; i++)
                    {
                        cadastrarProduto(&listaProdutos, quantidade, contador);
                    }

                    printf("\n** IMPRESSÃO DOS PRODUTOS RECÉM CADASTRADOS **\n");

                    do
                    {
                        printf("\nCódigo: %d\n", listaProdutos->proximo->codigo);
                        printf("Nome: %s\n", listaProdutos->proximo->nome);
                        printf("Valor: %.2f\n", listaProdutos->proximo->valor);
                        printf("Estoque: %d\n\n", listaProdutos->proximo->estoque);
                        pausar();
                    }
                    while(listaProdutos->proximo != NULL);
                    break;
                case 3:
                    if(listaVazia(&listaProdutos) == 0)
                    {
                        printf("\nO estoque de protudos está atualmente vazio...\n");
                    }
                    else
                    {
                        // atualizarProduto(&listaProdutos);
                    }
                    break;
                }
            }
            while(opcao != 0);

        }
    }
}

// 1
void exibir(cadastro_produto *no)
{
    system("cls || clear");

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
            printf("\n\n\t\tItem: %s                      Codigo: %d\n\nValor: %.2f                      Estoque: %d", no->nome, no->codigo, no->preco, no->estoque);
            printf("\n\n\n======================================================");
            no = no->proximo;
        }
        printf("\n\n\n");
        system("pause");
    }
}


void inserir(cadastro_produto **lista, char *test_name, int *teste_codigo, float *preco, int *estoque)
{
    //textColor(LIGHTGREEN, _BLACK);
    cadastro_produto *aux, *novo = calloc(1,sizeof(cadastro_produto));

    if(novo)
    {
        strcpy(novo->nome, test_name);
        novo->codigo = *teste_codigo;
        novo->preco = *preco;
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

void find_codigo(cadastro_produto *no, int *P_exist, int *p_codigo_test)
{
    cadastro_produto *aux;
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

void find_nome(cadastro_produto *no, char *name_testP, int *P_exist)
{
    cadastro_produto *aux;
    aux = no;
    char nome[2] = "";

    do
    {
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
    }
    while(strcmp(name_testP, nome) == 0);

    while(aux)
    {
        if(strcmp(aux->nome, name_testP) == 0)
        {
            *P_exist=1;
            break;
        }
        aux = aux->proximo;
    }
}

void atualizar(cadastro_produto *no)
{
    int inexistente, teste_codigo, existe, continuar;
    int opc,quant;
    char nome[26];
    float valor;
    cadastro_produto *aux;
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
            printf("\tItem: %s \tCodigo: %d \tPreco: %.2f \tEstoque: %d\n", aux->nome, aux->codigo, aux->preco, aux->estoque);
            printf("============================================\n");

            printf("\n\n\n\t 1 - Atualizar valor \n"
                   "\t 2 - Atualizar estoque \n"
                   "\t 3  <  CANCELAR  >\n\n"

                   "\t Selecione uma das opcões: \n\n");
            scanf("%i",&opc);

            valor = aux->preco; //passando o valor de pntr[i].valor a nossa váriavel local valor
            quant = aux->estoque; //passando o valor de pntr[i].quant a nossa váriavel local quant

            switch(opc)
            {
            case 1:
                printf("\t Digite o novo valor do produto: \n\n");
                scanf("%f",&aux->preco);

                if(aux->preco <= 0) //Se valor for menor que zero
                {
                    printf("\t Valor deve ser maior que 0 \n\n");
                    aux->preco = valor; //pntr[i].valor está recebendo o valor
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
                printf("\n");
                printf("\tItem: %s \tCodigo: %d \tPreco: %.2f \tEstoque: %d\n", aux->nome, aux->codigo, aux->preco, aux->estoque);
                printf("\n");

                printf("\t Deseja mesmo atualizar: [4] - Sim ou [0] - Não \n\n");
                scanf("%d",&opc);
                getchar();
            }
            if(opc == 0)
            {
                aux->preco = valor;
                aux->estoque = quant;
                printf("\t Alteracões não salvas \n\n");
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

void excluir(listaa *l)
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
        // Se encontrar algum valor
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

void salvar(cadastro_produto *no)
{
    int i;
    FILE *pointer;

    cadastro_produto *aux;
    aux = no;

    pointer = fopen("produtos.bin","wb"); //Abrindo o arquivo em modo escrita em arquivo binário
    if(pointer == NULL) //Se ponteiro for igual a NULL significa que não foi possível abri-lo
    {
        printf("\t Erro na abertura do arquivo \n\n");

        return 1;
    }
    else
    {
        while(aux != NULL)
        {
            fwrite(aux,sizeof(cadastro_produto),1,pointer); //fwrite recebe como parâmetro o ponteiro para struct, o tamanho da nossa struct produto, o 1 é o número
            // Que significa que apenas um objeto será escrito ou seja a nossa struct produto e o ultimo argumento
            // É o arquivo em que queremos salvar a nossa struct
            printf("\n\n");

            aux = aux->proximo;
        }
        fclose(pointer);
    }
}


void ler(cadastro_produto *no)
{
    FILE *pointer;
    int i;
    cadastro_produto *aux;
    aux = no;

    system("cls || clear");
    pointer = fopen("produtos.bin","rb");//Abri o arquivo em modo leitura de arquivo binário
    if(pointer == NULL)
    {
        printf("\t Erro na abertura do arquivo \n\n");
        return 1;
    }
    else
    {
        fread(aux,sizeof(aux),1,pointer);
        printf("%s", aux);
        printf("\n\n\n");
        system("pause");
        fclose(pointer);
    }
}


void realizar_vendas(cadastro_produto *no)
{
    int cod, opc, opc2, quant, existe, continuar, parcelas, local = 0, i = 0, t = 0, r = 0;
    float total, recebido, troco, total_parc;
    char nome[26][100];
    float val_unit[100];
    int quantidade[100];
    float sub_total[100];
    cadastro_produto *aux;
    system("cls || clear");
    do
    {
        i=0;
        t=0;
        if(no == NULL)
        {
            printf("\n\n\n\t\t\tLista vazia!\n");
            Sleep(1000);
            break;
        }
        do
        {
            aux = no;
            existe = 0;
            cod = 0;
            exibir(no);

            do
            {
                printf("\n\n\t\tDigite o codigo do produto que deseja vender:\n");
                scanf("%d", &cod);

                while(aux)
                {
                    if(cod == aux->codigo)
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
                    do
                    {
                        printf("\tITEM: %s \tCODIGO: %d \tPREÇO: %.2f \tESTOQUE: %d\n", aux->nome, aux->codigo, aux->preco, aux->estoque);

                        printf("Qual a quantidade?\n");
                        scanf("%d",&quant);
                        if(quant <= 0 || quant> aux->estoque)
                        {
                            system("cls || clear");
                            printf("Quantidade invalida ou estoque insuficiente!\nDigite 0 para retornar \n\n");
                            scanf("%d",&quant);
                        }
                    }
                    while(quant <=0 || quant > aux->estoque);

                    if (quant != 0)
                    {
                        aux->estoque = aux->estoque - quant; //Tirar do estoque a quantidade que deseja
                        strcpy(nome[i], aux->nome);
                        val_unit[i] = aux->preco;
                        quantidade[i] = quant;
                        sub_total[i] = aux->preco * quant;
                    }
                }
                else
                {
                    printf("\n\n\n\t\t\tPRODUTO NÃO LOCALIZADO!\n");
                    Sleep(1000);
                }
            }
            while(existe != 1);

            printf("Deseja continuar vendendo?\n");
            printf("(0)--Nao (1)--Sim");
            scanf("%i",&continuar);
            i++;
            if(continuar == 1)
            {
                t++;
            }
        }
        while(continuar == 1);

        for(i=0; i<=t; i++)
        {
            total += sub_total[i]; //Somar totais
        }
        printf("\n\t O valor total foi de R$%.2f(Sem Parcelas) \n\n", total);

        printf("\t Escolha uma forma de pagamento\n \t(1)-Vista ou (2)-Parcelado \n\n");
        scanf("%d",&opc);

        switch(opc)
        {
        case 1:// a vista
            if(total<=50) //5% Desconto
            {
                total *= 0.95;
            }
            else if(total>50 && total<100)  //10% Desconto
            {
                total *= 0.90;
            }
            else if(total>=100)  //18% Desconto
            {
                total = 0.82 /- total;
            }
            do
            {
                printf("\t\tTotal com Desconto: R$%.2f\n\n",total);
                printf("\nDigite o dinheiro recebido:\n");
                scanf("%f", &recebido);

                if(recebido<total)
                {
                    printf("Valor do troco Invalido,Falta R$ %.2f\n",recebido-total);
                }
            }
            while(recebido<total);

            troco = recebido-total;
            printf("\t\tTotal com desconto: %.2f\n", total);
            printf("\t\tTroco com desconto: %.2f\n\n", troco);
            printf("\n\tClique Enter para continuar...");
            break;

        case 2://parcelado
            do
            {
                printf("\tQual a quantidade de parcelas? \n\n");
                scanf("%d",&parcelas);

                if(parcelas<1)
                {
                    system("cls");
                    printf("\n\tNúmero de parcelas inválido, digite um valor acima de 1.\n\n");
                }
            }
            while(parcelas <1);

            if(parcelas<=3)  //5% Juros
            {
                total*= 1.05;
                total_parc = total/parcelas;
            }
            else if (parcelas>3) //8% Juros
            {
                total*= 1.08;
                total_parc = total/parcelas;
            }
            printf("\n|NOTA|\n\n");
            printf("|O valor a prazo (%d meses) ficou: R$%.2f\n",parcelas,total);
            printf("|O valor total das parcelas ficou: R$%.2f\n",total_parc);
            printf("|-----------------------------------------|\n\n\n");
            printf("|Digite ( 0 ) para voltar... \n\n");
            scanf("%d",&opc);
            break;
        }
        system("cls || clear");
        printf("\n                        < NOTA FISCAL > \n");
        printf("\n\n|| ITEM ||     NOME     || VALOR UNIT.(R$)|| QUANT. || SUB.TOTAL(R$)||");
        for(i=0; i<=t; i++)
        {
            printf("\n\n\n\n||  %d  ||   %s   ||   %.2f    ||   %d   ||   %.2f   ||", i+1, nome[i], val_unit[i], quantidade[i], sub_total[i]);
        }
        printf("\n\n\t\tTOTAL: %.2f", total);
        printf("\n\n\n");
        system("pause");

        system("cls || clear");
        printf("\n\n\t\tDESEJA FAZER UMA NOVA VENDA?\n\n\n\t\t\t< 1 > SIM.     < OUTRO VALOR > NÃO.\n");
        scanf("%d", &opc2);
    }
    while(opc2 == 1);

    return 0;
}
