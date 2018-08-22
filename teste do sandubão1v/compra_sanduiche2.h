void impressao_prodtipo(Produto produto[], int qte_prod_cad, int tipo_teste)
{
  for(int i=0; i<qte_prod_cad;i++)
  {
    if(produto[i].tipo==tipo_teste)
    {
      printf("%d - %s", produto[i].id, produto[i].nome);

       if(produto[i].qtd <= 0)
        {
          printf(" (Esgotado)");
        }
      printf("\n");
    } 
  }
}


float compra_sanduiche(Produto produtos[], int num, int posicao, Cliente cliente[], float* psaldo_bancario)
{
  int verduras = 0, num_sand, compra = 1, ok = 0, escolha, esgotado = 0;
  float somatorio = 0;
  Sanduiche sanduiche;
  int verif_qte;

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
      printf("Escolha o tipo de pão do seu sanduíche!\n");

      //Impressão das Opções de Pão
      impressao_prodtipo(produtos, num , 1);

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
              if(sanduiche.tamanhopao == 15)
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
              else if(sanduiche.tamanhopao == 30)
              {
                if(produtos[i].qtd > 1)
                {
                  sanduiche.pao = produtos[i];
                  ok = 1;
                  break;
                }
                else if(produtos[i].qtd == 1)
                {
                  esgotado = 2;
                }
                else
                {
                  esgotado = 1;
                }
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
          else if(esgotado == 2)
          {
            printf("Há apenas uma unidade desse produto. Por favor, escolha outra opção.\n\n");
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
      printf("Escolha o recheio do seu sanduíche!\n");

      //Impressão das Opções de Recheio
       impressao_prodtipo(produtos, num , 2);

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
              if(sanduiche.tamanhopao == 15)
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
              else if(sanduiche.tamanhopao == 30)
              {
                if(produtos[i].qtd > 1)
                {
                  sanduiche.recheio = produtos[i];
                  ok = 1;
                  break;
                }
                else if(produtos[i].qtd == 1)
                {
                  esgotado = 2;
                }
                else
                {
                  esgotado = 1;
                }
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
          else if(esgotado == 2)
          {
            printf("Há apenas uma unidade desse produto. Por favor, escolha outra opção.\n\n");
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
      printf("Escolha o tipo de queijo do seu sanduíche!\n");

      //Impressão das Opções de Queijo
      impressao_prodtipo(produtos, num , 3);

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
              if(sanduiche.tamanhopao == 15)
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
              else if(sanduiche.tamanhopao == 30)
              {
                if(produtos[i].qtd > 1)
                {
                  sanduiche.queijos = produtos[i];
                  ok = 1;
                  break;
                }
                else if(produtos[i].qtd == 1)
                {
                  esgotado = 2;
                }
                else
                {
                  esgotado = 1;
                }
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
          else if(esgotado == 2)
          {
            printf("Há apenas uma unidade desse produto. Por favor, escolha outra opção.\n\n");
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
      printf("Escolha o tipo de molho do seu sanduíche!\n");

      //Impressão das Opções de Molho
      impressao_prodtipo(produtos, num , 4);

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
              if(sanduiche.tamanhopao == 15)
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
              else if(sanduiche.tamanhopao == 30)
              {
                if(produtos[i].qtd > 1)
                {
                  sanduiche.molho = produtos[i];
                  ok = 1;
                  break;
                }
                else if(produtos[i].qtd == 1)
                {
                  esgotado = 2;
                }
                else
                {
                  esgotado = 1;
                }
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
          else if(esgotado == 2)
          {
            printf("Há apenas uma unidade desse produto. Por favor, escolha outra opção.\n\n");
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

      int sim;

      printf("\nVocê deseja adicionar verduras ao seu Sanduíche?\n\n1 - Sim\n2 - Não");

      while(1)
      {
        scanf(" %d", &escolha);

        if(escolha == 1)
        {
          sim = 1;
          break;
        }
        else if(escolha == 2)
        {
          sim = 0;
          break;
        }
        else
        {
          printf("\nComando inválido, por favor insira um dos números indicados.\n\n");
        }
      }

      if(sim == 1)
      {
        printf("\t\n\nSEXTO PASSO:\n");
        printf("Escolha as verduras que colocará em seu sanduíche (no máximo 3 tipos)!\n");

        //Impressão das Opções de Verdura
        impressao_prodtipo(produtos, num , 5);

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
                  // no lugar de verduras += 1;
                  // colocar verduras++;
                  verduras++;

                  if((3 - verduras) > 0)
                  {
                    printf("\nDeseja pôr mais alguma verdura? (Você ainda pode colocar mais %d!)\n\n", (3 - verduras));
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
                  else if(verduras == 3)
                  {
                    ok = 1;
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

      if(sanduiche.tamanhopao == 15)
      {
        sanduiche.preco = (sanduiche.recheio.valorv + sanduiche.molho.valorv + sanduiche.queijos.valorv + sanduiche.pao.valorv);

        for(int i=0; i<verduras;i++)
        {
          sanduiche.preco += sanduiche.salada[i].valorv;
        }
      }
      else if(sanduiche.tamanhopao == 30)
      {
        sanduiche.preco = ((sanduiche.recheio.valorv + sanduiche.molho.valorv + sanduiche.queijos.valorv + sanduiche.pao.valorv) * 2);
        
        for(int i=0; i<verduras;i++)
        {
          sanduiche.preco += 2*sanduiche.salada[i].valorv;
        }

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
      printf("\nPreço: R$ %.2f", sanduiche.preco);

      printf("\n\nDeseja comprar esse Sanduíche?\n\n1 - Sim\n2 - Não");

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
      cliente[posicao].compras_realizadas++;
      // nas 3° compras o cliente ganha 30% de desconto.

      if(sanduiche.tamanhopao == 15 && cliente[posicao].compras_realizadas % 3 != 0)
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
          produtos[sanduiche.salada[i].id -1].totalv += 1 * sanduiche.salada[i].valorv;
        }
        somatorio = somatorio + sanduiche.preco;
        *psaldo_bancario += sanduiche.preco;
      }
      else if(sanduiche.tamanhopao == 15 && cliente[posicao].compras_realizadas % 3 == 0)
      {
        produtos[sanduiche.pao.id -1].qtd -= 1;
        produtos[sanduiche.pao.id -1].vendidos += 1;
        produtos[sanduiche.pao.id -1].totalv += sanduiche.pao.valorv * 0.7;

        produtos[sanduiche.recheio.id -1].qtd -= 1;
        produtos[sanduiche.recheio.id -1].vendidos += 1;
        produtos[sanduiche.recheio.id -1].totalv += sanduiche.recheio.valorv * 0.7;

        produtos[sanduiche.molho.id -1].qtd -= 1;
        produtos[sanduiche.molho.id -1].vendidos += 1;
        produtos[sanduiche.molho.id -1].totalv += sanduiche.molho.valorv * 0.7;

        produtos[sanduiche.queijos.id -1].qtd -= 1;
        produtos[sanduiche.queijos.id -1].vendidos += 1;
        produtos[sanduiche.queijos.id -1].totalv += sanduiche.queijos.valorv * 0.7;

        for(int i = 0; i < verduras; i++)
        {
          produtos[sanduiche.salada[i].id -1].qtd -= 1;
          produtos[sanduiche.salada[i].id -1].vendidos += 1;
          produtos[sanduiche.salada[i].id -1].totalv += sanduiche.salada[i].valorv * 0.7;
        } 
        somatorio = somatorio + sanduiche.preco * 0.7;
        *psaldo_bancario += sanduiche.preco * 0.7;

        printf("\nO senhor(a) obteve um desconto de %.2f na compra do sanduíche\n\n", sanduiche.preco * 0.3); //colocar .2f //alterar
      }
      else if(sanduiche.tamanhopao == 30 && cliente[posicao].compras_realizadas % 3 != 0)
      {
        produtos[sanduiche.pao.id -1].qtd -= 2;
        produtos[sanduiche.pao.id -1].vendidos += 2;
        produtos[sanduiche.pao.id -1].totalv +=2* sanduiche.pao.valorv;

        produtos[sanduiche.recheio.id -1].qtd -= 1;
        produtos[sanduiche.recheio.id -1].vendidos += 1;
        produtos[sanduiche.recheio.id -1].totalv +=2* sanduiche.recheio.valorv;

        produtos[sanduiche.molho.id -1].qtd -= 1;
        produtos[sanduiche.molho.id -1].vendidos += 1;
        produtos[sanduiche.molho.id -1].totalv += 2*sanduiche.molho.valorv;

        produtos[sanduiche.queijos.id -1].qtd -= 1;
        produtos[sanduiche.queijos.id -1].vendidos += 1;
        produtos[sanduiche.queijos.id -1].totalv +=2* sanduiche.queijos.valorv;
        for(int i = 0; i < verduras; i++)
        {
          produtos[sanduiche.salada[i].id -1].qtd -= 1;
          produtos[sanduiche.salada[i].id -1].vendidos += 1;
          produtos[sanduiche.salada[i].id -1].totalv += 2* sanduiche.salada[i].valorv;
        }
        somatorio = somatorio + sanduiche.preco;
        *psaldo_bancario += sanduiche.preco;
      }
      else if(sanduiche.tamanhopao == 30 && cliente[posicao].compras_realizadas % 3 == 0)
      {
        produtos[sanduiche.pao.id -1].qtd -= 2;
        produtos[sanduiche.pao.id -1].vendidos += 2;
        produtos[sanduiche.pao.id -1].totalv += sanduiche.pao.valorv * 2* 0.7;

        produtos[sanduiche.recheio.id -1].qtd -= 2;
        produtos[sanduiche.recheio.id -1].vendidos += 2;
        produtos[sanduiche.recheio.id -1].totalv += sanduiche.recheio.valorv * 2 * 0.7;

        produtos[sanduiche.molho.id -1].qtd -= 1;
        produtos[sanduiche.molho.id -1].vendidos += 1;
        produtos[sanduiche.molho.id -1].totalv += sanduiche.molho.valorv * 2 * 0.7;

        produtos[sanduiche.queijos.id -1].qtd -= 1;
        produtos[sanduiche.queijos.id -1].vendidos += 1;
        produtos[sanduiche.queijos.id -1].totalv += sanduiche.queijos.valorv * 2 * 0.7;

        for(int i = 0; i < verduras; i++)
        {
          produtos[sanduiche.salada[i].id -1].qtd -= 1;
          produtos[sanduiche.salada[i].id -1].vendidos += 1;
          produtos[sanduiche.salada[i].id -1].totalv += sanduiche.salada[i].valorv * 2 * 0.7;
        } 
        somatorio = somatorio + sanduiche.preco * 2 * 0.7;
        *psaldo_bancario += sanduiche.preco * 2 * 0.7;

        printf("\nO senhor(a) obteve um desconto de %.2f na compra do sanduíche\n\n", sanduiche.preco  * 0.3); 
      }
    }

  }
  cliente[posicao].ultimo_sanduiche.verduras = verduras;
  cliente[posicao].ultimo_sanduiche = sanduiche;

  printf("\nO valor total de sua compra foi: R$ %.2f\n\nAgradecemos pela preferência!", somatorio);

  return somatorio;
}
