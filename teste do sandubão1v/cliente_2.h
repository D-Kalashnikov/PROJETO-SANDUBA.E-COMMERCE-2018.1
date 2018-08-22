#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
#include "structs.h"



/*//LIMPAR BUFFER deixa ela aqui! qualquer coisa tem ela
void limpar_buffer() // deixei essa função sem ser utilizada no código visto que toda vez q ela era executada o cliente tinha que dar dois enter para avançar na sua seleção de opções.
{
  char c;
  while(c !='\n')
  {
    c = getchar();
  }
}*/

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
int buscar_cliente(Cliente clientes[], int quant,  char cpf[13]){
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
int buscar_login_cliente(Cliente clientes[], int quant, char login[30])
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
  return -1; 
}

//CADASTRO CLIENTE
void cadastro_cliente( Cliente clientes[], int num, int* indice_cliente)
{
  int tam, resp, resp2, fim = 0, resp3, vazio;
  char cpf[13], login[30];

        //DADOS PESSOAIS
  //CPF 
  while(1)
  {
    printf("Digite o seu CPF:\n");
    fgets(cpf, 13, stdin);
    tam = strlen(cpf);
    cpf[tam-1] = '\0';
    fflush(stdin);
    vazio = buscar_vazio(tam, cpf);
    if(vazio != 1)
    {
      break;
    }
    else
    {
      printf("Opção inválida.\nTente novamente.\n");
    }
  }
  resp = buscar_cliente(clientes, num, cpf);
  if(resp == -1)
  {
    while(1)
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
        printf("Opção inválida.\n");
      }
    }
    if(resp3 == 1)
    { 
      strcpy(clientes[*indice_cliente].dados.cpf, cpf);
      printf("\n\tDados pessoais:\n\n");
      //NOME 
      while(1)
      {
        printf("Digite o seu nome:\n");
        fgets(clientes[*indice_cliente].dados.nome, 50, stdin);
        tam = strlen(clientes[*indice_cliente].dados.nome);
        clientes[*indice_cliente].dados.nome[tam-1] = '\0';
        fflush(stdin);
        vazio = buscar_vazio(tam, clientes[*indice_cliente].dados.nome);
        if(vazio != 1)
        {
          break;
        }
        else
        {
          printf("Opção inválida.\nTente novamente.\n");
        }
      }

      //IDADE
      printf("Digite a sua idade:\n");
      scanf("%i", &clientes[*indice_cliente].dados.idade);
      getchar();

              //ENDERECO 
      printf("\tEndereco:\n\n");
      //RUA
      while(1)
      {
        printf("Digite o nome da rua:\n");
        fgets(clientes[*indice_cliente].endereco.rua, 100, stdin);
        tam = strlen(clientes[*indice_cliente].endereco.rua);
        clientes[*indice_cliente].endereco.rua[tam-1] = '\0';
        fflush(stdin);
        vazio = buscar_vazio(tam, clientes[*indice_cliente].endereco.rua);
        if(vazio != 1)
        {
          break;
        }
        else
        {
          printf("Opção inválida.\nTente novamente.\n");
        }
      }

      //NUMERO 
      printf("Digite o numero da sua casa:\n");
      scanf("%i", &clientes[*indice_cliente].endereco.numero);
      getchar();

      //COMPLEMENTO 
      while(1)
      {
        printf("Digite o complemento:\n");
        fgets(clientes[*indice_cliente].endereco.complemento, 100, stdin);
        tam = strlen(clientes[*indice_cliente].endereco.complemento);
        clientes[*indice_cliente].endereco.complemento[tam-1] = '\0';
        fflush(stdin);
        vazio = buscar_vazio(tam, clientes[*indice_cliente].endereco.complemento);
        if(vazio != 1)
        {
          break;
        }
        else
        {
          printf("Opção inválida.\nTente novamente.\n");
        }
      }

      //BAIRRO 
      while(1)
      {
         printf("Digite o bairro:\n");
        fgets(clientes[*indice_cliente].endereco.bairro, 30, stdin);
        tam = strlen(clientes[*indice_cliente].endereco.bairro);
        clientes[*indice_cliente].endereco.bairro[tam-1] = '\0';
        fflush(stdin);
        vazio = buscar_vazio(tam, clientes[*indice_cliente].endereco.bairro);
        if(vazio != 1)
        {
          break;
        }
        else
        {
          printf("Opção inválida.\nTente novamente.\n");
        }
      }
  
      //CEP 
      while(1)
      {
        printf("Digite o seu CEP:\n");
        fgets(clientes[*indice_cliente].endereco.cep, 10, stdin);
        tam = strlen(clientes[*indice_cliente].endereco.cep);
        clientes[*indice_cliente].endereco.cep[tam-1] = '\0';
        fflush(stdin);
        vazio = buscar_vazio(tam, clientes[*indice_cliente].endereco.cep);
        if(vazio != 1)
        {
          break;
        }
        else
        {
          printf("Opção inválida.\nTente novamente.\n");
        }
      }
      

      //CIDADE 
      while(1)
      {
        printf("Digite a sua Cidade:\n");
        fgets(clientes[*indice_cliente].endereco.cidade, 30, stdin);
        tam = strlen(clientes[*indice_cliente].endereco.cidade);
        clientes[*indice_cliente].endereco.cidade[tam-1] = '\0';
        fflush(stdin);
        vazio = buscar_vazio(tam, clientes[*indice_cliente].endereco.cidade);
        if(vazio != 1)
        {
          break;
        }
        else
        {
          printf("Opção inválida.\nTente novamente.\n");
        }
      }

      //ESTADO 
      while(1)
      {
        printf("Digite a sigla do seu Estado:\n");
        fgets(clientes[*indice_cliente].endereco.estado, 3, stdin);
        tam = strlen(clientes[*indice_cliente].endereco.estado);
        clientes[*indice_cliente].endereco.estado[tam-1] = '\0';
        fflush(stdin);
        vazio = buscar_vazio(tam, clientes[*indice_cliente].endereco.estado);
        if(vazio != 1)
        {
          break;
        }
        else
        {
          printf("Opção inválida.\nTente novamente.\n");
        }
      }
  
            //CONTA
      printf("\tConta:\n\n");
      //LOGIN 
      while(fim!=1)
      {
        while(1)
        {
          getchar();
          printf("Digite o seu login:\n");
          fgets(login, 30, stdin);
          tam = strlen(login);
          login[tam-1] = '\0';
          fflush(stdin);
          vazio = buscar_vazio(tam, login);
          if(vazio != 1)
          {
            break;
          }
          else
          {
            printf("Opção inválida.\nTente novamente.\n");
          }
        }
        resp2 = buscar_login_cliente(clientes, num, login);
        if(resp2 == -1)
        {
          printf("Login disponível.\n");
          strcpy(clientes[*indice_cliente].login_password.login, login);
          fim = 1;
        }
        else
        {
          printf("Login não disponível.\nTente novamente.\n");
        }
      }

      //SENHA
      while(1)
      {
      	int i=0;
        char c;
        printf("Escolha uma senha para sua conta:\n");
        do{
            c=getch();
            if(isprint(c)){
            clientes[*indice_cliente].login_password.password[i]=c;
            i++;
            printf("*");
            }
            else if(c==8 && i){
            clientes[*indice_cliente].login_password.password[i]='\0';
            i--;
            printf("\b \b");
            } 
        }while(c!=13);
        fflush(stdin);
        vazio = buscar_vazio(tam, clientes[*indice_cliente].login_password.password);
          if(vazio != 1)
          {
            break;
          }
          else
          {
            printf("Opção inválida.\nTente novamente.\n");
          }
      }
        //STATUS
        clientes[*indice_cliente].dados.status = 1;

    clientes[*indice_cliente].compras_realizadas = 0;
    (*indice_cliente)++;
    }
    
  }
  else
  {
    printf("CPF ja cadastrado\n");
  }
}

//REMOVER CLIENTE 
/*int remover_cliente(int quant, Cliente clientes[])
{
  int resp, tam;
  char cpf[13];
  printf("Digite o CPF:");
  fgets(cpf, 13, stdin);
  tam = strlen(cpf);
  cpf[tam-1] = '\0';
  fflush(stdin);
  resp = buscar_cliente(clientes, quant,  cpf);
  if(resp !=-1)
  {
    int resp2;
    
    while(1)
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
      if(clientes[resp].dados.status == 1)
      {
        clientes[resp].dados.status = 0;
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
}*/
//DESATIVAR CLIENTE
void desativar_cliente(Cliente clientes[], int posicao)
{
      clientes[posicao].dados.status = 0;
      printf("Voce foi desativado\n");
}

//REATIVAR CLIENTE
void reativar_cliente(Cliente clientes[], int posicao)
{
      clientes[posicao].dados.status = 1;
      printf("Voce foi reativado\n");
}

//MUDANCA DE DADOS CLIENTE
void mudanca_cliente(int cont, int num, Cliente clientes[])
{
  int resp = 12;
  int tam, vazio, fim, resp2;
  while(resp!=0)
  {
     printf("Mudanca de dados:\nDseja mudar quais dados?\n0-Sair\n1-Nome\n2-Idade\n3-Rua\n4-Numero\n5-Complemento\n6-Bairro\n7-CEP\n8-Cidade\n9-Estado\n10-Login\n11-Senha\n");
  scanf("%i", &resp);
      //NOME 
      if(resp == 1)
      {
        while(1)
      {
        printf("Digite o seu nome:\n");
        fgets(clientes[cont].dados.nome, 50, stdin);
        tam = strlen(clientes[cont].dados.nome);
        clientes[cont].dados.nome[tam-1] = '\0';
        fflush(stdin);
        vazio = buscar_vazio(tam, clientes[cont].dados.nome);
        if(vazio != 1)
        {
          break;
        }
        else
        {
          printf("Opção inválida.\nTente novamente.\n");
        }
      }
      }
      else if(resp == 2)
      {
        //IDADE
      printf("Digite a sua idade:\n");
      scanf("%i", &clientes[cont].dados.idade);
      getchar();
      }
      else if(resp == 3)
      {
        //RUA
      while(1)
      {
        printf("Digite o nome da rua:\n");
        fgets(clientes[cont].endereco.rua, 100, stdin);
        tam = strlen(clientes[cont].endereco.rua);
        clientes[cont].endereco.rua[tam-1] = '\0';
        fflush(stdin);
        vazio = buscar_vazio(tam, clientes[cont].endereco.rua);
        if(vazio != 1)
        {
          break;
        }
        else
        {
          printf("Opção inválida.\nTente novamente.\n");
        }
      }
      }
      else if(resp == 4)
      {
         //NUMERO 
      printf("Digite o numero da sua casa:\n");
      scanf("%i", &clientes[cont].endereco.numero);
      getchar();
      }
      else if(resp == 5)
      {
        //COMPLEMENTO 
      while(1)
      {
        printf("Digite o complemento:\n");
        fgets(clientes[cont].endereco.complemento, 100, stdin);
        tam = strlen(clientes[cont].endereco.complemento);
        clientes[cont].endereco.complemento[tam-1] = '\0';
        fflush(stdin);
        vazio = buscar_vazio(tam, clientes[cont].endereco.complemento);
        if(vazio != 1)
        {
          break;
        }
        else
        {
          printf("Opção inválida.\nTente novamente.\n");
        }
      }
      }
      else if(resp == 6)
      {
        //BAIRRO 
      while(1)
      {
         printf("Digite o bairro:\n");
        fgets(clientes[cont].endereco.bairro, 30, stdin);
        tam = strlen(clientes[cont].endereco.bairro);
        clientes[cont].endereco.bairro[tam-1] = '\0';
        fflush(stdin);
        vazio = buscar_vazio(tam, clientes[cont].endereco.bairro);
        if(vazio != 1)
        {
          break;
        }
        else
        {
          printf("Opção inválida.\nTente novamente.\n");
        }
      }
      }
      else if(resp == 7)
      {
        //CEP 
      while(1)
      {
        printf("Digite o seu CEP:\n");
        fgets(clientes[cont].endereco.cep, 10, stdin);
        tam = strlen(clientes[cont].endereco.cep);
        clientes[cont].endereco.cep[tam-1] = '\0';
        fflush(stdin);
        vazio = buscar_vazio(tam, clientes[cont].endereco.cep);
        if(vazio != 1)
        {
          break;
        }
        else
        {
          printf("Opção inválida.\nTente novamente.\n");
        }
      }
      }
      else if(resp == 8)
      {
        //CIDADE 
      while(1)
      {
        printf("Digite a sua cidade:\n");
        fgets(clientes[cont].endereco.cidade, 30, stdin);
        tam = strlen(clientes[cont].endereco.cidade);
        clientes[cont].endereco.cidade[tam-1] = '\0';
        fflush(stdin);
        vazio = buscar_vazio(tam, clientes[cont].endereco.cidade);
        if(vazio != 1)
        {
          break;
        }
        else
        {
          printf("Opção inválida.\nTente novamente.\n");
        }
      }
      }
      else if(resp == 9)
      {
        //ESTADO 
      while(1)
      {
        printf("Digite a sigla do seu estado:\n");
        fgets(clientes[cont].endereco.estado, 3, stdin);
        tam = strlen(clientes[cont].endereco.estado);
        clientes[cont].endereco.estado[tam-1] = '\0';
        fflush(stdin);
        vazio = buscar_vazio(tam, clientes[cont].endereco.estado);
        if(vazio != 1)
        {
          break;
        }
        else
        {
          printf("Opção inválida.\nTente novamente.\n");
        }
      }
      }
      else if(resp == 10)
      {
        //LOGIN 
      while(fim!=1)
      {
        char login[13];
        while(1)
        {
          printf("Digite o seu login:\n");
          fgets(login, 30, stdin);
          tam = strlen(login);
          login[tam-1] = '\0';
          fflush(stdin);
          vazio = buscar_vazio(tam, login);
          if(vazio != 1)
          {
            break;
          }
          else
          {
            printf("Opção inválida.\nTente novamente.\n");
          }
        }
        resp2 = buscar_login_cliente(clientes, num, login);
        if(resp2 == -1)
        {
          printf("Login disponivel\n");
          strcpy(clientes[cont].login_password.login, login);
          fim = 1;
        }
        else
        {
          printf("Login nao disponivel.\nTente novamente.\n");
        }
      }
      }
      else if(resp == 11)
      {
              //SENHA
      while(1)
      {
      	int i=0;
        char c;
        printf("Escolha uma senha para sua conta:\n");
        do{
            c=getch();
            if(isprint(c)){
            clientes[cont].login_password.password[i]=c;
            i++;
            printf("*");
            }
            else if(c==8 && i){
            clientes[cont].login_password.password[i]='\0';
            i--;
            printf("\b \b");
            } 
        }while(c!=13);
        fflush(stdin);
        vazio = buscar_vazio(tam, clientes[cont].login_password.password);
          if(vazio != 1)
          {
            break;
          }
          else
          {
            printf("Opção inválida.\nTente novamente.\n");
          }
      	}
      }
      
      else if(resp == 0)
      {
        printf("Mudanca concluida.\n");
        break;
      }
      else
      {
        printf("Opção inválida.\nTente novamente.\n");
      }

}
  }
 

/*//BUSCAR SENHA 
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
  int check = buscar_login_cliente(clientes, quant, login); // invertir a ordem dos argumentos para a função funcionar
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
} */
