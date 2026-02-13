//! heap data structure in C++

#include <iostream>
#include <vector>


//? class for implementing heap (max heap)
class heap {

public:
    std :: vector<int> arr;
    int size;

    //^ constructor for initialization
    heap() {
        arr.push_back(-1);
        size = 0;
    }

    //^ method to insert value
    void insert(int val) {

        size += 1;
        int idx = size;
        arr.push_back(val);

        //todo place value to its correct position
        while(idx > 1) {
            int par = idx / 2;

            if(arr[par] < arr[idx]) {
                std :: swap(arr[par], arr[idx]);
                idx = par;
            }
            else {
                break;;
            }
        }
    }

    //^ function for deletion (deleting root)
    void deleteRoot() {

        if(size == 0) {
            std :: cout << "nothing to delete!\n";
            return;
        }

        //& swap root with last node
        std :: swap(arr[1], arr[size]);
        size--; //~ delete last node

        //todo take root to its correct position
        int i = 1;
        while(i <= size) {

            //^ left nd right child index
            int leftIdx = 2*i;
            int rightIdx = 2*i+1;
            int largest = i;

            if(leftIdx <= size && arr[i] < arr[leftIdx]) {
                largest = leftIdx;
            }
            if(rightIdx <= size && arr[i] < arr[rightIdx]) {
                largest = rightIdx;
            }

            //? if left right child is actually larger
            if(largest != i) {
                std :: swap(arr[i], arr[largest]);
                largest = i;
            }
            else {
                break;
            }
        }
    }    

    //^ print heap (array order)
    void print() {
        for(int i=1; i<=size; i++) {
            std :: cout << arr[i] << " ";
        }
        std :: cout << "\n\n";
    }
};

//* heapify algorithm (logn)
void heapifyAlgo(std :: vector<int> &arr, int n, int i) {

    int largest = i;
    int left = 2*i;
    int right = 2*i-1;

    //^ compare largest's val with child nodes (only index update)
    if(left <= n && arr[largest] < arr[left]) {
        largest = left;
    }
    if(right <= n && arr[largest] < arr[right]) {
        largest = right;
    }

    //todo check value of largest and put it on right place (actual node change)
    if(largest != i) {
        std :: swap(arr[largest], arr[i]);
        heapifyAlgo(arr, n, largest);
    }
}

void heapify(std :: vector<int>& arr) {

    int n = arr.size();

    for(int i=n/2; i>0; i--) {
        heapifyAlgo(arr,n, i);
    }

    //? print array after heapify
    for(int i=1; i<=n; i++) {
        std :: cout << arr[i] << " ";
    }
    std :: cout << "\n\n";
}

//* heap sort
void heapSort(std :: vector<int>& arr) {

    int n = arr.size();
    int size = n;

    //todo sort till size is > 1
    while(size > 1) {

        //^ step 1 : swap first and last(unosorted)
        std :: swap(arr[size], arr[1]);

        //^ step 2 : decrease size i.e ignore sorted ones
        size--;

        //^ step 2 : place first(root) to its correct position
        heapifyAlgo(arr, size, 1);

    }

    //& print array after sorting
    for(int i=1; i<=n; i++) {
        std :: cout << arr[i] << " ";
    }
    std :: cout << "\n\n";
}

int main() {

    heap h;
    h.insert(10);
    h.insert(16);
    h.insert(8);
    h.insert(25);

    h.print();

    std :: vector<int> nums = {-1, 16, 6, 10, 28, 12, 11, 25, 12};

    //? create heap from array
    heapify(nums);
    //? heap sort
    heapSort(nums);

    return 0;
}