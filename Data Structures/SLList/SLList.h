#include<iostream>

template<typename T>
struct Node{
            T data;
            Node<T>* next;

            Node(const T& newData, Node<T>* newNext = nullptr){
                this->data = newData;
                this->next = newNext;
            }
};

template<typename T>
class SLList{
    private:
        Node<T>* first;

    /* ------ Helping Functions ----- */
    void copy(const SLList<T>&);
    void destroy();

    public: 
        /* ----- Constructors ----- */
        SLList();
        SLList(const SLList<T>&);
        SLList<T>& operator=(const SLList<T>&);
        ~SLList();

        /* ----- Increasing Functionality ----- */
        void print() const;
        bool empty() const;
        void push_front(const T&);
        void push_back(const T&);

};


/* ------ Helping Functions ------- */
template<typename T>
void SLList<T>::copy(const SLList<T>& other){

    this->first = new Node<T>(other.first->data);

    Node<T>* otherIterate = other.first;
    Node<T>* cur = this->first;

    while(otherIterate->next != nullptr){
        cur->next = new Node<T>(otherIterate->next->data);
        otherIterate = otherIterate->next;
        cur = cur->next;
    }
}


template<typename T>
void SLList<T>::destroy(){

    Node<T>* toDelete = nullptr;

    while(first != nullptr){
        toDelete = new Node<T>(first->data);
        first = first->next;
        delete toDelete;
    }

    this->first = nullptr;
}


/* ---- Constructors ---- */
template<typename T>
SLList<T> :: SLList(){
    this->first = nullptr;
}


template<typename T>
SLList<T> :: SLList(const SLList<T>& other){
    this->copy(other);
}


template<typename T>
SLList<T>& SLList<T>:: operator=(const SLList<T>& other){

    if(this != &other){
        this->destroy();
        this->copy(other);
    }

    return *this;
}


template<typename T>
SLList<T>:: ~SLList(){
    this->destroy();
}


/* ----- Increasing Functionality  ------ */
template<typename T>
void SLList<T>:: print() const{

    Node<T>* cur = this->first;
    
    while(cur != nullptr){
        std::cout << cur->data << " ";
        cur = cur->next;
    }
    std::cout<<std::endl;
}


template<typename T>
bool SLList<T>:: empty() const{
    return (first == nullptr);
}


template<typename T>
void SLList<T>:: push_front(const T& newElem){

    Node<T>* newNode = new Node<T>(newElem);

    newNode->next = this->first;
    this->first = newNode;
    
}


template<typename T>
void SLList<T>:: push_back(const T& newElem){

    
    Node<T>* newNode = new Node<T>(newElem);

    Node<T>* cur = this->first;

    if(first == nullptr){
        first = newNode;
        return;
    }
    while(cur->next != nullptr){
        cur = cur->next;
    }

    
    cur->next = newNode;

}
