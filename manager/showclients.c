void show_clients(){
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
      getchar();
      system("cls");
    }
  }
}
