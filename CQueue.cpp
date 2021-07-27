//
// Created by Bohdan on 21.07.2021.
//

//#include "CQueue.h"

//template <typename T>
//CQueue<T>::CQueue<T> (): elements(0), first(nullptr), last(nullptr) {}

//template <typename T>
//CQueue <T>::~CQueue(){
//	for (unsigned i = 0; i < size(); i++) {
//		extract();
//	}
//}

//template <typename T>
//void CQueue <T>::show(){
//	if (size() <= 0) {
//		std::cout << "Queue is empty\n";
//		return;
//	}
//
//	Node* t = first;
//	for (unsigned i = 0; i < size(); i++, t = t->next)
//	{
//		std::cout << i + 1 << ". " << t->data << "\n";
//	}
//}
//
//template <typename T>
//void CQueue <T>::add(const T &data){
//	Node* t = new Node;
//	t->data = data;
//	t->next = nullptr;
//	if (first == nullptr) {
//		first = t;
//	}
//	else {
//		Node* t2 = last;
//		t2->next = t;
//	}
//	last = t;
//	elements++;
//}
//
//template <typename T>
//bool CQueue <T>::isEmpty(){
//	if (first == nullptr) {
//		return true;
//	}
//	return false;
//}
//
//template <typename T>
//unsigned CQueue <T>::size(){
//	return elements;
//}
//
//template <typename T>
//T CQueue <T>::extract(){
//	if (first == nullptr) die("underflow");
//
//	Node* t = first;
//	T data = t->data;
//	first = t->next;
//	delete t;
//	elements--;
//
//	return data;
//}
//
//template <typename T>
//const T &CQueue <T>::front() const{
//	if (first == nullptr) die("underflow");
//
//	Node* t = first;
//	T data = t->data;
//
//	return data;
//}
//
//template <typename T>
//void CQueue <T>::die(const std::string &msg){
//	std::cout << "Error: " << msg;
//	exit(EXIT_FAILURE);
//}

//void die(const std::string& msg) {
//	std::cout << "Error: " << msg;
//	exit(EXIT_FAILURE);
//};

#include "iostream"
#include "string"

template <typename T>
class CQueue{
private:
	struct Node {
		T data;
		Node* next;
	};
	
	Node* first;
	Node* last;
	unsigned elements;
public:
	CQueue() : elements(0), first(nullptr), last(nullptr) {};
	~CQueue() {
		for (unsigned i = 0; i < size(); i++) {
			extract();
		}
	};
	
	void show() {
		if (size() <= 0) {
			std::cout << "Queue is empty\n";
			return;
		}
		
		Node* t = first;
		for (unsigned i = 0; i < size(); i++, t = t->next)
		{
			std::cout << i + 1 << ". " << t->data << "\n";
		}
	};
	
	void add(const T& data) {
		Node* t = new Node;
		t->data = data;
		t->next = nullptr;
		if (first == nullptr) {
			first = t;
		}
		else {
			Node* t2 = last;
			t2->next = t;
		}
		last = t;
		elements++;
	};
	
	bool isEmpty() {
		if (first == nullptr) {
			return true;
		}
		return false;
	};
	
	unsigned size() {
		return elements;
	};
	
	T extract() {
		if (first == nullptr) {
			std::cout << "Error: " << "underflow";
			exit(EXIT_FAILURE);
		}
		
		Node* t = first;
		T data = t->data;
		first = t->next;
		delete t;
		elements--;
		
		return data;
	};
	
	T front() const {
		if (first == nullptr) {
			std::cout << "Error: " << "underflow";
			exit(EXIT_FAILURE);
		}
		
		Node* t = first;
		T data = t->data;
		
		return data;
	};
};