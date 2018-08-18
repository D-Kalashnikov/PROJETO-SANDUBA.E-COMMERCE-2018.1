//BUSCAR CLIENTE
int buscar_cliente(int quant, Cliente clientes[quant], char* cpf)
{
  int cont;
  for(cont=0; cont<quant; cont++)
  {
    if(strcmp(cpf, clientes[cont].dados.cpf)==0)
    {
      printf("\nCliente encontrado\n\n");
      printf("Nome: %s\nIdade: %i\nCPF: %s\nStatus: %i\n", clientes[cont].dados.nome, clientes[cont].dados.idade, clientes[cont].dados.cpf, clientes[cont].dados.status);

      return cont;
    }
  }
  printf("Cliente não encontrado.\n");
  return -1;
}

//BUSCAR LOGIN
int buscar_login(int quant, Cliente clientes[quant], char* login)
{
  int cont;
  for(cont=0; cont<quant; cont++)
  {
    if(strcmp(login, clientes[cont].login_password.login)==0)
    {
      return 1;
    }
    return -1;
  }
}

//CADASTRO CLIENTE
int cadastro_cliente(int num, Cliente clientes[num], int indice_cliente)
{
  int tam, resp, resp2, fim = 0, resp3;
  char cpf[13], login[30];

        //DADOS PESSOAIS
  //CPF 
  printf("Digite o seu CPF:\n");
  fgets(cpf, 13, stdin);
  tam = strlen(cpf);
  cpf[tam-1] = '\0';
  resp = buscar_cliente(num, clientes, cpf);
  if(resp == -1)
  {
    printf("\n\tDeseja se cadastrar?\n1-Sim\n2-Nao\n");
    scanf("%i", &resp3);
    getchar();
    if(resp3 == 1)
    {
      strcpy(clientes[indice_cliente].dados.cpf, cpf);
      printf("\n\tDados pessoais:\n\n");
      //NOME 
      printf("Digite o seu nome:\n");
      fgets(clientes[indice_cliente].dados.nome, 50, stdin);
      tam = strlen(clientes[indice_cliente].dados.nome);
      clientes[indice_cliente].dados.nome[tam-1] = '\0';

      //IDADE
      printf("Digite a sua idade:\n");
      scanf("%i", &clientes[indice_cliente].dados.idade);
      getchar();

              //ENDERECO 
      printf("\tEndereco:\n\n");
      //RUA
      printf("Digite o nome da rua:\n");
      fgets(clientes[indice_cliente].endereco.rua, 100, stdin);
      tam = strlen(clientes[indice_cliente].endereco.rua);
      clientes[indice_cliente].endereco.rua[tam-1] = '\0';

      //NUMERO 
      printf("Digite o numero da sua casa:\n");
      scanf("%i", &clientes[indice_cliente].endereco.numero);
      getchar();

      //COMPLEMENTO 
      printf("Digite o complemento:\n");
      fgets(clientes[indice_cliente].endereco.complemento, 100, stdin);
      tam = strlen(clientes[indice_cliente].endereco.complemento);
      clientes[indice_cliente].endereco.complemento[tam-1] = '\0';

      //BAIRRO 
      printf("Digite o bairro:\n");
      fgets(clientes[indice_cliente].endereco.bairro, 30, stdin);
      tam = strlen(clientes[indice_cliente].endereco.bairro);
      clientes[indice_cliente].endereco.bairro[tam-1] = '\0';

      //CEP 
      printf("Digite o seu CEP:\n");
      fgets(clientes[indice_cliente].endereco.cep, 10, stdin);
      tam = strlen(clientes[indice_cliente].endereco.cep);
      clientes[indice_cliente].endereco.cep[tam-1] = '\0';

      //CIDADE 
      printf("Digite a sua cidade:\n");
      fgets(clientes[indice_cliente].endereco.cidade, 30, stdin);
      tam = strlen(clientes[indice_cliente].endereco.cidade);
      clientes[indice_cliente].endereco.cidade[tam-1] = '\0';

      //ESTADO 
      printf("Digite a sigla do seu estado:\n");
      fgets(clientes[indice_cliente].endereco.estado, 3, stdin);
      tam = strlen(clientes[indice_cliente].endereco.estado);
      clientes[indice_cliente].endereco.estado[tam-1] = '\0';

            //CONTA
      printf("\tConta:\n\n");
      //LOGIN 
      while(fim!=1)
      {
      getchar();
      printf("Digite o seu login:\n");
      fgets(login, 30, stdin);
      tam = strlen(login);
      login[tam-1] = '\0';
      resp2 = buscar_login(num, clientes, login);
      if(resp == -1)
      {
        printf("Login disponivel\n");
        strcpy(clientes[indice_cliente].login_password.login, login);
        fim = 1;
      }
      else
    {
      printf("Login nao disponivel\nTente novamente\n");
    }
  

    //SENHA
    while(fim!=0)
    {
      printf("Escolha uma senha para sua conta:\n");
      fgets(clientes[indice_cliente].login_password.password, 9, stdin);
      tam = strlen(clientes[indice_cliente].login_password.password);
      clientes[indice_cliente].login_password.password[tam-1] = '\0';
      fim = 0;

      //STATUS
      clientes[indice_cliente].dados.status = 5;
      
      return 1;
    }
    }
    }
  }
  else
  {
    printf("CPF ja cadastrado\n");
    return -1;
  }
}

//REMOVER CLIENTE 
int remover_cliente(int quant, Cliente clientes[])
{
  int resp, tam;
  char cpf[13];
  printf("Digite o CPF:");
  fgets(cpf, 13, stdin);
  tam = strlen(cpf);
  cpf[tam-1] = '\0';
  resp = buscar_cliente(quant, clientes, cpf);
  if(resp !=-1)
  {
    int resp2;
    printf("Cliente achado\nDeseja remover cliente?\n1-sim  2-nao\n");
    scanf("%i", &resp2);
    getchar();
    if(resp2==1)
    {
      if(clientes[resp].dados.status == 5)
      {
        clientes[resp].dados.status = 6;
        printf("Cliente removido\n");
        return 2;
      }
      else
      {
        printf("O cliente ja estava removido\n");
        return 0;
      }
    }
    else
    {
      printf("Remocao cancelada\n");
      return 1;
    }
  }
  else
  {
    printf("Cliente nao achado\n");
    return -1;
  }
}


//BUSCAR SENHA 
int buscar_senha(int quant, Cliente clientes[], char password[]) 
{ 
  for(int cont=0; cont<quant; cont++) 
  { 
    if(strcmp(password, clientes[cont].login_password.password)==0) 
    { 
      return 1; 
    } 
  } 
  return -1; 
} 

//BUSCAR PASSWORD 
int buscar_password(int quant, Cliente clientes[], char password[], char login[]) 
{ 
  int check = buscar_login(quant, clientes, login); 
  if(check == 1) 
  { 
    for(int cont = 0; cont < quant; cont++)
    { 
      if(strcmp(password, clientes[cont].login_password.password) == 0) 
      { 
        return 1;
      }
    }
    return -1;
  } 
  else 
  { 
    return -1;
  } 
} 
