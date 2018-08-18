void saveAdmins(char* path, Admin* admins, int tam){
  FILE* archive = fopen(path, "w");
  fwrite(admins, sizeof(Admin), tam, archive);
  fclose(archive);
}
