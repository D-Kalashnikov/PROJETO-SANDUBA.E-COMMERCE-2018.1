void show_admins(){
  readAdmins("adminsDB.txt", admins, ind_tadmins);

  int i;
  for(i=0; i < ind_tadmins;){
    printf("Nome: %s\n", admins[i].dados.nome);
    printf("Idade: %i\n", admins[i].dados.idade);
    printf("Status: %i\n", admins[i].dados.status);
    printf("CPF: %i\n", admins[i].dados.cpf);
    printf("Login: %s\n", admins[i].login_password.login);
    i++;
    if(i%10 == 0 && i !=0){
      printf("Pressione alguma tecla para avançar para a próxima página...");
      getchar();
      system("cls");
    }
  }
}
