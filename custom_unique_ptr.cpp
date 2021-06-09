#include <iostream>

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        data = 0;
        next = NULL;
    }
    Node(int x)
    {
        data = x;
    }
};

template <typename T>
class MyUniquePtr
{
    T *ptr;

public:
    MyUniquePtr()
    {
        ptr = new T();
    }

    ~MyUniquePtr()
    {
        delete ptr;
    }

    friend MyUniquePtr<T> make_unique();
    T *operator->()
    {
        return ptr;
    }

    T *operator=(MyUniquePtr obj)
    {
        this.ptr = obj.ptr;
        return this.ptr;
    }
};

template <typename T2>
MyUniquePtr<T2> make_unique()
{
    MyUniquePtr<T2> ptr;

    return ptr;
}

/*
template <typename T3>
MyUniquePtr<T3> make_unique(int num, ...)
{
    MyUniquePtr<T3> *ptr = new MyUniquePtr<T3>();

    return ptr;
}
*/

int main()
{
    MyUniquePtr<Node> obj = make_unique<Node>();
    MyUniquePtr<Node> obj2 = make_unique<Node>();

    obj->data = 1500;
    obj2->data = 2100;

    obj->next = obj2;

    std::cout << obj->data << std::endl;
}