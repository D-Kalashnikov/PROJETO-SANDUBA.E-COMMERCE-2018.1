void compra_sanduiche(void)
{
  int ok = 0, escolha, n_recheio = 3, n_pao = 3, n_molho = 3;
  float somatorio;
  Sanduiche sanduiche;
  Produto recheios[3], paes[3], molhos[3];

  printf("\tPRIMEIRO PASSO:\n");
  printf("Escolha o tamanho do seu sanduíche!\n\n1 - 15cm\n2 - 30cm\n\n");

  //Escolha do Tamanho
  while(1)
  {
    scanf(" %d", &escolha);

    if(escolha == 1)
    {
      sanduiche.tamanhopao = 15;
      break;
    }
    else if(escolha == 2)
    {
      sanduiche.tamanhopao = 30;
      break;
    }
    else
    {
      printf("\nComando inválido, por favor insira um dos números indicados.\n\n");
    }
  }

  printf("\t\n\nSEGUNDO PASSO:\n");
  printf("Escolha o recheio do seu sanduíche!");

  //Impressão das Opções de Recheio
  for(int i = 0; i < n_recheio; i++)
  {
    printf("%d - %s\n", recheios[i].id, recheios[i].nome);
  }

  //Escolha do Recheio
  while(1)
  {
    scanf(" %d", &escolha);

    for(int i = 0; i < n_recheio; i++)
    {
      if(escolha == recheios[i].id)
      {
        sanduiche.recheio = recheios[i];
        ok = 1;
        break;
      }
    }

    if(ok == 0)
    {
      printf("\nComando inválido, por favor insira um dos números indicados.\n\n");
    }
    else if(ok == 1)
    {
      ok = 0;
      break;
    }
  }

}
