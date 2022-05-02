#ifndef BSTNode_H
#define BSTNode_H
#include <iostream>
#include <list>

using namespace std;

template<class K, class V>
class BSTNode {
    public:
        BSTNode(const K& key);
        BSTNode(const BSTNode<K,V>& orig);
        virtual ~BSTNode();

        /* Modificadors */
        // Declareu-hi aquí els modificadors (setters) dels atributs que manquen
        void setLeft(BSTNode<K,V> * newNode);
        void setRight(BSTNode<K,V> * newNode);

        /* Consultors */
        const K& getKey() const;
        const list<V>& getValues() const;
        // Declareu-hi aquí els consultors (getters) dels atributs que manquen
        BSTNode<K,V> * getLeft() const;
        BSTNode<K,V> * getRight() const;
        BSTNode<K,V> * getParent() const;

        /* Operacions */
        bool isRoot() const;
        bool hasLeft() const;
        bool hasRight() const;
        bool isExternal() const;
        void insertValue(const V& v);
        int depth() const;
        int height() const;
        bool operator==(const BSTNode<K,V>& node) const;
    private:
        K key;
        list<V> values;
        // Afegiu-hi aquí els atributs que manquen
        BSTNode<K,V>* left;
        BSTNode<K,V>* right;
        BSTNode<K,V>* parent;
        
};

template <class K, class V>
BSTNode<K,V>::BSTNode(const K& key){
    this->key = key;
}

template <class K, class V>
BSTNode<K,V>::BSTNode(const BSTNode<K,V>& orig){
    this->key = orig.key;
    this->values = orig.values;
}
template <class K, class V>
BSTNode<K,V>::~BSTNode(){
    if (hasLeft()) delete left;
    if (hasRight()) delete right;
    delete parent;
}

/* Modificadors */
// Declareu-hi aquí els modificadors (setters) dels atributs que manquen
template <class K, class V>
void setLeft(BSTNode<K,V> * newNode){
    left = newNode;
}
template <class K, class V>
void setRight(BSTNode<K,V> * newNode){
    right = newNode;
}

/* Consultors */
template <class K, class V>
const K& BSTNode<K,V>::getKey() const{
    return this->key;
}
template <class K, class V>
const list<V>& BSTNode<K,V>::getValues() const{
    return this->values;
}
// Declareu-hi aquí els consultors (getters) dels atributs que manquen
template <class K, class V>
BSTNode<K,V> * BSTNode<K,V>::getLeft() const{
    return left;
}
template <class K, class V>
BSTNode<K,V> * BSTNode<K,V>::getRight() const{
    return right;
}
template <class K, class V>
BSTNode<K,V> * BSTNode<K,V>::getParent() const{
    return parent;
}
/* Operacions */
template <class K, class V>
bool BSTNode<K,V>::isRoot() const{
    return parent == nullptr;
}
template <class K, class V>
bool BSTNode<K,V>::hasLeft() const{
    return left != nullptr;
}
template <class K, class V>
bool BSTNode<K,V>::hasRight() const{
    return right != nullptr;
}
template <class K, class V>
bool BSTNode<K,V>::isExternal() const{
    return left == nullptr && right == nullptr;
}
template <class K, class V>
void BSTNode<K,V>::insertValue(const V& v){
    values.push_back(v);
}
template <class K, class V>
int BSTNode<K,V>::depth() const{
    if (parent == nullptr)
        return 0;
    else 
        return depth(parent) + 1;
}

template <class K, class V>
int BSTNode<K,V>::height() const{
    if (isExternal()){
        return 1;
    }
    int height_left = 0;
    int height_right = 0;
    if (hasLeft())
        height_left = height(left) + 1;
    if (hasRight())
        height_right = height(right) + 1;
    return max(height_left, height_right);
}

template <class K, class V>
bool BSTNode<K,V>::operator==(const BSTNode<K,V>& node) const{
    return key == node.key && values == node.values;
}
#endif