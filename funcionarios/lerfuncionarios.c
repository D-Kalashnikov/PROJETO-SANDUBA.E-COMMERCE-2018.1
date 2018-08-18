void readFuncionarios(char* path, Funcionario* funcionarios, int tam){
    FILE* archive = fopen(path, "r");
    fread(funcionarios, sizeof(Funcionario), tam, archive);
    fclose(archive);
}


//readFuncionarios("FuncionariosDB.txt", funcionarios, ind_tfuncionarios) ← padrão de uso por favor seguir
