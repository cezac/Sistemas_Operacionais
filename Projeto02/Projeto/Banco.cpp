//
// Created by Caio- on 15/11/2022.
//

#include "Banco.h"
#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"
#include "sys/types.h"
#include "signal.h"
#include "sched.h"
#include <iostream>


// Funcao para trasnferir o dinheiro de uma conta a outra
int transferencia(int quant, int quantTransfer){
    conta clienteA; // Criando a contaA
    conta clienteB; // Criando a contaB

    clienteA.saldo = 1000; // Definindo saldo padrao
    clienteB.saldo = 0; // Definindo saldo padrao
    clienteA.tentativas = 0; // Definindo o n° de tentativas padrao
    clienteB.tentativas = 0; // Definindo o n° de tentativas padrao

    for (int i =0; i<quantTransfer; i++){

        if(clienteA.saldo >=quant){ // Se o saldo do clienteA for igual ou maior ao valor da transferencia

            std::cout << std::endl << "Transferencia Concluida com Sucesso" << std::endl;

            clienteA.saldo -= quant;
            clienteA.tentativas +=1;
            std::cout << "Saldo da conta A = " << clienteA.saldo << std::endl;
            std::cout << "Transferencias Executadas na conta A = " << clienteA.tentativas << std::endl << std::endl;

            clienteB.saldo +=quant;
            clienteB.tentativas +=1;
            std::cout << "Saldo da conta B = " << clienteB.saldo << std::endl;
            std::cout << "Transferencias Executadas na conta B = " << clienteB.tentativas << std::endl << std::endl;
        }
        else { // Se o saldo do clienteA for infeiror ao valor
            std::cout << std::endl << " ERRO DE TRANSFENCIA: ";
            std::cout << std::endl << " Falta de Saldo " << std::endl;
        }
    }

    return 0;
}

int main() {

    conta clienteA, clienteB;

    pid_t thread;
    int i;
    int valorTransacao;

    valorTransacao += 100;

    size_t s = 0;
    int* pilha = (int*) malloc(s);

    if (pilha == 0 ){
        std::cout << "Malloc nao conseguiu criar a pilha" << std::endl;
        exit(1);
    }

    transferencia(valorTransacao, 3);

    return 0;

}
