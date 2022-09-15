#include <iostream>
#include <thread>

using namespace std;

class filosofo{
    public:
        void operator()(){
            for (int i=0; i<3; i++){
                comendo();
                pensando();
            }
        }
        void comendo(){
            printf("\nO filosofo esta comendo");
        }

        void pensando(){
            printf("\nO filosofo esta pensando");
        }
/*
        void estado(){
            
        }
*/
};

int main(){
    printf("\n\n----INICIANDO O PROGRAMA----\n\n");
    filosofo f1;
    thread t1(f1);
    t1.join();
    printf("\n");

    return 0;
}
