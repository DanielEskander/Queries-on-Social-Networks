#ifndef RBTREE_H
#define RBTREE_H

#include <string>
#include <iostream>
#include <linux/rbtree.h>

using namespace std;

struct rbNode{
    string name;
    int index;
    struct rb_node node;
};

class rbTree{
    private:

    public: 
        rbTree();
        void insert(); //inserts new node into red black tree
        string ListFriendsInfo(string name); //lists the name, age, occupation of name's friends
        string ListInfo(string lown, string upn); //lists name, age, occupation of all names between lown and upn inclusive
        void insert(); //inserts new node into red black tree
        void printAll(); //prints name, age, occupation of all names in the red black tree
}

#endif