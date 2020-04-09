
/*
    Program to show the working of stack
    Author      :       Devashish Katoriya
*/

#include <iostream>

using namespace std;

template <class T>
class Stack
{
    int top, n;
    T *arr;

public:
    Stack()
    {
        top = -1;
        n = 100;
        arr = new T[n];
    }
    ~Stack()
    {
        top = -1;
        n = -1;
        //delete (arr T);
    }
    Stack(const Stack &s2)
    {
        top = s2.top;
        n = s2.n;
        arr = new T[n];
    }
    operator=(const Stack &s2)
    {
        top = s2.top;
        n = s2.n;
        arr = new T[n];
        return s2;
    }
    int getTop()
    {
        return top;
    }
    T getTopElement()
    {
        if (isEmpty())
            return -1;
        return arr[top];
    }
    bool isEmpty()
    {
        return top == -1;
    }
    bool isFull()
    {
        return top == 100 - 1;
    }
    void push(T ele)
    {
        if (!isFull())
            arr[++top] = ele;
        else
            cout << "Stack overflow!" << endl;
    }
    T pop()
    {
        if (!isEmpty())
            return arr[top--];
        else
            cout << "Stack underflow!" << endl;
        return -1;
    }
};

/*
int main()
{
    Stack<int> s;
    for (int i = 1001; i <= 1200; i++)
    {
        cout << s.getTopElement() << endl;
        s.push(i);
    }
    for (int i = 1001; i <= 1200; i++)
    {
        cout << s.getTopElement() << endl;
        s.pop();
    }
    for (int i = 1001; i <= 1200; i++)
    {
        cout << s.getTopElement() << endl;
        s.push(i);
    }
    for (int i = 1001; i <= 1200; i++)
    {
        cout << s.getTopElement() << endl;
        s.pop();
    }
    return 0;
}
*/