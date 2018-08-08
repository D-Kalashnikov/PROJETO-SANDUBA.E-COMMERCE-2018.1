void restockfunctional(){
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
   for(i = 0; i < ind_tprodutos; i++){
    printf("Quantidade em estoque:\n");
    printf("ID: %i\tNome:%s\tItens em estoque:%i\n",produtos[i].id,produtos[i].nome, produtos[i].qtd);
  }
}
