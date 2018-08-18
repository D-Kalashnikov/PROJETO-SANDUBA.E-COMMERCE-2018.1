int loginadmin_search(int ind_admins, Admin admins[ind_admins], char login){
  int cont;
  for(cont=0; cont<quant; cont++){
    if(strcmp(login, admins[cont].login_password.login)==0)
    {
      return 1;
    }
    return -1;
  }
}
