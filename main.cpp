#include <iostream>

#include "redblack_tree.h"

using namespace std;

int main(){
    rbTree tree;
    tree.insert("Dave", 1);
    tree.insert("Adam", 1);
    tree.insert("Even", 1);
    tree.insert("Ben", 1);
    tree.insert("Fre", 1);
    tree.insert("Cuz", 1);
    tree.addFriend("Dob", "Ben");
    tree.addFriend("Dave", "Fre");
    tree.ListFriendsInfo("Dave");
    //tree.ListInfo("Adam", "Dave");
    //tree.printAll();
    //cout<<'\n';
    return 0;
}