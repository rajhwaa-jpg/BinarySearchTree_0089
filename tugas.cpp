#include <iostream>
#include <string>
using namespace std;

class node 
{
public:
    string info;
    node *leftchild;
    node *rightchild;

    //constructor for the node class
    node (string i, node *l, node *r)
    {
        info = i;
        leftchild = l;
        rightchild = r;
    }
};

class binarytree
{
public:
    node *ROOT;

    binarytree()
    {
        ROOT = NULL; //initializing ROOT to NULL
    }

    //insert a node in the binary search tree
    void insert(string element)
    {
        node *newnode = new node(element, NULL, NULL);

        newnode->info = element;
        newnode->leftchild = NULL;
        newnode->rightchild = NULL;

        node *parent = NULL;
        node *currentnode = NULL;

        search(element, parent, currentnode);

        if (parent == NULL)
        {
            ROOT = newnode;
            return;
        }
    }
}