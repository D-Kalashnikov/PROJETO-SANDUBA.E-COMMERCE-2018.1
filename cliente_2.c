//LIMPAR BUFFER
void limpar_buffer() // deixei essa função sem ser utilizada no código visto que toda vez q ela era executada o cliente tinha que dar dois enter para avançar na sua seleção de opções.
{
  char c;
  while(c !='\n')
  {
    c = getchar();
  }
}

//BUSCAR VAZIO
int buscar_vazio(int quant, char palavra[])
{
  int cont, cont2=0;
  for(cont = 0; cont<quant; cont++)
  {
    if(palavra[cont] == 32)
    {
      cont2 = cont2 + 1;
    }
  }
  if(cont2==quant)
  {
    return -1;
  }
  else
  {
    return 1;
  }
}


//BUSCAR CLIENTE
//antes int buscar_cliente(int quant, Cliente clientes[quant], char* cpf)
int buscar_cliente(Cliente clientes[], int quant,  char cpf[13])
// o cpf não é um ponteiro. visto que ele recebe um valor que foi digitado pelo usuário e não um endereço de memória. troquei a ordem dos argumentos e a forma de declarar o vetor clientes.
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
//antes int buscar_login(int quant, Cliente clientes[quant], char* login)
int buscar_login(Cliente clientes[], int quant, char login[30])
// o login não é um ponteiro. visto que ele recebe um valor que foi digitado pelo usuário e não um endereço de memória. // invertir a ordem dos argumentos para a função funcionar e tirei a variável de dentro do indice do vetor clientes
{
  int cont;
  for(cont=0; cont<quant; cont++)
  {
    printf("login - %s\n", login);
    printf("clientes[cont].login_password.login - %s\n", clientes[cont].login_password.login);
    if(strcmp(login, clientes[cont].login_password.login)==0)
    {
      //antes return 1; 
      return cont;
    }
    //antes return -1; 
  }
  return -1; // retirei esse return -1 do local original uma vez que no cadastro do 1° cliente essa função não entra no laço for. e se os dois return estiverem no laço for a função não irá retornar nem 1 nem -1.
}

//CADASTRO CLIENTE
//antes int cadastro_cliente(int num, Cliente clientes[num], int indice_cliente)
void cadastro_cliente( Cliente clientes[], int num, int* indice_cliente)
// no lugar do int coloquei o void uma vez que a função de cadastrar cliente não tem porquê retornar 1 ou -1. Esse número de retorno da função de cadastro de cliente não será utilizado para nada.
//o indice_cliente é a variável criada no main que controla a posição onde será inserido o novo cliente, dessa forma, a função cadastro de cliente precisa do endereço de memória do indice_cliente para, assim que o próximo cliente for cadastrado, a variável indice_cliente no main ser incrementada em 1, assim, indice cliente coloquei como ponteiro
//troquei a ordem dos argumentos e a forma de declarar o vetor clientes.

{
  int tam, resp, resp2, fim = 0, resp3;
  char cpf[13], login[30];

        //DADOS PESSOAIS
  //CPF 
  printf("Digite o seu CPF:\n");
  fgets(cpf, 13, stdin);
  tam = strlen(cpf);
  cpf[tam-1] = '\0';
  //limpar_buffer();
  resp = buscar_cliente(clientes, num, cpf);
  
  
  if(resp == -1)
  {
    while(1) //adicionei esse laço para garantir que o cliente digite uma opção válida
    {
      printf("\n\tDeseja se cadastrar?\n1-Sim\n2-Nao\n");
      scanf("%i", &resp3);
      getchar();
      if(resp3==1 || resp3==2 )
      {
        break;
      }
      else
      {
        printf("Opção inválida\n");
      }
    }
    if(resp3 == 1)
    { 
      // aonde aparecia a variável indice_cliente, coloquei o conteudo de indice_cliente, visto que indice_cliente é um ponteiro
      strcpy(clientes[*indice_cliente].dados.cpf, cpf);
      printf("\n\tDados pessoais:\n\n");
      //NOME 
      printf("Digite o seu nome:\n");
      fgets(clientes[*indice_cliente].dados.nome, 50, stdin);
      tam = strlen(clientes[*indice_cliente].dados.nome);
      clientes[*indice_cliente].dados.nome[tam-1] = '\0';
      //limpar_buffer();

      //IDADE
      printf("Digite a sua idade:\n");
      scanf("%i", &clientes[*indice_cliente].dados.idade);
      getchar();

              //ENDERECO 
      printf("\tEndereco:\n\n");
      //RUA
      printf("Digite o nome da rua:\n");
      fgets(clientes[*indice_cliente].endereco.rua, 100, stdin);
      tam = strlen(clientes[*indice_cliente].endereco.rua);
      clientes[*indice_cliente].endereco.rua[tam-1] = '\0';
      //limpar_buffer();

      //NUMERO 
      printf("Digite o numero da sua casa:\n");
      scanf("%i", &clientes[*indice_cliente].endereco.numero);
      getchar();

      //COMPLEMENTO 
      printf("Digite o complemento:\n");
      fgets(clientes[*indice_cliente].endereco.complemento, 100, stdin);
      tam = strlen(clientes[*indice_cliente].endereco.complemento);
      clientes[*indice_cliente].endereco.complemento[tam-1] = '\0';
      //limpar_buffer();

      //BAIRRO 
      printf("Digite o bairro:\n");
      fgets(clientes[*indice_cliente].endereco.bairro, 30, stdin);
      tam = strlen(clientes[*indice_cliente].endereco.bairro);
      clientes[*indice_cliente].endereco.bairro[tam-1] = '\0';
      //limpar_buffer();

      //CEP 
      printf("Digite o seu CEP:\n");
      fgets(clientes[*indice_cliente].endereco.cep, 10, stdin);
      tam = strlen(clientes[*indice_cliente].endereco.cep);
      clientes[*indice_cliente].endereco.cep[tam-1] = '\0';
      //limpar_buffer();

      //CIDADE 
      printf("Digite a sua cidade:\n");
      fgets(clientes[*indice_cliente].endereco.cidade, 30, stdin);
      tam = strlen(clientes[*indice_cliente].endereco.cidade);
      clientes[*indice_cliente].endereco.cidade[tam-1] = '\0';
      //limpar_buffer();

      //ESTADO 
      printf("Digite a sigla do seu estado:\n");
      fgets(clientes[*indice_cliente].endereco.estado, 3, stdin);
      tam = strlen(clientes[*indice_cliente].endereco.estado);
      clientes[*indice_cliente].endereco.estado[tam-1] = '\0';
      //limpar_buffer();

      

            //CONTA
      printf("\tConta:\n\n");
      //LOGIN 
      while(fim!=1)
      {
        //getchar() //no programa aparece o nome conta e quando eu digito qualquer coisa, aparece duas mensagens em seguida: "Digite seu Login" e, mesmo sem digitar nada, "Login disponível"
        printf("Digite o seu login:\n");
        fgets(login, 30, stdin);
        tam = strlen(login);
        login[tam-1] = '\0';
        //limpar_buffer();
        resp2 = buscar_login(clientes, num, login);
        if(resp2 == -1) // a função login não estave funcionando porque dentro desse if estava resp == -1 ao invés de resp2 == -1
        {
          printf("Login disponivel\n");
          strcpy(clientes[*indice_cliente].login_password.login, login);
          fim = 1;
        }
        else
        {
          printf("Login nao disponivel\nTente novamente\n");
        }
      } // tava faltando essa chaves no laço

      //SENHA
      while(fim!=0)
      {
        printf("Escolha uma senha para sua conta:\n");
        fgets(clientes[*indice_cliente].login_password.password, 9, stdin);
        tam = strlen(clientes[*indice_cliente].login_password.password);
        clientes[*indice_cliente].login_password.password[tam-1] = '\0';
        //limpar_buffer();
        fim = 0;

        //STATUS
        //antes clientes[*indice_cliente].dados.status = 5;
        clientes[*indice_cliente].dados.status = 1;// conforme documentação

        

        
        //antes return 1; como o retorno é void, não tem return
      }

      // retirei um chave em excesso que estava aqui
    //ADICIONEI 
    clientes[*indice_cliente].compras_realizadas = 0;
    //esse atributo controlará a promoção estabelecida pela nossa empresa.
    (*indice_cliente)++;
    // após o cadastro do cliente, é necessário incrementar essa variável no main para que o próximo cliente cadastrado não seja sobreescrito.
    }
    
  }
  else
  {
    printf("CPF ja cadastrado\n");
    // antes return -1; como o retorno é void, não tem return
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
  //limpar_buffer();
  resp = buscar_cliente(clientes, quant,  cpf);//inverti os argumentos
  if(resp !=-1)
  {
    int resp2;
    
    while(1)// adicionei esse laço para forçar a seleção da opção correta
    {
      printf("Cliente achado\nDeseja remover cliente?\n1-sim  2-nao\n");
      scanf("%i", &resp2);
      getchar();
    if(resp2==1 || resp2==2 )
      {
        break;
      }
      else
      {
        printf("Opção inválida\n");
      }
    }
    if(resp2==1)
    {
      //antes if(clientes[resp].dados.status == 5)
      if(clientes[resp].dados.status == 1)
      {
        clientes[resp].dados.status = 6; // na documentação não há status para cliente removido, dessa forma, deixei como estava, status 6 é funcionário removido
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
  int check = buscar_login(clientes, quant, login); // invertir a ordem dos argumentos para a função funcionar
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
