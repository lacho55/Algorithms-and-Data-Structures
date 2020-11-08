#pragma once

template<class T>
struct Node{
    T data;
    Node<T>* left;
    Node<T>* right;

    Node(const T& newData, Node<T>* newLeft = nullptr, Node<T>* newRight = nullptr){
        data = newData;
        left = newLeft;
        right = newRight;
    }

};


template<class T>
class BinTree{
    private:
        Node<T>* root;

    public:
    /* ------- Public Methods -------- */
    BinTree();
    T search(const T&);
    void insert(const T&);
    void remove(const T&);
    void destroy();
    void print() const;
    ~BinTree();

    /* ------- Private Methods --------- */
    T findElement(const T&, Node<T>*&) const;
    T max(Node<T>*) const;
    void add(const T&, Node<T>*&);
    void deleteElement(const T&, Node<T>*&);
    void destroyTree(Node<T>*);
    void printTree(Node<T>*) const;
};


/* --------- Public Methods --------- */
template<class T>
BinTree<T>:: BinTree(){
    root = nullptr;
}


template<class T>
T BinTree<T>:: search(const T& element){
    findElement(element, this->root);
}


template<class T>
void BinTree<T>:: insert(const T& element){
    add(element, this->root);
} 


template<class T>
void BinTree<T>:: remove(const T& element){
    deleteElement(element, this->root);
}


template<class T>
void BinTree<T>:: destroy(){
    destroyTree(this->root);
}


template<class T>
void BinTree<T>:: print() const{
    printTree(this->root);
}


template<class T>
BinTree<T>:: ~BinTree(){
    destroy();
}


/* ------- Private Methods -------- */
template<class T>
T BinTree<T>:: findElement(const T& element, Node<T>*& node) const{

    if(element == node->data){
        return node->data;
    }
    else if(element < node->data){
        findElement(element, node->left);
    }
    else{
        findElement(element, node->right);
    }

    return nullptr;
}


template<class T>
T BinTree<T>:: max(Node<T>* val) const{

    Node<T>* node = val;

    while(node->right){
        node = node->right;
    }

    return node->data;
}


template<class T>
void BinTree<T>:: add(const T& element, Node<T>*& node){

    if(node){

        if(element < node->data){

            if(node->left){
                add(element, node->left);
            }
            else{
                node->left = new Node<T>(element, nullptr, nullptr);
            }
        }
        else if(element == node->data){
            return;
        }
        else{
            if(node->right){
                add(element, node->right);
            }
            else{
                node->right = new Node<T>(element, nullptr, nullptr);
            }
        }
    }
    else{
        node = new Node<T>(element, nullptr, nullptr);
    }
}


template<class T>
void BinTree<T>:: deleteElement(const T& element, Node<T>*& node){

    if(element < node->data){
        deleteElement(element, node->left);
    }
    else if(element > node->data){
        deleteElement(element, node->right);
    }
    else{
        if(node->left && node->right){
            node->data = max(node->left);

            deleteElement(max(node->left), node->left);
        }

        else if(node->left){
            Node<T>* temp = node;
            node = node->left;

            delete temp;
        }
        else{
            Node<T>* temp = node;
            node = node->right;

            delete temp;
        }
    }

}


template<class T>
void BinTree<T>:: destroyTree(Node<T>* node){

    if(node){

        destroyTree(node->left);
        destroyTree(node->right);

        delete node;
    }
}


template<class T>
void BinTree<T>:: printTree(Node<T>* node) const{

    if(node){

        printTree(node->left);

        std:: cout << node->data << " ";

        printTree(node->right);

        std:: cout << std:: endl;
    }
}
