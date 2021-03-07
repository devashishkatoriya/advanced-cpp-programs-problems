
// Program for circular linked list

#include <iostream>

using namespace std;


// Linked list node
class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};


// Function to display circular linked list
void display_ll(Node *head)
{
    if (head == NULL)
        return;
    Node *temp = head;

    while(temp->next != head)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << " ";
    cout << endl;
}


// Function to insert given value at the end of circular linked list
Node* insertEnd(Node *head, const int val)
{
    if (head == NULL)
    {
        Node *temp2 = new Node(val);
        temp2->next = temp2;
        return temp2;
    }

    Node *temp = head;
    while(temp->next != head)
    {
        temp = temp->next;
    }
    Node *temp2 = new Node(val);
    temp2->next = head;
    temp->next = temp2;

    return head;
}


// Function to delete a value from circular linked list
Node* deleteNode(Node *head, const int val)
{
    // If linked list is empty
    if (head == NULL)
    {
        return NULL;
    }

    // If we need to delete first node
    if (head->data == val)
    {
        Node *temp = head;
        while(temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;

        return temp->next;
    }

    // Else deletion node is somewhere in middle or at end 
    Node *temp = head;
    while(temp->next != head)
    {
        if (temp->next->data == val)
        {
            temp->next = temp->next->next;
            cout << "Value deleted." << endl;
            break;
        }
        temp = temp->next;
    }

    return head;
}


// Main function
int main()
{
    Node *ll;

    ll = insertEnd(ll, 1);

    display_ll(ll);

    ll = insertEnd(ll, 3);
    ll = insertEnd(ll, 5);

    display_ll(ll);

    ll = insertEnd(ll, 2);
    ll = insertEnd(ll, 4);
    ll = insertEnd(ll, 6);

    display_ll(ll);

    ll = deleteNode(ll, 1);

    display_ll(ll);

    return 0;
}