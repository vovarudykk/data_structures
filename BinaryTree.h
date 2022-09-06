#pragma once
#include <iostream>
#include <queue>

class BinaryTree
{
public: 

	BinaryTree() : root(nullptr) {};

	class Node {
	public:
		int data;
		Node* left;
		Node* right;
		Node* parent;

		Node(int data, Node* left = nullptr, Node* right = nullptr, Node* parent = nullptr) {
			this->data = data;
			this->left = left;
			this->right = right;
			this->parent = parent;
		}
	};

	Node* root;

	bool isEmpty() {
		return root == nullptr;
	}

	void add(int data) {
		std::cout << data << std::endl;
		_add(root, nullptr, data);
	}

	void _add(Node* currentRoot, Node* parentRoot, int data)
	{
		if (isEmpty()) {
			root = new Node(data);
			return;
		}
		if (currentRoot != nullptr) {
			if (data < currentRoot->data) {
				_add(currentRoot->left, currentRoot, data);
			}
			else {
				_add(currentRoot->right, currentRoot, data);
			}
		}
		else {
			if (data < parentRoot->data) {
				parentRoot->left = new Node(data, nullptr, nullptr, parentRoot);
			}
			else {
				parentRoot->right = new Node(data, nullptr, nullptr, parentRoot);
			}
		}
	}

	// обход в ширину
	void BreadthFirstSearch(Node* root) {
		std::queue<Node*> q;
		q.push(root);
		while (q.empty() == false) {
			Node* node = q.front();
			std::cout << node->data << " ";
			q.pop();
			if (node->left != nullptr) {
				q.push(node->left);
			}
			if (node->right != nullptr) {
				q.push(node->right);
			}
		}
	}

	// обход в глубину (прямой)
	void DFT_Preorder(Node* root) {
		if (root == nullptr) {
			return;
		}

		std::cout << root->data << " ";
		DFT_Preorder(root->left);
		DFT_Preorder(root->right);
	}

	// обход в глубину (центрированный)
	void DFT_Inorder(Node* root) {
		if (root == nullptr) {
			return;
		}
		DFT_Inorder(root->left);
		std::cout << root->data << " ";
		DFT_Inorder(root->right);
	}

	// обход в глубину (обратный)
	void DFT_Postorder(Node* root) {
		if (root == nullptr) {
			return;
		}
		DFT_Inorder(root->left);
		DFT_Inorder(root->right);
		std::cout << root->data << " ";
	}

	// Find the inorder successor
	Node* minValueNode(Node* node) {
		Node* current = node;

		// Find the leftmost leaf
		while (current && current->left != nullptr)
			current = current->left;
		return current;
	}

	void deleteNode(int data) {
		_deleteNode(root, data);
	}

	Node* _deleteNode(Node* currentRoot, int data) {
		if (root == nullptr) {
			return currentRoot;
		}
		if (data < currentRoot->data) {
			currentRoot->left = _deleteNode(currentRoot->left, data);
		}
		else if (data > currentRoot->data) {
			currentRoot->right = _deleteNode(currentRoot->right, data);
		}
		else {
			if (currentRoot->left == nullptr && 
				currentRoot->right == nullptr) {
				return nullptr;
			}
			else if (currentRoot->left == nullptr) {
				Node* temp = currentRoot->right;
				delete currentRoot;
				return temp;
			}
			else if (currentRoot->right == nullptr) {
				Node* temp = currentRoot->left;
				delete currentRoot;
				return temp;
			}

			Node* temp = minValueNode(currentRoot->right);
			currentRoot->data = temp->data;
			currentRoot->right = _deleteNode(currentRoot->right, temp->data);
		}
		return currentRoot;
	}

	Node* _search(Node* currentNode, int data) {
		if (currentNode == nullptr) {
			std::cout << "Element not found." << std::endl;
			return nullptr;
		}
		if (currentNode->data == data) {
			std::cout << "Element was found." << std::endl;
			return currentNode;
		}

		if (data < currentNode->data) {
			_search(currentNode->left, data);
		}
		else {
			_search(currentNode->right, data);
		}
	}

	Node* search(int data) {
		return _search(root, data);
	}

	bool _has(Node* currentNode, int data) {
		if (currentNode == nullptr) return false;
		if (currentNode->data == data) return true;

		if (data < currentNode->data) {
			_has(currentNode->left, data);
		}
		else {
			_has(currentNode->right, data);
		}
	}

	bool has(int data) {
		return _has(root, data);
	}
};

