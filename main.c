void main()
{
  Produto produto[100];
  Funcionario funcionario[30];
  int qte_prod_cad = 0, indice_func = 0, indice_cliente = 0;
  float saldo_bancario = 10000, percentual_sal = 0.01, percentual_odesp = 0.001;
  Cliente cliente;
  int pos_cliente;
  
  gerenciar_produto(produto, 100, &qte_prod_cad, &saldo_bancario);
  compra_sanduiche(produto, qte_prod_cad, &cliente, &saldo_bancario);
  calculo_e_impressao_rel_fin (produto, qte_prod_cad, saldo_bancario, percentual_sal, percentual_odesp);
  
  
}
