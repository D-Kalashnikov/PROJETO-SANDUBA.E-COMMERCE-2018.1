void readClientes(char* path, Cliente* clientes, int tam){
    FILE* archive = fopen(path, "r");
    fread(clientes, sizeof(Cliente), tam, archive);
    fclose(archive);
}
