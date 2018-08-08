#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


typedef struct{
	char nome[50];
	int idade;
	char cpf[13];
	int status;
}Pessoa;

typedef struct{
	char rua[100];
	int numero;
	char complemento[100];
	char bairro[30];
	char cep[10];
	char cidade[30];
	char estado[3];
}Endereco;

typedef struct{
	char login[30];
	char password[9];
}Login_password;

typedef struct{
	int id;
	char nome[30];
	int tipo; 
	float valorc;
	float valorv;
	int qtd;
	int comprados;
	int vendidos;
}Produto;

typedef struct{
	int tamanhopao;
	Produto recheio;
	Produto	molho;
	Produto	pao;
}Sanduiche;

typedef struct{
	Pessoa dados;
	Endereco endereco;
	Login_password login_password;
	int compras_realizadas;
	//Payment pagamento;
}Cliente;

typedef struct{
	Pessoa dados;
	int id_cargo;
}Funcionario;

typedef struct{
	Pessoa pessoa;
	Endereco endereco;
	Cliente cliente;
	Funcionario funcionario;
	Sanduiche sanduiche;
	Produto produto;
	Login_password login_password;
}Sistema;




/*int id;
	char nome[30];
	int tipo; 
	float valorc;
	float valorv;
	int qtd;
	int comprados;
	int vendidos;
*/


int buscarProduto (Produto produto[], int tam, int ultimaposicao, char nome[30])
{
  //produto é um vetor com todos os produtos já cadastrados, ultimaposicao é a ultimaposicao disponível para o cadastro, nome é o nome digitados pelo usuário que vai ser realizada a busca, esse nome é um atributo da estrutura.
  for (int i=0; i < ultimaposicao ; i++)
  {
    /*printf("%s, %s\n", produto[i].nome, nome);
    printf("%i\n", produto[i].id);
    printf("%i %i\n", strlen(nome), strlen(produto[i].nome));*/

    if(strcmp(nome, produto[i].nome)==0)
    {
      return produto[i].id;
    }
    else
    {
      return -1;
    }
  }
}


void cadastroProduto(Produto testep, Produto produto[], int tam, int* pultimaposicao)
{
  // testep é a estrutura digitada pelo usuário, é o vetor com todos os produtos já cadastrados, pultimaposicao é um apontador para alterar a ultimaposição que mostra a posicao disponível para cadastro.
  int posicao = buscarProduto ( produto, tam, *pultimaposicao,  testep.nome);
  if(posicao==0)
  {
    Produto* pproduto = &produto[*pultimaposicao];
    *pproduto = testep;
    (*pultimaposicao)++;

  }
  else
  {
    printf("Produto já cadastrado\n");
  }

}



void imprimirProduto(Produto produto)
{
  printf(" Id - %i\n", produto.id);
  printf(" Nome - %s\n", produto.nome);
  printf(" Tipo - %s\n", produto.tipo);
  printf(" Valor de compra - %.1f\n", produto.valorc);
  printf(" Valor de venda - %.1f\n", produto.valorv);
  printf(" Qte comprados - %i\n", produto.comprados);
  printf(" Qte vendidos - %i\n", produto.vendidos);
}

void main()
{
  Produto produto[100];// o administrador pode cadastrar tem q da liberdadde para o adm cadastrar os produtos
  Produto testeproduto;//produto que o usuário vai digitar e passarará pelas verificações das funções.
  int ultimaposicao = 0 , menu; // última posição é a posição no vetor produto disponível para cadastro  , e MENU se refere as opções que o usuário possui manipular os produtos
  do
  {
    do // o usuário só sai desse laço se digitar o menu correto
    {
    printf("Pressione 1-buscar produto, 2-cadastrar produto, 3- remover, 4-sair do programa.\n");
    scanf("%i", &menu);
    getchar();
    }while(menu <1 || menu > 4);

    if(menu==1)
    {
      printf("Digite o nome do produto:\n");
      scanf("%s",&testeproduto.nome);

      testeproduto.id = buscarProduto ( produto, 100, ultimaposicao,  testeproduto.nome);

      if (testeproduto.id != -1)
      {
        imprimirProduto(produto[testeproduto.id]);
      }
      else
      {
        printf("Produto não cadastrado.\n");
      }
    }
    else if(menu==2)
    {
      testeproduto.id = ultimaposicao;
      testeproduto.comprados = 0;
      testeproduto.vendidos = 0;

      printf("Digite o nome do produto:\n");
      scanf("%s",&testeproduto.nome);

      

      printf("Digite o tipo do produto:\n");
      scanf("%s",&testeproduto.tipo);

      printf("Digite o valor de compra do produto:\n");
      scanf("%f",&testeproduto.valorc);

      printf("Digite o valor de venda do produto:\n");
      scanf("%f",&testeproduto.valorv);

      cadastroProduto (testeproduto, produto, 100, &ultimaposicao);
      
      


      
    }
  }while(menu!=4);
  

  
}

/*typedef struct
{
  char nome[30];
  char cpf[10];
  int status;
}Cliente;

int inserir(Cliente c, Cliente* clientes, int* posicao)
{
  int existe = busca(c.cpf, clientes, *posicao);

  if(existe == -1)
  {
    clientes[*posicao] = c;
    (*posicao)++;

    return 1;
  }
  else
  {
    return 0;
  }
}

int remover(char* cpf, Cliente* clientes, int posicao)
{
  int existe = busca(cpf, clientes, posicao);

  if(existe != -1)
  {
    clientes[existe].status = 0;
    return 1;
  }
  else
  {
    return 0;
  }
}

int buscar(char* cpf, Cliente* clientes, int posicao)
{
  for(int i = 0; i < posicao; i++)
  {
    if(strcmp(clientes[i].cpf, cpf) == 0)
    {
      return i;
    }
  }

  return -1;
}



void main(void) 
{
  do
  {
  Cliente clientes[5];

  int posicao = 0, menu = 0;
  Cliente c;

  
  
  printf("Digite 1-Inserir, 2- buscar, 3-remover, 4-Sair do programa\n");
  scanf("%i", &menu);

  if (menu==1)
  {
    
    printf("Digite o nome do cliente que deseja inserir:\n");
    scanf("%s", c.nome);
    getchar();

    printf("Digite o cpf do cliente que deseja inserir:\n");
    scanf("%s", c.cpf);
    getchar();
    c.status= 1;
    inserir(c, clientes, &posicao);
  }

  else if(menu==2)
  {
    printf("Digite o cpf do cliente que deseja buscar:\n");
    scanf("%s", c.cpf);
    getchar();
    buscar(char* cpf, Cliente* clientes, int posicao)
  }
  

  }while (fim==0);
  
}
*/
