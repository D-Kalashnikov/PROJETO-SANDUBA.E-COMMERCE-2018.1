#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
#include "structs.h"

void showRecommended(int clientelogon, int ind_clientes, Cliente clientes[]){
  printf("Recomemdamos para você: \n");
  printf("Sanduíche de %s com %i cm, recheiado de %s com %s,", clientes[clientelogon].ultimo_sanduiche.pao.nome, clientes[clientelogon].ultimo_sanduiche.tamanhopao, clientes[clientelogon].ultimo_sanduiche.recheio.nome, clientes[clientelogon].ultimo_sanduiche.queijos.nome);

  printf("salada composta por:");
  for(int i = 0; i < clientes[clientelogon].ultimo_sanduiche.verduras; i++){
    printf(" %s,", clientes[clientelogon].ultimo_sanduiche.salada[i].nome);
  }

  printf(" e molho de %s pelo valor de R$%.2f!\n", clientes[clientelogon].ultimo_sanduiche.molho.nome, clientes[clientelogon].ultimo_sanduiche.preco);
}

float buyRecommended(int clientelogon, int ind_clientes, Cliente clientes[], int ind_tprodutos, Produto produtos[]){
  float somatorio;
  int flag = 0;
  showRecommended(clientelogon, ind_clientes, clientes);
  do{
    printf("\nDeseja realmente comprar este sanduíche?\n1 - Sim\n2 - Não\n");
    int s_n = 0;
    scanf("%i",&s_n);

    if(s_n == 1){
      //
        if(clientes[clientelogon].ultimo_sanduiche.tamanhopao == 15){
        produtos[clientes[clientelogon].ultimo_sanduiche.pao.id -1].qtd -= 1;
        produtos[clientes[clientelogon].ultimo_sanduiche.pao.id -1].vendidos += 1;
        produtos[clientes[clientelogon].ultimo_sanduiche.pao.id -1].totalv += clientes[clientelogon].ultimo_sanduiche.pao.valorv;

        produtos[clientes[clientelogon].ultimo_sanduiche.recheio.id -1].qtd -= 1;
        produtos[clientes[clientelogon].ultimo_sanduiche.recheio.id -1].vendidos += 1;
        produtos[clientes[clientelogon].ultimo_sanduiche.recheio.id -1].totalv += clientes[clientelogon].ultimo_sanduiche.recheio.valorv;

        produtos[clientes[clientelogon].ultimo_sanduiche.molho.id -1].qtd -= 1;
        produtos[clientes[clientelogon].ultimo_sanduiche.molho.id -1].vendidos += 1;
        produtos[clientes[clientelogon].ultimo_sanduiche.molho.id -1].totalv += clientes[clientelogon].ultimo_sanduiche.molho.valorv;

        produtos[clientes[clientelogon].ultimo_sanduiche.queijos.id -1].qtd -= 1;
        produtos[clientes[clientelogon].ultimo_sanduiche.queijos.id -1].vendidos += 1;
        produtos[clientes[clientelogon].ultimo_sanduiche.queijos.id -1].totalv += clientes[clientelogon].ultimo_sanduiche.queijos.valorv;
      }
      else if(clientes[clientelogon].ultimo_sanduiche.tamanhopao == 30)
      {
        produtos[clientes[clientelogon].ultimo_sanduiche.pao.id -1].qtd -= 2;
        produtos[clientes[clientelogon].ultimo_sanduiche.pao.id -1].vendidos += 2;
        produtos[clientes[clientelogon].ultimo_sanduiche.pao.id -1].totalv += 2*clientes[clientelogon].ultimo_sanduiche.pao.valorv;

        produtos[clientes[clientelogon].ultimo_sanduiche.recheio.id -1].qtd -= 2;
        produtos[clientes[clientelogon].ultimo_sanduiche.recheio.id -1].vendidos += 2;
        produtos[clientes[clientelogon].ultimo_sanduiche.recheio.id -1].totalv += 2*clientes[clientelogon].ultimo_sanduiche.recheio.valorv;

        produtos[clientes[clientelogon].ultimo_sanduiche.molho.id -1].qtd -= 2;
        produtos[clientes[clientelogon].ultimo_sanduiche.molho.id -1].vendidos += 2;
        produtos[clientes[clientelogon].ultimo_sanduiche.molho.id -1].totalv += 2*clientes[clientelogon].ultimo_sanduiche.molho.valorv;

        produtos[clientes[clientelogon].ultimo_sanduiche.queijos.id -1].qtd -= 2;
        produtos[clientes[clientelogon].ultimo_sanduiche.queijos.id -1].vendidos += 2;
        produtos[clientes[clientelogon].ultimo_sanduiche.queijos.id -1].totalv += 2*clientes[clientelogon].ultimo_sanduiche.queijos.valorv;
      }
      //

      for(int i = 0; i < clientes[clientelogon].ultimo_sanduiche.verduras; i++)
      {
        produtos[clientes[clientelogon].ultimo_sanduiche.salada[i].id -1].qtd -= 1;
        produtos[clientes[clientelogon].ultimo_sanduiche.salada[i].id -1].vendidos += 1;
        produtos[clientes[clientelogon].ultimo_sanduiche.salada[i].id -1].totalv += clientes[clientelogon].ultimo_sanduiche.salada[i].valorv;
      }
      //
      clientes[clientelogon].compras_realizadas++;
      if(clientes[clientelogon].compras_realizadas % 3 == 0){
      	somatorio = clientes[clientelogon].ultimo_sanduiche.preco * 0.7;
	  }
	  
	  else{
      somatorio = clientes[clientelogon].ultimo_sanduiche.preco;
 	 }
      flag = 1;
      return somatorio;
    }

    else if(s_n == 2){
      printf("Sem problemas, temos diversas opções de composição para você neste dia de hoje!\n");
      flag = 1;
    }

    else{
      printf("Comando inválido... Tente novamente...\n");
    }
  }while(flag == 0);
}
