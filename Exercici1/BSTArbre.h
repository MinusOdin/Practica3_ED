#ifndef BSTArbre_H
#define BSTArbre_H

#include <iostream>
#include "BSTNode.h"

using namespace std;
template<class K, class V>
class BSTArbre {
    public:
        BSTArbre();
        BSTArbre(BSTArbre *tree);
        virtual ~BSTArbre();
        bool empty() const;
        int size() const;
        int height() const;
        BSTNode<K,V>* insert(const K& k, const V& value);
        const list<V>& valuesOf(const K& k) const;
        void printPreorder(const BSTNode<K,V>* n = nullptr) const;
        void printInorder(const BSTNode<K,V>* n = nullptr) const;
        void printPostorder(const BSTNode<K,V>* n = nullptr) const;
        const list<BSTNode<K, V>*>& getLeafNodes() const;
        void printSecondLargestKey() const;
        void mirrorTree();
    protected:
        BSTNode<K,V>* root;
        BSTNode<K,V>* search(const K& k) const;
    private:
        int _size;
        /* Mètodes auxiliars definiu aquí els que necessiteu */
};

template<class K, class V>
BSTArbre<K, V>::BSTArbre(){

}
template<class K, class V>
BSTArbre<K, V>::BSTArbre(BSTArbre *tree){

}
template<class K, class V>
BSTArbre<K, V>::~BSTArbre(){

}
template<class K, class V>
bool BSTArbre<K, V>::empty() const{

}
template<class K, class V>
int BSTArbre<K, V>::size() const{

}
template<class K, class V>
int BSTArbre<K, V>::height() const{

}
template<class K, class V>
BSTNode<K,V>* BSTArbre<K, V>::insert(const K& k, const V& value){

}
template<class K, class V>
const list<V>& BSTArbre<K, V>::valuesOf(const K& k) const{

}
template<class K, class V>
void BSTArbre<K, V>::printPreorder(const BSTNode<K,V>* n = nullptr) const{

}
template<class K, class V>
void BSTArbre<K, V>::printInorder(const BSTNode<K,V>* n = nullptr) const{

}
template<class K, class V>
void BSTArbre<K, V>::printPostorder(const BSTNode<K,V>* n = nullptr) const{

}
template<class K, class V>
const list<BSTNode<K, V>*>& BSTArbre<K, V>::getLeafNodes() const{

}
template<class K, class V>
void BSTArbre<K, V>::printSecondLargestKey() const{

}
template<class K, class V>
void BSTArbre<K, V>::mirrorTree(){

}
template<class K, class V>
BSTNode<K,V>* BSTArbre<K, V>::search(const K& k) const{
    
}
#endif