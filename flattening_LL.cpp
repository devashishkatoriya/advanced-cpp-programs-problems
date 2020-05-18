
/*
Given a Linked List of size N, where every node represents a linked 
list and contains two pointers of its type:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.

You have to flatten the linked list to a single linked list which 
should be sorted.

       5 -> 10 -> 19 -> 28
       |    |     |     |
       V    V     V     V
       7    20    22    35
       |          |     |
       V          V     V
       8          50    40
       |                |
       V                V
       30               45
And after flattening the above list, the sorted linked list looks like:

 5-> 7-> 8- > 10 -> 19-> 20-> 22-> 28-> 30-> 35-> 40-> 45-> 50.

Note: The flattened list will be printed using the bottom pointer 
instead of next pointer.

Input:
The first line of the input contains an integer 'T' denoting the number 
of test cases. Then T test cases follow.
First line of each test case contains an integer N denoting the number 
of head nodes connected to each other.
Second line of each test case contains N space separated numbers (M1, M2...Mn) 
denoting number of elements in linked lists starting with each head.
Third line of each test case contains all the elements of the linked list 
starting with 1st head node and covering all the elements through its down 
pointer, then 2nd head node and covering all its elements through down pointer 
and so on till the last head node of the linked list.

Output:
For each testcase, in a new line, print the flattened list in sorted order.

Your Task:
This is a function problem. You need to complete the function flatten() that 
takes head of the list as parameter and returns the root of flattened list. 
The printing is done by the driver code.

Constraints:
1 <= T <= 100
0 <= N <= 50
1 <= Mi <= 20
1 <= Element of linked list <= 103

Example:
Input:
1                   
4 
4 2 3 4                  
5 7 8 30 10 20 19 22 50 28 35 40 45

Output:
5 7 8 10 19 20 22 28 30 35 40 45 50
*/

// { Driver Code Starts
#include <bits/stdc++.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node *flatten(Node *root);

int main(void)
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, m, flag = 1, flag1 = 1;
        struct Node *temp = NULL;
        struct Node *head = NULL;
        struct Node *pre = NULL;
        struct Node *tempB = NULL;
        struct Node *preB = NULL;
        cin >> n;
        int work[n];
        for (int i = 0; i < n; i++)
            cin >> work[i];
        for (int i = 0; i < n; i++)
        {
            m = work[i];
            --m;
            int data;
            scanf("%d", &data);
            temp = new Node(data);
            temp->next = NULL;
            temp->bottom = NULL;

            if (flag)
            {
                head = temp;
                pre = temp;
                flag = 0;
                flag1 = 1;
            }
            else
            {
                pre->next = temp;
                pre = temp;
                flag1 = 1;
            }
            for (int j = 0; j < m; j++)
            {

                int temp_data;
                scanf("%d", &temp_data);
                tempB = new Node(temp_data);

                if (flag1)
                {
                    temp->bottom = tempB;
                    preB = tempB;
                    flag1 = 0;
                }
                else
                {
                    preB->bottom = tempB;
                    preB = tempB;
                }
            }
        }
        Node *fun = head;
        Node *fun2 = head;

        Node *root = flatten(head);
        printList(root);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
Node *flatten(Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    Node *temp, *bTemp;
    int dTemp, swapped;

    // Flatten the linked list towards bottom ptr
    temp = root;
    while (temp != NULL)
    {
        bTemp = temp;
        while (bTemp->bottom != NULL)
        {
            bTemp = bTemp->bottom;
        }

        bTemp->bottom = temp->next;
        temp = temp->next;
    }

    // Perform bubble sort on linked list
    bTemp = NULL;
    do
    {
        swapped = 0;
        temp = root;

        while (temp->bottom != bTemp)
        {
            if (temp->data > temp->bottom->data)
            {
                dTemp = temp->data;
                temp->data = temp->bottom->data;
                temp->bottom->data = dTemp;

                swapped = 1;
            }
            temp = temp->bottom;
        }
        bTemp = temp;
    } while (swapped);

    return root;
}
