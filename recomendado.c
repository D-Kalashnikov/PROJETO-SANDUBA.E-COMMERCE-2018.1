void Recommended(int clientelogon, int ind_clientes, Cliente clientes[ind_clientes]){
  printf("Recomemdamos para você: \n");
  printf("Sanduíche de %s com %i cm, recheiado de %s com %s e molho de %s pelo valor de %.2f!\n", clientes[clientelogon].ultimo_sanduiche.pao, clientes[clientelogon].ultimo_sanduiche.tamanhopao, clientes[clientelogon].ultimo_sanduiche.recheio, clientes[clientelogon].ultimo_sanduiche.queijos, clientes[clientelogon].ultimo_sanduiche.molho, clientes[clientelogon].ultimo_sanduiche.preco);
}
