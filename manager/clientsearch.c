int client_search(int quant, Cliente clientes[quant])
  {
  int cont;
  char cpf[13];

  printf("Digite o CPF a ser buscado:\n");
  scanf("%s", cpf);

  for(cont=0; cont<quant; cont++)
  {
    if(strcmp(cpf, clientes[cont].dados.cpf)== 0)
    {
      printf("Cliente encontrado\n");
      printf("Nome: %s\nIdade: %i\nCPF: %s\nStatus: %i\n", clientes[cont].dados.nome, clientes[cont].dados.idade, clientes[cont].dados.cpf, clientes[cont].dados.status);

      return cont;
    }
  }
  printf("Cliente não encontrado.\n");
  return -1;
}
