#include <iostream>
#include "CQueue.cpp"
using namespace std;

int main(){
	CQueue<int> queue;
	cout << "Is empty? -> " << queue.isEmpty() << endl;
	queue.show();
	queue.add(5);
	queue.add(10);
	queue.show();
	cout << "Is empty? -> " << queue.isEmpty() << endl;
	cout << "Queue size " << queue.size() << endl;
	
	cout << "Removed: " << queue.extract() << endl;
	cout << "Now front item: " << queue.front() << endl;
	
	queue.extract();
	cout << "Is empty? -> " << queue.isEmpty() << endl;

	return 0;
}
