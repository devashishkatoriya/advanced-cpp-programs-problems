
// Max-Heap example program

#include <iostream>

using namespace std;


// Class for Max-Heap
class MaxHeap
{
    int *arr;
    int size;
    int n;
    int MIN_VAL;

    int getParent(const int x)
    {
        return (x % 2 == 0) ? (x - 1) / 2 : (x - 2) / 2;
    }

    void heapify()
    {
        int curr = n-1;
        int parent = getParent(curr);

        // While newly inserted element is lesser than its parent
        while(arr[curr] > arr[parent])
        {
            // Swap parent and that child
            int temp = arr[curr];
            arr[curr] = arr[parent];
            arr[parent] = temp;

            curr = getParent(curr);
            parent = getParent(curr);
        }
    }

    void downHeapify()
    {
        int curr = 0;
        int child1 = (2*curr) + 1;
        int child2 = (2*curr) + 2;

        // While curr is less than (for max-heap) its children
        while((arr[curr] < arr[child1] || arr[curr] < arr[child2]) && curr < n)
        {
            if (arr[child1] > arr[child2])
            {
                int temp = arr[curr];
                arr[curr] = arr[child1];
                arr[child1] = temp;

                curr = child1;
                child1 = (2*curr) + 1;
                child2 = (2*curr) + 2;
            }
            else
            {
                int temp = arr[curr];
                arr[curr] = arr[child2];
                arr[child2] = temp;

                curr = child2;
                child1 = (2*curr) + 1;
                child2 = (2*curr) + 2;
            }
        }
    }

public:
    /**
     * @param size Size of heap to create
     */
    MaxHeap(int size)
    {
        this->size = size;
        arr = new int[this->size];
        n = 0;
        MIN_VAL = -9999999;
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

    /**
     * @param element Integer to insert into heap
     */
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

    // Function to remove top element from max-heap
    int remove()
    {
        if (n <= 0)
        {
            cout << "Heap Underflow!" << endl;
            return -9999;
        }
        int temp = arr[0];
        arr[0] = arr[n-1];
        arr[n-1] = temp;

        n -= 1;
        int result = arr[n];
        arr[n] = MIN_VAL;

        downHeapify();

        return result;
    }
};



// Main Function
int main()
{
    const int size = 20;
    
    MaxHeap obj(50);

    obj.displayHeap();

    for (int i=0; i<=11; i++)
    {
        obj.insert(i);
        obj.displayHeap();
    }

    cout << "Delete#1: " << obj.remove() << endl;
    obj.displayHeap();

    cout << "Delete#2: " << obj.remove() << endl;
    obj.displayHeap();

    cout << "Delete#3: " << obj.remove() << endl;
    obj.displayHeap();

    cout << "Delete#4: " << obj.remove() << endl;
    obj.displayHeap();

    return 0;
}