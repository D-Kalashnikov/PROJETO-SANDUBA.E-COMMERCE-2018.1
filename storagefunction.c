void Storage(){
  for(int i; i < tam; i++){
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
    printf("ID:%i", produtos[i].id);
    printf("Nome: %s", produtos[i].nome);
    printf("Tipo: %i", produtos[i].tipo);
    printf("Valor de compra: %.2f", produtos[i].valorc);
    printf("Valor de venda: %.2f", produtos[i].valorv);
    printf("Quantidade em estoque: %i", produtos[i].qtd);
    printf("Itens comprados: %i", produtos[i].comprados);
    printf("Itens vendidos: %i", produtos[i].vendidos);
  }
}