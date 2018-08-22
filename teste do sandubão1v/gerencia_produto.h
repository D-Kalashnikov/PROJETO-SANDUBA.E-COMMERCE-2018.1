#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
#include "structs.h"

int menu_gerenciar_produto()
{
  int menu;
  do
  {
    printf("Para gerenciar os produtos, siga o menu: 1- Cadastro, 2-Pesquisa, 3-Alterar, 4-impressão,5-Comprar, 6-sair\n");
    scanf("%i", &menu);
    getchar();
  }while(menu<1 || menu>6);

  return menu;
}

int menu_alterar_prod()
{
  int menu;

  do
    {
    printf("Siga as opções para alteração dos produtos:\n");
    printf("1-nome do produto\n");
    printf("2-tipo do produto\n");
    printf("3-valor de compra\n");
    printf("4-valor de venda\n");
    printf("5-valores de compra e venda\n");//alterar aqui
    printf("6-desistir da alteração\n");
    scanf("%i", &menu);
    getchar();

    }while(menu<1 || menu>6);

  return menu;
}

int pesquisar_prod(Produto produto[], int qte_prod_cad,char nome[30])
{
  for(int i=0; i<qte_prod_cad; i++)
  {
    if (strcmp(produto[i].nome, nome)==0)
    {
    return i;
    }
  }
  return -1;
}



void alterar_prod(Produto produto[], int qte_prod_cad,char nome[30])
{
  int menu=0, indice_teste;
  char nome_teste[30];
  int ajus_scanf;

  int indice = pesquisar_prod(produto, qte_prod_cad, nome);
  if(indice!=-1)
  {
    menu = menu_alterar_prod();
    if(menu==1)
    {
      printf("Digite o novo nome do produto.\n");
      fgets(nome_teste, 30, stdin);
      ajus_scanf = strlen(nome_teste);
      nome_teste[ajus_scanf - 1] = '\0';

      indice_teste = pesquisar_prod(produto, qte_prod_cad, nome_teste);
      if(indice_teste==-1)
      {
        strcpy(produto[indice].nome, nome_teste);
      }
      else
      {
        printf("Alteração não foi efetivada! Nome já cadastrado!\n");
      }
    }
    else if(menu==2)
    {
      do
      {
        printf("Digite o novo tipo do produto: 1-pao, 2-recheio, 3-queijo, 4-molho, 5-vegetal\n");
        scanf("%i", &produto[indice].tipo);
        getchar();
      }while(produto[indice].tipo<1 || produto[indice].tipo>5);
      //alterar aqui
    }

    else if(menu==3)
    {
      printf("Digite o novo valor da compra.\n");
      scanf("%f", &produto[indice].valorc);
      getchar();
    }
    else if (menu==4)
    {
      printf("Digite o novo valor da venda.\n");
      scanf("%f", &produto[indice].valorv);
      getchar();
    }
    else if(menu==5)
    {
      printf("Digite o novo valor da compra.\n");
      scanf("%f", &produto[indice].valorc);
      getchar();
    
      printf("Digite o novo valor da venda.\n");
      scanf("%f", &produto[indice].valorv);
      getchar();
    }
    
  }
  else
  {
    printf("Não foi possível a alteração. Produto não cadastrado!\n");
  } 
}

void cadastrar_prod(Produto produto[], int tam, int* pqte_prod_cad)
{
  char nome_teste[30];
  int ajus_scanf;

  printf("Digite o nome do produto:\n");
  fgets(nome_teste, 30, stdin);
  ajus_scanf = strlen(nome_teste);
  nome_teste[ajus_scanf - 1] = '\0';

  int indice = pesquisar_prod(produto, *pqte_prod_cad, nome_teste);
  if(indice==-1)
  {
    produto[*pqte_prod_cad].id = (*pqte_prod_cad) + 1;
    strcpy(produto[*pqte_prod_cad].nome, nome_teste);
    do
    {
    printf("Digite o tipo do produto: 1-pao, 2-recheio, 3-queijo, 4-molho, 5-vegetal\n");
    scanf("%i", &produto[*pqte_prod_cad].tipo);
    getchar();
    }while(produto[*pqte_prod_cad].tipo<1 || produto[*pqte_prod_cad].tipo>5);
    //alterar aqui
    
    printf("Digite o valor da compra.\n");
    scanf("%f", &produto[*pqte_prod_cad].valorc);
    getchar();

    printf("Digite o valor da venda.\n");
    scanf("%f", &produto[*pqte_prod_cad].valorv);
    getchar();

    produto[*pqte_prod_cad].totalc = 0;
    produto[*pqte_prod_cad].totalv = 0;
    produto[*pqte_prod_cad].qtd = 0;
    produto[*pqte_prod_cad].comprados = 0;
    produto[*pqte_prod_cad].vendidos = 0;
    
    (*pqte_prod_cad)++;
  }
  else
  {
    printf("Não foi possível realizar o cadastro. Produto já cadastrado!\n");
  }
}
void imprimir_prod(Produto produto[], int i)
{
  printf("ID - %i\n", produto[i].id);
  printf("Nome - %s\n", produto[i].nome);
  printf("Tipo - %i\n", produto[i].tipo);
  printf("Valor unitário de Compra - %.2f\n", produto[i].valorc);
  printf("Valor unitário de Venda - %.2f\n", produto[i].valorv);
  printf("Total de Compras - %.2f\n", produto[i].totalc);
  printf("Valor de Vendas - %.2f\n", produto[i].totalv);
  printf("Quantidade em estoque - %i\n", produto[i].qtd);
  printf("Quantidade Comprada - %i\n", produto[i].comprados);
  printf("Quantidade Vendida - %i\n", produto[i].vendidos);
  printf("\n\n");
}
void imprimir_todos_prod(Produto produto[], int qte_prod_cad)
{
  for(int i=0; i < qte_prod_cad; i++)
  {
    printf("ID - %i\n", produto[i].id);
    printf("Nome - %s\n", produto[i].nome);
    printf("Tipo - %i\n", produto[i].tipo);
    printf("Valor unitário de Compra - %.2f\n", produto[i].valorc);
    printf("Valor unitário de Venda - %.2f\n", produto[i].valorv);
    printf("Total de Compras - %.2f\n", produto[i].totalc);
    printf("Valor de Vendas - %.2f\n", produto[i].totalv);
    printf("Quantidade em estoque - %i\n", produto[i].qtd);
    printf("Quantidade Comprada - %i\n", produto[i].comprados);
    printf("Quantidade Vendida - %i\n", produto[i].vendidos);
    printf("\n\n");
  }
}
void comprar_prod(Produto produto[],int qte_prod_cad,float* psaldo_bancario)
{
  char nome_toverify[30];
  int qtd_toadd;
  int indice;
  int ajus_scanf;


  printf("Digite o nome do produto a ser estocado:\n");
  fgets(nome_toverify, 30, stdin);
  ajus_scanf = strlen(nome_toverify);
  nome_toverify[ajus_scanf - 1] = '\0';

  indice = pesquisar_prod (produto, qte_prod_cad, nome_toverify);
  if(indice!=-1)
  {
    imprimir_prod(produto, indice);
    
    printf("Digite a quantidade de produtos a ser estocado:\n");
    scanf("%i", &qtd_toadd);

    if((*psaldo_bancario) - qtd_toadd * produto[indice].valorc>=0)
    {
      produto[indice].comprados += qtd_toadd;
      produto[indice].qtd += qtd_toadd;
      produto[indice].totalc += qtd_toadd * produto[indice].valorc;
      (*psaldo_bancario)-= qtd_toadd * produto[indice].valorc;
    }
    else
    {
      printf("Saldo bancário insuficiente para realizar a compra! O saldo bancário atual é %.2f:\n", *psaldo_bancario);
    }

    
  }
  else
  {
    printf("Não foi possível efetuar a compra. Produto não cadastrado!\n");
  }
}
void gerenciar_produto(Produto produto [], int tam, int* pqte_prod_cad, float* psaldo_bancario)
{
  int indice, menu, ajus_scanf;
  char nome_teste[30];
  do
  {
    menu = menu_gerenciar_produto();

    if(menu==1)
    {
      //cadastrar_prod(produto, *pqte_prod_cad);
    }
    else if(menu==2)
    {
      printf("Digite o nome do produto a ser pesquisado:\n");
      fgets(nome_teste, 30, stdin);
      ajus_scanf = strlen(nome_teste);
      nome_teste[ajus_scanf - 1] = '\0';

      indice = pesquisar_prod(produto, *pqte_prod_cad, nome_teste);
      if(indice!=-1)
      {
        imprimir_prod(produto, indice);
        
      }
      else
      {
        printf("Produto não cadastrado.\n");
      }
      
      
    }
    else if(menu==3)
    { 
      printf("Digite o nome do produto a ser alterado:\n");
      fgets(nome_teste, 30, stdin);
      ajus_scanf = strlen(nome_teste);
      nome_teste[ajus_scanf - 1] = '\0';
      
      alterar_prod(produto, *pqte_prod_cad, nome_teste); 
    }
    else if(menu==4)
    {
      imprimir_todos_prod(produto,*pqte_prod_cad);
    }
    else if(menu==5)
    {
      comprar_prod(produto, *pqte_prod_cad, psaldo_bancario);
    }
  }while(menu!=6);
}
