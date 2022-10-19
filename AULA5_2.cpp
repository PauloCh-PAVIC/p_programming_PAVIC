//Pavic Multithreading C++ - 2022
#include<iostream>
#include<thread>
using namespace std;

void pauloChaves() {
	printf("paulo, threads");

}
void call_from_thread() {
	cout << "Hello, Word from thread" << endl;

}
int main() {
	//Launch a thread
	thread paulo(pauloChaves);
	thread t1(call_from_thread);


	cout << "Hello, Word from CPU " << endl;

	// After Join
	paulo.join();
	t1.join();


	cout << "Hello, Word from CPU - after Join" << endl;
	return 0;
}