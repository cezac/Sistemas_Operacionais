#include <iostream>
#include <thread>

using namespace std;

void pensar(){
    printf("\npensando");
}

void comer(){
    printf("\ncomendo");
}

void *filosofo(void *arg){
    int fid = *((int*)arg); // ID do filosofo

    while (true){ // Loop para comer e pensar
        pensar();
        comer();
    }
}

int main(){
    pthread_t tid[5];
    int arg[5];
    for (int i = 0; i < 5; i++) // Criacao de cada thread que executa cada filosofo
    {
        arg[i] = i;
        pthread_create(&tid[i], NULL, &filosofo, &arg[i]);
        pthread_detach(tid[i]);
    }


    return 0;
}

