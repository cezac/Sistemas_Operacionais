/* http://www.di.ubi.pt/~operativos/praticos/html/13-sinc.html
Utilizamos este site para nos guiar com utilização das bibliotecas semaphore e pthread
O site também demostra uma solução para o problema, mas a implementação está diferente*/

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define N 5 // Números de garfos;
#define Pensando 2 // Criando valores de controle;
#define com_Fome 1 // Criando valores de controle;
#define Comendo 0 // Criando valores de controle;
#define ESQUERDA (filosofos+4) % N // Garfos a esquerda;
#define DIREITA (filosofos+1) % N // Garfos a direita;

int garfo[N];
int vet[N] = { 0, 1, 2, 3, 4 };

// Aqui vamos utilizar dois Semáforos com operações diferentes;
// Um será para para pegar o garfo (sem_wait) outro para devolver garfo(sem_post);

sem_t mutex; //Declarando Semáforo binário para exclusão mútua;
sem_t S[N]; //Declarando Semáforo binário para reset de estado;


// Função para determinar quem pode comer
void mesa(int filosofos) {
	if (garfo[filosofos] == com_Fome && garfo[ESQUERDA] != Comendo && garfo[DIREITA] != Comendo) { // Caso este critério não seja válido o filosósfo não inicar a comer;
		
		garfo[filosofos] = Comendo; // Mudança de estado do filósofo;
		sleep(2);

		printf("Filosofos %d pega garfo %d e %d\n", filosofos + 1, ESQUERDA + 1, filosofos + 1);
		printf("\n");
		printf("*** Filosofos %d esta comendo ***\n", filosofos + 1);

		sem_post(&S[filosofos]); // Utilização do Semáforo para resetar o status de go/ngo;
	}
}

void pega_Garfo(int filosofos) {

	sem_wait(&mutex);	// Utilização do Mutex, alterando o status do sefámoro para espera;
	garfo[filosofos] = com_Fome;	// Mudança de estado do filósofo;
	printf("Filosofos %d esta com fome\n", filosofos + 1);
	mesa(filosofos);	// Chamando a função para saciar o filósofo;
	sem_post(&mutex);	// Resetando o semáforo Mutex, para próxima chamda;
	sem_wait(&S[filosofos]);	// Notificando semáforo S para aguardar próxima chamada;
	sleep(1);
}

void devolve_Garfo(int filosofos) {

	sem_wait(&mutex); // Utilização do Mutex, alterando o status do sefámoro para espera;
	garfo[filosofos] = Pensando; // Mudança de estado do filósofo;

	printf("Filosofos %d devolve garfo %d e %d\n",filosofos + 1, ESQUERDA + 1, filosofos + 1);
	printf("\n");
	printf("Filosofos %d esta pensando\n", filosofos + 1);
	
	mesa(ESQUERDA); // Chamando a função mesa para devolver os garfos que foram utilizados
	mesa(DIREITA); // Chamando a função mesa para devolver os garfos que foram utilizados
	sem_post(&mutex); // Resetando o semáforo Mutex, para próxima chamda;
}

// Função Filosofos será chamada na criação de threads abaixo, aqui iniciamos a execução do jantar;
// Aqui as funções de pega e devolve são chamadas e elas iniciam o fluxo de comer, chamando a função mesa;
// A função mesa é quem determina quem pode ou não comer;

void* Filosofos(void* num) {

	while (1) {
		int* i = num;
		sleep(1);
		pega_Garfo(*i);
		sleep(0);
		devolve_Garfo(*i);
	}
}



int main() {
	int i;
	pthread_t thread_id[N];

	sem_init(&mutex, 0, 1);
	for (i = 0; i < N; i++)
		sem_init(&S[i], 0, 0);

	for (i = 0; i < N; i++) {
		pthread_create(&thread_id[i], NULL, Filosofos, &vet[i]);
		printf("Filosofos %d esta pensando\n", i + 1);
	}

	for (i = 0; i < N; i++) {
		pthread_join(thread_id[i], NULL);
	}
}
