#pragma once

template<class T>
struct Node{
    T data;
    Node<T>* next;
    Node<T>* prev;
    Node(const T&, Node<T>* = nullptr, Node<T>* = nullptr);
};

template<class T>
class DLList{
    Node<T>* first;
    Node<T>* last;
    size_t currentSize;

    /*---- Helper Functions ----*/
    void copy(const DLList<T>&);
    void destroy();

    public:
        DLList();
        DLList(const DLList<T>&);
        DLList<T>& operator=(const DLList<T>&);
        ~DLList();
};
