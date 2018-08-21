#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
#include "structs.h"

void readAdmins(char* path, Admin* admins, int tam){
    FILE* archive = fopen(path, "r");
    fread(admins, sizeof(Admin), tam, archive);
    fclose(archive);
}

//

void saveAdmins(char* path, Admin* admins, int tam){
  FILE* archive = fopen(path, "w");
  fwrite(admins, sizeof(Admin), tam, archive);
  fclose(archive);
}

//

void readClientes(char* path, Cliente* clientes, int tam){
    FILE* archive = fopen(path, "r");
    fread(clientes, sizeof(Cliente), tam, archive);
    fclose(archive);
}

//

void saveClientes(char* path, Cliente* clientes, int tam){
  FILE* archive = fopen(path, "w");
  fwrite(clientes, sizeof(Cliente), tam, archive);
  fclose(archive);
}

//

void show_clients(int ind_tclientes, Cliente clientes[]){
  readClientes("clientsDB.txt", clientes, ind_tclientes);

  int i;
  for(i=0; i < ind_tclientes;){
    printf("Nome: %s\n", clientes[i].dados.nome);
    printf("Idade: %i\n", clientes[i].dados.idade);
    printf("Status: %i\n", clientes[i].dados.status);
    printf("CPF: %i\n", clientes[i].dados.cpf);
    printf("Endereço:\nRua: %s\nNº: %i\tCEP: %s\tEstado: %s\tCidade: %s\tBairro: %s\nComplemento: %s", clientes[i].endereco.rua, clientes[i].endereco.numero, clientes[i].endereco.cep, clientes[i].endereco.estado, clientes[i].endereco.cidade, clientes[i].endereco.bairro, clientes[i].endereco.complemento);
    printf("Login: %s\n", clientes[i].login_password.login);
    printf("Compras realizadas: %i\n", clientes[i].compras_realizadas);
    i++;
    if(i%10 == 0 && i !=0){
      printf("Pressione alguma tecla para avançar para a próxima página...");
      _getch();
      system("cls");
    }
  }
}

//

void show_admins(int ind_tadmins, Admin admins[]){
  readAdmins("adminsDB.txt", admins, ind_tadmins);

  int i;
  for(i=0; i < ind_tadmins;){
    printf("Nome: %s\n", admins[i].dados.nome);
    printf("Idade: %i\n", admins[i].dados.idade);
    printf("Status: %i\n", admins[i].dados.status);
    printf("CPF: %i\n", admins[i].dados.cpf);
    printf("Login: %s\n", admins[i].login_password.login);
    i++;
    if(i%10 == 0 && i !=0){
      printf("Pressione alguma tecla para avançar para a próxima página...");
      _getch();
      system("cls");
    }
  }
}

//

int client_search(int ind_tclientes, Cliente clientes[])
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

//

int admin_search(int ind_admins, Admin admins[], char cpf[13]){
  int i;
  for(i=0; i<ind_admins; i++)
  {
    if(strcmp(admins[i].dados.cpf, cpf)== 0)
    {
      return i;
    }
  }
  return -1;
}

//

void AdminDisable(int ind_admins, Admin admins[]){
  int choice;
  char cpf[13];
  printf("Digite o CPF do Admin a ser desabilitado:\n");
  scanf("%s", cpf);
  int search = admin_search(ind_admins, admins, cpf);
  int flag = 0;

  do{
  if(search != -1){
    printf("Admin encontrado\n");
    printf("Nome: %s\nIdade: %i\nCPF: %s\nStatus: %i\n", admins[search].dados.nome, admins[search].dados.idade, admins[search].dados.cpf, admins[search].dados.status);
    printf("Deseja realmente desabilitar esse administrador?\n");
    printf("1 - Sim\n");
    printf("2 - Não\n");
    scanf("%i", &choice);
      if(choice == 1){
        if(admins[search].dados.status != 7){
        admins[search].dados.status = 7;
        flag = 1;
        }
        
        else{
          printf("Admin já desabilitado!\n");
          flag = 1;
        }
      }

      else if(choice == 2){
        printf("Operação cancelada\nAperte uma tecla para sair...");
        flag = 1;
        _getch();
        system("cls");
      }

      else{
        printf("Comando inválido... Tente novamente\n");
        _getch();
        system("cls");
      }
    }
    
    else{
      printf("Admin não encontrado!\n");
    }
  }while(flag == 0);
}

//

void AdminEnabled(int ind_admins, Admin admins[]){
  int choice;
  char cpf[13];
  printf("Digite o CPF do Admin a ser reabilitado:\n");
  scanf("%s", cpf);
  int search = admin_search(ind_admins, admins, cpf);
  int flag = 0;

  do{
  if(search != -1){
    printf("Admin encontrado\n");
    printf("Nome: %s\nIdade: %i\nCPF: %s\nStatus: %i\n", admins[search].dados.nome, admins[search].dados.idade, admins[search].dados.cpf, admins[search].dados.status);
    printf("Deseja realmente reabilitar esse administrador?\n");
    printf("1 - Sim\n");
    printf("2 - Não\n");
    scanf("%i", &choice);
      if(choice == 1){
        if(admins[search].dados.status != 4){
        admins[search].dados.status = 4;
        flag = 1;
        }
        
        else{
          printf("Admin já está disponivel!\n");
          flag = 1;
        }
      }

      else if(choice == 2){
        printf("Operação cancelada\nAperte uma tecla para sair...");
        flag = 1;
        _getch();
        system("cls");
      }

      else{
        printf("Comando inválido... Tente novamente\n");
        _getch();
        system("cls");
      }
      
}
    
    else{
      	printf("Admin não encontrado!\n");
      }
  }while(flag == 0);
}

//

void BlockClient(int ind_tclientes, Cliente clientes[]){
  int choice;
  int search = client_search(ind_tclientes, clientes);
  int flag = 0;

  do{
  if(search != -1){
    printf("Deseja realmente bloquear esse usuario?\n");
    printf("1 - Sim\n");
    printf("2 - Não\n");
    scanf("%i", &choice);
      if(choice == 1){
        if(clientes[search].dados.status != 3){
        clientes[search].dados.status = 3;
        flag = 1;
        }
        
        else{
          printf("Usuario já está bloqueado!\n");
          flag = 1;
      }
  	}

      else if(choice == 2){
        printf("Operação cancelada\nAperte uma tecla para sair...");
        flag = 1;
        _getch();
        system("cls");
      }

      else{
        printf("Comando inválido... Tente novamente\n");
        _getch();
        system("cls");
      }
    }
  }while(flag == 0);
}

//

void DisblockClient(int ind_tclientes, Cliente clientes[]){
  int choice;
  int search = client_search(ind_tclientes, clientes);
  int flag = 0;

  do{
  if(search != -1){
    printf("Deseja realmente desbloquear esse usuario?\n");
    printf("1 - Sim\n");
    printf("2 - Não\n");
    scanf("%i", &choice);
      if(choice == 1){
        if(clientes[search].dados.status != 1){
        clientes[search].dados.status = 1;
        flag = 1;
        printf("Usuário desbloqueado!\n");
        }
        
        else{
          printf("Usuario já esta disponível!\n");
          flag = 1;
        }
      }

      else if(choice == 2){
        printf("Operação cancelada\nAperte uma tecla para sair...");
        flag = 1;
        _getch();
        system("cls");
      }

      else{
        printf("Comando inválido... Tente novamente\n");
        _getch();
        system("cls");
      }
    }
  }while(flag == 0);
}

//

int loginadmin_search(int ind_admins, Admin admins[], char* login){
  int i;
  for(i = 0; i < ind_admins; i++){
    if(strcmp(login, admins[i].login_password.login)==0)
    {
      return 1;
    }
    return -1;
  }
}

//

void Add_Admin(int ind_admins, Admin admins[]){
  char c;
  int i=0;
  char cpf[13];
  char login[30];
  int end = 0;
  int endlp = 0;

   do{ 
    printf("Digite o CPF a ser cadastrado:\n");
    scanf("%s", cpf);

    int search = admin_search(ind_admins, admins, cpf);

    if(search == -1){
      strcpy(admins[ind_admins].dados.cpf, cpf);
      //
      printf("Digite o nome do novo Administrador:\n");
      fgets(admins[ind_admins].dados.nome, 50, stdin);
      int tam = strlen(admins[ind_admins].dados.nome);
      admins[ind_admins].dados.nome[tam-1]= '\0';
      //
      printf("Digite a idade do novo Administrador:\n");
      scanf("%i", admins[ind_admins].dados.idade);
      //
      admins[ind_admins].dados.status = 4;

      //LOGIN/PASSWORD
      do{
        printf("Digite o login do novo Administrador:\n");
        fgets(login, 30, stdin);
        int login_admsearch = loginadmin_search(ind_admins, admins, login);

        if(login_admsearch == -1){
          strcpy(admins[ind_admins].login_password.login, login);
          //
          printf("\nDigite a senha: ");
          do{
            c=getch();
            if(isprint(c)){
            admins[ind_admins].login_password.password[i]=c;
            i++;
            printf("*");
            }
            else if(c==8 && i){
            admins[ind_admins].login_password.password[i]='\0';
            i--;
            printf("\b \b");
            } 
        }while(c!=13);             
       admins[ind_admins].login_password.password[i]='\0';
       end = 1;
       endlp = 1;
       system("cls");  
       printf("\n\nCadastro efetuado com sucesso...\n\n");
        }

        else{
          if(login_admsearch != -1){
            printf("Login invalido, tente novamente...");
          }
        }

      }while(endlp == 0);
    }
    
    else{
        printf("CPF já cadastrado, tente novamente...\n");
    }
    
  }while(end == 0);
}

//
