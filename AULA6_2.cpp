#include<thread>
#include<iostream>
#include<chrono>
#include<mutex>

unsigned int contador = 0;
std::mutex locker;

void fun_thread() {
	
	for (int i = 0; i < 10; i++) {
		
		printf("Esperando thread: %d...\n", std::this_thread::get_id());
		std::this_thread::sleep_for(std::chrono::milliseconds(500)); //Temporizador
		locker.lock();
		contador++;
		locker.unlock();
	}
	
}

int main() {
	std::thread thread01(fun_thread);
	std::thread thread02(fun_thread);


		thread01.join();
	thread02.join();
	printf("Contador: %u...\n", contador);
}

	