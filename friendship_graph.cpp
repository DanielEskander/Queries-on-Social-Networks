#include "redblack_tree.h"

#include <iostream> 
#include <string>

using namespace std;

void rbTree::addFriend(string name1, string name2){
    Node *first = new Node(name1, NULL);
    Node *second = new Node(name2, NULL);
    rNode *add1 = findHelper(name1);
    rNode *add2 = findHelper(name2);
    if(add1 == NULL || add2 == NULL)
        return;
    if(add1->friends == NULL)
        add1->friends = second;
    else
    {
        Node *lastNode1 = add1->friends;
        while(lastNode1->next != NULL)
        {
            lastNode1 = lastNode1->next;
        }
        lastNode1->next = second;
    }
    if(add2->friends == NULL)
        add2->friends = first;  
    else
    {
        Node *lastNode2 = add2->friends;
        while(lastNode2->next != NULL)
        {
            lastNode2 = lastNode2->next;
        }
        lastNode2->next = first;
    }
}




