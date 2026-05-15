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