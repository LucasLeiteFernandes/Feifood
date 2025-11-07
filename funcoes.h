typedef struct {
    char email[20];
    char nome[20];
    float valor_total;
    char itens[255];
} Pedido;

typedef struct {
    char nome_alimento[30];
    float nota;
    int n_pedidos;
    char descricao[255];
} alimento;

typedef struct {
    char email[20];
    char nome[20];
    char senha[20];
} usuario;

int menu_login();
int cadastro(char *email, char *nome, char *senha);
int login(char *email, char *nome, char *senha);
int menu_principal();
int verificar_senha(char *senha);
void colocar_alimento();
void imprimir_alimento();
float buscar_alimento(char *nome_comida);
int menu_add_pedido();
int realizar_pedido(Pedido pedido);
void imprimir_pedido(Pedido pedido);
int confirmar_pedido();
int cancelar_pedido(Pedido *pedido, char *itens);
int remover_item(Pedido *pedido);
int avaliar_pedido(float nota, char *itens_pedidos);
void imprimir_alimentos();