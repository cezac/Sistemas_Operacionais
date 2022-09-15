#include <iostream>
#include <thread>
#include <mutex>
#include <unistd.h>

using namespace std;

#define N 5 // Numero de filosofos
#define maxTempo 10 // Tempo maximo de comer/pensar
#define minTempo 5 // Tempo minimo de comer/pensar
mutex garfos[5]; // Mutex (semaforo) de garfos para evitar que dois filosofos peguem o mesmo garfo simultaneamente
mutex tentarPegarGarfo; // Mutex (semaforo) para evitar que dois filosofos tentem pegar os garfos simultaneamente

void comer(int id);
void pensar(int id);
void pegarGarfo(int id);
void soltarGarfo(int id);
void filosofo(int id);

// Funcao para pegar o garfo
void pegarGarfo(int id){
    tentarPegarGarfo.lock(); // Evita corrida para tentar lock nos garfos, apenas 1 tenta pegar garfo a cada momento
    lock(garfos[id], garfos[(id + 1) % N]); // O filosofo so pegara os garfos se conseguir pegar os dois simultaneamente (esquerda e direita)
    tentarPegarGarfo.unlock();
}

// Funcao para soltar os garfos utilizados (esquerda e direita)
// Unlock de cada garfo, um de cada vez
void soltarGarfo(int id){
    garfos[id].unlock();
    garfos[(id + 1) % N].unlock();
}

// Funcao para comer
// Utiliza sleep aleatorio que auxilia a evitar
void comer(int id){
    pegarGarfo(id);
    printf("\n****O filosofo %d esta comendo****", id);
    int tempo = rand() % maxTempo + minTempo; // Valor aleatorio de sleep
    sleep(tempo); // Tempo para comer
    soltarGarfo(id);
    printf("\n----O filosofo %d parou de comer----", id);
}

// Funcao para pensar
void pensar(int id){
    printf("\nO filosofo %d esta pensando", id);
    int tempo = rand() % maxTempo + minTempo; // Valor aleatorio de sleep
    sleep(tempo); // Tempo para pensar
}

// Funcao que representa um filosofo e seu estado de comer e pensar
void filosofo(int id){
    int vzsComeu = 0; // contador para verificar quantas vezes cada filosofo comeu
    int vzsPensou = 0; // contador para verificar quantas vezes cada filosofo pensou

    pensar(id);
    while (1) {
        comer(id);
        vzsComeu++;
        pensar(id);
        vzsPensou++;
        printf("\n\nO filosofo %d pensou %d vezes e comeu %d vezes", id, vzsPensou, vzsComeu);
    }
}

int main(){
    printf("\n\n----JANTAR DOS FILOSOFOS----\n\n");

    // Criacao de cada thread que representa cada filosofo, passando como argumento a funcao filosofo e o identificador (id) de cada um
    thread t1(filosofo, 0);
    thread t2(filosofo, 1);
    thread t3(filosofo, 2);
    thread t4(filosofo, 3);
    thread t5(filosofo, 4);

    // While para manter o programa rodando e esperar um input que encerre o programa
    int e = 1;
    while (e != 0) {
        cin >> e;
    }

    printf("\n");

    return 0;
}