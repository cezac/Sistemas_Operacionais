#include <iostream>
#include <thread>
#include <mutex>
#include <unistd.h>

using namespace std;

#define N 5
#define maxTempo 5
#define minTempo 3

class Filosofo {
private:
  int id;

public:
  mutex garfos[N];

  void operator()(int num) {
    setID(num);

    pensar();
    while (1) {
      if (pegarGarfo() == -1)
        comer();
        soltarGarfo();
      pensar();
    }
  }

  void setID(int num) { id = num; }

  void comer() {
    printf("\nO filosofo %d esta comendo", id);

    sleep(rand() % maxTempo + minTempo);

    printf("\nO filosofo %d parou de comer", id);
  }

  void pensar() {
    printf("\nO filosofo %d esta pensando", id);
    sleep(rand() % maxTempo + minTempo);
  }

  int pegarGarfo() {
    return try_lock(garfos[id], garfos[(id + 1) % N]);
  }

  void soltarGarfo() {
    garfos[id].unlock();
    garfos[(id + 1) % N].unlock();
  }
};

int main() {
  printf("\n\n----JANTAR DOS FILOSOFOS----\n\n");

  // filosofo *filosofos[5];
  // filosofos[0] = new filosofo;
  // thread t1(filosofos[0]);
  Filosofo f1;
  Filosofo f2;
  Filosofo f3;
  Filosofo f4;
  Filosofo f5;

  thread t1(f1, 1);
  thread t2(f2, 2);
  thread t3(f3, 3);
  thread t4(f4, 4);
  thread t5(f5, 5);

  int e = 1;
  while (e != 0) {
    cin >> e;
  }

  printf("\n");

  return 0;
}

// Objeto (class) filosofo
// filosofo possui id unico pra cada filosofo
// filosofo possui funcoes para comer, pensar
// comer so pode ser executado se o filosofo consegue pegar dois garfos
// uso de mutex para bloquear os garfos em uso
// uso de random sleep para determinar os tempos de comer e pensar

// g++ -std=c++11 -pthread

// https://github.com/BigWheel92/Dining-Philosophers/blob/main/main.cpp