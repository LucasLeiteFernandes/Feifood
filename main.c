#include<stdio.h>      // Biblioteca padrão para entrada e saída (printf, scanf)
#include<stdlib.h>     // Biblioteca para funções utilitárias (exit, malloc, etc.)
#include<string.h>     // Biblioteca para manipulação de strings (strcpy, strcat, strcmp, etc.)
#include<ctype.h>      // Biblioteca para funções de caracteres (isupper, islower, etc.)
#include"funcoes.h"    // Arquivo de cabeçalho personalizado que contém as funções implementadas em outro arquivo

int main(){
    int opcao;                                   // Variável para armazenar a escolha do usuário nos menus
    int logado = 1, senha_verificada, tem_item = 1, pedido_realizado;
    // logado → controla se o usuário está logado
    // senha_verificada → resultado da verificação da senha
    // tem_item → indica se há algum item no pedido (1 = não tem, 0 = tem)
    // pedido_realizado → indica se o pedido foi concluído com sucesso

    char email[20], nome[20], senha[20];         // Strings para dados do usuário
    char comida[30], itens[255], copia_pedido[255], copia_itens[255];
    // comida → alimento pesquisado
    // itens → string com descrição dos itens do pedido e seus valores
    // copia_pedido e copia_itens → usadas para armazenar versões simplificadas dos itens (para avaliação)

    float valor_total = 0, valor = 0, nota = 0;  // Valores monetários e nota de avaliação
    Pedido pedido;                               // Estrutura do tipo Pedido (definida em funcoes.h)
    pedido.valor_total = 0;                      // Inicializa o total do pedido
    strcpy(pedido.itens, "");                    // Zera a lista de itens do pedido
    strcpy(copia_pedido, "");                    // Zera a cópia do pedido
    strcpy(copia_itens, "");                     // Zera a cópia dos itens
    
    //colocar_alimento();
    //imprimir_alimento();
    // Essas funções provavelmente preenchem e exibem os alimentos disponíveis no sistema (desativadas por enquanto)

    // ---------- LOOP DE LOGIN ----------
    while (logado != 0){                         // Enquanto o usuário não sair ou logar corretamente
        opcao = menu_login();                    // Mostra o menu de login e lê a opção do usuário

        if (opcao == 1){                         // Opção 1: sair do programa
            printf("Saindo...\n");
            exit(0);

        } else if (opcao == 2){                  // Opção 2: cadastrar novo usuário
            printf("- Cadastrar usuario -\n");
            printf("- Digite seu email: ");
            scanf("%s", &email);

            printf("- Digite seu nome de usuario: ");
            scanf("%s", &nome);

            printf("- Digite sua senha: ");
            scanf("%s", &senha);

            // Verifica se a senha atende aos critérios
            senha_verificada = verificar_senha(senha);
            if (senha_verificada == 0){
                // Enquanto a senha não for válida, pede novamente
                do{
                    printf("- A senha deve conter pelo menos 1 letra maiuscula, 1 minuscula, 1 numero, 1 caractere especial e 8 digitos \n");
                    printf("- Digite sua senha novamente: ");
                    scanf("%s", &senha);
                    senha_verificada = verificar_senha(senha);
                } while (senha_verificada == 0);
            }

            printf("- Cadastro realizado com sucesso. ");
            cadastro(email, nome, senha);         // Registra o usuário no arquivo binário

        } else if (opcao == 3){                  // Opção 3: fazer login
            printf("- Logar usuario -\n");
            printf("- Digite seu email: ");
            scanf("%s", &email);

            printf("- Digite seu nome de usuario: ");
            scanf("%s", &nome);

            printf("- Digite sua senha: ");
            scanf("%s", &senha);

            logado = login(email, nome, senha);   // Tenta autenticar o usuário (retorna 0 se logado)
        }
    }

    // ---------- LOOP PRINCIPAL (PÓS-LOGIN) ----------
    do {
        printf("- %s -\n", nome);                 // Exibe o nome do usuário logado
        opcao = menu_principal();                 // Exibe o menu principal

        if (opcao == 1){                         // Opção 1: sair do sistema
            printf("Saindo...\n");
            exit(0);          

        } else if (opcao == 2){                  // Opção 2: buscar alimento e adicionar ao pedido
            valor = 0;
            printf("\n- Buscar alimento -\n");
            imprimir_alimentos();                 // Mostra todos os alimentos disponíveis
            printf("- Digite o alimento que deseja buscar: ");
            scanf("%s", &comida);

            valor = buscar_alimento(comida);      // Busca o alimento e retorna seu preço
            if (valor != 0){                      // Se o alimento foi encontrado
                opcao = menu_add_pedido();        // Pergunta se quer adicionar ao pedido
                if (opcao == 1){                  // Caso o usuário desista
                    opcao = 0;
                    continue;
                } else if (opcao == 2){           // Caso confirme o pedido
                    printf("Alimento adicionado ao pedido!\n");

                    strcpy(pedido.email, email);  // Associa o pedido ao usuário
                    strcpy(pedido.nome, nome);
                    pedido.valor_total += valor;  // Soma o valor do item ao total

                    // Formata e adiciona o item ao pedido
                    sprintf(itens,"%s,R$%.2f/", comida, valor);
                    strcat(pedido.itens, itens);

                    // Armazena uma cópia simples (sem valor) para avaliação posterior
                    sprintf(copia_itens, "%s/", comida);
                    strcat(copia_pedido, copia_itens);

                    tem_item = 0;                 // Indica que o pedido tem pelo menos um item
                }
            }

        } else if (opcao == 3){                   // Opção 3: revisar e finalizar o pedido
            if (tem_item == 0){                   // Só permite se houver itens no pedido
                imprimir_pedido(pedido);          // Mostra o pedido atual
                int confirmacao = confirmar_pedido();  // Pergunta o que o usuário quer fazer com o pedido

                if (confirmacao == 2){            // Confirmar pedido
                    pedido_realizado = realizar_pedido(pedido);
                    cancelar_pedido(&pedido, itens);   // Limpa o pedido após finalizar

                } else if(confirmacao == 1){       // Voltar
                    continue;

                } else if (confirmacao == 3){      // Remover item do pedido
                    remover_item(&pedido);

                } else if (confirmacao == 4){      // Cancelar todo o pedido
                    int pedido_cancelado = cancelar_pedido(&pedido, itens);
                    if (pedido_cancelado == 0){
                        printf("Pedido cancelado\n");
                    }
                }

                if (pedido_realizado == 0){        // Mensagem de sucesso
                    printf("Pedido realizado com sucesso!\n");
                } 
            } else {
                printf("Nenhum item foi adicionado a sacola!\n");
            }

        } else if (opcao == 4){                   // Opção 4: avaliar pedido
            printf("Avaliar pedido\n");
            if (tem_item == 0){                   // Só permite se o usuário tiver feito um pedido
                do {
                    printf("Digite o valor da nota para todos os itens pedidos (0 a 5): ");
                    scanf("%f", &nota);
                } while (nota < 0 || nota > 5);   // Validação da nota
                
                avaliar_pedido(nota, copia_pedido); // Registra a avaliação
                printf("Pedido avaliado!\n");
            } else {
                printf("Nenhum pedido foi realizado!\n");
            }
            tem_item = 1;                         // Reseta a flag de itens (novo pedido começa vazio)
        }

    } while (opcao != 1);                         // Continua até o usuário escolher sair

    return 0;                                     // Fim do programa
}
