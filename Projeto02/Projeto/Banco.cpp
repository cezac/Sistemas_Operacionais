//
// Created by Caio- on 15/11/2022.
//

#include "Banco.h"
#include <iostream>
#include <mutex>
#include <thread>

std::mutex semaforo; // Criando um mutex

// Funcao para trasnferir o dinheiro de uma conta a outra
int transferencia(int quantTransfer, conta* clienteA, conta* clienteB){

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
        semaforo.unlock();
    }
    else { // Se o saldo do clienteA for inferior ao valor
        std::cout << std::endl << " ERRO DE TRANSFENCIA: ";
        std::cout << std::endl << " Falta de Saldo " << std::endl;
        semaforo.unlock();
    }
    return 0;

}


int main() {

    int valorTransacao = 10;

    conta primaria;
    conta secundaria;

    primaria.saldo = 1000;
    secundaria.saldo = 0;

    primaria.tentativas = 0;
    secundaria.tentativas = 0;

    std::thread vec[100];

    for (int i = 0; i < 100; i++)
    {
        vec[i] = std::thread(transferencia, valorTransacao, &primaria, &secundaria);
    }

    for (int i = 0; i < 100; i++)
    {
        vec[i].join();
    }

    std::cout << std::endl << "Saldo da Primeira Conta: " << primaria.saldo;
    std::cout << std::endl << "Saldo da Segunda Conta: " << secundaria.saldo << std::endl;

}
