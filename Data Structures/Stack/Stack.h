#include<iostream>
using namespace std;

template<class T>
struct Node{
    T data;
    Node<T>* next;

    Node(const T& newData, Node<T>* newNext = nullptr){
        data = newData;
        next = newNext;
    }
};


template<class T>
class Stack{
    private:
        Node<T>* first;
        size_t counter;

    public:
        /* ------ Constructors ------- */
        Stack();
        Stack(const Stack<T>&);
        Stack<T>& operator=(const Stack<T>&);
        ~Stack();

        /* ------ Helping functions ------ */
        void push(const T&);
        size_t size() const;
        void pop();
        T top() const;
        

    /* ------- Private Methods ------ */
    void copy(const Stack<T>&);
    void copyReverse(const Stack<T>&);
    void init();
    void empty();
    bool isEmpty() const;

    

};


/* ------ Constructors ------- */
template<class T>
Stack<T>:: Stack(){
    first = nullptr;
    counter = 0;
}


template<class T>
Stack<T>:: Stack(const Stack<T>& other){
    this->init();
    this->copy(other);
}


template<class T>
Stack<T>& Stack<T>:: operator=(const Stack<T>& other){

    if(this != &other){
        this->empty();
        this->init();
        this->copy(other);
    }

    return *this;
}


template<class T>
Stack<T>:: ~Stack(){
    this->empty();
}


/* ------- Helping Functions ------ */
template<class T>
void Stack<T>:: push(const T& element){

    Node<T>* add = new Node<T>(element, this->first);

    if(add){
        this->first = add;
        this->counter++;
    }

}


template<class T>
size_t Stack<T>:: size() const{
    return this->counter;
}


template<class T>
void Stack<T>:: pop(){

    if(!this->isEmpty()){

        Node<T>* toDel = this->first;
        this->first = this->first->next;
        delete toDel;
        counter--;
    }

}


template<class T>
T Stack<T>:: top() const{
    return this->first->data;
}


template<class T>
bool Stack<T>:: isEmpty() const{
    return (this->first == nullptr);
}


/* ------ Private Methods ------- */
template<class T>
void Stack<T>:: copy(const Stack<T>& other){

    Stack<T> reverse;

    reverse.copyReverse(other);

    this->copyReverse(reverse);

}


template<class T>
void Stack<T>:: copyReverse(const Stack<T>& other){

    Node<T>* toAdd = other.first;
    size_t otherSize = other.size();

    for(size_t i = 0; i <= otherSize; i++){
        this->push(toAdd->data);
        toAdd = toAdd->next;
    }

}


template<class T>
void Stack<T>:: init(){
    this->first = nullptr;
    this->counter = 0;
}


template<class T>
void Stack<T>:: empty(){

    for(size_t i = 0; i <= this->counter; i++){
        this->pop();
    }

}

