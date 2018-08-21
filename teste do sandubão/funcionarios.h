#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
#include "structs.h"

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
      return 0;
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
  limpar_buffer();
  tam = strlen(cpf);
  cpf[tam-1] = '\0';
  resp = buscar_funcionario(num, funcionarios, cpf);
  if(resp==-1)
  {
    strcpy(funcionarios[indice_funcionario].dados.cpf, cpf);
    //NOME
    printf("Digite o nome do funcionario:\n");
    fgets(funcionarios[indice_funcionario].dados.nome, 50, stdin);
    limpar_buffer();
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

//ALTERAÇÕES PRA BUSCAR LOGIN, BUSCAR SENHA E A PARTE DE LOGIN, CONSIDERANDO OS ADMINS:

int buscar_login(int quant_clientes, int quant_admins, Cliente clientes[], Admin admins[], char login[])
{
  for(int cont=0; cont<quant_clientes; cont++)
  {
    if(strcmp(login, clientes[cont].login_password.login)==0)
    {
      return 1;
    }
  }

  for(int cont=0; cont<quant_admins; cont++)
  {
    if(strcmp(login, admins[cont].login_password.login)==0)
    {
      return 2;
    }
  }
  
  return -1;
}

int buscar_password(int quant_clientes, int quant_admins, int* posicao, Cliente clientes[], Admin admins[], char password[], char login[])
{
  int check = buscar_login(quant_clientes, quant_admins, clientes, admins, login);

  if(check == 1)
  {
    for(int cont = 0; cont < quant_clientes; cont++)
    {
      if(strcmp(password, clientes[cont].login_password.password) == 0)
      {
        *posicao = cont;
        return 1;
      }
    }
    return -1;
  }
  if(check == 2)
  {
    for(int cont = 0; cont < quant_admins; cont++)
    {
      if(strcmp(password, admins[cont].login_password.password) == 0)
      {
        *posicao = cont;
        return 2;
      }
    }
    return -1;
  }
  else
  {
    return -1;
  }
}

int login_function(int quant_clientes, int quant_admins, int* posicao, Cliente clientes[], Admin admins[])
{
  char login[30], password[9];
  int tam;

  printf("\nDigite o seu Nome de Usuário:\n\n");
  fgets(login, 30, stdin);
  tam = strlen(login);
  login[tam-1] = '\0';
  
  printf("\nDigite a sua Senha:\n\n");
  fgets(password, 9, stdin);
  tam = strlen(password);
  password[tam-1] = '\0';

  int check = buscar_password(quant_clientes, quant_admins, posicao, clientes, admins, password, login);

  if(check == 1)
  {
  	if(clientes[*posicao].dados.status == 1){
    	return 1; //Login e Senha corretos (CLIENTE)
    }
    
    else if(clientes[*posicao].dados.status == 0){
    	return 0;
	}
	
	else if(clientes[*posicao].dados.status == 3){
		return 3;
	}
  }
  else if(check == 2)
  {
    if(admins[*posicao].dados.status == 2)
    {
      return 2; //Login e Senha corretos (MASTER ADMIN)
    }
    else if(admins[*posicao].dados.status == 4)
    {
      return 4; //Login e Senha corretos (ADMIN)
    }
    
    else if(admins[*posicao].dados.status == 7){
    	return 7;
	}
  }
  else
  {
    return -1; //Dados incorretos
  }
}
