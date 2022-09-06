template<typename T>
class DoublyList {
public:
    DoublyList();

    ~DoublyList();

    void push_front(T data);

    void push_back(T data);

    void pop_front();

    void pop_back();

    void removeAt(int index);

    void insert(T data, int index);

    void clear();

    int GetSize() { return Size; };

    T& operator[](const int index);

private:
    template<typename T>
    class Node {
    public:
        Node* pNext;
        Node* pPrev;
        T data;

        Node(T data = T(), Node* pNext = nullptr, Node* pPrev = nullptr) {
            this->data = data;
            this->pNext = pNext;
            this->pPrev = pPrev;
        };
    };

    int  Size;
    Node<T>* head;
    Node<T>* tail;
};

template<typename T>
DoublyList<T>::DoublyList() {
    Size = 0;
    head = nullptr;
    tail = nullptr;
};

template<typename T>
DoublyList<T>::~DoublyList() {
    clear();
}

template<typename T>
void DoublyList<T>::push_front(T data) {
    if (head == nullptr) {
        push_back();
    }
    else {
        Node<T> newNode = new Node<T>(data, head, nullptr);
        head->pPrev = newNode;
        head = newNode;
        Size++;
    }
}

template<typename T>
void DoublyList<T>::push_back(T data) {
    if (head == nullptr) {
        Node<T>* newNode = new Node<T>(data);
        head = newNode;
        tail = newNode;
    }
    else {
        Node<T>* newNode = new Node<T>(data, nullptr, tail);
        tail->pNext = newNode;
        tail = newNode;
    }
    Size++;
};

template<typename T>
void DoublyList<T>::pop_front() {
    Node<T>* temp = head;
    head = head->pNext;

    if (head != nullptr) {
        head->pPrev = nullptr;
    }    

    delete temp;
    Size--;
}

template<typename T>
void DoublyList<T>::pop_back() {
    Node<T> temp = tail;
    tail = tail->pPrev;
    tail->pNext = nullptr;
    delete temp;
    Size--;
}

template<typename T>
void DoublyList<T>::removeAt(int index) {
    if (index == 0) {
        pop_front();
    }
    else if (index == Size - 1) {
        Node<T>* toDelete = tail;
        tail = tail->pPrev;
        tail->pNext = nullptr;

        delete toDelete;
        Size--;
    }
    else {
        Node<T>* previous = this->head;

        for (int i = 0; i < index - 1; i++) {
            previous = previous->pNext;
        }

        Node<T>* toDelete = previous->pNext;
        Node<T>* next = toDelete->pNext;
        
        previous->pNext = next;
        next->pPrev = previous;

        delete toDelete;
        Size--;
    }
}

template<typename T>
void DoublyList<T>::insert(T data, int index) {
    if (index == 0) {
        push_front(data);
    }
    else if (index == Size + 1 || head == nullptr) {
        push_back(data);
    }
    else {
        Node<T>* previous = this->head;

        for (int i = 0; i < index - 1; i++) {
            previous = previous->pNext;
        }

        Node<T>* next = previous->pNext;

        Node<T> newNode = new Node<T>(data, next, previous);
        previous->pNext = newNode;
        next->pPrev = newNode;

        Size++;
    }
}

template<typename T>
void DoublyList<T>::clear() {
    while (Size) {
        pop_front();
    };
}

template<typename T>
T& DoublyList<T>::operator[](const int index) {
    int counter = 0;
    Node<T>* current = nullptr;

    if (index > Size / 2) {
        counter = Size - 1;
        current = this->tail;

        while (current != nullptr) {
            if (counter == index) {
                return current->data;
            }
            current = current->pPrev;
            counter--;
        }
    }
    else {
        current = this->head;

        while (current != nullptr) {
            if (counter == index) {
                return current->data;
            }
            current = current->pNext;
            counter++;
        }
    }
};