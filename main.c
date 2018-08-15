void main()
{
  Produto produto[100];
  Funcionario funcionario[30];
  int qte_prod_cad = 0;
  float receita = 10000;// 10.000 investimento inicial
  float despesa = 500 + 500 + 2000; // manut. site + frete + salários
  float saldo_bancario = receita - despesa;
  float lucro=0; 
  
  gerenciar_produto(produto, 100, &qte_prod_cad, &saldo_bancario);
  calculo_rel_fin (produto, qte_prod_cad, &receita, &despesa, &lucro);
  impressao_rel_financeiro(produto, qte_prod_cad, receita, despesa, lucro);
  
  
}
