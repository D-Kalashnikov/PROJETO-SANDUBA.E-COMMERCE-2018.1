void Storage(){
  for(int i; i < tam;){
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
      getchar();
      system("cls");
    }
  }
}
