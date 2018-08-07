void compra_sanduiche(void)
{
  int ok = 0, escolha, esgotado = 0, tam = 10;
  float somatorio;
  Sanduiche sanduiche;
  Produto produtos[10];

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
  for(int i = 0; i < tam; i++)
  {
    if(produtos[i].tipo == 1)
    { 
      printf("%d - %s", produtos[i].id, produtos[i].nome);

      if(produtos[i].qtd <= 0)
      {
        printf(" (Esgotado)");
      }

      printf("\n");
    }
  }

  //Escolha do Recheio
  while(1)
  {
    scanf(" %d", &escolha);

    for(int i = 0; i < tam; i++)
    {
      if(produtos[i].tipo == 1)
      {
        if(escolha == produtos[i].id)
        {
          if(produtos[i].qtd > 0)
          {
            sanduiche.recheio = produtos[i];
            ok = 1;
            break;
          }
          else
          {
            esgotado = 1;
          }
        }
      }
    }

    if(ok == 0)
    {
      if(esgotado == 1)
      {
        printf("\nProduto esgotado. Por favor, escolha outra opção.\n\n");
        esgotado = 0;
      }
      else
      {
        printf("\nComando inválido. Por favor, insira um dos números indicados.\n\n");
      }
    }
    else if(ok == 1)
    {
      ok = 0;
      break;
    }
  }

  printf("\t\n\nTERCEIRO PASSO:\n");
  printf("Escolha o tipo de pão do seu sanduíche!");

  //Impressão das Opções de Pão
  for(int i = 0; i < tam; i++)
  {
    if(produtos[i].tipo == 2)
    { 
      printf("%d - %s", produtos[i].id, produtos[i].nome);

      if(produtos[i].qtd <= 0)
      {
        printf(" (Esgotado)");
      }

      printf("\n");
    }
  }

  //Escolha do Pão
  while(1)
  {
    scanf(" %d", &escolha);

    for(int i = 0; i < tam; i++)
    {
      if(produtos[i].tipo == 2)
      {
        if(escolha == produtos[i].id)
        {
          if(produtos[i].qtd > 0)
          {
            sanduiche.pao = produtos[i];
            ok = 1;
            break;
          }
          else
          {
            esgotado = 1;
          }
        }
      }
    }

    if(ok == 0)
    {
      if(esgotado == 1)
      {
        printf("\nProduto esgotado. Por favor, escolha outra opção.\n\n");
        esgotado = 0;
      }
      else
      {
        printf("\nComando inválido. Por favor, insira um dos números indicados.\n\n");
      }
    }
    else if(ok == 1)
    {
      ok = 0;
      break;
    }
  }

  printf("\t\n\nQUARTO PASSO:\n");
  printf("Escolha o tipo de molho do seu sanduíche!");

  //Impressão das Opções de Molho
  for(int i = 0; i < tam; i++)
  {
    if(produtos[i].tipo == 3)
    { 
      printf("%d - %s", produtos[i].id, produtos[i].nome);

      if(produtos[i].qtd <= 0)
      {
        printf(" (Esgotado)");
      }

      printf("\n");
    }
  }

  //Escolha do Molho
  while(1)
  {
    scanf(" %d", &escolha);

    for(int i = 0; i < tam; i++)
    {
      if(produtos[i].tipo == 3)
      {
        if(escolha == produtos[i].id)
        {
          if(produtos[i].qtd > 0)
          {
            sanduiche.molho = produtos[i];
            ok = 1;
            break;
          }
          else
          {
            esgotado = 1;
          }
        }
      }
    }

    if(ok == 0)
    {
      if(esgotado == 1)
      {
        printf("\nProduto esgotado. Por favor, escolha outra opção.\n\n");
        esgotado = 0;
      }
      else
      {
        printf("\nComando inválido. Por favor, insira um dos números indicados.\n\n");
      }
    }
    else if(ok == 1)
    {
      ok = 0;
      break;
    }
  }

}
