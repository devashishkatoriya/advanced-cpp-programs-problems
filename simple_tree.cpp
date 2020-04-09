
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
        //val = NULL;
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
                cout << "Where to go (l/r) ? ";
                cin >> ch;
                if (ch == 'l')
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
                else if (ch == 'r')
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
                else if (ch == '0')
                {
                    cout << "Cancelling insertion." << endl;
                    break;
                }
                else
                {
                    cout << "Invalid option!" << endl;
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

int main()
{
    Tree<int> t;

    t.insert(5);
    t.insert(3);
    t.insert(7);

    cout << "\nInorder:";
    t.inorder(t.get_root());

    cout << "\nPreorder:";
    t.preorder(t.get_root());

    cout << "\nPostorder:";
    t.postorder(t.get_root());

    return 0;
}