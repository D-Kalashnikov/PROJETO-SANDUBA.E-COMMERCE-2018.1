void DisblockClient(int ind_tclientes, Cliente clientes[ind_tclientes]){
  int choice;
  int search = client_search(ind_tclientes, clientes);
  int flag = 0;

  do{
  if(search != -1){
    printf("Deseja realmente desbloquear esse usuario?\n");
    printf("1 - Sim\n");
    printf("2 - Não\n");
    scanf("%i", &choice);
      if(choice == 1){
        if(clientes[search].dados.status != 1){
        clientes[search].dados.status = 1;
        flag = 1;
        }
        
        else{
          printf("Usuario já esta disponível!\n");
          flag = 1;
        }
      }

      else if(choice == 2){
        printf("Operação cancelada\nAperte uma tecla para sair...");
        flag = 1;
        getchar();
        system("cls");
      }

      else{
        printf("Comando inválido... Tente novamente\n");
        getchar();
        system("cls");
      }
    }
  }while(flag == 0);
}
