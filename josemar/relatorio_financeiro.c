void impressao_rel_financeiro(Produto produto[], int qte_prod_cad, Funcionario funcionario[], int indice_func, float receita, float despesa, float lucro)
{
  
  printf("(+) RECEITA:         = %.2f\n", receita);
  printf("Invest. inicial = 10000.00\n");
  for(int i=0; i<qte_prod_cad;i++)
  {
    printf("Venda de produtos:\n");
    printf("%s = ",produto[i].nome);
    printf("%.2f\n",produto[i].totalv);
  }
  printf("\n\n");
  printf("(-) DESPESA:          = %.2f\n", despesa);
  printf("Manut. do site =  500.00\n");
  printf("Frete =  500.00\n");

  for(int i=0; i<indice_func;i++)
  {
    printf("Salário funcionarios:\n");
    printf("%s = ",funcionario[i].dados.nome);
    printf("%.2f\n",funcionario[i].salario);
  }
  printf("\n\n");
  
  for(int i=0; i<qte_prod_cad;i++)
  {
    printf("Compra de produtos:\n");
    printf("%s = ",produto[i].nome);
    printf("%.2f\n",produto[i].totalc);
  }
  printf("\n\n");
  printf("(=) LUCRO:            = %.2f\n", lucro);
  printf("\n");


}
  void calculo_rel_fin(Produto produto[], int qte_prod_cad, Funcionario funcionario[], int indice_func, float* preceita, float* pdespesa, float* plucro)
{
  
  
  for(int i=0; i<qte_prod_cad;i++)
  {
    *preceita += produto[i].totalv;
  }

  for(int i=0; i<qte_prod_cad;i++)
  {
    *pdespesa += produto[i].totalc;
  }

  for(int i=0; i<indice_func;i++)
  {
    *pdespesa += funcionario[i].salario;
  }



  *plucro = *preceita - *pdespesa;
  
}
