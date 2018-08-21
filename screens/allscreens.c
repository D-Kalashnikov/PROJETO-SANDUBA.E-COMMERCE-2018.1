void print_image(FILE *archive)
  {
      char read_string[MAX_LEN];
  
      while(fgets(read_string,sizeof(read_string),archive) != NULL){
        printf("%s",read_string);
      }
  }
  //LOGOSCREEN
  
  void LogoScreen(){

      char *filename = "logoscreen.txt";
      FILE *archive = NULL;
  
      if((archive = fopen(filename,"r")) == NULL)
      {
          fprintf(stderr,"Erro na abertura do arquivo %s\n",filename);
      }
  
      print_image(archive);
  
      fclose(archive);
}

//Loginscreen

void LoginScreen(){

      char *filename = "loginscreen.txt";
      FILE *archive = NULL;
  
      if((archive = fopen(filename,"r")) == NULL)
      {
          fprintf(stderr,"Erro na abertura do arquivo %s\n",filename);
      }
  
      print_image(archive);
  
      fclose(archive);
}

//Cadastroscreen

void CadastroScreen(){

      char *filename = "cadastroscreen.txt";
      FILE *archive = NULL;
  
      if((archive = fopen(filename,"r")) == NULL)
      {
          fprintf(stderr,"Erro na abertura do arquivo %s\n",filename);
      }
  
      print_image(archive);
  
      fclose(archive);
}

//Carrinhoscreen

void CarrinhoScreen(){

      char *filename = "carrinhoscreen.txt";
      FILE *archive = NULL;
  
      if((archive = fopen(filename,"r")) == NULL)
      {
          fprintf(stderr,"Erro na abertura do arquivo %s\n",filename);
      }
  
      print_image(archive);
  
      fclose(archive);
}

//StorageScreen

void StorageScreen(){

      char *filename = "storagescreen.txt";
      FILE *archive = NULL;
  
      if((archive = fopen(filename,"r")) == NULL)
      {
          fprintf(stderr,"Erro na abertura do arquivo %s\n",filename);
      }
  
      print_image(archive);
  
      fclose(archive);
}

//AdminScreen

void AdminScreen(){

      char *filename = "adminscreen.txt";
      FILE *archive = NULL;
  
      if((archive = fopen(filename,"r")) == NULL)
      {
          fprintf(stderr,"Erro na abertura do arquivo %s\n",filename);
      }
  
      print_image(archive);
  
      fclose(archive);
}

//ConfigScreen

void ConfigScreen(){

      char *filename = "configscreen.txt";
      FILE *archive = NULL;
  
      if((archive = fopen(filename,"r")) == NULL)
      {
          fprintf(stderr,"Erro na abertura do arquivo %s\n",filename);
      }
  
      print_image(archive);
  
      fclose(archive);
}

//FinanceiroScreen

void FinanceiroScreen(){

      char *filename = "financeiroscreen.txt";
      FILE *archive = NULL;
  
      if((archive = fopen(filename,"r")) == NULL)
      {
          fprintf(stderr,"Erro na abertura do arquivo %s\n",filename);
      }
  
      print_image(archive);
  
      fclose(archive);
}


//
