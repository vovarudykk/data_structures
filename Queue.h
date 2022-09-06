#pragma once
#include <iostream>
template <typename T>
class Queue
{
public:
	Queue() : size(0), head(nullptr), tail(nullptr) {};
	~Queue() { clear(); };

	int getSize() { return size; };

	bool isEmpty() { return size == 0; };

	void clear() {
		while (!isEmpty()) {
			pop();
		}
	}

	void push(T data) {
		Node<T>* newNode = new Node<T>(data, tail);
		if (isEmpty()) {
			head = tail = newNode;
		}
		else {
			tail->pPrev = newNode;
			tail = newNode;
		}
		size++;
	}

	void pop() {
		if (!isEmpty()) {
			Node<T>* deleteNode = head;
			head = head->pPrev;
			if (size == 1) {
				tail = nullptr;
			}
			else {
				head->pNext = nullptr;
			}
			delete deleteNode;
			size--;
		}		
	}

	T front() {
		return head;
	}

	T back() {
		return tail;
	}

	void print() {
		Node<T>* current = head;
		while (current != nullptr) {
			std::cout << current->data << std::endl;
			current = current->pPrev;
		}
	}



private:
	template <typename T>
	class Node {
	public:
		T data;
		Node<T>* pNext;
		Node<T>* pPrev;

		Node(T data = T(), Node<T>* pNext = nullptr, Node<T>* pPrev = nullptr) {
			this->data = data;
			this->pNext = pNext;
			this->pPrev = pPrev;
		}
	};

	int size;
	Node<T>* head;
	Node<T>* tail;
};

