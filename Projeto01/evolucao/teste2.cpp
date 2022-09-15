#include <iostream>
#include <thread>

using namespace std;

class MyFunctor{
    public:
        void operator()(){
            comer();
        }
        void comer(){
            cout << "\ncomendo\n";
        }
};

int main(){
    MyFunctor fnctor;
    thread t(fnctor);
    cout << "\nmain thread\n";
    t.join();

    return 0;
}
