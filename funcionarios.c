//BUSCAR FUNCIONARIO
int buscar_funcionario(int quant, Funcionario funcionarios[], char* cpf)
{
  int cont;
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
  char cpf[13];
  int tam;
  printf("Digite o CPF:\n");
  fgets(cpf, 13, stdin);
  tam = strlen(cpf);
  cpf[tam-1] = '\0';
  int resp = buscar_funcionario(num, funcionarios, cpf);
  if(resp !=-1)
  {
    if(funcionarios[resp].dados.status == 5)
    {
      funcionarios[resp].dados.status = 6;
      printf("Funcionario removido\n");
      return 1;
    }
    else
    {
      printf("Funcionario já esta removido\n");
    }
  }
  printf("Funcionario não pode ser removido\n");
  return -1;
}

//CADASTRAR FUNCIONARIO
int cadastrar_funcionario(int num, Funcionario funcionarios[num], int indice_funcionario)
{
  int tam, resp;
  char cpf[13];
  //CPF
  printf("Digite o CPF:\n");
  fgets(cpf, 13, stdin);
  tam = strlen(cpf);
  cpf[tam-1] = '\0';
  resp = buscar_funcionario(num, funcionarios, cpf);
  if(resp==-1)
  {
    strcpy(funcionarios[indice_funcionario].dados.cpf, cpf);
    //NOME
    printf("Digite o nome do funcionario:\n");
    fgets(funcionarios[indice_funcionario].dados.nome, 50, stdin);
    tam = strlen(funcionarios[indice_funcionario].dados.nome);
    funcionarios[indice_funcionario].dados.nome[tam-1] = '\0';
      
    //IDADE
    printf("Digite a idade:\n");
    scanf("%i", &funcionarios[indice_funcionario].dados.idade);
    getchar();

    //STATUS
    funcionarios[indice_funcionario].dados.status = 5;

    return 1;
  }
  return -1;
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
