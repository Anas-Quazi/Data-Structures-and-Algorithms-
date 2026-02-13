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

int main() {

    heap h;
    h.insert(10);
    h.insert(16);
    h.insert(8);
    h.insert(25);

    h.print();

    h.deleteRoot();
    h.print();

    return 0;
}