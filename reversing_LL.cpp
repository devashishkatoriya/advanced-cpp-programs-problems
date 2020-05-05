/*
Given a linked list of N nodes.The task is to reverse this list.

Input : Head of following linked list 1->2->3->4->NULL
            Output : Linked list should be changed to,
4->3->2->1->NULL

    Input : Head of following linked list 1->2->3->4->5->NULL
                Output : Linked list should be changed to,
5->4->3->2->1->NULL

    Input : NULL
                Output : NULL

                                Input : 1->NULL
                                    Output : 1->NULL

                                        Input : First line of input contains number of testcases T.For each testcase,
first line contains length of linked list and next line contains the elements of linked list.

    Output : Reverse the linked list and return head of the modified list.

                User Task : The task is to complete the function
                            reverseList() which head reference as the only argument and
    should return new head after reversing the list.

        Constraints : 1 <= T <= 100 1 <= N <= 103

        Example : Input : 2 6 1 2 3 4 5 6 5 2 7 8 9 10 Output : 6 5 4 3 2 1 10 9 8 7 2

                    Explanation : Testcase 1 : After reversing the list,
elements are as 6->5->4->3->2->1. Testcase 2 : After reversing the list, elements are as 10->9->8->7->2.
*/

// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
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

void append(struct Node **head_ref, struct Node **tail_ref,
            int new_data)
{
    struct Node *new_node = new Node(new_data);

    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

/* Function to get the middle of the linked list*/
struct Node *reverseList(struct Node *head);

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

/* Driver program to test above function*/
int main()
{
    int T, n, l;
    cin >> T;

    while (T--)
    {
        struct Node *head = NULL, *tail = NULL;

        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> l;
            append(&head, &tail, l);
        }
        head = reverseList(head);

        printList(head);

        cout << endl;
    }
    return 0;
}

// } Driver Code Ends

/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

Node *append_beg(Node *head, int val)
{
    struct Node *new_node = new Node(val);

    if (head == NULL)
        head = new_node;
    else
        new_node->next = head;
    head = new_node;

    return head;
}

// Should reverse list and return new head.
Node *reverseList(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *t = head;
    struct Node *new_node = new Node(head->data);
    Node *t2 = NULL;
    while (t->next != NULL)
    {
        t2 = append_beg(t2, t->data);
        t = t->next;
    }
    t2 = append_beg(t2, t->data);

    return t2;
}
