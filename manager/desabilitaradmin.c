void AdminDisable(int quant, Admin admins[quant]){
  int choice;
  int search = admin_search(quant, admins);
  int flag = 0;

  do{
  if(search != -1){
    printf("Deseja realmente desabilitar esse administrador?\n");
    printf("1 - Sim\n");
    printf("2 - Não\n");
    scanf("%i", &choice);
      if(choice == 1){
        admins[cont].dados.status = 7;
        flag = 1;
      }

      else if(choice == 2){
        printf("Operação cancelada\nAperte uma tecla para sair...");
        flag = 1;
        getchar();
        system("cls")
      }

      else{
        printf("Comando inválido... Tente novamente\n");
        getchar();
        system("cls");
      }
    }
  }while(flag == 0);
}
