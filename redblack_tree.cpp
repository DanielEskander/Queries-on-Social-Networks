#include "redblack_tree.h"

#include <iostream> 
#include <string>
#include <string.h> 

using namespace std;

void rbTree::insert(string name, int index){
    if(findHelper(name) != NULL)
        return;
    rNode *ptr = new rNode(name, index);
    root = rbinsert(root, ptr);
    fixViolation(root, ptr);
}

void rbTree::fixViolation(rNode *&root, rNode *&ptr){
    rNode *parent_ptr = NULL;
    rNode *grand_p_ptr = NULL;
    while((ptr != root) && (ptr->color != BLACK) && (ptr->parent->color == RED))
    {
        parent_ptr = ptr->parent;
        grand_p_ptr = ptr->parent->parent;
        if(parent_ptr == grand_p_ptr->left)
        {
            rNode *uncle_ptr = grand_p_ptr->right;
            if(uncle_ptr != NULL && uncle_ptr->color == RED)
            {
                grand_p_ptr->color = RED;
                parent_ptr->color = BLACK;
                uncle_ptr->color = BLACK;
                ptr = grand_p_ptr;
            }
            else
            {
                if(ptr == parent_ptr->right)
                {
                    rotateLeft(root, parent_ptr);
                    ptr = parent_ptr;
                    parent_ptr = ptr->parent;
                }
                rotateRight(root, grand_p_ptr);
                swap(parent_ptr->color, grand_p_ptr->color);
                ptr = parent_ptr;
            }
        }
        else
        {
            rNode *uncle_pt = grand_p_ptr->left;
            if((uncle_pt != NULL) && (uncle_pt->color == RED))
            {
                grand_p_ptr->color = RED;
                parent_ptr->color = BLACK;
                uncle_pt->color = BLACK;
                ptr = grand_p_ptr;
            }
            else
            {
                if(ptr == parent_ptr->left)
                {
                    rotateRight(root, parent_ptr);
                    ptr = parent_ptr;
                    parent_ptr = ptr->parent;
                }
                rotateLeft(root, grand_p_ptr);
                swap(parent_ptr->color, grand_p_ptr->color);
                ptr = parent_ptr;
            }
        }
    }
    root->color = BLACK;
}

rNode* rbTree::rbinsert(rNode *root, rNode *ptr){
    if(root == NULL)
        return ptr;
    if(strcmp(root->name.c_str(), ptr->name.c_str()) > 0){
        root->left = rbinsert(root->left, ptr);
        root->left->parent = root;
    }
    else if(strcmp(root->name.c_str(), ptr->name.c_str()) < 0){
        root->right = rbinsert(root->right, ptr);
        root->right->parent = root;
    }
    return root;
}

void rbTree::rotateLeft(rNode *&root, rNode *&ptr)
{
    rNode *ptr_right = ptr->right;
    ptr->right = ptr_right->left;
    if(ptr->right != NULL)
        ptr->right->parent = ptr;
    ptr_right->parent = ptr->parent;
    if(ptr->parent == NULL)
        root = ptr_right;
    else if(ptr == ptr->parent->left)
        ptr->parent->left = ptr_right;
    else
        ptr->parent->right = ptr_right;
    ptr_right->left = ptr;
    ptr->parent = ptr_right;
}

void rbTree::rotateRight(rNode *&root, rNode *&ptr)
{
    rNode *ptr_left = ptr->left;
    ptr->left = ptr_left->right;
    if (ptr->left != NULL)
        ptr->left->parent = ptr;
    ptr_left->parent = ptr->parent;
    if (ptr->parent == NULL)
        root = ptr_left;
    else if(ptr == ptr->parent->left)
        ptr->parent->left = ptr_left;
    else
        ptr->parent->right = ptr_left;
    ptr_left->right = ptr;
    ptr->parent = ptr_left;
}

string rbTree::ListFriendsInfo(string name){
    rNode *list = findHelper(name);
    if(list == NULL)
        return "";
    string output = "";
    while(list->friends != NULL){
        output += list->friends->name;
        output += " ";
        list->friends = list->friends->next;
    }
    return output;
}

void rbTree::ListInfo(string lown, string upn){
    return ListInfoHelper(lown, upn, root);
}

void rbTree::ListInfoHelper(string lown, string upn, rNode *root){
    if (root == NULL)
        return;
    ListInfoHelper(lown, upn, root->left);
    if(strcmp(root->name.c_str(), lown.c_str()) >= 0 && strcmp(root->name.c_str(), upn.c_str()) <= 0){
        cout<<root->name<< " ";
    }
    ListInfoHelper(lown, upn, root->right);
}

rNode* rbTree::findHelper(string name){
    return find(root, name);
}

rNode* rbTree::find(rNode *root, string name){
    if(root == NULL)
        return NULL;
    if(strcmp(name.c_str(), root->name.c_str()) == 0)
        return root;
    else if (strcmp(name.c_str(), root->name.c_str()) < 0)
        return find(root->left, name);
    else
        return find(root->right, name);
}

void rbTree::printHelper(rNode *root){
    //Mary,21,Developer,Jane,Alex,Ben
    if (root == NULL)
        return;
    printHelper(root->left);
    cout << root->name << "  " << root->color << " ";
    if(root->left != NULL)
        cout << root->left->name << " ";
    if(root->right != NULL)
        cout << root->right->name << " ";
    cout << "\n";
    printHelper(root->right);
}

void rbTree::printAll(){
    printHelper(this->root);
}


