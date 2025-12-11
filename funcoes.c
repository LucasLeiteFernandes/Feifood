#include<stdio.h>
#include<string.h>
#include<ctype.h>

// Estrutura para armazenar dados de um usuário
typedef struct {
    char email[20];
    char nome[20];
    char senha[20];
} usuario;

// Estrutura para armazenar informações de um alimento
typedef struct {
    char nome_alimento[30];
    char descricao[255];
    int n_pedidos;
    float preco;
    float nota;
} alimento;

// Estrutura para armazenar informações de um pedido feito por um usuário
typedef struct {
    char email[20];
    char nome[20];
    float valor_total;
    char itens[255];
} Pedido;

// Função que insere alimentos pré-definidos no arquivo binário "alimentos.bin"
void colocar_alimento() {
    FILE *alimentos = fopen("alimentos.bin", "ab");
    if (alimentos == NULL) {
        printf("erro ao abrir o arquivo!\n");
        return;
    }

    alimento comida;

    // A seguir, são adicionados vários alimentos fixos com nome, descrição, nota, preço e número de pedidos
    strcpy(comida.nome_alimento, "Pizza");
    strcpy(comida.descricao, "Queijo,Catupiry,Tomate");
    comida.nota = 25.00;
    comida.preco = 25.90;
    comida.n_pedidos = 5;
    fwrite(&comida, sizeof(alimento), 1, alimentos);

    strcpy(comida.nome_alimento, "Hamburguer");
    strcpy(comida.descricao, "Pao,Carne,Queijo,Alface,Tomate");
    comida.nota = 30.00;
    comida.preco = 18.50;
    comida.n_pedidos = 8;
    fwrite(&comida, sizeof(alimento), 1, alimentos);

    strcpy(comida.nome_alimento, "Batata-Frita");
    strcpy(comida.descricao, "Batata,Sal,Queijo");
    comida.nota = 20.00;
    comida.preco = 12.00;
    comida.n_pedidos = 6;
    fwrite(&comida, sizeof(alimento), 1, alimentos);

    strcpy(comida.nome_alimento, "Refrigerante-Lata");
    strcpy(comida.descricao, "Bebida-Gaseificada,350ml");
    comida.nota = 15.00;
    comida.preco = 6.50;
    comida.n_pedidos = 10;
    fwrite(&comida, sizeof(alimento), 1, alimentos);

    strcpy(comida.nome_alimento, "Suco-Natural");
    strcpy(comida.descricao, "Laranja,Acucar,Gelo");
    comida.nota = 28.00;
    comida.preco = 9.90;
    comida.n_pedidos = 7;
    fwrite(&comida, sizeof(alimento), 1, alimentos);

    strcpy(comida.nome_alimento, "Pastel-de-Carne");
    strcpy(comida.descricao, "Massa,Carne,Tempero,Queijo");
    comida.nota = 22.00;
    comida.preco = 8.50;
    comida.n_pedidos = 12;
    fwrite(&comida, sizeof(alimento), 1, alimentos);

    strcpy(comida.nome_alimento, "Cachorro-Quente");
    strcpy(comida.descricao, "Pao,Salsicha,Maionese,Batata-Palha");
    comida.nota = 26.00;
    comida.preco = 11.00;
    comida.n_pedidos = 9;
    fwrite(&comida, sizeof(alimento), 1, alimentos);

    strcpy(comida.nome_alimento, "Lasanha-Bolonhesa");
    strcpy(comida.descricao, "Massa,Carne-Moida,Molho,Queijo");
    comida.nota = 35.00;
    comida.preco = 29.90;
    comida.n_pedidos = 4;
    fwrite(&comida, sizeof(alimento), 1, alimentos);

    strcpy(comida.nome_alimento, "Salada-Caesar");
    strcpy(comida.descricao, "Alface,Frango,Queijo,Croutons");
    comida.nota = 18.00;
    comida.preco = 15.00;
    comida.n_pedidos = 7;
    fwrite(&comida, sizeof(alimento), 1, alimentos);

    strcpy(comida.nome_alimento, "Sorvete-de-Chocolate");
    strcpy(comida.descricao, "Chocolate,Leite,Acucar,Gelo");
    comida.nota = 24.00;
    comida.preco = 7.50;
    comida.n_pedidos = 6;
    fwrite(&comida, sizeof(alimento), 1, alimentos);

    strcpy(comida.nome_alimento, "Hamburguer-de-siri");
    strcpy(comida.descricao, "?????? ?? ??????,??????,??????,??????,?????? ??????");
    comida.nota = 34.00;
    comida.preco = 49.50;
    comida.n_pedidos = 7;
    fwrite(&comida, sizeof(alimento), 1, alimentos);

    fclose(alimentos);
    printf("Alimentos adicionados com sucesso!\n");
}

// Função que lê e imprime os alimentos do arquivo binário para verificações
void imprimir_alimento(){
    FILE *alimentos = fopen("alimentos.bin", "rb");
    if (alimentos == NULL) printf("erro");

    alimento comida;
    int i = 0;

    while (fread(&comida, sizeof(alimento), 1, alimentos) == 1) {
        i++;
        printf("\n%d alimento lido\n", i);
        printf("-  %s\n", comida.nome_alimento);
        printf("- Preco: %.2f\n", comida.preco);
        printf("- Nota: %.2f\n", comida.nota);
        printf("- Nota(media): %.2f\n", comida.nota / comida.n_pedidos);
        printf("- Quantidade de pedidos: %d\n", comida.n_pedidos);
        printf("descricao: %s\n", comida.descricao);
    }

    fclose(alimentos);
}

// Exibe menu inicial de login/cadastro
int menu_login(){
    int opcao;
    do {
        printf("\n");
        printf("1 - Sair\n");
        printf("2 - Cadastrar usuario\n");
        printf("3 - Logar\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);
    } while (opcao < 1 || opcao > 3);
    return opcao;
}

// Exibe o menu principal após login
int menu_principal(){
    int opcao;
    do {
        printf("\n");
        printf("1 - Sair \n");
        printf("2 - Buscar alimento\n");
        printf("3 - Gerenciar pedido\n");
        printf("4 - Avaliar pedido\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);
    } while (opcao < 1 || opcao > 4);
    return opcao;
}

// Verifica se a senha é forte (contém letras maiúsculas, minúsculas, dígitos, caractere especial e tem 8+ caracteres)
int verificar_senha(char *senha) {
    int tem_maiuscula = 0, tem_minuscula = 0;
    int tem_digito = 0, tem_especial = 0;
    int t = strlen(senha);

    for (int i = 0; senha[i] != '\0'; i++) {
        if (isupper(senha[i])) tem_maiuscula = 1;
        else if (islower(senha[i])) tem_minuscula = 1;
        else if (isdigit(senha[i])) tem_digito = 1;
        else if (strchr("!@#$%^&*", senha[i])) tem_especial = 1;
    }
    if (tem_maiuscula && tem_minuscula && tem_digito && tem_especial && t >= 8)
        return 1;
    else
        return 0;
}

// Salva um novo usuário no arquivo binário
int cadastro(char *email, char *nome, char *senha){
    FILE *usuarios = fopen("usuarios.bin", "ab");
    if (usuarios == NULL) return 1;

    usuario user;
    strcpy(user.email, email);
    strcpy(user.nome, nome);
    strcpy(user.senha, senha);

    fwrite(&user, sizeof(usuario), 1, usuarios);
    fclose(usuarios);

    return 0;
}

// Faz o login de um usuário comparando dados com o arquivo binário
int login(char *email, char *nome, char *senha){
    FILE *usuarios = fopen("usuarios.bin", "rb");
    if (usuarios == NULL) return 1;

    usuario user;
    while (fread(&user, sizeof(usuario), 1, usuarios) == 1) {
        if (strcmp(user.email, email) == 0 && strcmp(user.nome, nome) == 0 && strcmp(user.senha, senha) == 0) {
            fclose(usuarios);
            printf("Entrando...\n\n");
            return 0;
        }
    }

    fclose(usuarios);
    printf("Usuario nao encontrado\n");
    return 1;
}

// Imprime lista de ingredientes separados por vírgulas, um por linha
void imprimir_ingredientes(char *ingredientes){
    int i, len = strlen(ingredientes);
    for (i = 0; i < len; i++) {
        if (ingredientes[i] == ',')
            printf(";\n- ");
        else
            printf("%c", ingredientes[i]);
    }
    printf(";");
}

// Busca um alimento pelo nome e exibe seus detalhes
float buscar_alimento(char *nome_comida){
    FILE *alimentos = fopen("alimentos.bin", "rb");
    if (alimentos == NULL) printf("erro");

    alimento comida;
    while (fread(&comida, sizeof(alimento), 1, alimentos) == 1) {
        if (strcmp(comida.nome_alimento, nome_comida) == 0){
            printf("\n================================\n");
            printf("- %s -\n", comida.nome_alimento);
            printf("--------------------------------\n");
            printf("- Preco:                R$%.2f\n", comida.preco);
            printf("- Nota:                 %.2f/5\n", comida.nota / comida.n_pedidos);
            printf("- Qntd de pedidos:      %d\n", comida.n_pedidos);
            printf("--------------------------------\n");
            printf("- Ingredientes:\n- ");
            imprimir_ingredientes(comida.descricao);
            printf("\n================================\n\n");
            fclose(alimentos);
            return comida.preco;
        }
    }
    
    fclose(alimentos);
    printf("\n- Alimento nao encontrado!\n");
    return 0;
}

// Lista todos os alimentos cadastrados com nome, preço e nota média
void imprimir_alimentos(){
    FILE *alimentos = fopen("alimentos.bin", "rb");
    if (alimentos == NULL) printf("erro");
    int t = 22, i, len;

    alimento comida;
    printf("=======================================================\n");
    printf("-                  Buscar alimento                    -\n");
    printf("=======================================================\n");
    printf("-                 Lista de Alimentos                  -\n");
    printf("-------------------------------------------------------\n");
    printf("- Nome                   Preco                 Nota   -\n");
    while (fread(&comida, sizeof(alimento), 1, alimentos) == 1) {
        printf("- %s ", comida.nome_alimento);
        len = strlen(comida.nome_alimento);
        for (i = 0; i < t - len; i++){
            printf(" ");
        } printf("R$%.2f ", comida.preco);
        if (comida.preco > 10 && comida.preco < 100){
            for (i = 0; i < 14; i++){
                printf(" ");
            }
        } else if (comida.preco < 10){
            for (i = 0; i < 15; i++){
                printf(" ");
            }
        } printf("%.2f/5 -\n", comida.nota / comida.n_pedidos);
    }
    printf("=======================================================\n\n");
    fclose(alimentos);
}

// Menu para adicionar itens ao pedido
int menu_add_pedido(){
    int opcao;
    printf("1 - voltar\n");
    printf("2 - Adicionar ao pedido: ");
    printf("\nEscolha uma opcao: ");
    scanf("%d", &opcao);
    return opcao;
}

// Imprime as informações completas de um pedido
void imprimir_pedido(Pedido pedido){
    int i, len = strlen(pedido.itens);
    int t = 28, tItemAtual = 0, tSub = 0, a;
    printf("=======================================\n");
    printf("- Nome: %s\n", pedido.nome);
    printf("- Email: %s\n", pedido.email);
    printf("=======================================\n");
    printf("- Item                        Preco   -\n");
    printf("---------------------------------------\n- ");

    for (i = 0; i < len; i++) {
        if (pedido.itens[i] == ','){   
            for (a = 0; a < t - tSub; a++) 
                printf(" ");
        } else if(i == len - 1){
            printf(" -\n");
        } else if (pedido.itens[i] == '/'){
            printf(" -\n- ");
            tSub = 0;
        } else {
            printf("%c", pedido.itens[i]);
            tSub++;
        }
    }
    printf("=======================================\n");
    printf("- Total                       R$%.2f -\n", pedido.valor_total);
    printf("=======================================\n\n");
}

// Grava o pedido no arquivo binário
int realizar_pedido(Pedido pedido){
    FILE *pedidos = fopen("pedidos.bin", "ab");
    if (pedidos == NULL) return 1;

    fwrite(&pedido, sizeof(Pedido), 1, pedidos);
    fclose(pedidos);
    return 0;
}

// Menu para confirmar ou cancelar o pedido
int confirmar_pedido(){
    int opcao;
    printf("- Deseja realizar o pedido?\n");
    printf("1 - Voltar\n");
    printf("2 - Realizar pedido\n");
    printf("3 - Remover item\n");
    printf("4 - Cancelar pedido\n");
    printf("\nEscolha uma opcao: ");
    scanf("%d", &opcao);
    return opcao;
}

// Cancela um pedido limpando os campos da struct
int cancelar_pedido(Pedido *pedido, char *itens){
    strcpy(pedido->email, "");
    strcpy(pedido->nome, "");
    pedido->valor_total = 0;
    strcpy(itens,"");
    strcpy(pedido->itens,"");
    return 0;
}

// Remove um item específico do pedido e atualiza o valor total
int remover_item(Pedido *pedido) {
    FILE *alimentos = fopen("alimentos.bin", "rb");
    if (alimentos == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return 1;
    }

    alimento comida;
    char item_remover[30];
    char novo_itens[255] = "";
    char item_atual[100] = "";
    int i = 0, j = 0, len = strlen(pedido->itens);
    int encontrado = 0;

    printf("\n- Digite o nome do item que deseja remover: ");
    scanf(" %s", item_remover);

    // Busca o item no arquivo de alimentos para obter o preço
    while (fread(&comida, sizeof(alimento), 1, alimentos) == 1) {
        if (strcmp(comida.nome_alimento, item_remover) == 0) {
            encontrado = 1;
            break;
        }
    }
    fclose(alimentos);

    if (!encontrado) {
        printf("Item não está no pedido.\n");
        return 1;
    }

    // Reconstrói a string de itens removendo o escolhido
    for (i = 0; i <= len; i++) {
        if (pedido->itens[i] == '/' || pedido->itens[i] == '\0') {
            item_atual[j] = '\0';
            if (strstr(item_atual, item_remover) == NULL) {
                strcat(novo_itens, item_atual);
                if (pedido->itens[i] != '\0')
                    strcat(novo_itens, "/");
            } else {
                pedido->valor_total -= comida.preco;
            }
            j = 0;
            item_atual[0] = '\0';
        } else {
            item_atual[j++] = pedido->itens[i];
        }
    }

    if (novo_itens[strlen(novo_itens) - 1] == '/'){
        novo_itens[strlen(novo_itens) - 1] = '\0';
    }

    strcpy(pedido->itens, novo_itens);
    printf("\nItem removido com sucesso!\n");
    printf("Novo valor total: R$%.2f\n", pedido->valor_total);
    return 0;
}

// Atualiza as notas dos alimentos com base na avaliação de um pedido
int avaliar_pedido(float nota, char *itens_pedidos) {
    FILE *alimentos = fopen("alimentos.bin", "rb+");
    if (alimentos == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    alimento comida;
    char nome_comida[30];
    int i, j = 0;
    int lenPedido = strlen(itens_pedidos);

    // Percorre cada item do pedido separado por '/'
    for (i = 0; i < lenPedido; i++) {
        if (itens_pedidos[i] == '/') {
            nome_comida[j] = '\0';
            rewind(alimentos);

            // Atualiza a nota e o número de pedidos do alimento correspondente
            while (fread(&comida, sizeof(alimento), 1, alimentos) == 1) {
                if (strcmp(comida.nome_alimento, nome_comida) == 0) {
                    comida.nota += nota;
                    comida.n_pedidos++;
                    fseek(alimentos, -sizeof(alimento), SEEK_CUR);
                    fwrite(&comida, sizeof(alimento), 1, alimentos);
                    break;
                }
            }
            j = 0;
            nome_comida[0] = '\0';
        } else {
            nome_comida[j++] = itens_pedidos[i];
        }
    }

    fclose(alimentos);
    return 0;
}
