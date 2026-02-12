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
        arr[idx] = val;

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

    

    //^ print heap (array order)
    void print() {
        for(int i=1; i<=size; i++) {
            std :: cout << arr[i] << " ";
        }
    }
};

int main() {

    heap h;
    h.insert(10);
    h.insert(16);
    h.insert(8);
    h.insert(25);

    h.print();

    return 0;
}