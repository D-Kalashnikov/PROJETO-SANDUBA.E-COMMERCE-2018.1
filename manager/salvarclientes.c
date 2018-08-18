void saveClientes(char* path, Cliente* clientes, int tam){
  FILE* archive = fopen(path, "w");
  fwrite(clientes, sizeof(Cliente), tam, archive);
  fclose(archive);
}
