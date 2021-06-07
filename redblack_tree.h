#ifndef RBTREE_H
#define RBTREE_H

#include <string>
#include <iostream>

using namespace std;

enum Color {RED, BLACK};

struct Node{
    string name;
    Node *next;

     Node(string name, Node *next){
        this->name = name;
        this->next = next;
    }
};

struct rNode{
    string name;
    bool color;
    int index;
    rNode *parent;
    rNode *left;
    rNode *right;
    Node *friends;

    rNode(string name, int index){
        this->name = name;
        this->index = index;
        left = right = parent = NULL;
        this->color = RED;
        friends = NULL;
    }
};

struct User {
	char name[20];
	char age[3];
	char occupation[30];
};

class rbTree{
    private:
        rNode *root;
    public: 
        rbTree() {root = NULL;}; 
        void insert(string name, int index); //inserts new node into red black tree
        void addFriend(string name1, string name2);
        void fixViolation(rNode *&root, rNode *&ptr);
        void rotateLeft(rNode *&root, rNode *&ptr);
        void rotateRight(rNode *&root, rNode *&ptr);
        rNode* rbinsert(rNode *root, rNode *ptr); //inserts new node into red black tree
        void printRecord(int index, string rootName);
        string getString(); 
        void ListUserInfo(string name);
        void ListFriendsInfo(string name); //lists the name, age, occupation of name's friends
        void ListInfoHelper(string lown, string upn, rNode *root);
        void ListInfo(string lown, string upn); //lists name, age, occupation of all names between lown and upn inclusive
        rNode* findHelper(string name);
        rNode* find(rNode *root, string name);
        void printHelper(rNode *root);
        void printAll(); //prints name, age, occupation of all names in the red black tree
};

#endif