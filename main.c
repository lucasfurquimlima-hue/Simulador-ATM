#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

// Definição de constantes
#define PIN_CORRETO "1234"

// Protótipos das funções (declaração para o compilador conhecer as funções)
void exibirMenu();
void realizarDeposito(float *saldo);
void realizarSaque(float *saldo);
void consultarSaldo(float saldo);
int verificarSenha();

int main() {
    float saldo = 0.0;
    int opcao;

    printf("--- BEM-VINDO AO SISTEMA ATM ---\n");

    // Validação de segurança inicial
    if (!verificarSenha()) {
        printf("\nAcesso bloqueado. Senha incorreta.\n");
        return 0; // Encerra o programa se a senha estiver errada
    }

    do {
        exibirMenu();
        printf("Escolha uma opcao: ");

        // Verifica se a entrada é um número para evitar loops infinitos
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida! Use apenas numeros.\n");
            while (getchar() != '\n'); 
            continue;
        }

        switch (opcao) {
            case 1:
                consultarSaldo(saldo);
                break;
            case 2:
                realizarDeposito(&saldo);
                break;
            case 3:
                realizarSaque(&saldo);
                break;
            case 4:
                printf("\nEncerrando sistema... Ate logo!\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}

// --- IMPLEMENTAÇÃO DAS FUNÇÕES ---

void exibirMenu() {
    printf("\n---------- MENU ----------\n");
    printf("1. Consultar Saldo\n");
    printf("2. Deposito\n");
    printf("3. Saque\n");
    printf("4. Sair\n");
    printf("--------------------------\n");
}

void consultarSaldo(float saldo) {
    printf("\n>>> Saldo atual: R$ %.2f\n", saldo);
}

void realizarDeposito(float *saldo) {
    float valor;
    printf("Digite o valor do deposito: R$ ");
    scanf("%f", &valor);
    if (valor > 0) {
        *saldo += valor;
        printf("Sucesso: R$ %.2f adicionados.\n", valor);
    } else {
        printf("Erro: Valor de deposito deve ser positivo.\n");
    }
}

void realizarSaque(float *saldo) {
    float valor;
    printf("Digite o valor do saque: R$ ");
    scanf("%f", &valor);
    if (valor > 0 && valor <= *saldo) {
        *saldo -= valor;
        printf("Sucesso: Retire seu dinheiro abaixo.\n");
    } else if (valor > *saldo) {
        printf("Erro: Saldo insuficiente (Saldo atual: R$ %.2f).\n", *saldo);
    } else {
        printf("Erro: Valor invalido.\n");
    }
}

int verificarSenha() {
    char senha_digitada[20];
    printf("Digite sua senha de 4 digitos: ");
    scanf("%s", senha_digitada);

    // Agora o strcmp funcionará corretamente
    if (strcmp(senha_digitada, PIN_CORRETO) == 0) {
        return 1; // Senha correta
    } else {
        return 0; // Senha incorreta
    }
}