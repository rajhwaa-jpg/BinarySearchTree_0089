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

        if (element<parent->info)
        {
            parent->leftchild = newnode;
        }
        else if (element>parent->info)
        {
            parent->rightchild = newnode;
        }
    }
    //this function searches the current node of the specified node
    //as well as the current node of is parrent
    void search(string element, node *&parent, node *&currentnode)
    {
        currentnode = ROOT;
        parent = NULL;

        while ((currentnode !=NULL) && (currentnode->info != element))
        {
            parent = currentnode;

            if (element<currentnode->info)
                currentnode = currentnode->leftchild;
            else
                currentnode = currentnode->rightchild;
        }
    }
    void inorder(node *ptr)
    {
        if (ROOT ==NULL)
        {
            cout << "tree is empty" << endl;
            return;
        }
        if (ptr !=NULL)
        {
            inorder(ptr->leftchild);
            cout << ptr->info << "";
            inorder(ptr->rightchild);
        }
    }
    void preorder(node *ptr)
    {
        if (ROOT == NULL)
        {
            cout << "tree is empty" << endl;
            return;
        }
        if (ptr != NULL)
        {
            cout << ptr->info << "";
            preorder(ptr->leftchild);
            preorder(ptr->rightchild);
        }
    }
    void postorder(node *ptr)
    {
        //perfoms the postorder traveelsal os the tree

        if (ROOT == NULL)
        {
            cout << "tree is empty" << endl;
            return;
        }
        if (ptr != NULL)
        {
            postorder(ptr->leftchild);
            postorder(ptr->rightchild);
            cout << ptr->info << "";
        }
    }   
};

int main()
{
    binarytree obj;

    while (true)
    {
        cout << "\nmenu" << endl;
        cout << "1. implement insert operation" << endl;
        cout << "2. perform inorder traversal" << endl;
        cout << "3. perform preorder traversal" << endl;
        cout << "4. perform postorder traversal" << endl;
        cout << "5. exit" << endl;
        cout << "\nenter your choice (1-5): ";

        char ch;
        cin >> ch;
        switch (ch)
        {
        case '1':
        {
            cout << "enter a word: ";
            string word;
            cin >> word;
            obj.insert(word);
            break;
        }
        case '2':
        {
            obj.inorder(obj.ROOT);
            break;
        }
        case '3':
        {
            obj.preorder(obj.ROOT);
            break;
        }
        case '4':
        {
            obj.postorder(obj.ROOT);
            break;
        }
        case '5':
        {
            exit(0);
        }
        default:
        {
            cout << "invalid choice!" << endl;
        }
        }
    }
    return 0;
}