
#include <iostream>

using namespace std;

template <class T>
class Queue
{
    int front, end;
    T arr[50];       // Make changes here

public:
    Queue()
    {
        front = -1;
        end = -1;
    }
    bool isFull()
    {
        if ((front == end) && (front != -1))
            return true;
        return false;
    }

    bool isEmpty()
    {
        if ((front == end) && (end == -1))
            return true;
        return false;
    }
    void enqueue(T val)
    {
        if (isFull())
        {
            cout << "Overflow" << endl;
        }
        else
        {
            if (front == -1)
            {
                front = end = 0;
            }
            arr[front] = val;
            front = (front + 1) % 50;       // Make changes here
        }
    }
    T dequeue()
    {
        if (isEmpty())
        {
            cout << "Underflow" << endl;
            return -1;
        }
        else
        {
            T val = arr[end];
            end = (end + 1) % 50;       // Make changes here

            if (front == end)
            {
                end = -1;
                front = -1;
            }

            return val;
        }
    }
    T getFront()
    {
        return arr[front];
    }
};

/*
int main()
{
    Queue<int> q;

    for (int i = 1; i <= 5; i++)
    {
        cout << i << endl;
        q.enqueue(i);
    }

    for (int i = 1; i <= 5; i++)
    {
        cout << q.dequeue() << endl;
    }

    for (int i = 1; i <= 5; i++)
    {
        cout << i << endl;
        q.enqueue(i);
    }

    for (int i = 1; i <= 5; i++)
    {
        cout << q.dequeue() << endl;
    }
    return 0;
}
*/