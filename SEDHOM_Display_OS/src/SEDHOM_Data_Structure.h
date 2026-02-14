#ifndef SEDHOM_DATA_STRUCTURE_H_
#define SEDHOM_DATA_STRUCTURE_H_

// ================================= STACK =================================
template<typename T>
class Stack
{
private:
    T* array;
    int size;
    int top;

public:
    Stack() : array(nullptr), size(0), top(-1) {}
    Stack(int Stack_size);
    ~Stack();

    void init_Stack(int Stack_size);
    bool isEmpty();
    bool isFull();
    void push(T value);
    T pop();
    T peek();
};

// -------- Stack implementation --------
template<typename T>
Stack<T>::Stack(int Stack_size)
{
    size = Stack_size;
    array = new T[size];
    top = -1;
}

template<typename T>
Stack<T>::~Stack()
{
    delete[] array;
}

template<typename T>
void Stack<T>::init_Stack(int Stack_size)
{
    delete[] array;
    size = Stack_size;
    array = new T[size];
    top = -1;
}

template<typename T>
bool Stack<T>::isEmpty()
{
    return top == -1;
}

template<typename T>
bool Stack<T>::isFull()
{
    return top == size - 1;
}

template<typename T>
void Stack<T>::push(T value)
{
    if (isFull()) return;
    array[++top] = value;
}

template<typename T>
T Stack<T>::pop()
{
    if (isEmpty()) return T();
    return array[top--];
}

template<typename T>
T Stack<T>::peek()
{
    if (isEmpty()) return T();
    return array[top];
}

// ================================= QUEUE =================================
template<typename T>
class Queue
{
private:
    T* array;
    int size;
    int front;
    int rear;
    int count;

public:
    Queue() : array(nullptr), size(0), front(0), rear(-1), count(0) {}
    Queue(int Queue_size);
    ~Queue();

    void init_Queue(int Queue_size);
    bool enqueue(T value);
    T dequeue();

    bool isEmpty() { return count == 0; }
    bool isFull() { return count == size; }
    int getCount() { return count; }
};

// -------- Queue implementation --------
template<typename T>
Queue<T>::Queue(int Queue_size)
{
    size = Queue_size;
    array = new T[size];
    front = 0;
    rear = -1;
    count = 0;
}

template<typename T>
Queue<T>::~Queue()
{
    delete[] array;
}

template<typename T>
void Queue<T>::init_Queue(int Queue_size)
{
    delete[] array;
    size = Queue_size;
    array = new T[size];
    front = 0;
    rear = -1;
    count = 0;
}

template<typename T>
bool Queue<T>::enqueue(T value)
{
    if (isFull()) return false;
    rear = (rear + 1) % size;
    array[rear] = value;
    count++;
    return true;
}

template<typename T>
T Queue<T>::dequeue()
{
    if (isEmpty()) return T();
    T value = array[front];
    front = (front + 1) % size;
    count--;
    return value;
}
// ================================= Linked List =================================
template<typename T>
class Node
{
    public:
        T value ;
        Node<T> * next ;
        Node(T val)
        {
            this->value = val;
            this->next = nullptr;
        }
};
template<typename T>
class LinkedList
{
    private:
        Node<T>* head ;   
    public:
      LinkedList();
     ~LinkedList();  
     void add_end(T val);

};

// -------- LinkedList implementation --------
template<typename T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
}

template<typename T>
LinkedList<T>::~LinkedList()
{
    Node<T>* current = head;

    while (current != nullptr)
    {
        Node<T>* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}

template<typename T>
void LinkedList<T>::add_end(T val)
{
    Node<T>* newNode = new Node<T>(val);
    if(head == nullptr)
    {
        head = newNode;
        return ;
    }
    else
    {
        Node<T>* temp = head;
        while ( temp->next = nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}


//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
#endif /* SEDHOM_DATA_STRUCTURE_H_ */
