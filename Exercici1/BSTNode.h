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

        /* Consultors */
        const K& getKey() const;
        const list<V>& getValues() const;
        // Declareu-hi aquí els consultors (getters) dels atributs que manquen

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
        BSTNode<K,V>* left;
        BSTNode<K,V>* right;
        BSTNode<K,V>* parent;
        // Afegiu-hi aquí els atributs que manquen
};

template <class K, class V>
BSTNode<K,V>::BSTNode(const K& key){
    this.key = key;
}

template <class K, class V>
BSTNode<K,V>::BSTNode(const BSTNode<K,V>& orig){
    this.key = orig.key;
    this->values = orig.values;
}
template <class K, class V>
BSTNode<K,V>::~BSTNode(){
    delete left;
    delete right;
}

/* Modificadors */
// Declareu-hi aquí els modificadors (setters) dels atributs que manquen

/* Consultors */
template <class K, class V>
const K& BSTNode<K,V>::getKey() const{
    return this.key;
}
template <class K, class V>
const list<V>& BSTNode<K,V>::getValues() const{
    return this.values
}
// Declareu-hi aquí els consultors (getters) dels atributs que manquen

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
    values.insert(v);
}
template <class K, class V>
int BSTNode<K,V>::depth() const{

}
template <class K, class V>
int BSTNode<K,V>::height() const{

}
template <class K, class V>
bool BSTNode<K,V>::operator==(const BSTNode<K,V>& node) const{
    return key == node.key && values == node.values;
}
#endif