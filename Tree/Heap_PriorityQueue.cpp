//! heap data structure in C++

#include <iostream>
#include <vector>
#include <queue> //~ inclue priority queue header file


//? class for implementing heap (by default max heap, but we can change)
class Heap {

public:
    std :: vector<int> arr;
    int size;
    bool isMaxHeap;

    //^ constructor for initialization
    Heap(bool maxHeap = true) {
        arr.push_back(-1);
        size = 0;
        isMaxHeap = maxHeap;
    }

    //^ method to insert value
    void insert(int val) {

        size += 1;
        int idx = size;
        arr.push_back(val);

        //todo place value to its correct position
        while(idx > 1) {
            int par = idx / 2;

            //! Comparison based on heap type
            bool shouldSwap = isMaxHeap ? (arr[par] < arr[idx])   //~ Max heap
                                        : (arr[par] > arr[idx]);  //~ Min heap

            if(shouldSwap) {
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
            int target = i;

            //& find target based on heap type
            if(isMaxHeap) {

                //^ for max heap : find largest
                if(leftIdx <= size && arr[target] < arr[leftIdx]) {
                    target = leftIdx;
                }
                if(rightIdx <= size && arr[target] < arr[rightIdx]) {
                    target = rightIdx;
                }
            }
            else {

                //^ for max heap : find largest
                if(leftIdx <= size && arr[target] > arr[leftIdx]) {
                    target = leftIdx;
                }
                if(rightIdx <= size && arr[target] > arr[rightIdx]) {
                    target = rightIdx;
                }
            }

            //? if left right child is actually larger
            if(target != i) {
                std :: swap(arr[i], arr[target]);
                i = target;
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
void heapifyAlgo(std :: vector<int> &arr, int n, int i, bool isMaxHeap = true) {

    int target = i;
    int left = 2*i;
    int right = 2*i+1;

    //^ compare largest's/ smallest val with child nodes (only index update)
    if(isMaxHeap) {
        if(left <= n && arr[target] < arr[left]) {
            target = left;
        }
        if(right <= n && arr[target] < arr[right]) {
            target = right;
        }
    }
    else {
        if(left <= n && arr[target] > arr[left]) {
            target = left;
        }
        if(right <= n && arr[target] > arr[right]) {
            target = right;
        }
    }

    //todo check value of largest and put it on right place (actual node change)
    if(target != i) {
        std :: swap(arr[target], arr[i]);
        heapifyAlgo(arr, n, target, isMaxHeap);
    }
}

void heapify(std :: vector<int>& arr, bool isMaxHeap = true) {

    int n = arr.size() - 1;

    for(int i=n/2; i>0; i--) {
        heapifyAlgo(arr,n, i, isMaxHeap);
    }

    //? print array after heapify
    for(int i=1; i<=n; i++) {
        std :: cout << arr[i] << " ";
    }
    std :: cout << "\n\n";
}

//* heap sort : O(nlogn)
void heapSort(std :: vector<int>& arr, bool isMaxHeap = true) {

    int n = arr.size() - 1;

    //! Step 0: Build max/min heap first
    for(int i = n/2; i >= 1; i--) {
        heapifyAlgo(arr, n, i, isMaxHeap);
    }

    int size = n;

    //todo sort till size is > 1
    while(size > 1) {

        //^ step 1 : swap first and last(unosorted)
        std :: swap(arr[size], arr[1]);

        //^ step 2 : decrease size i.e ignore sorted ones
        size--;

        //^ step 3 : place first(root) to its correct position
        heapifyAlgo(arr, size, 1, isMaxHeap);

    }

    //& print array after sorting
    for(int i=1; i<=n; i++) {
        std :: cout << arr[i] << " ";
    }
    std :: cout << "\n\n";
}

//* priority queue functions 
void priorQueue() {

    //^ creation
    std :: priority_queue<int> pq;

    //? insertion/deletion
    pq.push(7);
    pq.push(21);
    pq.push(51);
    pq.push(9);
    // pq.pop();

    //? top and display
    std :: cout << "top : " << pq.top() << "\n";

    while(!pq.empty()) {
        std :: cout << pq.top() << " ";
        pq.pop();
    }
    std :: cout << "\n\n";
}

//* kth smallest element (using max heap) 
int kthSmall(std :: vector<int>& nums, int k) {

    //^ step 1 : create max heap for first k elements
    std :: priority_queue<int> pq;
    for(int i=0; i<k; i++) {
        pq.push(nums[i]);
    }

    //^ step 2 : compare rest elements with root node
    for(int i=k; i<nums.size(); i++) {
        if(nums[i] < pq.top()) {
            pq.pop();
            pq.push(nums[i]);
        }
     }

     //& top/root is the smallest at last
     return pq.top();
}

//*kth largest element
int kthLargest(std :: vector<int>& nums, int k) {

    //^ create min heap of first k elements
    std :: priority_queue<int, std :: vector<int>, std :: greater<int>> pq;
    for(int i=0; i<k; i++) {
        pq.push(nums[i]);
    }

    //? compare with rest 
    for(int i=k; i<nums.size(); i++) {
        if(nums[i] > pq.top()) {
            pq.pop();
            pq.push(nums[i]);
        }
    }

    return pq.top();
}

int main() {

    Heap h;
    h.insert(10);
    h.insert(16);
    h.insert(8);
    h.insert(25);

    h.print();

    std :: vector<int> nums = {-1, 16, 6, 10, 28, 12, 11, 25, 12};

    std :: cout << kthSmall(nums, 1);
    std :: cout << "\n\n";
    std :: cout << kthLargest(nums, 7);
    

    return 0;
}