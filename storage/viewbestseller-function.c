void bestseller(int ind_tprodutos, Produto produtos[ind_tprodutos]){
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

  for(i = 0; i < ind_tprodutos; i++){
    printf("Produtos mais vendidos:\n");
    printf("ID: %i\tNome:%s\tItens vendidos:%i\n",produtos[i].id,produtos[i].nome, produtos[i].vendidos);
  }
}
