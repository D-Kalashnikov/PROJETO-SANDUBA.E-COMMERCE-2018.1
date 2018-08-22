#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
#include "allscreens.h"
#include "cliente_2.h"
#include "compra_sanduiche2.h"
#include "structs.h"
#include "funcionarios.h"
#include "recomendado.h"
#include "storage.h"
#include "manager.h"
#include "relatorio_financeiro.h"
#include "gerencia_produto.h"

#define esc 27
#define MAX_LEN 128

void main() {
	setlocale(LC_ALL, "Portuguese");
	char key;
	char select;
	char internal;
	int logon_status=1;
	Produto produtos[100];
  	Funcionario funcionarios[30];
	Cliente clientes[100];
  	Admin admins[20];
  	int qte_prod_cad = 0, indice_func = 0, indice_cliente = 0, indice_adm = 0;
  	float saldo_bancario = 10000, percentual_sal = 0.01, percentual_odesp = 0.001;
  	int posicao;
  	float somatorio = 0;
  	
  	/*
  	do{
  	
  }while(key != esc);*/
  	
  	
  	do{
  		LogoScreen();
  		key = _getch();
  		
  		if(key == '1'){
  			do{
			system("cls");
  			LoginScreen();
  			printf("\n\n");
  			logon_status = login_function(indice_cliente, indice_adm, posicao, clientes, admins);
  			if(logon_status == -1){
  				printf("Dados não encontrados!\n");
  				_getch();
  				system("cls");
			}
			  
			else if(logon_status == 1){
				do{
					system("cls");
					SandubaScreen();
					printf("\n\n");
					printf("1 - Realizar compras\n2 - Configurações da conta\nESC - Sair\n");
					select = _getch();
						if(select == '1'){
							CarrinhoScreen();
							printf("\n\n");
							somatorio = compra_sanduiche(produtos, qte_prod_cad, posicao, clientes, &saldo_bancario);
						}
						
						else if(select == '2'){
							ConfigScreen();
							printf("\n\n");
						}
						
						else if(select == esc){
							system("cls");
						}
						
						else{
							printf("Comando inválido... Tente novamente...\n");
						}
				}while(select != esc);
			}
			
			else if(logon_status == 0){
				do{
					system("cls");
					SandubaScreen();
					printf("\n\n");
					printf("Você desativou esta conta!\n");
					printf("Gostaria de reativar o acesso?\n\n1 - Sim\n2 - Não\nESC - Sair\n");
					select = _getch();
						if(select == '1'){
							
						}
						
						else if(select == '2'){
							system("cls");
						}
						
						else if(select == esc){
							system("cls");
						}
						
						else{
							printf("Comando inválido... Tente novamente...\n");
						}
				}while(select != esc);
			}
			
			else if(logon_status == 3){
				system("cls");
				printf("Conta com acesso bloqueado ao sistema, favor contatar o administrador do sistema.\n");
				_getch();
  				system("cls");
			}
			
			else if(logon_status == 2){
				do{
					system("cls");
					AdminScreen();
					printf("\n\n");
					printf("1 - Controle de Estoque\n2 - Relatório Financeiro\n3 - Dados cadastrais\nESC - Sair\n");
					select = _getch();
						if(select == '1'){
							StorageScreen();
							printf("\n\n");
							printf("1 - Visualizar Estoque\n2 - Visualizar quantidades\n3 - Visualizar produtos mais vendidos\n4 - Visualizar produtos mais comprados\n5 - Procurar produto\n")
							gerenciar_produto(produtos, qte_prod_cad, &qte_prod_cad, &saldo_bancario);
						}
						
						else if(select == '2'){
							FinanceiroScreen();
							printf("\n\n");
							calculo_e_impressao_rel_fin (produtos, qte_prod_cad, saldo_bancario, percentual_sal, percentual_odesp);
							printf("Pressione alguma tecla para sair.\n");
							_getch();
							system("cls");
						}
						
						else if(select == '3'){
							ConfigScreen();
							printf("\n\n");
						}
						
						else if(select == esc){
							system("cls");
						}
						
						else{
							printf("Comando inválido... Tente novamente...\n");
						}
				}while(select != esc);
			}
			
			else if(logon_status == 4){
				do{
					system("cls");
					AdminScreen();
					printf("\n\n");
					printf("1 - Controle de Estoque\n2 - Relatório Financeiro\n3 - Dados cadastrais\nESC - Sair\n");
					select = _getch();
						if(select == '1'){
							StorageScreen();
							printf("\n\n");
							gerenciar_produto(produtos, qte_prod_cad, &qte_prod_cad, &saldo_bancario);
						}
						
						else if(select == '2'){
							FinanceiroScreen();
							printf("\n\n");
							calculo_e_impressao_rel_fin (produtos, qte_prod_cad, saldo_bancario, percentual_sal, percentual_odesp);
							printf("Pressione alguma tecla para sair.\n");
							_getch();
							system("cls");
						}
						
						else if(select == '3'){
							ConfigScreen();
							printf("\n\n");
						}
						
						else if(select == esc){
							system("cls");
						}
						
						else{
							printf("Comando inválido... Tente novamente...\n");
						}
				}while(select != esc);
			}
			
			else if(logon_status == 7){
				system("cls");
				printf("Administrador com acesso desabilitado ao sistema, favor contatar o administrador geral.\n");
				_getch();
  				system("cls");
			}
  			system("cls");
  			}while(select != esc);
		  }
		  
		else if(key == '2'){
			system("cls");
			CadastroScreen();
			printf("\n\n");
			
		}
		
		else if(key == esc){
			system("cls");
			printf("Encerrando o programa...\n");
		}
		
		else{
			system("cls");
			printf("Comando inválido... Tente novamente...\n");
		}
	  }while(key != esc);
}
