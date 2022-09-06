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

	//поиск высоты узла
	int Height(Node* root) {
		//если узел пустой
		if (root == nullptr) {
			return 0;
		}

		//иначе, ищем высоту правого и левого подузла (рекурсивно)
		int hLeft = Height(root->left);
		int hRight = Height(root->right);

		//если левого больше, чем правого то добавляем +1 к левому 
		if (hLeft > hRight) {
			return hLeft + 1;
		}
		//иначе добавляем +1 к правому
		else {
			return hRight + 1;
		}
	}

	//задаем значение балансировки
	void SetBalance(Node* (&root)) {
		if (root != nullptr) {
			//баланс = высота справа - высота слева
			root->balance = Height(root->right) - Height(root->left);
		}
	}

	//поворот вправо
	void TurnRight(Node* (&root)) {
		// запоминаем указатель на левое поддерево и 
		// правое поддерево левого поддерева
		Node* leftSubTree;
		Node* leftSubTreeRightSubtree;
		
		leftSubTree = root->left;
		leftSubTreeRightSubtree = leftSubTree->right;

		//укажем для левого поддерева справа текущий элемент
		leftSubTree->right = root;
		//текущему элементу слева назначим лево-правое поддерево
		root->left = leftSubTreeRightSubtree;
		//на место текущего элемента назначим левое поддерево
		root = leftSubTree;
		SetBalance(root->right);
		SetBalance(root);
	}

	//поворот влево
	void TurnLeft(Node* (&root)) {
		//запоминаем правый элемент
		// и левый от правого
		Node* rightSubTree;
		Node* rightSubTreeLeftSubtree;

		rightSubTree = root->right;
		rightSubTreeLeftSubtree = rightSubTree->left;

		//для переписываем текущий элемент в левого потомка правого
		rightSubTree->left = root;
		// в правого потомка текущего элемента записываем левый от правого
		root->right = rightSubTreeLeftSubtree;
		// в текущий элемент записываем правый от него
		root = rightSubTree;
		// сетим балансы
		SetBalance(root->left);
		SetBalance(root);
	}

	void insert(Node* (&root), int data) {
		// если текущий элемент пустой, то создаем пустой новый узел с данными
		if (root == nullptr) {
			root = new Node(data);
		}
		//иначе, проверяем куда его засунуть
		else {
			// если данные больше, чем данные текущего элемента
			// то идем вправо
			if (data > root->data) {
				// рекурсивно пытаемся вставить новый элемент
				insert(root->right, data);
				// проверяем условие авл дерева
				// если баланс больше 1, то делаем проворот\ы
				if (Height(root->right) - Height(root->left) > 1) {
					// если при этом длинна правого от правого меньше, чем левого от правого
					// то делаем предварительный проворот вправо
					if (Height(root->right->right) < Height(root->right->left)) {
						TurnRight(root->right);
					}
					//делаем обязательный проворот влево
					TurnLeft(root);
				}
			}
			// если данные меньше, чем данные текущего элемента
			// то идем влево
			else {
				if (data < root->data) {
					// рекурсивно вставляем элемент на уровень глубже влево
					insert(root->left, data);
					// если баланс больше 1,
					// то делаем проворот вправо
					if (Height(root->left) - Height(root->right) > 1) {
						// если высота левого от левого меньше, чем длинна правого от левого
						// то делаем предварительный проворот влево
						if (Height(root->left->left) < Height(root->left->right)) {
							TurnLeft(root->left);
						}
						// обязательный проворот вправо
						TurnRight(root);
					}
				}
			}
			// обязательно обновляем баланс для текущего элемента после каждого прохода
			SetBalance(root);
		}
	}

	// не работает, но лучше чем ничего 
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

