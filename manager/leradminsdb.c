void readAdmins(char* path, Admin* admins, int tam){
    FILE* archive = fopen(path, "r");
    fread(admins, sizeof(Admin), tam, archive);
    fclose(archive);
}
