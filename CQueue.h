//
// Created by bomtv on 21.07.2021.
//

#ifndef QUEUE_EXS_CQUEUE_H
#define QUEUE_EXS_CQUEUE_H

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
	unsigned elements{};
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
		if (first == nullptr) die("underflow");
		
		Node* t = first;
		T data = t->data;
		first = t->next;
		delete t;
		elements--;
		
		return data;
	};
	const T& front() const {
		if (first == nullptr) die("underflow");
		
		Node* t = first;
		T data = t->data;
		
		return data;
	};
	
	void die(const std::string& msg) {
		std::cout << "Error: " << msg;
		exit(EXIT_FAILURE);
	};
};


#endif //QUEUE_EXS_CQUEUE_H
