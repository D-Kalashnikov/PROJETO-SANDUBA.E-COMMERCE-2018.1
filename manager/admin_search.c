int admin_search(int ind_admins, Admin admins[ind_admins], char cpf){
  int i;
  for(i=0; i<ind_admins; i++)
  {
    if(strcmp(cpf, admins[i].dados.cpf)== 0)
    {
      return i;
    }
  }
  return -1;
}
