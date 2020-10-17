
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
