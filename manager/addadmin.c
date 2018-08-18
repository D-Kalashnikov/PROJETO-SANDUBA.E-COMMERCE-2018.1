void Add_Admin(){
  char c;
  char cpf[13];
  char login[30];
  int end = 0;
  int endlp = 0;

   do{ 
    printf("Digite o CPF a ser cadastrado:\n");
    scanf("%s", cpf);

    int search = admin_search(range, admins, cpf);

    if(search == -1){
      strcpy(admins[ind_admins].dados.cpf, cpf);
      //
      printf("Digite o nome do novo Administrador:\n");
      fgets(admins[ind_admins].dados.nome, 50, stdin);
      int tam = strlen(admins[ind_admins].dados.nome);
      admins[ind_admins].dados.nome[tam-1]= '\0';
      //
      printf("Digite a idade do novo Administrador:\n");
      scanf("%i", admins[ind_admins].dados.idade);
      //
      admins[ind_admins].dados.status = 4;

      //LOGIN/PASSWORD
      do{
        printf("Digite o login do novo Administrador:\n");
        fgets(login, 30, stdin);
        int login_admsearch = loginadmin_search(range, admins, login);

        if(login_admsearch == -1){
          strcpy(admins[ind_admins].login_password.login, login);
          //
          printf("\nDigite a senha: ");
          do{
            c=getch();
            if(isprint(c)){
            admins[ind_admins].login_password.password[i]=c;
            i++;
            printf("*");
            }
            else if(c==8 && i){
            admins[ind_admins].login_password.password[i]='\0';
            i--;
            printf("\b \b");
            } 
        }while(c!=13);             
       admins[ind_admins].login_password.password[i]='\0';
       end = 1;
       wendlp = 1;
       system("cls");  
       printf("\n\nCadastro efetuado com sucesso...\n\n");
        }

        else{
          if(login_admsearch != -1){
            printf("Login invalido, tente novamente...");
          }
        }

      }while(endlp == 0);

        else{
        printf("CPF já cadastrado, tente novamente...\n");
        }
    }
  }while(end == 0);
}
