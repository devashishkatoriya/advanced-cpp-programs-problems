
// Simple priority queue example

#include <iostream>

using namespace std;

template <class T>
class Element
{
public:
    T ele;
    int priority;
    Element()
    {
        ele = '-';
        priority = -999;
    }
};

template <class T2>
class PriorityQueue
{
    Element<T2> *arr;
    int front, rear;
    int n;

    bool isEmpty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return rear == n - 1;
    }

public:
    PriorityQueue()
    {
        n = 5;
        arr = new Element<T2>[n];

        front = -1;
        rear = -1;
    }
    PriorityQueue(int n)
    {
        arr = new Element<T2>[n];

        front = -1;
        rear = -1;
    }
    operator=(const PriorityQueue &s2)
    {
        n = s2.n;
        arr = new Element<T2>[n];

        front = s2.front;
        rear = s2.rear;

        return &this;
    }

    PriorityQueue(const PriorityQueue &p2)
    {
        n = p2.n;
        arr = new Element<T2>[n];

        front = p2.front;
        rear = p2.rear;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Underflow" << endl;
            return;
        }
        cout << "Priority Queue: ";
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i].ele << " ";
        }
        cout << endl;
    }
    void insert(T2 ele, int prio)
    {
        if (isFull())
        {
            cout << "Overflow!" << endl;
            return;
        }

        // If first insertion
        if (front == -1)
        {
            front = 0;
        }

        // Insert ele at last
        rear++;
        arr[rear].ele = ele;
        arr[rear].priority = prio;

        // Swap till ele at its correct pos
        for (int i = rear; i > front; i--)
        {
            if (arr[i].priority < arr[i - 1].priority)
            {
                Element<T2> temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
            }
            else
            {
                break;
            }
        }
    }
};

// Main Function
int main()
{
    PriorityQueue<char> q(5);

    q.insert('A', 4);
    q.insert('B', 1);
    q.insert('C', 3);

    q.display();

    q.insert('D', 5);
    q.insert('E', 0);

    q.display();

    return 0;
}