typedef struct{
	int id; // número de identificação do produto, coincide com a sequência que foram cadastrados
	char nome[30]; 
	int tipo; // 0-pão, 1-recheio, 2-molho, 3-queijo, 4-salada
	float valorc; // valor unitário de compra
	float valorv; // valor unitário de venda
  float totalc; //ADICIONEI, valor total de compras
	float totalv; // ADICIONEI, valor total de vendas
	int qtd; // não sei para que serve?????
	int comprados; // quantidade de produtos comprados
	int vendidos; //quantidade de produtos vendidos

  // adicionei as várias totalc e totalv para serem utilizadas na impressão do resultado financeiro, elas devem ser alteradas quando for utilizada as funções compras e vendas de produtos.
}Produto;

int pesquisar_prod(Produto produto[], int qte_prod_cad,char nome[30])
{
  for(int i=0; i<qte_prod_cad; i++)
  {
    if (strcmp(produto[i].nome, nome)==0)
    {
    return i;
    }

  }
  return -1;
}

void alterar_prod(Produto produto[], int qte_prod_cad,char nome[30])
{
  int menu=0;

  int indice = pesquisar_prod(produto, qte_prod_cad, nome);
  if(indice!=-1)
  {
    do
    {
    printf("Siga as opções pora modificar: 1-valor de compra, 2-valor de venda, 3-valores de compra e venda, 4-desistir da alteração\n");
    scanf("%i", &menu);
    getchar();
    }while(menu<1 || menu>4);

    if(menu==1)
    {
      printf("Digite o novo valor da compra.\n");
      scanf("%f", &produto[indice].valorc);
      getchar();
    }
    else if (menu==2)
    {
      printf("Digite o novo valor da venda.\n");
      scanf("%f", &produto[indice].valorv);
      getchar();
    }
    else if(menu==3)
    {
      printf("Digite o novo valor da compra.\n");
      scanf("%f", &produto[indice].valorc);
      getchar();
    
      printf("Digite o novo valor da venda.\n");
      scanf("%f", &produto[indice].valorv);
      getchar();
    }
  }
  else
  {
    printf("Não foi possível a alteração. Produto não cadastrado!\n");
  } 
}

void cadastrar_prod(Produto produto[], int qte_prod_cad, int* pqte_prod_cad)
{
  char nome_teste[30];
  printf("Digite o nome do produto:\n");
  scanf("%s", nome_teste);
  getchar();

  int indice = pesquisar_prod(produto, qte_prod_cad, nome_teste);
  if(indice==-1)
  {
    produto[qte_prod_cad].id = qte_prod_cad;
    strcpy(produto[qte_prod_cad].nome, nome_teste);
    do
    {
    printf("Digite o tipo do produto: 0-pao, 1-recheio, 2-molho, 3-queijo, 4-salada\n");
    scanf("%i", &produto[qte_prod_cad].tipo);
    getchar();
    }while(produto[qte_prod_cad].tipo<0 || produto[qte_prod_cad].tipo>4);
    
    printf("Digite o valor da compra.\n");
    scanf("%f", &produto[qte_prod_cad].valorc);
    getchar();

    printf("Digite o valor da venda.\n");
    scanf("%f", &produto[qte_prod_cad].valorv);
    getchar();

    produto[qte_prod_cad].totalc = 0;
    produto[qte_prod_cad].totalv = 0;

    produto[qte_prod_cad].comprados = 0;
    produto[qte_prod_cad].vendidos = 0;
    
    (*pqte_prod_cad)++;
  }
  else
  {
    printf("Não foi possível realizar o cadastro. Produto já cadastrado!\n");
  }
}

void imprimir_prod(Produto produto[], int qte_prod_cad)
{
  for(int i=0; i < qte_prod_cad; i++)
  {
    printf("ID - %i\n", produto[i].id);
    printf("Nome - %s\n", produto[i].nome);
    printf("Valor unitário de Compra - %.2f\n", produto[i].valorc);
    printf("Valor unitário de Venda - %.2f\n", produto[i].valorv);
    printf("Total de Compras - %.2f\n", produto[i].totalc);
    printf("Valor de Vendas - %.2f\n", produto[i].totalv);
    printf("Quantidade Comprada - %i\n", produto[i].comprados);
    printf("Quantidade Vendida - %i\n", produto[i].vendidos);
    printf("\n\n");
  }
}
void main()
{
  Produto produto[100]; // vetor de produtos, cadastro de no máximo 99 produtos, vou estudar como deixar isso ilimitado
  char nome_teste[30]; // nome que o usuário digitará no main se quiser pesquisar ou alterar algum produto
  int qte_prod_cad = 0; //fornece o índice do vetor produto no qual o próximo produto será cadastrado, toda vez que um produto é cadastrado essa variável é incrementada em 1. E ela coincide com o atributo ID do vetor produto nesse índice
  int menu = 0; // guia o usuário a gerenciar um menu de opções
  int indice; // retorna o índicie de uma busca. Normalmente, indica a posição que um produto foi encontrado quando se chama a função pesquisar.
  
  do
  {
    printf("Para gerenciar os produtos, siga o menu: 1- Cadastro, 2-Pesquisa, 3-Alterar, 4-impressão, 5-sair\n");
    scanf("%i", &menu);
    getchar();

    if(menu==1)
    {
      cadastrar_prod(produto, qte_prod_cad, &qte_prod_cad);
    }
    else if(menu==2)
    {
      printf("Digite o nome do produto a ser pesquisado:\n");
      scanf("%s", nome_teste);
      getchar();

      indice = pesquisar_prod(produto, qte_prod_cad, nome_teste); // essa função retorna a posição - índice do vetor -  onde o produto esta cadastrado, se ele não tiver cadastrado, essa funçãor retorna -1.
      printf("%i\n", indice);
      if(indice!=-1)
      {
        
        printf("ID - %i\n", produto[indice].id);
        printf("Nome - %s\n", produto[indice].nome);
        printf("Valor unitário de Compra - %.2f\n", produto[indice].valorc);
        printf("Valor unitário de Venda - %.2f\n", produto[indice].valorv);
        printf("Total de Compras - %.2f\n", produto[indice].totalc);
        printf("Valor de Vendas - %.2f\n", produto[indice].totalv);
        printf("Quantidade Comprada - %i\n", produto[indice].comprados);
        printf("Quantidade Vendida - %i\n", produto[indice].vendidos);
      }
      else
      {
        printf("Produto não cadastrado.\n");
      }
      
      
    }
    else if(menu==3)
    { 
      printf("Digite o nome do produto a ser alterado:\n");
      scanf("%s", nome_teste);
      getchar();
      
      alterar_prod(produto, qte_prod_cad, nome_teste); // essa função permite o usuário alterar o 
    }
    else if(menu==4)
    {
      imprimir_prod(produto,qte_prod_cad); // essa função imprime uma listagem com todos os produtos cadastrados e seus atributos
    }
  }while(menu!=5);
}
