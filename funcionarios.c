//BUSCAR FUNCIONARIO
int buscar_funcionario(int quant, Funcionario funcionarios[quant])
{
  int cont;
  char cpf[13];
  printf("Digite o CPF:");
  scanf("%s", cpf);
  getchar();
  for(cont=0; cont<quant; cont++)
  {
    if(strcmp(cpf, funcionarios[cont].dados.cpf)==0)
    {
      printf("Funcionario encontrado\n");
      printf("Nome: %s\nIdade: %i\nCPF: %s\nStatus: %i\n", funcionarios[cont].dados.nome, funcionarios[cont].dados.idade, funcionarios[cont].dados.cpf, funcionarios[cont].dados.status);

      return cont;
    }
  }
  printf("Funcionario não encontrado.\n");
  return -1;
}

//REMOVER FUNCIONARIO
int remover_funcionario(int num, Funcionario funcionarios[num])
{
  int resp = buscar_funcionario(num, funcionarios);
  if(resp !=-1)
  {
    funcionarios[resp].dados.status = 0;
    printf("Funcionario removido\n");
    return 1;
  }
  printf("Funcionario não pode ser removido\n");
  return -1;
}

//CADASTRAR FUNCIONARIO
int cadastrar_funcionario(int num, Funcionario funcionarios[num], int indice_funcionario)
{
  int resp = buscar_funcionario(num, funcionarios);
  if(resp == -1)
  {
    
    printf("Digite o nome do funcionario:\n");
    fgets(funcionarios[indice_funcionario].dados.nome, 50, stdin);
    printf("Digite a idade:\n");
    scanf("%i", &funcionarios[indice_funcionario].dados.idade);
    getchar();
    printf("Digite o CPF:\n");
    fgets(funcionarios[indice_funcionario].dados.cpf, 13, stdin);
  }
}

//RELATORIO FINANCEIRO
void relatorio_financeiro()
{

}

//ALTERACAO DE SALARIO
void alteracao_salario(float* percentual)
{
  float percentsalario;
  printf("Digite o novo percentual para o salario do funcionario:\n");
  scanf("%f", &percentsalario);
  *(percentual) = percentsalario;
  printf("Salario modificado\n");
}
