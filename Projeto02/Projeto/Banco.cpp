//
// Created by Caio- on 15/11/2022.
//

#include "Banco.h"
#include <iostream>
#include "mutex"
#include "thread"

std::mutex semaforo; // Criando um mutex

// Funcao para trasnferir o dinheiro de uma conta a outra
int transferencia(int quantTransfer, conta* clienteA, conta* clienteB){

    clienteA->tentativas = 0; // Definindo o n° de tentativas padrao
    clienteB->tentativas = 0; // Definindo o n° de tentativas padrao

    semaforo.lock(); // Mutex travado enquanto a funcao executa transacao

    if(clienteA->saldo >=quantTransfer){ // Se o saldo do clienteA for igual ou maior ao valor da transferencia

        std::cout << std::endl << "Transferencia Concluida com Sucesso" << std::endl;

        clienteA->saldo -= quantTransfer;
        clienteA->tentativas +=1;
        std::cout << "Saldo da conta A = " << clienteA->saldo << std::endl;
        std::cout << "Transferencias Executadas na conta A = " << clienteA->tentativas << std::endl << std::endl;

        clienteB->saldo +=quantTransfer;
        clienteB->tentativas +=1;
        std::cout << "Saldo da conta B = " << clienteB->saldo << std::endl;
        std::cout << "Transferencias Executadas na conta B = " << clienteB->tentativas << std::endl << std::endl;
        semaforo.unlock(); // Transacao finalizada, mutex desbloqueado
    }
    else { // Se o saldo do clienteA for inferior ao valor
        std::cout << std::endl << " ERRO DE TRANSFENCIA: ";
        std::cout << std::endl << " Falta de Saldo " << std::endl;
        semaforo.unlock(); // Transacao finalizada, mutex desbloqueado
    }
    return 0;

}

int main() {

    int valorTransacao = 10; // Valor a ser debitado nas transacoes

    conta primaria; // cria uma conta
    conta secundaria; // cria uma conta

    primaria.saldo = 1000; // define o saldo da conta primaria
    secundaria.saldo = 0; // define o saldo da conta secundaria

    std::thread vec[100]; // cria um array de threads

    for (int i = 0; i < 100; i++)
    {
        // Cada execucao deste laco incrementa a posicao i do vetor de threads com a execucao da funcao transferencia
        vec[i] = std::thread(transferencia, valorTransacao, &primaria, &secundaria); 
    }

    for (int i = 0; i < 100; i++)
    {
        // Cada chamada executada no laco interior deve aguardar a execucao da thread anterior para iniciar a próxima
        vec[i].join();
    }

    std::cout << std::endl << "Saldo da Primeira Conta: " << primaria.saldo;
    std::cout << std::endl << "Saldo da Segunda Conta: " << secundaria.saldo << std::endl;

}
