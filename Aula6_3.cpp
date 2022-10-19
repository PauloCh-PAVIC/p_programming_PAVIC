// Pavic Multithreading C++ - 2022 - Parte 2 

#include <thread>
#include<iostream> 
#include<chrono>
#include<mutex>
#include<atomic>

//unsigned int contador = 0;
std::atomic< unsigned int > contador = 0;
unsigned int contador2 = 0;


std::mutex locker;

void fun_thread() {

    for (int i = 0; i < 5; i++) {
        printf("Esperar o thread: %d...\n", std::this_thread::get_id());
        //std::cout << "Esperar thread:" << std::this_thread::get_id() << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); //Colocando um tempo
        // locker.lock();
        contador++;
        //locker.unlock();
        printf("contador: %d...\n", contador.load());
    }
    contador2 = contador;
}

int main() {

    std::thread thread01(fun_thread); // Declaração dos threads
    std::thread thread02(fun_thread);
    thread01.join();
    thread02.join();

    //std::cout << "contador" << std::endl;

   printf("contador: %d...\n",contador2);

}