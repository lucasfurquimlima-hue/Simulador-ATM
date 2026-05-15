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