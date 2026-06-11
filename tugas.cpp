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
}