int admin_search(int quant, Admin admins[quant])
  {
  int cont;
  char cpf[13];

  printf("Digite o CPF a ser buscado:\n");
  scanf("%s", cpf);

  for(cont=0; cont<quant; cont++)
  {
    if(strcmp(cpf, admins[cont].dados.cpf)== 0)
    {
      printf("Admin encontrado\n");
      printf("Nome: %s\nIdade: %i\nCPF: %s\nStatus: %i\n", admins[cont].dados.nome, admins[cont].dados.idade, admins[cont].dados.cpf, admins[cont].dados.status);

      return cont;
    }
  }
  printf("Admin não encontrado.\n");
  return -1;
}
