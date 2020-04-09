
#include <iostream>

using namespace std;

template <class T>
class HashTable
{
    T *arr;
    int n, size, k;

    int get_hash(T ele)
    {
        return (ele * ele) % k;
    }

    void clean()
    {
        for (int i = 0; i < n; i++)
        {
            arr[i] = -1;
        }
    }

public:
    HashTable()
    {
        n = 20;
        size = 0;
        k = 7;
        arr = new T[n];
        clean();
    }
    HashTable(int n)
    {
        size = 0;
        k = 7;
        arr = new T[n];
        clean();
    }
    void insert(T ele)
    {
        int pos = get_hash(ele);
        while (arr[pos] != -1)
        {
            pos = (pos + 1) % n;
        }
        arr[pos] = ele;
    }
    int get_size()
    {
        return size;
    }
    void display()
    {
        cout << "\nHash Table:" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << endl;
        }
    }
};

int main()
{
    HashTable<int> h;

    h.insert(7);
    h.insert(17);
    h.insert(4);
    h.insert(1);

    h.display();

    return 0;
}