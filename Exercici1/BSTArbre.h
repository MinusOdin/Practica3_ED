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
        void recursive_getLeafNodes(BSTNode<K,V> * node, list<BSTNode<K, V>*>& llistaLeaf);
        BSTNode<K,V>* recursive_printSecondLargestKey(BSTNode<K,V> * node) const;
        void recursive_mirrorTree(BSTNode<K,V> * node);
        BSTNode<K,V>* recursive_search(BSTNode<K,V> * node, const K& k);
};

template<class K, class V>
BSTArbre<K, V>::BSTArbre(){
    root = nullptr;
    _size = 0;
}
template<class K, class V>
BSTArbre<K, V>::BSTArbre(BSTArbre *tree){
    this->root = tree->root;
    this->_size = tree->_size;
}
template<class K, class V>
BSTArbre<K, V>::~BSTArbre(){
    delete root;
}


template<class K, class V>
bool BSTArbre<K, V>::empty() const{
    return root == nullptr;
}
template<class K, class V>
int BSTArbre<K, V>::size() const{
    return _size;
}
template<class K, class V>
int BSTArbre<K, V>::height() const{
    return root->height();
}
template<class K, class V>
BSTNode<K,V>* BSTArbre<K, V>::insert(const K& k, const V& value){
    BSTNode<K, V> * newNode = new BSTNode<K, V>(k);
    if (root == nullptr) root = newNode;
    else{
        BSTNode<K, V> * auxNode = root;
        bool added = false;
        while(!added){
            if(auxNode->getKey() == k){
                auxNode->insertValue(value);
                delete newNode;
            }
            else if (newNode->getKey() > auxNode->getKey()){
                if (!auxNode->hasLeft()){
                    auxNode->setLeft(newNode);
                    added = true;
                    return newNode;
                }
                else auxNode = auxNode->getLeft();
            }
            else if(newNode->getKey() < auxNode->getKey()){
                if (!auxNode->hasRight()) {
                    auxNode->setRight(newNode);
                    added = true;
                    return newNode;
                }
                else auxNode = auxNode->getRight();
            }
        }
    }
    throw "algo va malament";
}
template<class K, class V>
const list<V>& BSTArbre<K, V>::valuesOf(const K& k) const{

}
template<class K, class V>
void BSTArbre<K, V>::printPreorder(const BSTNode<K,V>* n) const{
    cout << "Key: " << n->getKey() << " Values: {";

    for (auto const &i: n->getValues()) {
        cout << i <<",";
    }
    cout << "}" << endl;
    if(n->hasLeft()) printPreorder(n->getLeft());
    if(n->hasRight()) printPreorder(n->getRight());
}
template<class K, class V>
void BSTArbre<K, V>::printInorder(const BSTNode<K,V>* n) const{
    if(n->hasLeft()) printInorder(n->getLeft());
    cout << "Key: " << n->getKey() << " Values: {";

    for (auto const &i: n->getValues()) {
        cout << i <<",";
    }
    cout << "}" << endl;
    if(n->hasRight()) printInorder(n->getRight());
}
template<class K, class V>
void BSTArbre<K, V>::printPostorder(const BSTNode<K,V>* n) const{
    if(n->hasLeft()) printPostorder(n->getLeft());
    if(n->hasRight()) printPostorder(n->getRight());
    cout << "Key: " << n->getKey() << " Values: {";

    for (auto const &i: n->getValues()) {
        cout << i <<",";
    }
    cout << "}" << endl;
}
template<class K, class V>
const list<BSTNode<K, V>*>& BSTArbre<K, V>::getLeafNodes() const{
    return recursive_getLeafNodes(root);
}
template<class K, class V>
void BSTArbre<K, V>::recursive_getLeafNodes(BSTNode<K,V> * node, list<BSTNode<K, V>*>& llistaLeaf){
    if(node->isExternal()) llistaLeaf.insert(node);
    if(node->hasLeft()) recursive_getLeafNodes(node->getLeft());
    if(node->hasRight()) recursive_getLeafNodes(node->getRight());
}
template<class K, class V>
void BSTArbre<K, V>::printSecondLargestKey() const{
    BSTNode<K, V> * temp = recursive_printSecondLargestKey(root);
    cout << "Key: " << temp->getKey() << " Values: {";

    for (auto const &i: temp->getValues()) {
        cout << i <<",";
    }
    cout << "}" << endl;
}

template<class K, class V>
BSTNode<K,V>* BSTArbre<K, V>::recursive_printSecondLargestKey(BSTNode<K,V> * node) const{
    if(node->isExternal()){
        if(!node->isRoot()) return node->getParent();// cuidado if(!n->isRoot())
        else throw "Exeption nomes hi ha arrel";
    }
    if(node->hasRight()) recursive_printSecondLargestKey(node->getRight());
    else if(node->hasLeft()) return node->getLeft();
    throw "Exeption nomes hi ha arrel";

}
template<class K, class V>
void BSTArbre<K, V>::mirrorTree(){
    recursive_mirrorTree(root);
}

template<class K, class V>
void BSTArbre<K, V>::recursive_mirrorTree(BSTNode<K,V> * node){
    BSTNode<K,V> * temp = node->getLeft();
    node->setLeft(node->getRight());
    node->setRight(temp);
    if(node->hasLeft()) recursive_mirrorTree(node->getLeft());
    if(node->hasRight()) recursive_mirrorTree(node->getRight());
}
template<class K, class V>
BSTNode<K,V>* BSTArbre<K, V>::search(const K& k) const{
    return recursive_mirrorTree(root, k);
}

template<class K, class V>
BSTNode<K,V>* BSTArbre<K, V>::recursive_search(BSTNode<K,V> * node, const K& k){
    if( node->getKey() == k) return node;
    if(node->hasLeft()) recursive_search(node->getLeft());
    if(node->hasRight()) recursive_search(node->getRight());
    throw "EXCEPTION: Key no found";
}
#endif