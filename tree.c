#include <iostream>
#include <string.h>
#include "Tree.h"

using namespace std;

Tree::Tree(){
    root = NULL;
    return;
}

Tree::~Tree(){
    ClearTree(root);
    return;
}

void Code202_Tree::ClearTree(TreeNode *T){
    if(T==NULL) return;
    if(T->left != NULL) ClearTree(T->left);
    if(T->right != NULL) ClearTree(T->right);
    delete T;
    return;
}

bool Tree::isEmpty(){
    return(root==NULL);
}

TreeNode *Tree::DupNode(TreeNode * T){
    TreeNode *dupNode;
    dupNode = new TreeNode();
    *dupNode = *T;
    dupNode->left = NULL;
    dupNode->right = NULL;
    return dupNode;
}

TreeNode *Tree::SearchTree(int Key){
    int ValueInTree = false;
    TreeNode *temp;

    temp = root;
    while((temp != NULL) && (temp->Key != Key)){
        if(Key < temp->Key)
            temp = temp->left;
        else
            temp = temp->right;
    }
    if(temp == NULL) return temp;
    else
        return(DupNode(temp));
}

int Tree::Insert(TreeNode *newNode){
    TreeNode *temp;
    TreeNode *back;
    temp = root;
    back = NULL;
    while(temp != NULL){
        back = temp;
        if(newNode->Key < temp->Key)
            temp = temp->left;
        else
            temp = temp->right;
    }
    if(back == NULL) 
        root = newNode;
    else{
        if(newNode->Key < back->Key)
            back->left = newNode;
        else
            back->right = newNode;
    }
   return(true);
}

int Tree::Insert(int Key, float f, int i, char *cA){
    TreeNode *newNode;
    newNode = new TreeNode();
    newNode->Key = Key;
    newNode->fValue = f;
    newNode->iValue = i;
    strcpy(newNode->cArray, cA);
    newNode->left = newNode->right = NULL;
    return(Insert(newNode));
}

int Tree::Delete(int Key){
    TreeNode *back;
    TreeNode *temp;
    TreeNode *delParent;
    TreeNode *delNode;
    temp = root;
    back = NULL;
    while((temp != NULL) && (Key != temp->Key)){
        back = temp;
        if(Key < temp->Key)
            temp = temp->left;
        else
            temp = temp->right;
    }

    if(temp == NULL){
        cout << "Key not found. Nothing deleted.\n";
        return false;
    }
    else{
        if(temp == root){
            delNode = root;
            delParent = NULL; 
        }                
        else{
            delNode = temp;
            delParent = back;
        }
    }

    if(delNode->right == NULL){
        if(delParent == NULL){
            root = delNode->left;
            delete delNode;
            return true;
        }
        else{
            if(delParent->left == delNode)
                delParent->left = delNode->left;
            else
                delParent->right = delNode->left;
                delete delNode;
            return true;
        }
    }
    else{
        if(delNode->left == NULL){
            if(delParent == NULL){
                root = delNode->right;
                delete delNode;
                return true;
            }
            else{
                if(delParent->left == delNode)
                    delParent->left = delNode->right;
                else
                    delParent->right = delNode->right;
                delete delNode;
                return true;
            }
        }
        else{
            temp = delNode->left;
            back = delNode;
            while(temp->right != NULL){
                back = temp;
                temp = temp->right;
            }
            delNode->Key = temp->Key;
            delNode->fValue = temp->fValue;
            delNode->iValue = temp->iValue;
            strcpy(delNode->cArray, temp->cArray);

            if(back == delNode)
                back->left = temp->left;
            else
                back->right = temp->left;
            delete temp;
            return true;
        }
    }
}

void Tree::PrintOne(TreeNode *T){
    cout << T->Key << "\t\t" << T->fValue << "\t\t" << T->iValue << "\t\t" 
        << T->cArray << "\n";
}

void Tree::PrintAll(TreeNode *T){
    if(T != NULL){
        PrintAll(T->left);
        PrintOne(T);
        PrintAll(T->right);
    }
}

void Tree::PrintTree(){
    PrintAll(root);
}

