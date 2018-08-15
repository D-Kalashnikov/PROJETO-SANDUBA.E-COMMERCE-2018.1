void product_search(){
  readStorageDB("storageDB.txt", produtos, ind_tprodutos);
  
  char search[30];
  printf("Digite o nome do produto:\n");
  fgets(search, 30,  stdin);
  int x = strlen(search);
  search[x-1] = '\0';

  int res = 0;

  for(int i = 0; i < ind_tprodutos; i++){
    if(strncmp(produtos[i].nome, search, (x-1)) == 0){
      printf("printf("ID:%i\n", produtos[i].id);
      printf("Nome: %s\n", produtos[i].nome);
      printf("Tipo: %i\n", produtos[i].tipo);
      printf("Valor de compra: %.2f\n", produtos[i].valorc);
      printf("Valor de venda: %.2f\n", produtos[i].valorv);
      printf("Quantidade em estoque: %i\n", produtos[i].qtd);
      printf("Itens comprados: %i\n", produtos[i].comprados);
      printf("Itens vendidos: %i\n", produtos[i].vendidos);
      printf("\n\n");")
    }
  }
}
