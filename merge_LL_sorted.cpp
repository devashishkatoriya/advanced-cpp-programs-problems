// { Driver Code Starts
#include <iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *sortedMerge(struct Node *a, struct Node *b);

void append(struct Node **head_ref, struct Node **tail_ref, int new_data)
{
    struct Node *new_node = new Node(new_data);

    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

/* Function to print Nodes in a given linked list */
void printList(struct Node *n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

/* Driver program to test above function*/
int main()
{
    int T, i, n1, n2, l, k;

    cin >> T;

    while (T--)
    {
        struct Node *head1 = NULL, *tail1 = NULL;
        struct Node *head2 = NULL, *tail2 = NULL;

        cin >> n1 >> n2;
        for (i = 1; i <= n1; i++)
        {
            cin >> l;
            append(&head1, &tail1, l);
        }
        for (i = 1; i <= n2; i++)
        {
            cin >> l;
            append(&head2, &tail2, l);
        }
        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends

/* Link list Node
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

// Function to merge the two sorted linked lists
// head1, head2: head of the two sorted linked lists
Node *sortedMerge(Node *head1, Node *head2)
{
    if (head1 == NULL)
        return head2;
    else if (head2 == NULL)
        return head1;

    Node *t1 = head1;
    Node *t2 = head2;

    Node *n1, *n2;

    while (t1->next != NULL && t2->next != NULL)
    {
        if (t1->data > t2->data)
        {
            n1 = t1->next;
            n2 = t2->next;

            t2->next = t1;
            t1 = t2;
            t2 = n2;

            head1 = t1;
        }
        else
        {
            // Find correct position
            while (t1->next != NULL && t1->next->data < t2->data)
            {
                t1 = t1->next;
            }

            n1 = t1->next;
            n2 = t2->next;

            t1->next = t2;
            t2->next = n1;
            t2 = n2;
            t1 = t1->next;
        }
    }
    if (t1->next == NULL)
    {
        t1->next = t2;
    }
    else
    {
    }
    /*
    // Find correct position
    while (n1->next != NULL && n2->next != NULL && n1->data < t2->data)
    {
        t1 = t1->next;
        t2 = t2->next;
        
        n1 = t1->next;
        n2 = t2->next;
    }
    */

    return head1;
}
