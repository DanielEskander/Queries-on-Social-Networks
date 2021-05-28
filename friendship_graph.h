#ifndef FGRAPH_H
#define FGRAPH_H

#include <string>
#include <iostream>
#include "redblack_tree.h"

using namespace std;

struct graphNode{
    string name;
    rNode *left;
    rNode *right;

    graphNode(string name, rNode *left, rNode *right){
        this->name = name;
        this->left = left;
        this->right = right;
    }
};

class fGraph{
    private:
        graphNode *root;
        rbTree tree; //Note, might not be the same instance as in redblack tree so values might be wrong
    public: 
        fGraph() {root = NULL;};
        void insert(string name);
        void addFriend(string name1, string name2);
};

#endif