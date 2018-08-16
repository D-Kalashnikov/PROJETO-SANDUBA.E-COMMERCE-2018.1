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

int  check_qte(Produto produto[],int qte_prod_cad, Sanduiche sanduiche,int escolha,int tipo)
{
  if(escolha==0) 
  {
    return 0; // usuário desistiu da compra
  }
  for(int i = 0; i < qte_prod_cad; i++)
  {
    if(produto[i].tipo == tipo)
    {
      if(escolha == produto[i].id)
      {
        if(produto[i].qtd > 0)
        {
          sanduiche.pao = produto[i];
          return 1; // produto tem no estoque
        }  
        else
        {
          return -1;// produto não tem no estoque
        }
      }
    }
    
  }
  return -2;// cliente digitou o id incorreto, pois, se o id estivesse certo, a função retornaria ou 1 ou -1.
}
float compra_sanduiche(int* quant, Produto produto[], int qte_prod_cad, Cliente* cliente)
{
  int verduras = 0, num_sand, compra = 1, escolha;
  int verif_qte;
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

     impressao_prodtipo(produto, qte_prod_cad, 1);

      while(1)
      {
        scanf(" %d", &escolha);
        verif_qte = check_qte (produto, qte_prod_cad, sanduiche, escolha, 1);
        if(verif_qte==0)
        {
          printf("Agradecemos pela preferência!");
          return 0;
        }
        else if(verif_qte==1)
        {
          break;
        }
        else if(verif_qte==-1)
        {
          printf("\nProduto esgotado. Por favor, escolha outra opção.\n\n");
        }
        else if(verif_qte==-2)
        {
           printf("\nComando inválido. Por favor, insira um dos números indicados.\n\n");
        }
      }

      printf("\t\n\nTERCEIRO PASSO:\n");
      printf("Escolha o recheio do seu sanduíche!\n");

      impressao_prodtipo(produto, qte_prod_cad, 2);
      
      while(1)
      {
        scanf(" %d", &escolha);
        verif_qte = check_qte(produto, qte_prod_cad, sanduiche, escolha, 2);
        if(verif_qte==0)
        {
          printf("Agradecemos pela preferência!");
          return 0;
        }
        else if(verif_qte==1)
        {
          break;
        }
        else if(verif_qte==-1)
        {
          printf("\nProduto esgotado. Por favor, escolha outra opção.\n\n");
        }
        else if(verif_qte==-2)
        {
           printf("\nComando inválido. Por favor, insira um dos números indicados.\n\n");
        }
      }
        

      printf("\t\n\nQUARTO PASSO:\n");
      printf("Escolha o tipo de queijo do seu sanduíche!\n");

      impressao_prodtipo(produto, qte_prod_cad, 3);

      while(1)
      {
        scanf(" %d", &escolha);
        verif_qte = check_qte(produto, qte_prod_cad, sanduiche, escolha, 3);
        if(verif_qte==0)
        {
          printf("Agradecemos pela preferência!");
          return 0;
        }
        else if(verif_qte==1)
        {
          break;
        }
        else if(verif_qte==-1)
        {
          printf("\nProduto esgotado. Por favor, escolha outra opção.\n\n");
        }
        else if(verif_qte==-2)
        {
           printf("\nComando inválido. Por favor, insira um dos números indicados.\n\n");
        }
      }
      
      printf("\t\n\nQUINTO PASSO:\n");
      printf("Escolha o tipo de molho do seu sanduíche!/n");

      impressao_prodtipo(produto, qte_prod_cad, 4);

      while(1)
      {
        scanf(" %d", &escolha);
        verif_qte = check_qte(produto, qte_prod_cad, sanduiche, escolha, 4);
        if(verif_qte==0)
        {
          printf("Agradecemos pela preferência!");
          return 0;
        }
        else if(verif_qte==1)
        {
          break;
        }
        else if(verif_qte==-1)
        {
          printf("\nProduto esgotado. Por favor, escolha outra opção.\n\n");
        }
        else if(verif_qte==-2)
        {
           printf("\nComando inválido. Por favor, insira um dos números indicados.\n\n");
        }
      }
      printf("\t\n\nSEXTO PASSO:\n");
      printf("Escolha as verduras que colocará em seu sanduíche (no máximo 3 tipos)!\n");

      impressao_prodtipo(produto, qte_prod_cad, 5);
      
      int continuar = 0;

      while(1)
      {
        scanf(" %d", &escolha);
        verif_qte = check_qte(produto, qte_prod_cad, sanduiche, escolha, 5);
        if(verif_qte==0)
        {
          printf("Agradecemos pela preferência!");
          return 0;
        }
        else if(verif_qte==1)
        {
          sanduiche.salada[verduras] = produto[i];
          verduras += 1;
          if((3 - verduras) > 0)
          {
            do
            {
            printf("\nDeseja pôr mais alguma verdura? (Você ainda pode colocar mais %d!\n\n)", (3 - verduras));
            printf("1 - Sim\n2 - Não\n\n");
            scanf("%i",&continuar);
            getchar();

              if(continuar!=1 && continuar!=2)
              {
                printf("\nComando inválido. Por favor, insira um dos números indicados.\n\n");   
              }
            }while(continuar!=1 && continuar!=2);
            

            if(continuar==2)
            {
              break;
            }
          }
          else
          {
            break;
          }
        }
       else if(verif_qte==-1)
        {
          printf("\nProduto esgotado. Por favor, escolha outra opção.\n\n");
        }
        else
        {
           printf("\nComando inválido. Por favor, insira um dos números indicados.\n\n");
        }
      }
      
      //ATENÇÃO!, DAQUI PARA BAIXO DEIXEI O CÓDIGO COMO ESTAVA.

      if(sanduiche.tamanhopao == 15)
      {
        sanduiche.preco = (sanduiche.recheio.valorv + sanduiche.molho.valorv + sanduiche.queijos.valorv + sanduiche.pao.valorv);
      }
      else if(sanduiche.tamanhopao == 30)
      {
        sanduiche.preco = ((sanduiche.recheio.valorv + sanduiche.molho.valorv + sanduiche.queijos.valorv + sanduiche.pao.valorv) * 2);
      }

      somatorio = somatorio + sanduiche.preco;

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
    if(compra == 1)
    {
      sanduiche.pao.qtd -= 1;
      sanduiche.pao.vendidos += 1;
      sanduiche.pao.totalv += sanduiche.pao.valorv;

      sanduiche.recheio.qtd -= 1;
      sanduiche.recheio.vendidos += 1;
      sanduiche.recheio.totalv += sanduiche.recheio.valorv;

      sanduiche.molho.qtd -= 1;
      sanduiche.molho.vendidos += 1;
      sanduiche.molho.totalv += sanduiche.molho.valorv;

      sanduiche.queijos.qtd -= 1;
      sanduiche.queijos.vendidos += 1;
      sanduiche.queijos.totalv += sanduiche.queijos.valorv;

      for(int i = 0; i < verduras; i++)
      {
        sanduiche.salada[i].qtd -= 1;
        sanduiche.salada[i].vendidos += 1;
        sanduiche.salada[i].totalv += sanduiche.salada[i].valorv;
      }
      
      carrinho[i] = sanduiche;
    }
  }
  cliente->ultimo_sanduiche = sanduiche;

  printf("\nO valor total de sua compra foi: R$ %f\n\nAgradecemos pela preferência!", somatorio);

  return somatorio;
}
