void compra_sanduiche(int* quant, Produto produtos[])
{
  int ok = 0, escolha, esgotado = 0, num = 10;
  float somatorio;
  Sanduiche sanduiche;

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
  printf("Escolha o tipo de pão do seu sanduíche!");

  //Impressão das Opções de Pão
  for(int i = 0; i < num; i++)
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

  //Escolha do Pão
  while(1)
  {
    scanf(" %d", &escolha);

    for(int i = 0; i < num; i++)
    {
      if(produtos[i].tipo == 1)
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

  printf("\t\n\nTERCEIRO PASSO:\n");
  printf("Escolha o recheio do seu sanduíche!");

  //Impressão das Opções de Recheio
  for(int i = 0; i < num; i++)
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

  //Escolha do Recheio
  while(1)
  {
    scanf(" %d", &escolha);

    for(int i = 0; i < num; i++)
    {
      if(produtos[i].tipo == 2)
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

  printf("\t\n\nQUARTO PASSO:\n");
  printf("Escolha o tipo de queijo do seu sanduíche!");

  //Impressão das Opções de Queijo
  for(int i = 0; i < num; i++)
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

  //Escolha do Queijo
  while(1)
  {
    scanf(" %d", &escolha);

    for(int i = 0; i < num; i++)
    {
      if(produtos[i].tipo == 3)
      {
        if(escolha == produtos[i].id)
        {
          if(produtos[i].qtd > 0)
          {
            sanduiche.queijos = produtos[i];
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

  printf("\t\n\nQUINTO PASSO:\n");
  printf("Escolha o tipo de molho do seu sanduíche!");

  //Impressão das Opções de Molho
  for(int i = 0; i < num; i++)
  {
    if(produtos[i].tipo == 4)
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

    for(int i = 0; i < num; i++)
    {
      if(produtos[i].tipo == 4)
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

  printf("\t\n\nSEXTO PASSO:\n");
  printf("Escolha as verduras que colocará em seu sanduíche (no máximo 3 tipos)!");

  //Impressão das Opções de Verdura
  for(int i = 0; i < num; i++)
  {
    if(produtos[i].tipo == 5)
    { 
      printf("%d - %s", produtos[i].id, produtos[i].nome);

      if(produtos[i].qtd <= 0)
      {
        printf(" (Esgotado)");
      }

      printf("\n");
    }
  }

  //Escolha das Verduras

  int verduras = 0, continuar = 0;

  while(1)
  {
    scanf(" %d", &escolha);

    for(int i = 0; i < num; i++)
    {
      if(produtos[i].tipo == 5)
      {
        if(escolha == produtos[i].id)
        {
          if(produtos[i].qtd > 0)
          {
            sanduiche.salada[verduras] = produtos[i];
            verduras = verduras + 1;

            if((3 - verduras) > 0)
            {
              printf("\nDeseja pôr mais alguma verdura? (Você ainda pode colocar mais %d!\n\n)", (3 - verduras));
              printf("1 - Sim\n2 - Não\n\n");
              while(1)
              {
                scanf(" %d", &escolha);

                if(escolha == 1)
                {
                  continuar = 1;
                  break;
                }
                else if(escolha == 2)
                {
                  ok = 1;
                  break;
                }
                else
                {
                  printf("\nComando inválido. Por favor, insira um dos números indicados.\n\n");
                }
              }
            }
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
      if(continuar == 1)
      {
        continuar = 0;
        printf("\nEscolha a próxima verdura!\n\n");
      }
      else if(esgotado == 1)
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
