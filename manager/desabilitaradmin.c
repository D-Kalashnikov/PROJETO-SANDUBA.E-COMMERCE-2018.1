void AdminDisable(int ind_admins, Admin admins[ind_admins]){
  int choice;
  char cpf[13];
  printf("Digite o CPF do Admin a ser desabilitado:\n");
  int search = admin_search(ind_admins, admins, cpf);
  int flag = 0;

  do{
  if(search != -1){
    printf("Admin encontrado\n");
    printf("Nome: %s\nIdade: %i\nCPF: %s\nStatus: %i\n", admins[search].dados.nome, admins[search].dados.idade, admins[search].dados.cpf, admins[search].dados.status);
    printf("Deseja realmente desabilitar esse administrador?\n");
    printf("1 - Sim\n");
    printf("2 - Não\n");
    scanf("%i", &choice);
      if(choice == 1){
        if(admins[search].dados.status != 7){
        admins[search].dados.status = 7;
        flag = 1;
        }
        
        else{
          printf("Admin já desabilitado!\n");
          flag = 1;
        }
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
    
    else{
      printf("Admin não encontrado!\n");
    }
  }while(flag == 0);
}
