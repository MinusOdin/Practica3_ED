#include <iostream>
#include "BSTArbre.h"
#include "BSTNode.h"

using namespace std;

int main(){
    BSTArbre<int, int> * tree1 = new BSTArbre<int, int>();
    int testKeys[] = {2, 0, 8, 45, 76, 5, 3, 40};
    int testValues[] = {5, 5, 1, 88, 99, 12, 9, 11};
    for (int i = 0; i < size(testKeys); i++){
        tree1->insert(testKeys[i], testValues[i]);
    }
    tree1->printPreorder();
    tree1->printInorder();
    tree1->printPostorder();
    tree1->printSecondLargestKey();
    BSTArbre<int, int> * tree2 = new BSTArbre<int, int> (tree1);
    tree1->mirrorTree();
    tree1->printInorder();
    delete tree1;

}