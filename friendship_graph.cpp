#include "friendship_graph.h"

#include <iostream> 
#include <string>

using namespace std;

void fGraph::insert(string name){
    rNode *add = tree.findHelper(name);
    root = new graphNode(add->name, add->left, add->right);
}

void fGraph::addFriend(string name1, string name2){
    Node *first = new Node(name1, NULL);
    Node *second = new Node(name2, NULL);
    rNode *add1 = tree.findHelper(name1);
    rNode *add2 = tree.findHelper(name2);
    add1->friends->next = second;
    add2->friends->next = first;
}



