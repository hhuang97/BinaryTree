#include <iostream>
#include <string.h>
#include "Tree.h"

using namespace std;

int main(void){
    Code202_Tree    *theTree;
    TreeNode        *newNode;

    theTree = new Tree();

    cout <<"Building tree...\n";
    newNode = new TreeNode();
    newNode->Key = 8;
    newNode->iValue = 2;
    newNode->fValue = 2.3f;
    strcpy(newNode->cArray, "Node1");
    newNode->left = newNode->right = NULL;
    theTree->Insert(newNode);

    newNode = new TreeNode();
    newNode->Key = 4;
    newNode->iValue = 4;
    newNode->fValue = 3.4f;
    strcpy(newNode->cArray, "Node2");
    newNode->left = newNode->right = NULL;
    theTree->Insert(newNode);
    newNode = new TreeNode();
    newNode->Key = 12;
    newNode->iValue = 8;
    newNode->fValue = 4.5f;
    strcpy(newNode->cArray, "Node3");
    newNode->left = newNode->right = NULL;
    theTree->Insert(newNode);
    newNode = new TreeNode();
    newNode->Key = 2;
    newNode->iValue = 16;
    newNode->fValue = 5.6f;
    strcpy(newNode->cArray, "Node4");
    newNode->left = newNode->right = NULL;
    theTree->Insert(newNode);
    newNode = new TreeNode();
    newNode->Key = 6;
    newNode->iValue = 32;
    newNode->fValue = 6.7f;
    strcpy(newNode->cArray, "Node5");
    newNode->left = newNode->right = NULL;
    theTree->Insert(newNode);

    theTree->Insert(10, 7.8f, 64, "Node6");
    theTree->Insert(14, 8.9f, 128, "Node7");
    theTree->Insert(1, 9.0f, 256, "Node8");
    theTree->Insert(3, 0.9f, 512, "Node9");
    theTree->Insert(5, 9.8f, 1024, "Node10");
    theTree->Insert(7, 8.7f, 2048, "Node11");
    theTree->Insert(9, 7.6f, 4096, "Node12");
    theTree->Insert(11, 6.5f, 8192, "Node13");
    theTree->Insert(13, 5.4f, 16384, "Node14");
    theTree->Insert(15, 4.3f, 32768, "Node15");

    cout <<"All nodes inserted\n";

    cout <<"-----------------------------------------------------\n";
    theTree->PrintTree();
    cout <<"Press Enter to continue...";
    cin.get();
    cout <<"-----------------------------------------------------\n";

    cout <<"-----------------------------------------------------\n";
    cout <<"Testing the search function\n";
    newNode = theTree->SearchTree(13);
    if(newNode != NULL)
    {
        theTree->PrintOne(newNode);
        delete newNode;
    }
    else
        cout <<"Search key not found.\n";

    newNode = theTree->SearchTree(6);
    if(newNode != NULL)
    {
        theTree->PrintOne(newNode);
        delete newNode;
    }
    else
        cout <<"Search key not found.\n";

    newNode = theTree->SearchTree(1);
    if(newNode != NULL)
    {
        theTree->PrintOne(newNode);
        delete newNode;
    }
    else
        cout <<"Search key not found.\n";

    newNode = theTree->SearchTree(25);
    if(newNode != NULL)
    {
        theTree->PrintOne(newNode);
        delete newNode;
    }
    else
        cout <<"Search key not found.\n";

    cout <<"-----------------------------------------------------\n";
    cout <<"Testing delete function\n";
    cout <<"-----------------------------------------------------\n";
    cout <<"Testing deleting a leaf...\n";
    theTree->Delete(7);
    theTree->PrintTree();
     cout <<"Press Enter to continue...";
    cin.get();
    cout <<"-----------------------------------------------------\n";

    cout <<"-----------------------------------------------------\n";
    cout <<"Testing deleting a node with 2 children...\n";
    theTree->Delete(12);
    theTree->PrintTree();
    cout <<"Press Enter to continue...";
    cin.get();
    cout <<"-----------------------------------------------------\n";

    cout <<"-----------------------------------------------------\n";
    cout <<"Testing deleting a node with 1 child...\n";
    theTree->Delete(6);
    theTree->PrintTree();
    cout <<"Press Enter to continue...";
    cin.get();
    cout <<"-----------------------------------------------------\n";

    cout <<"-----------------------------------------------------\n";
    cout <<"Testing trying to delete a node that is not in the tree...\n";
    theTree->Delete(7);
    theTree->PrintTree();
    cout <<"Press Enter to continue...";
    cin.get();
    cout <<"-----------------------------------------------------\n";

    cout <<"-----------------------------------------------------\n";
    cout <<"Testing deleting the root...\n";
    theTree->Delete(8);
    theTree->PrintTree();
    cout <<"Done.\nPress Enter to continue...";
    cin.get();

    cout <<"-----------------------------------------------------\n";
    return 0;
}

