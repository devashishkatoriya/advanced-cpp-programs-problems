
// Write a program to reverse a substring stored in a linked list

#include <iostream>

using namespace std;

class Node
{
public:
    char data;
    Node *next;

    Node()
    {
        data = '-';
        next = NULL;
    }
    Node(char A)
    {
        data = A;
        next = NULL;
    }
};

void display_list(Node *head)
{
    while(head != NULL)
    {
        cout << head -> data << " ";
        head = head -> next;
    }
    cout << endl;
}

Node *insertEnd(Node *head, char A)
{
    if (head == NULL)
    {
        return new Node(A);
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new Node(A);

    return head;
}

Node* reverse_substr(Node *head, string substr)
{
    const int n = substr.length();
    Node *temp = head;

    while(temp->next != NULL)
    {
        // If next char is substr
        if (temp->next->data == substr[0])
        {
            Node *temp2 = temp->next;

            bool isFound = true;
            for(int i=0; i<n && temp2!=NULL; i++, temp2=temp2->next)
            {
                if (substr[i] != temp2->data)
                {
                    isFound = false;
                    break;
                }
                //prev = temp2;
            }
            if (isFound)
            {
                Node *prev = temp2;
                Node *curr = temp->next;
                Node *nxt = curr->next;

                while(curr != temp2)
                {
                    curr->next = prev;

                    prev = curr;
                    curr = nxt;
                    nxt = nxt->next;
                }
                temp->next = prev;
                break;
            }
        }
        temp = temp->next;
    }

    return head;
}

int main()
{
    const string str = "helloworld";
    const string substr = "lowo";

    const int N = str.length();
    Node *head = NULL;

    for(int i=0; i<N; i++)
    {
        head = insertEnd(head, str[i]);
    }
    display_list(head);

    reverse_substr(head, substr);
    display_list(head);

    return 0;
}


/* OUTPUT

h e l l o w o r l d
h e l o w o l r l d
*/
