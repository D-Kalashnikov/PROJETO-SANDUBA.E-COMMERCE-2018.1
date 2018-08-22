#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
#include "structs.h"

void calculo_e_impressao_rel_fin (Produto produto[],int qte_prod_cad, float saldo_bancario,float  percentual_sal, float percentual_odesp)
{

  //Cálculo do relatório financeiro.
  float receita = 0, despesa = 0, despesa_apagar = 0;
  
  for(int i=0; i<qte_prod_cad;i++)
  {
   receita += produto[i].totalv;
  }

  for(int i=0; i<qte_prod_cad;i++)
  {
   despesa += produto[i].totalv * (percentual_odesp + percentual_sal);
   despesa_apagar += produto[i].totalv * (percentual_odesp + percentual_sal);

   despesa += produto[i].totalc;
  }
  //impressao do relatório financeiro

  printf("\n(+)RECEITA:         = %.2f\n", receita);
  
  printf("Venda de produtos:\n");

  for(int i=0; i<qte_prod_cad;i++)
  {
    printf("%s = ",produto[i].nome);
    printf("%.2f\n",produto[i].totalv);
  }

  printf("\n\n");
  printf("(-) DESPESA:          = %.2f\n", despesa);
  printf("Manut. do site e Frete= %.2f\n", receita * percentual_odesp);
  printf("Salários              = %.2f\n", receita * percentual_sal);
  printf("\n\n");
  printf("Compra de produtos:\n");

  for(int i=0; i<qte_prod_cad;i++)
  {
    printf("%s = ",produto[i].nome);
    printf("%.2f\n",produto[i].totalc);
  }

  printf("\n\n");
  printf("(=) LUCRO:            =     %.2f\n\n", receita - despesa);
  printf("(+)Invest. inicial       = 10000.00\n\n");
  printf("(=) SALDO BANCÁRIO:   =     %.2f\n", saldo_bancario - despesa_apagar);
  printf("\n");
  
}
