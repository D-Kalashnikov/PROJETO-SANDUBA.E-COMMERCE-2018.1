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
	int tipo; //1 = Pão, 2 = Recheio, 3 = Queijo, 4 = Molho, 5 = Vegetal
	float valorc;
	float valorv;
	float totalc;
	float totalv;
	int qtd;
	int comprados;
	int vendidos;
}Produto;

typedef struct{
	int tamanhopao;
	Produto recheio;
	Produto	molho;
	Produto	pao;
	Produto queijos;
	Produto salada[10];
	float preco;
}Sanduiche;

typedef struct{
	Pessoa dados;
	Endereco endereco;
	Login_password login_password;
	int compras_realizadas;
	Sanduiche ultimo_sanduiche;
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
