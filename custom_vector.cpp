
// Program to implement std::vector 

#include <iostream>

template <typename T>
class Vector
{
    class Node
    {
    public:
        T val;
        Node *next;
        Node(T value)
        {
            val = value;
            next = nullptr;
        }
    };

    Node *head;
    Node *tail;

    int vector_size;

public:
    Vector()
    {
        head = tail = nullptr;
        vector_size = 0;
    }
    Vector(int num, T defau)
    {
        head = tail = nullptr;
        vector_size = 0;

        for (int i=0; i<num; i++)
        {
            push_front(defau);
        }
    }

    int size() const
    {
        return vector_size;
    }

    void push_front(T value)
    {
        Node *n_node = new Node(value);

        if (head == nullptr)
        {
            head = tail = n_node;
        }
        else
        {
            n_node->next = head;
            head = n_node;
        }
        vector_size++;
    }

    void push_back(T value)
    {
        Node *n_node = new Node(value);

        if (head == nullptr)
        {
            head = tail = n_node;
        }
        else
        {
            tail->next = n_node;
            tail = n_node;
        }
        vector_size++;
    }

    T pop_front()
    {
        T temp;

        if (head == nullptr)
            return temp;

        temp = head->val;
        head = head->next;

        vector_size--;
        return temp;
    }

    T pop_back()
    {
        T temp;

        if (head == nullptr)
            return temp;

        temp = tail->val;
        Node *t2;
        t2 = head;

        while(t2->next != tail)
        {
            t2 = t2->next;
        }
        t2->next = nullptr;
        tail = t2;

        vector_size--;
        return temp;
    }

    T operator[](int n)
    {
        Node *temp = head;
        temp = head;
        for (int i=0; i<n && temp!=nullptr; i++)
        {
            temp = temp->next;
        }
        return temp->val;
    }
};

int main()
{
    Vector<int> obj;

    obj.push_back(5);
    obj.push_back(4);
    obj.push_back(3);
    obj.push_back(2);
    obj.push_back(1);

    obj.pop_back();
    obj.pop_back();

    obj.push_front(3);
    obj.push_front(2);
    obj.push_front(1);

    obj.pop_front();

    for (int i=0; i<obj.size(); i++)
    {
        std::cout << obj[i] << std::endl;
    }
}