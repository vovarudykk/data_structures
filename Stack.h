#include <stdexcept>  
#include <iostream>   

template<typename T>
class Stack {
public:
	Stack() : head(nullptr), size(0) {};
	~Stack() { clear(); };

	void push(const T& data) {
		Node<T>* newNode = new Node<T>(data, head);
		head = newNode;
		size++;
	}

	bool isEmpty() const {
		return head == nullptr;
	}

	int getSize() const {
		return size;
	}

	void clear() {
		while (!isEmpty()) {
			pop();
		}
	}

	T& top() const {
		if (isEmpty()) {
			throw std::length_error("Stack is empty");
		}
		return head->data;
	}

	void pop() {
		if (isEmpty()) {
			throw std::length_error("Stack is empty");
		}
		Node<T>* deleteNode = head;
		head = deleteNode->pNext;
		delete deleteNode;
	}

	T& operator[] (const int index) {
		if (index > size) {
			throw std::length_error("Stack doesn`t contains element with index " + index);
		}

		Node<T>* current = this->head;
		int counter = 0;
		while (current != nullptr) {
			if (counter == index) {
				return current->data;
			}
			current = current->pNext;
			counter++;
		}
	}

private:
	template<typename T>
	class Node {
	public:
		T data;
		Node<T>* pNext;

		Node(T data = T(), Node* pNext = nullptr) {
			this->data = data;
			this->pNext = pNext;
		};
	};

	int size;
	Node<T>* head;
};

