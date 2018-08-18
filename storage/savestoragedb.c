void saveStorageDB(char* path, Produto* produtos, int tam){
  FILE* archive = fopen(path, "w");
  fwrite(produtos, sizeof(Produto), tam, archive);
  fclose(archive);
}
