int client_search(int ind_tclientes, Cliente clientes[ind_tclientes])
  {
  int i;
  char cpf[13];

  printf("Digite o CPF a ser buscado:\n");
  scanf("%s", cpf);

  for(i=0; i<ind_tclientes; i++)
  {
    if(strcmp(cpf, clientes[i].dados.cpf)== 0)
    {
      printf("Cliente encontrado\n");
      printf("Nome: %s\nIdade: %i\nCPF: %s\nStatus: %i\n", clientes[i].dados.nome, clientes[i].dados.idade, clientes[i].dados.cpf, clientes[i].dados.status);

      return i;
    }
  }
  printf("Cliente não encontrado.\n");
  return -1;
}
