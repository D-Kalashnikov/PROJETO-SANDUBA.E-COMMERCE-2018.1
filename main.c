void main()
{
  Produto produto[100];
  Funcionario funcionario[30];
  int qte_prod_cad = 0, indice_func = 0;
  float receita = 10000;// 10.000 investimento inicial
  float despesa = 500 + 500; // manut. site + frete
  float saldo_bancario = receita - despesa;
  float lucro=0;
  Cliente cliente;
  
  gerenciar_produto(produto, 100, &qte_prod_cad, &saldo_bancario);
  calculo_rel_fin (produto, qte_prod_cad, funcionario, indice_func, &receita, &despesa, &lucro);
  impressao_rel_financeiro(produto, qte_prod_cad, funcionario, indice_func, receita, despesa, lucro);
  compra_sanduiche(&qte_prod_cad, produto, qte_prod_cad, &cliente);
  
  
}
