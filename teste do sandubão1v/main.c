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
	char nome[30];
	int logon_status;
	Produto produtos[100];
  	Funcionario funcionarios[30];
	Cliente clientes[100];
  	Admin admins[20];
  	int qte_prod_cad = 0, indice_func = 0, indice_cliente = 0, indice_adm = 0;
  	float saldo_bancario = 10000, percentual_sal = 0.01, percentual_odesp = 0.001;
  	int posicao;
  	float somatorio = 0;
  	
  	readStorageDB("storageDB.txt", produtos, qte_prod_cad);
  	readFuncionarios("FuncionariosDB.txt", funcionarios, indice_func);
  	readAdmins("AdminsDB.txt", admins, indice_adm);
  	readClientes("ClientesDB.txt", clientes, indice_cliente);
  	
  	
  	do{
  		LogoScreen();
  		key = _getch();
  		
  		if(key == '1'){
  			//do{
			system("cls");
  			LoginScreen();
  			printf("\n\n");
  			logon_status = login_function(indice_cliente, indice_adm, &posicao, clientes, admins);
  			
  			if(logon_status == -1){
  				printf("\nDados não encontrados!\n");
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
							do{
								ConfigScreen();
								printf("\n\n");
								printf("1 - Alteração de dados da conta\n2 - Desativar a conta\nESC - Sair");
								internal = _getch();
									if(internal == '1'){
										mudanca_cliente(posicao, indice_cliente, clientes);
									}
									
									else if(internal == '2'){
										desativar_cliente(clientes, posicao);
									}
									
									else if(internal == esc){
										system("cls");
									}
									
									else{
										printf("Comando inválido... Tente novamente...\n");
									}
							}while(internal != esc);
						}
						
						else if(select == esc){
							system("cls");
						}
						
						else{
							printf("Comando invÃ¡lido... Tente novamente...\n");
						}
				}while(select != esc);
			}
			
			else if(logon_status == 0){
				do{
					system("cls");
					SandubaScreen();
					printf("\n\n");
					printf("VocÃª desativou esta conta!\n");
					printf("Gostaria de reativar o acesso?\n\n1 - Sim\n2 - NÃ£o\nESC - Sair\n");
					select = _getch();
						if(select == '1'){
							reativar_cliente(clientes, posicao);
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
							do{
								StorageScreen();
								printf("\n\n");
								printf("1 - Visualizar Estoque\n2 - Visualizar quantidades\n3 - Visualizar produtos mais vendidos\n4 - Visualizar produtos mais comprados\n5 - Procurar produto\n6 - Restocagem\n7 - Alterar produtos\n8 - Cadastrar produtos\nESC - Sair");
								internal = _getch();
									if(internal == '1'){
										Storage(qte_prod_cad, produtos);
										printf("Pressione alguma tecla para sair.\n");
										_getch();
										system("cls");
									}
									
									else if(internal == '2'){
										stockfunctional(qte_prod_cad, produtos);
										printf("Pressione alguma tecla para sair.\n");
										_getch();
										system("cls");
									}
									
									else if(internal == '3'){
										bestseller(qte_prod_cad, produtos);
										printf("Pressione alguma tecla para sair.\n");
										_getch();
										system("cls");
									}
									
									else if(internal == '4'){
										restockfunctional(qte_prod_cad, produtos);
										printf("Pressione alguma tecla para sair.\n");
										_getch();
										system("cls");
									}
									
									else if(internal == '5'){
										product_search(qte_prod_cad, produtos);
										printf("Pressione alguma tecla para sair.\n");
										_getch();
										system("cls");
									}
									
									else if(internal == '6'){
										restock(qte_prod_cad, produtos, &saldo_bancario);
										printf("Pressione alguma tecla para sair.\n");
										_getch();
										system("cls");
									}
									
									else if(internal == '7'){
										printf("Digite o nome do produto a ser alterado:\n");
										fgets(nome, 30, stdin);
										int tam = strlen(nome);
										nome[tam-1]='\0';
										fflush(stdin);
										alterar_prod(produtos, qte_prod_cad, nome);
										printf("Pressione alguma tecla para sair.\n");
										_getch();
										system("cls");
									}
									
									else if(internal == '8'){
										cadastrar_prod(produtos, qte_prod_cad, &qte_prod_cad);
										printf("Pressione alguma tecla para sair.\n");
										_getch();
										system("cls");
									}
									
									else if(internal == esc){
										system("cls");
									}
									
									else{
										printf("Comando inválido... Tente novamente...\n");
									}
							}while(internal != esc);		
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
							do{
								ConfigScreen();
								printf("\n\n");
								printf("1 - Mostrar admins\n2 - Mostrar clientes\n3 - Desabilitar Admin\n4 - Reabilitar Admin\n5 - Bloquear cliente\n6 - Desbloquear cliente\n7 - Adicionar administrador\nESC - Sair\n");
								internal = _getch();
									if(internal == '1'){
										show_admins(indice_adm, admins);
										printf("Pressione alguma tecla para sair.\n");
										_getch();
										system("cls");
									}
									
									else if(internal == '2'){
										show_clients(indice_cliente, clientes);
										printf("Pressione alguma tecla para sair.\n");
										_getch();
										system("cls");
									}
									
									else if(internal == '3'){
										AdminDisable(indice_adm, admins);
										printf("Pressione alguma tecla para sair.\n");
										_getch();
										system("cls");
									}
									
									else if(internal == '4'){
										AdminEnabled(indice_adm, admins);
										printf("Pressione alguma tecla para sair.\n");
										_getch();
										system("cls");
									}
									
									else if(internal == '5'){
										BlockClient(indice_cliente, clientes);
										printf("Pressione alguma tecla para sair.\n");
										_getch();
										system("cls");
									}
									
									else if(internal == '6'){
										DisblockClient(indice_cliente, clientes);
										printf("Pressione alguma tecla para sair.\n");
										_getch();
										system("cls");
									}
									
									else if(internal == '7'){
										Add_Admin(&indice_adm, admins);
										printf("Pressione alguma tecla para sair.\n");
										_getch();
										system("cls");
									}
									
									else if(internal == esc){
										system("cls");
									}
									
									else{
										printf("Comando inválido... Tente novamente...\n");
									}
							}while(internal != esc);
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
					printf("1 - Controle de Estoque\n2 - RelatÃ³rio Financeiro\n3 - Dados cadastrais\nESC - Sair\n");
					select = _getch();
						if(select == '1'){
								do{
								StorageScreen();
								printf("\n\n");
								printf("1 - Visualizar Estoque\n2 - Visualizar quantidades\n3 - Visualizar produtos mais vendidos\n4 - Visualizar produtos mais comprados\n5 - Procurar produto\n6 - Restocagem\n7 - Alterar produtos\n8 - Cadastrar produtos\nESC - Sair");
								internal = _getch();
									if(internal == '1'){
										Storage(qte_prod_cad, produtos);
										printf("Pressione alguma tecla para sair.\n");
										_getch();
										system("cls");
									}
									
									else if(internal == '2'){
										stockfunctional(qte_prod_cad, produtos);
										printf("Pressione alguma tecla para sair.\n");
										_getch();
										system("cls");
									}
									
									else if(internal == '3'){
										bestseller(qte_prod_cad, produtos);
										printf("Pressione alguma tecla para sair.\n");
										_getch();
										system("cls");
									}
									
									else if(internal == '4'){
										restockfunctional(qte_prod_cad, produtos);
										printf("Pressione alguma tecla para sair.\n");
										_getch();
										system("cls");
									}
									
									else if(internal == '5'){
										product_search(qte_prod_cad, produtos);
										printf("Pressione alguma tecla para sair.\n");
										_getch();
										system("cls");
									}
									
									else if(internal == '6'){
										restock(qte_prod_cad, produtos, &saldo_bancario);
										printf("Pressione alguma tecla para sair.\n");
										_getch();
										system("cls");
									}
									
									else if(internal == '7'){
										printf("Digite o nome do produto a ser alterado:\n");
										fgets(nome, 30, stdin);
										int tam = strlen(nome);
										nome[tam-1]='\0';
										fflush(stdin);
										alterar_prod(produtos, qte_prod_cad, nome);
										printf("Pressione alguma tecla para sair.\n");
										_getch();
										system("cls");
									}
									
									else if(internal == '8'){
										cadastrar_prod(produtos, qte_prod_cad, &qte_prod_cad);
										printf("Pressione alguma tecla para sair.\n");
										_getch();
										system("cls");
									}
									
									else if(internal == esc){
										system("cls");
									}
									
									else{
										printf("Comando inválido... Tente novamente...\n");
									}
							}while(internal != esc);
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
							do{
								ConfigScreen();
								printf("\n\n");
								printf("1 - Mostrar admins\n2 - Mostrar clientes\n3 - Bloquear cliente\n4 - Desbloquear cliente\nESC - Sair\n");
								internal = _getch();
									if(internal == '1'){
										show_admins(indice_adm, admins);
										printf("Pressione alguma tecla para sair.\n");
										_getch();
										system("cls");
									}
									
									else if(internal == '2'){
										show_clients(indice_cliente, clientes);
										printf("Pressione alguma tecla para sair.\n");
										_getch();
										system("cls");
									}
									
									else if(internal == '3'){
										BlockClient(indice_cliente, clientes);
										printf("Pressione alguma tecla para sair.\n");
										_getch();
										system("cls");
									}
									
									else if(internal == '4'){
										DisblockClient(indice_cliente, clientes);
										printf("Pressione alguma tecla para sair.\n");
										_getch();
										system("cls");
									}
									
									else if(internal == esc){
										system("cls");
									}
									
									else{
										printf("Comando inválido... Tente novamente...\n");
									}
							}while(internal != esc);
						}
						
						else if(select == esc){
							system("cls");
						}
						
						else{
							printf("Comando invÃ¡lido... Tente novamente...\n");
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
  			//}while(select != esc);
		  }
		  
		else if(key == '2'){
			system("cls");
			CadastroScreen();
			printf("\n\n");
			cadastro_cliente(clientes, indice_cliente, &indice_cliente);
			system("cls");
			printf("\n\nCadastro efetuado com sucesso...\n\n");
			_getch();
		}
		
		else if(key == esc){
			//ADICIONAR O SALVAMENTO DOS DADOS
			system("cls");
			printf("Encerrando o programa...\n");
		}
		
		else{
			system("cls");
			printf("Comando invÃ¡lido... Tente novamente...\n");
		}
	  }while(key != esc);
}
