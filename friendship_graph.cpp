#include "redblack_tree.h"

#include <iostream> 
#include <string>
#include <cstring>

using namespace std;

void rbTree::addFriend(string name1, string name2){
    rNode *add1 = findHelper(name1);
    rNode *add2 = findHelper(name2);
    if(add1 == NULL || add2 == NULL)
        return;
    if(add1->friends == NULL)
        Node *second = new Node(name2, NULL);
        add1->friends = second;
    else
    {
        Node *lastNode1 = add1->friends;
        while(lastNode1->next != NULL)
        {
            if (strcmp(lastNode1->name.c_str(), name2.c_str()) == 0){
                break;
            }
            lastNode1 = lastNode1->next;
        }
        if(lastNode1->next == NULL){
            Node *second = new Node(name2, NULL);
            lastNode1->next = second;
        }
    if(add2->friends == NULL)
        Node *first = new Node(name1, NULL);
        add2->friends = first;  
    else
    {
        Node *lastNode2 = add2->friends;
        while(lastNode2->next != NULL)
        {
            if (strcmp(lastNode2->name.c_str(), name2.c_str()) == 0){
                break;
            }
            lastNode2 = lastNode2->next;
        }
        if(lastNode2->next == NULL){
            Node *first = new Node(name1, NULL);
            lastNode2->next = first;
        }
    }
}

