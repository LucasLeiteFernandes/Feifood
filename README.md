Perfeito 💪
Aqui está um **README.md completo**, no formato ideal para o GitHub — com explicação de **instalação, execução, descrição de todas as funções (do arquivo `funcoes.c` e `funcoes.h`)**, e **explicação detalhada do fluxo da `main.c`**.

---

````markdown
# 🍔 FEIFOOD

Este projeto é um **sistema de gerenciamento de pedidos de restaurante**, feito em **linguagem C**, com **armazenamento em arquivos binários**.  
Permite **cadastro e login de usuários**, **busca e adição de alimentos**, **criação e cancelamento de pedidos**, além de **avaliação dos pedidos realizados**.

---

## 📦 Instalação e Execução

### 🔹 1. Clonar o repositório

```bash
git clone https://github.com/seuusuario/sistema-pedidos.git
cd sistema-pedidos
````

### 🔹 2. Compilar o projeto

Use o compilador GCC:

```bash
gcc main.c funcoes.c -o pedidos
```

### 🔹 3. Executar o programa

```bash
./pedidos
```

---

## 🧠 Estrutura do Projeto

```
sistema-pedidos/
├── main.c          # Arquivo principal com o fluxo do programa
├── funcoes.c       # Implementação das funções auxiliares
├── funcoes.h       # Declaração das funções e estruturas
└── alimentos.bin   # (gerado automaticamente) Base de dados de alimentos
```

---

## ⚙️ Estruturas e Funções

### 🔸 Estrutura `Pedido`

Declarada em `funcoes.h`:

```c
typedef struct {
    char email[50];
    char nome[50];
    char itens[255];
    float valor_total;
} Pedido;
```

Representa um pedido realizado por um usuário, com:

* `email` → email do cliente;
* `nome` → nome do cliente;
* `itens` → lista de itens adicionados ao pedido;
* `valor_total` → soma total dos valores dos alimentos.

---

## 🔧 Funções — Arquivo `funcoes.c`

Abaixo estão as principais funções que compõem o sistema.

---

### 🧩 `int menu_login(void)`

Exibe o menu de login inicial:

```
1 - Sair
2 - Cadastrar usuário
3 - Fazer login
```

Retorna a opção escolhida pelo usuário.

---

### 🧩 `int menu_principal(void)`

Exibe o menu principal após o login:

```
1 - Sair
2 - Buscar alimento
3 - Visualizar pedido
4 - Avaliar pedido
```

Retorna a opção selecionada.

---

### 🧩 `int menu_add_pedido(void)`

Mostra um menu perguntando se o usuário quer adicionar o alimento ao pedido:

```
1 - Cancelar
2 - Adicionar ao pedido
```

Retorna a escolha feita.

---

### 🧩 `int confirmar_pedido(void)`

Pergunta o que o usuário quer fazer com o pedido atual:

```
1 - Voltar
2 - Confirmar pedido
3 - Remover item
4 - Cancelar pedido
```

Retorna a escolha feita.

---

### 🧩 `int verificar_senha(char *senha)`

Valida a senha informada pelo usuário.
Critérios:

* Mínimo 8 caracteres;
* Pelo menos uma letra maiúscula;
* Uma letra minúscula;
* Um número;
* Um caractere especial.

Retorna:

* `1` → senha válida;
* `0` → senha inválida.

---

### 🧩 `int cadastro(char *email, char *nome, char *senha)`

Registra um novo usuário no arquivo `usuarios.bin`.

Grava:

* Email,
* Nome de usuário,
* Senha criptografada (ou direta, dependendo da implementação).

Retorna `0` em caso de sucesso.

---

### 🧩 `int login(char *email, char *nome, char *senha)`

Valida o login do usuário comparando com os dados em `usuarios.bin`.

Retorna:

* `0` → login bem-sucedido;
* `1` → falha no login (usuário ou senha incorretos).

---

### 🧩 `void imprimir_alimentos(void)`

Lê e exibe todos os alimentos cadastrados no arquivo `alimentos.bin`.

Formato exibido:

```
Nome: X | Preço: R$Y
```

---

### 🧩 `float buscar_alimento(char *nome)`

Procura um alimento pelo nome dentro do arquivo `alimentos.bin`.
Se encontrado, retorna o valor do alimento.
Se não existir, retorna `0`.

---

### 🧩 `int realizar_pedido(Pedido pedido)`

Registra o pedido no arquivo `pedidos.bin`, com:

* Nome do cliente,
* Itens,
* Valor total.

Retorna `0` se o pedido foi gravado com sucesso.

---

### 🧩 `void imprimir_pedido(Pedido pedido)`

Mostra na tela o conteúdo atual do pedido:

```
Itens:
 - X
 - Y
Valor total: R$Z
```

---

### 🧩 `int remover_item(Pedido *pedido)`

Permite ao usuário remover um alimento específico da lista `pedido->itens`.
Atualiza o valor total automaticamente.
Retorna `0` se o item foi removido com sucesso.

---

### 🧩 `int cancelar_pedido(Pedido *pedido, char *itens)`

Cancela todo o pedido atual, limpando:

* Lista de itens,
* Valor total.

Retorna `0` em caso de sucesso.

---

### 🧩 `void avaliar_pedido(float nota, char *copia_pedido)`

Registra uma avaliação dos itens do pedido (nota de 0 a 5) em `avaliacoes.bin`.
A string `copia_pedido` contém apenas os nomes dos itens avaliados.

---

## 🧭 Fluxo da Aplicação — `main.c`

A função `main()` organiza todo o funcionamento do sistema:

1. **Login ou Cadastro:**

   * Usuário pode cadastrar nova conta ou logar.
   * Senhas são validadas antes do cadastro.
   * Enquanto `logado != 0`, o usuário fica no menu de login.

2. **Menu Principal:**

   * Após o login, o sistema mostra o menu principal com 4 opções:

     * Sair;
     * Buscar alimento;
     * Visualizar pedido;
     * Avaliar pedido.

3. **Busca e Adição de Alimentos:**

   * Exibe os alimentos cadastrados (`imprimir_alimentos()`).
   * Permite buscar um alimento e adicioná-lo ao pedido (`buscar_alimento()`).

4. **Gerenciamento do Pedido:**

   * Usuário pode visualizar o pedido atual (`imprimir_pedido()`).
   * Confirmar o pedido (`realizar_pedido()`).
   * Remover itens (`remover_item()`).
   * Cancelar o pedido (`cancelar_pedido()`).

5. **Avaliação:**

   * Após concluir o pedido, o usuário pode avaliá-lo (`avaliar_pedido()`).
   * O sistema armazena as notas de 0 a 5 associadas aos itens do pedido.

6. **Encerramento:**

   * O programa finaliza ao escolher a opção “Sair”.

---

## 🗂️ Arquivos de Dados Gerados

| Arquivo          | Descrição                                   |
| ---------------- | ------------------------------------------- |
| `usuarios.bin`   | Guarda os dados dos usuários cadastrados    |
| `alimentos.bin`  | Contém o catálogo de alimentos disponíveis  |
| `pedidos.bin`    | Armazena os pedidos realizados              |
| `avaliacoes.bin` | Registra as notas atribuídas pelos usuários |

---

## 🧑‍💻 Exemplo de Uso

```bash
$ ./pedidos

- Menu de Login -
1 - Sair
2 - Cadastrar usuário
3 - Fazer login
> 2

Digite seu email: lucas@email.com
Digite seu nome: lucas
Digite sua senha: Lucas@123
Cadastro realizado com sucesso.

- Menu Principal -
1 - Sair
2 - Buscar alimento
3 - Visualizar pedido
4 - Avaliar pedido
```

---

## 🧩 Autor

**Lucas Leite**
💻 Desenvolvedor C e criador deste sistema.

---

## 📜 Licença

Este projeto está sob a licença MIT — veja o arquivo [LICENSE](LICENSE) para mais detalhes.

```

---

Quer que eu gere também a **versão com tabela de funções e descrições técnicas (parâmetros e retorno)**, no estilo documentação técnica de API (ex: `verificar_senha(char *senha)` → parâmetros, retorno, uso)? Isso deixaria o README mais profissional.
```
