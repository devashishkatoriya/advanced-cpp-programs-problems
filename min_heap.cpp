
// Min-Heap example program

#include <iostream>

using namespace std;


// Class for Min-Heap
class MinHeap
{
    int *arr;
    int size;
    int n;

    int getParent(const int x)
    {
        return (x % 2 == 0) ? (x - 1) / 2 : (x - 2) / 2;
    }

    void heapify()
    {
        int curr = n-1;
        int parent = getParent(curr);

        // While newly inserted element is lesser than its parent
        while(arr[curr] < arr[parent])
        {
            // Swap parent and that child
            int temp = arr[curr];
            arr[curr] = arr[parent];
            arr[parent] = temp;

            curr = getParent(curr);
            parent = getParent(curr);
        }
    }

public:
    MinHeap(int size)
    {
        this->size = size;
        arr = new int[this->size];
        n = 0;
    }

    int getMaxSize()
    {
        return this->size;
    }

    int getNumElements()
    {
        return this->n;
    }

    void displayHeap()
    {
        cout << "Heap is ";
        for(int i=0; i<n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void insert(int element)
    {
        if (n>=size)
        {
            cout << "Heap Overflow!" << endl;
            return;
        }

        arr[n] = element;
        n += 1;

        heapify();

        cout << element << " inserted successfully." << endl;
    }
};



// Main Function
int main()
{
    const int size = 20;
    
    MinHeap obj(20);

    obj.insert(1);
    obj.insert(2);
    obj.insert(3);
    obj.insert(4);
    obj.insert(5);
    obj.insert(6);
    obj.insert(0);
    obj.insert(7);
    obj.insert(8);
    obj.insert(9);
    obj.insert(10);
    obj.insert(-1);
    
    obj.displayHeap();

    return 0;
}