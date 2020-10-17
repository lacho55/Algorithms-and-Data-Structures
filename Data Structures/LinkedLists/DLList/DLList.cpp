#include <assert.h>
#include "DLList.h"

//Node constructor
template<class T>
Node<T> :: Node(const T& newData, Node<T>* newNext, Node<T>* newPrev) : data(newData), next(newNext), prev(newPrev){}


/* ---- Helper Functions ----*/
template<class T>
void DLList<T> :: copy(const DLList<T>& other){

   first = last = nullptr;
   currentSize = 0;

   if(other.first != nullptr){

       Node<T>* otherIterate = other.first;

       while(otherIterate != nullptr){

           Node<T>* newElement = new Node<T>(other->data);

           if(!first){
               first = last = newElement;
           } else{
               last->next = newElement;
               newElement->prev = last;
               last = last->next;
           }
           currentSize++;
           otherIterate = otherIterate->next;

       }

   }

}


template<class T>
void DLList<T> :: destroy(){
    while(first != nullptr){
        Node<T>* toDelete = first;
        first = first->next;
        delete toDelete;
    }
    first = last = nullptr;
    currentSize = 0;
}


//DLList constructor
template<class T>
DLList<T> :: DLList(){
    first = nullptr;
    last = nullptr;
    currentSize = 0;
}


template<class T>
DLList<T> :: DLList(const DLList<T>& other){
    copy(other);
}


template<class T>
DLList<T>& DLList<T> :: operator = (const DLList<T>& other){
    if(this != other){
        destroy();
        copy(other);
    }

    return *this;
}


template<class T>
DLList<T> :: ~DLList(){
    destroy();
}


template<class T>
void DLList<T> :: push_back(const T& data){
    Node<T>* toAdd = new Node<T>(data, nullptr, last);

    if(!first){
        first = last = toAdd;

    }else{
        last->next = toAdd;
        last = last->next;
    }
    currentSize++;
}


template<class T>
void DLList<T> :: push_front(const T& data){
    Node<T>* toAdd = new Node<T>(data,first, nullptr); // we can skipp defining nullptr for the last pointer

    if(first){
        first->prev = toAdd;
    }
    first = toAdd;
    if(!last){
        first = last;
    }
    currentSize++;

}


template<class T>
void DLList<T> :: pop_back(){
    if(first){
        if(first == last){
            delete first;
            first = last = nullptr;
            return;
        }

        Node<T>* toDelete = last;
        last = last->prev;
        last->next = nullptr;
        delete toDelete;
        currentSize--;

    }
}


template<class T>
void DLList<T> :: pop_front(){
    if(first){
        if(first == last){
            delete first;
            first = last = nullptr;
            return;
        }
        Node<T>* toDelete = first;
        first = first->next;
        first->prev = nullptr;
        delete toDelete;
        currentSize--;

    }
}


template<class T>
T DLList<T> :: front() const{
    assert(first);
    return first->data;
}


template<class T>
T DLList<T> :: back() const{
    assert(last);
    return last->data;
}


template<class T>
bool DLList<T> :: empty() const{
    return first == nullptr;
}


template<class T>
size_t DLList<T> :: size() const{
    return currentSize;
}


template<class T>
void DLList<T> :: print() const{

    Node<T>* curr = first;

    std :: cout << "{ ";

    for(size_t i = 0; i < currentSize - 1; ++i){
        std :: cout << curr->data << ", ";
        curr = curr->next;
    }
    std :: cout << curr->data << " }\n";
}


template<class T>
void DLList<T> :: reverse() {
    if((first == nullptr) || (currentSize == 1)){
        return;
    }

    Node<T>* current = first;
    Node<T>* temp = last;
    last = first;
    first = temp;

    while(current != nullptr){
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
}
