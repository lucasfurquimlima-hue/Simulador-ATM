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