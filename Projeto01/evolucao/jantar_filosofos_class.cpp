#include <iostream>
#include <thread>
#include <unistd.h>

using namespace std;

class Filosofo {
private:
  int id;

public:
  int garfos = 5;
  pthread_mutex_t tentarComer;

  void operator()(int num) {
    setID(num);

    pensar();
    while (1) {
        if (garfos >= 2)
            comer();
        pensar();
    }
  }

  void setID(int num) {
    id = num;
  }

  void comer() {
    pegarGarfo();
    printf("\nO filosofo %d esta comendo", id);
    pthread_mutex_unlock(&tentarComer);

    sleep(rand() % 10 + 5);

    soltarGarfo();
    printf("\nO filosofo %d parou de comer", id);
    pthread_mutex_lock(&tentarComer);
  }

  void pensar() {
    printf("\nO filosofo %d esta pensando", id);
    sleep(rand() % 10 + 5);
  }

  void pegarGarfo() {
    pthread_mutex_lock(&tentarComer);
    garfos-=2;
    pthread_mutex_unlock(&tentarComer);
  }

  void soltarGarfo() {
    pthread_mutex_lock(&tentarComer);
    garfos += 2;
    pthread_mutex_unlock(&tentarComer);
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