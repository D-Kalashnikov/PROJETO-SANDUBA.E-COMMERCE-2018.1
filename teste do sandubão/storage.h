#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
#include "structs.h"

void readStorageDB(char* path, Produto* produtos, int tam){
    FILE* archive = fopen(path, "r");
    fread(produtos, sizeof(Produto), tam, archive);
    fclose(archive);
}
//

void saveStorageDB(char* path, Produto* produtos, int tam){
  FILE* archive = fopen(path, "w");
  fwrite(produtos, sizeof(Produto), tam, archive);
  fclose(archive);
}

//

void product_search(int ind_tprodutos, Produto produtos[]){
  readStorageDB("storageDB.txt", produtos, ind_tprodutos);
  
  char search[30];
  printf("Digite o nome do produto:\n");
  fgets(search, 30,  stdin);
  int x = strlen(search);
  search[x-1] = '\0';

  int res = 0;

  for(int i = 0; i < ind_tprodutos; i++){
    if(strncmp(produtos[i].nome, search, (x-1)) == 0){
      printf("ID:%i\n", produtos[i].id);
      printf("Nome: %s\n", produtos[i].nome);
      printf("Tipo: %i\n", produtos[i].tipo);
      printf("Valor de compra: %.2f\n", produtos[i].valorc);
      printf("Valor de venda: %.2f\n", produtos[i].valorv);
      printf("Quantidade em estoque: %i\n", produtos[i].qtd);
      printf("Itens comprados: %i\n", produtos[i].comprados);
      printf("Itens vendidos: %i\n", produtos[i].vendidos);
      printf("\n\n");
    }
  }
}

//

void restockfunctional(int ind_tprodutos, Produto produtos[]){
  readStorageDB("storageDB.txt", produtos, ind_tprodutos);

  int aux_v=0;
  int aux_id=0;
  char aux_string[30];

  for(int i = 0; i < ind_tprodutos; i++){
    for (int j = i + 1; j < ind_tprodutos; j++) {
	if (produtos[i].qtd < produtos[j].qtd) {
		//
        	aux_v = produtos[i].qtd;
			produtos[i].qtd = produtos[j].qtd;
			produtos[j].qtd = aux_v;
        	//
        	aux_id = produtos[i].id;
        	produtos[i].id = produtos[j].id;
        	produtos[j].id = aux_id;
        	//
        	strcpy(aux_string, produtos[i].nome);
        	strcpy(produtos[i].nome, produtos[j].nome);
        	strcpy(produtos[j].nome, aux_string);
		}
	}
  }
	
   for(int i = 0; i < ind_tprodutos; i++){
    printf("Quantidade em estoque:\n");
    printf("ID: %i\tNome:%s\tItens em estoque:%i\n",produtos[i].id,produtos[i].nome, produtos[i].qtd);
  }
}

//

void restock(int ind_tprodutos, Produto produtos[], float* psaldo_bancario){
  readStorageDB("storageDB.txt", produtos, ind_tprodutos);

  restockfunctional(ind_tprodutos, produtos);
  int id_toverify;
  int qtd_toadd;

  printf("Digite o ID do produto a ser restocado:\n");
  scanf("%i", &id_toverify);

  for(int i=0; i<ind_tprodutos; i++){
    if(id_toverify == produtos[i].id){
      printf("ID:%i\n", produtos[i].id);
      printf("Nome: %s\n", produtos[i].nome);
      printf("Tipo: %i\n", produtos[i].tipo);
      printf("Valor de compra: %.2f\n", produtos[i].valorc);
      printf("Valor de venda: %.2f\n", produtos[i].valorv);
      printf("Quantidade em estoque: %i\n", produtos[i].qtd);
      printf("Itens comprados: %i\n", produtos[i].comprados);
      printf("Itens vendidos: %i\n", produtos[i].vendidos);
      printf("\n\n");

      printf("Digite a quantidade de produtos a ser estocado:\n");
      scanf("%i", &qtd_toadd);

      produtos[i].qtd = produtos[i].qtd + qtd_toadd;
      
      if((*psaldo_bancario) - qtd_toadd * produtos[i].valorc>=0){
      produtos[i].comprados += qtd_toadd;
      produtos[i].qtd += qtd_toadd;
      produtos[i].totalc += qtd_toadd * produtos[i].valorc;
      (*psaldo_bancario)-= qtd_toadd * produtos[i].valorc;
    }
    else{
      printf("Saldo bancário insuficiente para realizar a compra! O saldo bancário atual é %.2f:\n", *psaldo_bancario);
    }
      
    }

    else{
      printf("Produto não encontrado\n");
    }
  }
}

//

void stockfunctional(int ind_tprodutos, Produto produtos[]){
  readStorageDB("storageDB.txt", produtos, ind_tprodutos);

  int aux_v=0;
  int aux_id=0;
  char aux_string[30];

  for(int i = 0; i < ind_tprodutos; i++){
    for (int j = i + 1; j < ind_tprodutos; j++) {
		if (produtos[i].qtd > produtos[j].qtd) {
			//
        		aux_v = produtos[i].qtd;
				produtos[i].qtd = produtos[j].qtd;
				produtos[j].qtd = aux_v;
        		//
        		aux_id = produtos[i].id;
        		produtos[i].id = produtos[j].id;
        		produtos[j].id = aux_id;
        		//
        		strcpy(aux_string, produtos[i].nome);
        		strcpy(produtos[i].nome, produtos[j].nome);
        		strcpy(produtos[j].nome, aux_string);
		}
	}
  }

  for(int i = 0; i < ind_tprodutos; i++){
    printf("Quantidade em estoque:\n");
    printf("ID: %i\tNome:%s\tItens em estoque:%i\n",produtos[i].id,produtos[i].nome, produtos[i].qtd);
  }
}

//

void Storage(int ind_tprodutos, Produto produtos[]){
  for(int i; i < ind_tprodutos;){
    readStorageDB("storageDB.txt", produtos, ind_tprodutos);
    
    printf("___________________\n");
    switch(produtos[i].tipo){
      case 1:
      printf("\tPao\n");
      break;

      case 2:
      printf("\tRecheio\n");
      break;

      case 3:
      printf("\tMolho\n");
      break;

      case 4:
      printf("\tVegetais\n");
      break;

      case 5:
      printf("\tQueijos\n");
      break;
    }
    printf("___________________\n");
    printf("ID:%i\n", produtos[i].id);
    printf("Nome: %s\n", produtos[i].nome);
    printf("Tipo: %i\n", produtos[i].tipo);
    printf("Valor de compra: %.2f\n", produtos[i].valorc);
    printf("Valor de venda: %.2f\n", produtos[i].valorv);
    printf("Quantidade em estoque: %i\n", produtos[i].qtd);
    printf("Itens comprados: %i\n", produtos[i].comprados);
    printf("Itens vendidos: %i\n", produtos[i].vendidos);
    printf("\n\n");
    i++;
    if(i%10 == 0 && i !=0){
      printf("Pressione alguma tecla para avançar para a próxima página...");
      _getch();
      system("cls");
    }
  }
}

//

void bestseller(int ind_tprodutos, Produto produtos[]){
  readStorageDB("storageDB.txt", produtos, ind_tprodutos);

  int aux_v=0;
  int aux_id=0;
  char aux_string[30];

  for(int i = 0; i < ind_tprodutos; i++){
    for (int j = i + 1; j < ind_tprodutos; j++) {
	if (produtos[i].vendidos < produtos[j].vendidos) {
	//
        aux_v = produtos[i].vendidos;
	produtos[i].vendidos = produtos[j].vendidos;
	produtos[j].vendidos = aux_v;
        //
        aux_id = produtos[i].id;
        produtos[i].id = produtos[j].id;
        produtos[j].id = aux_id;
        //
        strcpy(aux_string, produtos[i].nome);
        strcpy(produtos[i].nome, produtos[j].nome);
        strcpy(produtos[j].nome, aux_string);
			}
		}
  }

  for(int i = 0; i < ind_tprodutos; i++){
    printf("Produtos mais vendidos:\n");
    printf("ID: %i\tNome:%s\tItens vendidos:%i\n",produtos[i].id,produtos[i].nome, produtos[i].vendidos);
  }
}

//


