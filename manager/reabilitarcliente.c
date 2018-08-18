void DisblockClient(int quant, Cliente clientes[quant]){
  int choice;
  int search = client_search(quant, clientes);
  int flag = 0;

  do{
  if(search != -1){
    printf("Deseja realmente desbloquear esse usuario?\n");
    printf("1 - Sim\n");
    printf("2 - Não\n");
    scanf("%i", &choice);
      if(choice == 1){
        clientes[cont].dados.status = 1;
        flag = 1;
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
