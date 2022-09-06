#pragma once
#include <iostream>
#include <queue>

class AVLTree
{
public:	
	class Node {
	public:
		int data;
		int balance;
		Node* left;
		Node* right;

		Node(int data, int balance = 0, Node* left = nullptr, Node* right = nullptr) {
			this->data = data;
			this->balance = balance;
			this->left = left;
			this->right = right;
		};
	};

	//����� ������ ����
	int Height(Node* root) {
		//���� ���� ������
		if (root == nullptr) {
			return 0;
		}

		//�����, ���� ������ ������� � ������ ������� (����������)
		int hLeft = Height(root->left);
		int hRight = Height(root->right);

		//���� ������ ������, ��� ������� �� ��������� +1 � ������ 
		if (hLeft > hRight) {
			return hLeft + 1;
		}
		//����� ��������� +1 � �������
		else {
			return hRight + 1;
		}
	}

	//������ �������� ������������
	void SetBalance(Node* (&root)) {
		if (root != nullptr) {
			//������ = ������ ������ - ������ �����
			root->balance = Height(root->right) - Height(root->left);
		}
	}

	//������� ������
	void TurnRight(Node* (&root)) {
		// ���������� ��������� �� ����� ��������� � 
		// ������ ��������� ������ ���������
		Node* leftSubTree;
		Node* leftSubTreeRightSubtree;
		
		leftSubTree = root->left;
		leftSubTreeRightSubtree = leftSubTree->right;

		//������ ��� ������ ��������� ������ ������� �������
		leftSubTree->right = root;
		//�������� �������� ����� �������� ����-������ ���������
		root->left = leftSubTreeRightSubtree;
		//�� ����� �������� �������� �������� ����� ���������
		root = leftSubTree;
		SetBalance(root->right);
		SetBalance(root);
	}

	//������� �����
	void TurnLeft(Node* (&root)) {
		//���������� ������ �������
		// � ����� �� �������
		Node* rightSubTree;
		Node* rightSubTreeLeftSubtree;

		rightSubTree = root->right;
		rightSubTreeLeftSubtree = rightSubTree->left;

		//��� ������������ ������� ������� � ������ ������� �������
		rightSubTree->left = root;
		// � ������� ������� �������� �������� ���������� ����� �� �������
		root->right = rightSubTreeLeftSubtree;
		// � ������� ������� ���������� ������ �� ����
		root = rightSubTree;
		// ����� �������
		SetBalance(root->left);
		SetBalance(root);
	}

	void insert(Node* (&root), int data) {
		// ���� ������� ������� ������, �� ������� ������ ����� ���� � �������
		if (root == nullptr) {
			root = new Node(data);
		}
		//�����, ��������� ���� ��� ��������
		else {
			// ���� ������ ������, ��� ������ �������� ��������
			// �� ���� ������
			if (data > root->data) {
				// ���������� �������� �������� ����� �������
				insert(root->right, data);
				// ��������� ������� ��� ������
				// ���� ������ ������ 1, �� ������ ��������\�
				if (Height(root->right) - Height(root->left) > 1) {
					// ���� ��� ���� ������ ������� �� ������� ������, ��� ������ �� �������
					// �� ������ ��������������� �������� ������
					if (Height(root->right->right) < Height(root->right->left)) {
						TurnRight(root->right);
					}
					//������ ������������ �������� �����
					TurnLeft(root);
				}
			}
			// ���� ������ ������, ��� ������ �������� ��������
			// �� ���� �����
			else {
				if (data < root->data) {
					// ���������� ��������� ������� �� ������� ������ �����
					insert(root->left, data);
					// ���� ������ ������ 1,
					// �� ������ �������� ������
					if (Height(root->left) - Height(root->right) > 1) {
						// ���� ������ ������ �� ������ ������, ��� ������ ������� �� ������
						// �� ������ ��������������� �������� �����
						if (Height(root->left->left) < Height(root->left->right)) {
							TurnLeft(root->left);
						}
						// ������������ �������� ������
						TurnRight(root);
					}
				}
			}
			// ����������� ��������� ������ ��� �������� �������� ����� ������� �������
			SetBalance(root);
		}
	}

	// �� ��������, �� ����� ��� ������ 
	void deleteNode(Node* (&root), int data) {
		if (root == nullptr) {
			std::cout << "This element was not exist." << std::endl;
		}
		else if (data < root->data) {
			deleteNode(root->left, data);
		}
		else if (data > root->data) {
			deleteNode(root->right, data);
		}
		else if (root->left == nullptr && root->right == nullptr) {
			Node* temp = root;
			delete temp;
			root = nullptr;
			std::cout << "Element was deleted." << std::endl;
		}
		else if (root->left == nullptr) {
			Node* temp = root;
			delete temp;
			root = root->right;
			std::cout << "Element was deleted." << std::endl;
		}
		else if (root->right == nullptr) {
			Node* temp = root;
			delete temp;
			root = root->left;
			std::cout << "Element was deleted." << std::endl;
		}
		else {
			root->data = deleteMin(root->right);
		}
	}

	int deleteMin(Node* (&root)) {
		int temp;
		if (root->left == nullptr) {
			temp = root->data;
			root = root->right;
			return temp;
		}
		else {
			temp = deleteMin(root->left);
			return temp;
		}
	}

	// ����� � ������
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

	// ����� � ������� (������)
	void DFT_Preorder(Node* root) {
		if (root == nullptr) {
			return;
		}

		std::cout << root->data << " ";
		DFT_Preorder(root->left);
		DFT_Preorder(root->right);
	}

	// ����� � ������� (��������������)
	void DFT_Inorder(Node* root) {
		if (root == nullptr) {
			return;
		}
		DFT_Inorder(root->left);
		std::cout << root->data << " ";
		DFT_Inorder(root->right);
	}

	// ����� � ������� (��������)
	void DFT_Postorder(Node* root) {
		if (root == nullptr) {
			return;
		}
		DFT_Inorder(root->left);
		DFT_Inorder(root->right);
		std::cout << root->data << " ";
	}

	void output(Node* p) {
		if (p != nullptr) {
			output(p->left);
			std::cout << p->data << " ";
			output(p->right);
		}
	}

	void printByLevel(Node* p, int n, int level, int prob) {
		if (p) {
			if (level == n) {
				for (int i = 1; i <= prob; i++) 
					std::cout << " ";
				std::cout << p->data;
			}
			else {
				printByLevel(p->left, n, level + 1, prob);
				printByLevel(p->right, n, level + 1, prob);
			}
		}
	}

	void printAllLevel(Node* p) {
		int h = Height(p);
		int prob = 3;
		if (p != nullptr) {
			for (int i = 0; i <= h; i++) {
				printByLevel(p, i, 0, prob * (h - i));
				std::cout << std::endl;
			}
		}
	}
};

