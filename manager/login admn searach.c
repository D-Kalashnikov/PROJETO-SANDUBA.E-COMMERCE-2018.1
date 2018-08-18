int loginadmin_search(int ind_admins, Admin admins[ind_admins], char login){
  int i;
  for(i = 0; i < ind_admins; i++){
    if(strcmp(login, admins[i].login_password.login)==0)
    {
      return 1;
    }
    return -1;
  }
}
