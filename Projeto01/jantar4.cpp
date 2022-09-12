#include <iostream>
#include <thread>
#include <mutex>
#include <unistd.h>

using namespace std;

#define N 5
#define maxTempo 5
#define minTempo 3
mutex garfos[5];
mutex tentarPegarGarfo;

void comer(int id);
void pensar(int id);
int pegarGarfo(int id);
void soltarGarfo(int id);
void filosofo(int id);

int pegarGarfo(int id){
    return try_lock(garfos[id], garfos[(id + 1) % N]);
}

void soltarGarfo(int id){
    tentarPegarGarfo.lock();
    garfos[id].unlock();
    garfos[(id + 1) % N].unlock();
    tentarPegarGarfo.unlock();
}

void comer(int id){
    printf("\nO filosofo %d esta comendo", id);

    sleep(rand() % maxTempo + minTempo);

    printf("\nO filosofo %d parou de comer", id);
}

void pensar(int id){
    printf("\nO filosofo %d esta pensando", id);
    sleep(rand() % maxTempo + minTempo);
}

void filosofo(int id){
    int vzsComeu = 0;
    int vzsPensou = 0;

    pensar(id);
    while (1) {
      if (pegarGarfo(id) == -1){
        comer(id);
        vzsComeu++;
        soltarGarfo(id);
      }
      pensar(id);
      vzsPensou++;
      printf("\n\nO filosofo %d pensou %d vezes e comeu %d vezes\n", id, vzsPensou, vzsComeu);
    }
}

int main(){
    printf("\n\n----JANTAR DOS FILOSOFOS----\n\n");

    thread t1(filosofo, 1);
    thread t2(filosofo, 2);
    thread t3(filosofo, 3);
    thread t4(filosofo, 4);
    thread t5(filosofo, 5);

    int e = 1;
    while (e != 0) {
        cin >> e;
    }

    printf("\n");

    return 0;
}