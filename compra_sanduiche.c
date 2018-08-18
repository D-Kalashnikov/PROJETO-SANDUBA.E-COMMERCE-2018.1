float compra_sanduiche(int* quant, Produto produtos[], int tam, Cliente* cliente)
{
  int verduras = 0, num_sand, compra = 1, ok = 0, escolha, esgotado = 0, num = *quant;
  float somatorio = 0;
  Sanduiche sanduiche;

  printf("Antes de tudo, por favor, digite o número de sanduíches que você deseja comprar (digitar 0 irá cancelar a compra):");

  while(1)
  {
    scanf(" %d", &num_sand);

    if(num_sand == 1)
    {
      printf("\nHora de começar a compra de seu Sanduíche (novamente, digitar 0 em qualquer passo irá cancelar a compra)!\n\n");
      break;
    }
    else if(num_sand == 0)
    {
      printf("\nAgradecemos pela preferência!\n\n");
      return 0;
    }
    else if(num_sand > 1)
    {
      break;
    }
    else
    {
      printf("\nComando inválido, por favor insira um dos números indicados.\n\n");
    }
  }

  Sanduiche carrinho[num_sand];

  for(int i = 1; i <= num_sand; i++)
  {
    compra = 1;
    
    if(num_sand > 1)
    {
      printf("\nHora de começar a compra de seu Sanduíche %d (novamente, digitar 0 em qualquer passo irá cancelar a compra)!\n\n", i);
    }

    while(compra == 1)
    {
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
        else if(escolha == 0)
        {
          printf("Agradecemos pela preferência!");
          return 0;
        }
        else
        {
          printf("\nComando inválido, por favor insira um dos números indicados.\n\n");
        }
      }

      printf("\t\n\nSEGUNDO PASSO:\n");
      //antes printf("Escolha o tipo de pão do seu sanduíche!");
      printf("Escolha o tipo de pão do seu sanduíche!\n");

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

        if(escolha == 0)
        {
          printf("Agradecemos pela preferência!");
          return 0;
        }

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
      //antes printf("Escolha o recheio do seu sanduíche!");
      printf("Escolha o recheio do seu sanduíche!\n");

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

        if(escolha == 0)
        {
          printf("Agradecemos pela preferência!");
          return 0;
        }

        for(int i = 0; i < num; i++)
        {
          if(produtos[i].tipo == 2)
          {
            if(escolha == produtos[i].id)
            {
              if(produtos[i].qtd > 0)
              {
                sanduiche.recheio = produtos[i];
                //antes produtos[i].qtd = produtos[i].qtd - 1;
                //antes produtos[i].vendidos = produtos[i].vendidos + 1;
                //antes produtos[i].totalv = produtos[i].totalv + produtos[i].valorv;
                //JOSEMAR - retirei isso do teu código porque, do jeito que está, a compra é contabilizada mesmo que o cliente desista dela.
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
      //antes printf("Escolha o tipo de queijo do seu sanduíche!");
      printf("Escolha o tipo de queijo do seu sanduíche!\n");

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

        if(escolha == 0)
        {
          printf("Agradecemos pela preferência!");
          return 0;
        }

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
      //antes printf("Escolha o tipo de molho do seu sanduíche!");
      printf("Escolha o tipo de molho do seu sanduíche!\n");

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

        if(escolha == 0)
        {
          printf("Agradecemos pela preferência!");
          return 0;
        }

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

      int continuar = 0;

      while(1)
      {
        scanf(" %d", &escolha);

        if(escolha == 0)
        {
          printf("Agradecemos pela preferência!");
          return 0;
        }

        for(int i = 0; i < num; i++)
        {
          if(produtos[i].tipo == 5)
          {
            if(escolha == produtos[i].id)
            {
              if(produtos[i].qtd > 0)
              {
                sanduiche.salada[verduras] = produtos[i];
                verduras += 1;

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

      if(sanduiche.tamanhopao == 15)
      {
        sanduiche.preco = (sanduiche.recheio.valorv + sanduiche.molho.valorv + sanduiche.queijos.valorv + sanduiche.pao.valorv);
      }
      else if(sanduiche.tamanhopao == 30)
      {
        sanduiche.preco = ((sanduiche.recheio.valorv + sanduiche.molho.valorv + sanduiche.queijos.valorv + sanduiche.pao.valorv) * 2);
      }

      printf("\nConferindo:\n\n");

      printf("Sanduíche de %s\n Pão: %s\nQueijo: %s\nMolho: %s\nVegetais: ", sanduiche.recheio.nome, sanduiche.pao.nome, sanduiche.queijos.nome, sanduiche.molho.nome);
      for(int i = 0; i < verduras; i++)
      {
        if((verduras - i) > 1)
        {
        printf("%s, ", sanduiche.salada[i].nome);
        }
        else
        {
          printf("%s", sanduiche.salada[i].nome);
        }
      }
      printf("\nPreço: R$ %f", sanduiche.preco);

      printf("\n\nDeseja adicionar esse Sanduíche ao Carrinho?\n\n1 - Sim\n2 - Não");

      while(1)
      {
        scanf(" %d", &escolha);

        if(escolha == 1)
        {
          compra = 0;
          break;
        }
        else if(escolha == 2)
        {
          int certeza;

          printf("\n\nTem certeza? Isso irá desfazer as escolhas pro sanduíche até então!\n\n1 - Sim\n2 - Não");
          
          while(1)
          {
            scanf(" %d", &escolha);

            if(escolha == 1)
            {
              certeza = 1;
              break;
            }
            else if(escolha == 2)
            {
              certeza = 0;
              break;
            }
            else
            {
              printf("\nComando inválido. Por favor, insira um dos números indicados.\n\n");
            }
          }

          if(certeza == 1)
          {
            printf("\nDeseja...\n\n1 - Refazer o seu sanduíche.\n2 - Finalizar a compra assim mesmo.");

            while(1)
            {
              scanf(" %d", &escolha);

              if(escolha == 1)
              {
                break;
              }
              else if(escolha == 2)
              {
                printf("\n\nAgradecemos pela preferência!\n");
                return 0;
              }
              else
              {
                printf("\nComando inválido. Por favor, insira um dos números indicados.\n\n");
              }
            }
          }
          else if(certeza == 0)
          {
            compra = 0;
            break;
          }
        }
        else
        {
          printf("\nComando inválido. Por favor, insira um dos números indicados.\n\n");
        }
      }
    }
    
    if(compra == 0)
    {
      produtos[sanduiche.pao.id -1].qtd -= 1;
      produtos[sanduiche.pao.id -1].vendidos += 1;
      produtos[sanduiche.pao.id -1].totalv += sanduiche.pao.valorv;

      produtos[sanduiche.recheio.id -1].qtd -= 1;
      produtos[sanduiche.recheio.id -1].vendidos += 1;
      produtos[sanduiche.recheio.id -1].totalv += sanduiche.recheio.valorv;

      produtos[sanduiche.molho.id -1].qtd -= 1;
      produtos[sanduiche.molho.id -1].vendidos += 1;
      produtos[sanduiche.molho.id -1].totalv += sanduiche.molho.valorv;

      produtos[sanduiche.queijos.id -1].qtd -= 1;
      produtos[sanduiche.queijos.id -1].vendidos += 1;
      produtos[sanduiche.queijos.id -1].totalv += sanduiche.queijos.valorv;

      for(int i = 0; i < verduras; i++)
      {
        produtos[sanduiche.salada[i].id -1].qtd -= 1;
        produtos[sanduiche.salada[i].id -1].vendidos += 1;
        produtos[sanduiche.salada[i].id -1].totalv += sanduiche.salada[i].valorv;
      }

      somatorio = somatorio + sanduiche.preco;

      carrinho[i] = sanduiche;
    }
  }
  cliente->ultimo_sanduiche = sanduiche;

  printf("\nO valor total de sua compra foi: R$ %f\n\nAgradecemos pela preferência!", somatorio);

  return somatorio;
}
