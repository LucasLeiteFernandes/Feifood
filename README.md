# Feifood
Projeto de desenvolvimento de algoritos do 2° semestre de 2025
Perfeito 👍
Aqui está o **README.md** formatado e limpo — você pode **copiar e colar diretamente** no GitHub sem precisar ajustar nada.

---

# 🍔 Sistema de Pedidos de Alimentos em C

Um sistema de pedidos de alimentos desenvolvido em **C**, utilizando **arquivos binários** para armazenar usuários, alimentos e pedidos.
O sistema permite **cadastro, login, criação de pedidos, cancelamento, remoção de itens e avaliação** dos pedidos realizados.

---

## 📁 Estrutura do Projeto

```
📦 projeto-pedidos
 ┣ 📜 main.c
 ┣ 📜 funcoes.c
 ┣ 📜 funcoes.h
 ┣ 📜 usuarios.bin
 ┣ 📜 alimentos.bin
 ┣ 📜 pedidos.bin
 ┗ 📜 README.md
```

---

## ⚙️ Instalação e Execução

### 🔧 Pré-requisitos

Certifique-se de ter o compilador GCC instalado:

```bash
gcc --version
```

Se não tiver, instale com:

```bash
sudo apt install build-essential
```

No Windows, você pode usar o **MinGW** ou **Code::Blocks**.

---

### 🚀 Compilação

No terminal, dentro da pasta do projeto, compile os arquivos:

```bash
gcc main.c funcoes.c -o sistema
```

Em seguida, execute o programa:

```bash
./sistema
```

---

## 🧠 Estrutura Lógica

O sistema é dividido em duas partes principais:

1. **funcoes.c / funcoes.h** → Contêm todas as funções auxiliares (cadastro, login, manipulação de arquivos, etc.)
2. **main.c** → Contém o fluxo principal do programa, menus e interações com o usuário.

---

# 🧩 FUNÇÕES (funcoes.c)

### `int verificar_senha(char *senha)`

Verifica se a senha inserida atende aos critérios de segurança:

* Mínimo de 8 caracteres
* Pelo menos uma letra maiúscula
* Pelo menos uma letra minúscula
* Pelo menos um número
* Pelo menos um caractere especial

**Retorno:**
✅ `1` → senha válida
❌ `0` → senha inválida

---

### `int cadastro(char *email, char *nome, char *senha)`

Realiza o **cadastro de um novo usuário**, salvando suas informações em um arquivo binário (`usuarios.bin`).

**Retorno:**
✅ `0` → cadastro realizado com sucesso

---

### `int login(char *email, char *nome, char *senha)`

Verifica as credenciais do usuário comparando com os registros salvos em `usuarios.bin`.

**Retorno:**
✅ `0` → login bem-sucedido
❌ `1` → credenciais incorretas

---

### `void colocar_alimento()`

Adiciona manualmente alimentos e seus valores no arquivo `alimentos.bin`.
Normalmente usada apenas uma vez para preencher o banco inicial.

---

### `void imprimir_alimentos()`

Exibe todos os alimentos disponíveis no sistema com seus respectivos preços.

---

### `float buscar_alimento(char *nome)`

Procura um alimento pelo nome no arquivo `alimentos.bin` e retorna seu valor.

**Retorno:**

* Valor do alimento encontrado
* `0` se o alimento não for encontrado

---

### `int menu_login()`

Exibe o menu inicial com as opções:

1. Sair
2. Cadastrar
3. Logar

**Retorno:** número da opção escolhida.

---

### `int menu_principal()`

Exibe o menu após o login:

1. Sair
2. Buscar alimento
3. Finalizar pedido
4. Avaliar pedido

**Retorno:** número da opção escolhida.

---

### `int menu_add_pedido()`

Exibe as opções após encontrar um alimento:

1. Voltar
2. Adicionar ao pedido

---

### `void imprimir_pedido(Pedido pedido)`

Exibe todos os itens adicionados ao pedido e o valor total acumulado.

---

### `int confirmar_pedido()`

Exibe o menu de confirmação do pedido:

1. Voltar
2. Confirmar pedido
3. Remover item
4. Cancelar pedido

**Retorno:** número da opção selecionada.

---

### `int realizar_pedido(Pedido pedido)`

Finaliza o pedido e grava as informações no arquivo `pedidos.bin`.

**Retorno:**
✅ `0` → pedido realizado com sucesso

---

### `int remover_item(Pedido *pedido)`

Remove um item específico do pedido atual.
O usuário informa o nome do alimento a ser removido.

---

### `int cancelar_pedido(Pedido *pedido, char *itens)`

Cancela o pedido atual, limpando os itens e zerando o valor total.

**Retorno:**
✅ `0` → pedido cancelado com sucesso

---

### `void avaliar_pedido(float nota, char *itens)`

Registra a nota (de 0 a 5) dada pelo usuário aos itens do último pedido.
As avaliações podem ser armazenadas em um arquivo separado (ex: `avaliacoes.txt`).

---

# 💻 MAIN.C (Fluxo Principal)

A função `main()` coordena toda a lógica do programa, dividida em **duas grandes fases**:

---

## 🟢 1. Login e Cadastro

Enquanto o usuário não estiver logado (`logado != 0`):

* O menu de login é mostrado (`menu_login()`).
* O usuário pode:

  * **Sair**
  * **Cadastrar** (chama `cadastro()`)
  * **Logar** (chama `login()`)

Após o login bem-sucedido (`logado = 0`), o programa avança para o menu principal.

---

## 🟡 2. Menu Principal (após login)

O usuário tem as opções:

### **1. Sair**

Encerra o programa.

### **2. Buscar alimento**

* Exibe os alimentos disponíveis (`imprimir_alimentos()`).
* Permite buscar por nome (`buscar_alimento()`).
* Caso encontrado, o usuário pode adicioná-lo ao pedido (`pedido.itens` e `pedido.valor_total`).

### **3. Finalizar pedido**

* Mostra os itens do pedido (`imprimir_pedido()`).
* Permite confirmar, remover ou cancelar o pedido.
* Se confirmado, grava o pedido (`realizar_pedido()`).

### **4. Avaliar pedido**

* O usuário dá uma nota de **0 a 5** aos itens do último pedido (`avaliar_pedido()`).

---

## 🧾 Estrutura do Pedido (`struct Pedido`)

Definida em `funcoes.h`:

```c
typedef struct {
    char email[20];
    char nome[20];
    char itens[255];
    float valor_total;
} Pedido;
```

---

# 🧪 Exemplo de Uso

### 1. Rodar o programa

```bash
./sistema
```

### 2. Menu de Login

```
1 - Sair
2 - Cadastrar
3 - Logar
```

### 3. Menu Principal

```
1 - Sair
2 - Buscar alimento
3 - Finalizar pedido
4 - Avaliar pedido
```

---

# 🧰 Tecnologias Utilizadas

* Linguagem: **C**
* Armazenamento: **Arquivos binários**
* Compilador: **GCC**
* Estrutura modular: `main.c`, `funcoes.c`, `funcoes.h`

---

# 👨‍💻 Autor

**Lucas Leite**
Projeto acadêmico desenvolvido para fins de estudo da linguagem C, manipulação de arquivos e lógica de programação estruturada.

---

# 🪪 Licença

Este projeto está licenciado sob a [MIT License](LICENSE).

---

✅ **Dica:** se quiser deixar o README mais visual, adicione um diagrama de fluxo (ex: com [Mermaid](https://mermaid.js.org/)) mostrando o caminho **Cadastro → Login → Pedido → Avaliação**.
Posso gerar esse diagrama pra você se quiser. Deseja que eu adicione ele aqui?
