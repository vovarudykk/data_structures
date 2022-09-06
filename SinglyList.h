template<typename T>
class SinglyList {
public:
    SinglyList();

    ~SinglyList();

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
        T data;

        Node(T data = T(), Node* pNext = nullptr) {
            this->data = data;
            this->pNext = pNext;
        };
    };

    int  Size;
    Node<T>* head;
};

template<typename T>
SinglyList<T>::SinglyList() {
    Size = 0;
    head = nullptr;
};

template<typename T>
SinglyList<T>::~SinglyList() {
    clear();
}

template<typename T>
void SinglyList<T>::push_front(T data) {
    head = new Node<T>(data, head);
    Size++;
}

template<typename T>
void SinglyList<T>::push_back(T data) {
    if (head == nullptr) {
        head = new Node<T>(data);
    }
    else {
        Node<T>* current = this->head;

        while (current->pNext != nullptr) {
            current = current->pNext;
        }

        current->pNext = new Node<T>(data);
    }
    Size++;
};

template<typename T>
void SinglyList<T>::pop_front() {
    Node<T>* temp = head;

    head = head->pNext;
    delete temp;
    Size--;
}

template<typename T>
void SinglyList<T>::pop_back() {
    removeAt(Size - 1);
}

template<typename T>
void SinglyList<T>::removeAt(int index) {
    if (index == 0) {
        pop_front();
    }
    else {
        Node<T>* previous = this->head;

        for (int i = 0; i < index - 1; i++) {
            previous = previous->pNext;
        }

        Node<T>* toDelete = previous->pNext;
        previous->pNext = toDelete->pNext;

        delete toDelete;
        Size--;
    }
}

template<typename T>
void SinglyList<T>::insert(T data, int index) {
    if (index == 0) {
        push_front(data);
    }
    else {
        Node<T>* previous = this->head;

        for (int i = 0; i < index - 1; i++) {
            previous = previous->pNext;
        }

        previous->pNext = new Node<T>(data, previous->pNext);
        Size++;
    }
};

template<typename T>
void SinglyList<T>::clear() {
    while (Size) {
        pop_front();
    };
};

template <typename T>
T& SinglyList<T>::operator[](const int index) {
    int counter = 0;
    Node<T>* current = this->head;

    while (current != nullptr) {
        if (counter == index) {
            return current->data;
        }
        current = current->pNext;
        counter++;
    };
};