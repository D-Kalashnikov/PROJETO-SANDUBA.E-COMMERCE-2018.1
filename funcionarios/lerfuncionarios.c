void readFuncionarios(char* path, Funcionario* funcionarios, int tam){
    FILE* archive = fopen(path, "r");
    fread(funcionarios, sizeof(Funcionario), tam, archive);
    fclose(archive);
}
