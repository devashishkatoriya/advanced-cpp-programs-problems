
#include <iostream>

using namespace std;

template <class T2>
class Node
{
public:
    T2 val;
    Node *left, *right;
    Node()
    {
        left = right = NULL;
    }
};

template <class T>
class Tree
{
    Node<T> *root;

public:
    Tree()
    {
        root = NULL;
    }
    void insert(T ele)
    {
        Node<T> *node1 = new Node<T>;
        node1->val = ele;
        cout << "\nGot element: " << node1->val << endl;

        if (root == NULL)
        {
            cout << "Root node inserted." << endl;
            root = node1;
        }
        else
        {
            char ch;
            Node<T> *curr = root;
            while (1)
            {
                cout << "Currently at " << curr->val << endl;
                if (node1->val < curr->val)
                {
                    if (curr->left == NULL)
                    {
                        cout << "Inserted to left of " << curr->val << endl;
                        curr->left = node1;
                        break;
                    }
                    else
                    {
                        cout << "Traversing to left." << endl;
                        curr = curr->left;
                    }
                }
                else
                {
                    if (curr->right == NULL)
                    {
                        cout << "Inserted to right of " << curr->val << endl;
                        curr->right = node1;
                        break;
                    }
                    else
                    {
                        cout << "Traversing to right." << endl;
                        curr = curr->right;
                    }
                }
            }
        }
    }
    Node<T> *get_root()
    {
        return root;
    }
    void inorder(Node<T> *node)
    {
        if (node == NULL)
            return;
        inorder(node->left);
        cout << " " << node->val;
        inorder(node->right);
    }

    void preorder(Node<T> *node)
    {
        if (node == NULL)
            return;
        cout << " " << node->val;
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node<T> *node)
    {
        if (node == NULL)
            return;
        postorder(node->left);
        postorder(node->right);
        cout << " " << node->val;
    }
};

// Main Function
int main()
{
    Tree<int> t;

    t.insert(5);
    t.insert(3);
    t.insert(7);
    t.insert(9);
    t.insert(6);
    t.insert(4);
    t.insert(-1);
    t.insert(1);
    t.insert(2);
    t.insert(15);

    cout << "\nInorder Traversal:";
    t.inorder(t.get_root());

    cout << "\nPreorder Traversal:";
    t.preorder(t.get_root());

    cout << "\nPostorder Traversal:";
    t.postorder(t.get_root());
    return 0;
}