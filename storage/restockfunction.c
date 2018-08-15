void restock(){
  readStorageDB("storageDB.txt", produtos, ind_tprodutos);

  restockfunctional();
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
      /*
      //Depois fazer a parte de calculos de valor para o relatorio financeiro
      */
    }
  }
}
