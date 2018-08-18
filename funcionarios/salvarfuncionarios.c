void saveFuncionarioDB(char* path, Funcionario* funcionarios, int tam){
  FILE* archive = fopen(path, "w");
  fwrite(funcionarios, sizeof(Funcionario), tam, archive);
  fclose(archive);
}
