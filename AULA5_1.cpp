#include<iostream>
#include<thread>
#include<chrono>
using namespace std;


void call_from_thread() {
	cout << "Hello World, from Thread" << endl; 
	this_thread::sleep_for(chrono::milliseconds(5000));
}

int main() {

	thread t1(call_from_thread);
	thread t2(call_from_thread);
	thread t3(call_from_thread);
	//this_thread::sleep_for(chrono::milliseconds(5000));
	t2.join();
	t3.join();
	t1.join();

	cout << "Hello World, from CPU - after join" << endl;
	this_thread::sleep_for(chrono::milliseconds(5000));
	
	cout << "Hello World, from CPU - after join" << endl;

	return 0;
}