#pragma once

template<class T>
struct Node{
    T data;
    Node<T>* next;
    Node<T>* prev;

    /* ---- Node constructor ---- */
    Node(const T&, Node<T>* = nullptr, Node<T>* = nullptr);
};


template<class T>
class DLList{
    private:
    Node<T>* first;
    Node<T>* last;
    size_t currentSize;

    /* ----- Helper Functions ---- */
    void copy(const DLList<T>&);
    void destroy();

    /* ---- DLList Constructors ---- */
    public:
        DLList();
        DLList(const DLList<T>&);
        DLList<T>& operator=(const DLList<T>&);
        ~DLList();

        /* ---- Main Functions ---- */
        void push_back(const T& data);
        void push_front(const T& data);
        void pop_back();
        void pop_front();
        T front() const;
        T back() const;
        bool empty() const;
        size_t size() const;
        void print();
        void reverse();
};
