void readStorageDB(char* path, Produto* produtos, int tam){
    FILE* archive = fopen(path, "r");
    fread(produtos, sizeof(Prouto), tam, archive);
    fclose(archive);
  }
