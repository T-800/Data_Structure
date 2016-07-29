#ifndef DATA_STRUCTURE_TREE_H
#define DATA_STRUCTURE_TREE_H

#include <vector>


template<typename T>
class Node {

protected:
    T* data;
    Node<T>* parent;
    std::vector< Node<T>* > children;
    Node(){};
public:

    Node(Node<T>* parent, T data);
    ~Node();


    T& getData() const;
    void setData(const T& data);
    Node<T>* getParent() const;

};


template<typename U>
class BNode : Node<U>{

private:

public:

    BNode(BNode<U>* parent, U data);

    friend std::ostream& operator <<(std::ostream& out, const BNode& v){
        out << v.data << ": ";
        out << "left: " << v.children[0] << ", right: " << v.children[1];
        return out;
    }
    BNode<U>* getLeft();
    BNode<U>* getRight();
    void setLeft(BNode<U>* left) const;
    void setRight(BNode<U>* right) const;

    void setLeft(const U& data) const;
    void setRight(const U& data) const;



};


template<typename V>
class NNode : Node<V>{

private:

public:

    NNode(NNode<V>* parent, V data);

    friend std::ostream& operator <<(std::ostream& out, const NNode& v){
        out << v.data << ": ";
        for(int i=0; i<v.children.size(); i++){
            out << v.children[i] << " ";
        }
        return out;
    }
    void addChild(const V& data);
    void removeChild(const std::size_t& indx);
    NNode<V>* findChild(const V& data) const;
    NNode<V>* getChild(const std::size_t& indx) const;
    int getNumChildren() const;


};


template<class T>
Node<T>::Node(Node<T>* parent, T data) : parent(parent){
    Node<T>::data = new T(data);
}

template<class U>
BNode<U>::BNode(BNode<U>* parent, U data){
    this->parent = parent;
    this->data = new U(data);
}

template<class U>
BNode<U>* BNode<U>::getLeft() {
    return this->children[0];
}

template<class U>
BNode<U>* BNode<U>::getRight(){
    return this->children[1];
}
template<class U>
void BNode<U>::setLeft(BNode<U> *left) const {
    this->children[0] = left;
}

template<class U>
void BNode<U>::setRight(BNode<U> *right) const {
    this->children[1] = right;
}

template<class U>
void BNode<U>::setLeft(const U &data) const {
    this->children[0] = new U(this, data);
}

template<class U>
void BNode<U>::setRight(const U &data) const {
    this->children[1] = new U(this, data);
}

template<class T>
NNode<T>::NNode(NNode<T>* parent, T data){
    this->parent = parent;
    this->data = new T(data);
}


template<class T>
Node<T>::~Node() {
    delete data;
    for(Node<T>* childNode : children)
        delete childNode;
}

template<class T>
T& Node<T>::getData() const {
    return *this->data;
}

template<class T>
void Node<T>::setData(const T& data) {
    *this->data = data;
}


template<class T>
Node<T>* Node<T>::getParent() const {
    return parent;
}

template<class T>
void NNode<T>::addChild(const T& data) {
    this->children.push_back(new NNode<T>(this, data));
}

template<class T>
void NNode<T>::removeChild(const std::size_t& indx) {
    this->children.erase(this->children.begin()+indx);
}


template<class T>
NNode<T>* NNode<T>::findChild(const T& data) const {
    for(int i=0; i<this->children.size(); i++)
        if(this->children[i]->getData() == data)
            return this->children[i];
    return nullptr;
}

template<class T>
NNode<T>* NNode<T>::getChild(const std::size_t& indx) const {
    return this->children[indx];
}

template<class T>
int NNode<T>::getNumChildren() const {
    return this->children.size();
}


#endif //DATA_STRUCTURE_TREE_H
