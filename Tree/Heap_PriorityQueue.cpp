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

//! ----- Leetcode probelems -----

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

//*kth largest element : leetcode 215
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

//* kth largest in stream : leetcode 703
class KthLargest {
public:

    std :: priority_queue<int, std :: vector<int>, std :: greater<int>> pq;
    int k;

    KthLargest(int k, std :: vector<int>& nums) {

        this -> k = k;    
        //^ create min heap of first k elements
        for(int i : nums) {
            pq.push(i);

            if(pq.size() > k) {
            pq.pop();
        }
        }
        
    }
    
    int add(int val) {
        
        if(pq.size() < k) {
            pq.push(val);
        }
        else if(val > pq.top()) {
            pq.pop();
            pq.push(val);
        }

        return pq.top();
    }
};

//* merge 2 binary max heaps
std :: vector<int> mergeHeap(std :: vector<int>& a, std :: vector<int>& b) {

    //? merge array
    for(int i=1; i<b.size(); i++) {
        a.push_back(b[i]);
    }

    //^ build heap using merged array
    heapify(a,true);

    return a;
}

//* is binary tree a heap
//& class for tree node
class Node {
public:
    //^ data, and adress of left nd right child
    int data;
    Node* left;
    Node* right;
    Node* next;

    //^ constructor for initialization
    Node(int val) {
        data = val;
        left = right = next = NULL;
    }
};
int countNodes(Node* root) {

    //^ base case
    if(root == NULL) return 0;

    //~ rEcuRsiON... magiccc!
    int leftNodes = countNodes(root -> left);
    int rightNodes = countNodes(root -> right);

    //! the whole logic is here 
    return (leftNodes + rightNodes) + 1;
}

//? check if tree is Complete Binary Tree (call with index = 1)
bool isCBT(Node* root, int i, int n) {
    //^ empty tree is CBT
    if(root == NULL) return true;

    //^ invalid index (1-based indexing): if index > n it's not CBT
    if(i > n) return false;

    //~ recursively verify left and right positions
    return isCBT(root -> left, 2*i, n) && isCBT(root -> right, 2*i + 1, n);
}

//? check if tree is Max-Heap (complete + heap property)
bool isMaxHeap(Node* root) {

    //^ empty tree is valid heap
    if(root == NULL) return true;

    //& total node count (used by CBT check)
    int n = countNodes(root);

    //todo must be complete binary tree first (start index = 1)
    if(!isCBT(root, 1, n)) return false;

    //^ leaf node -> valid heap
    if(root -> left == NULL && root -> right == NULL) return true;

    //^ only left child present
    if(root -> left && !root -> right) {
        return (root -> data >= root -> left -> data) && isMaxHeap(root -> left);
    }

    return (root -> data >= root -> left -> data)
        && (root -> data >= root -> right -> data)
        && isMaxHeap(root -> left)
        && isMaxHeap(root -> right);
}

//* minimum number of ropes
long long minRopes(std :: vector<long long>& nums) {

    //& min heap for smallest elements
    std :: priority_queue<long long, std :: vector<long long>, std :: greater<long long>> pq;

    for(long long val : nums) {
        pq.push(val);
    }

    long long ans = 0;
    //todo pick two smallest elements
    while(pq.size() > 1) {

        long long n1 = pq.top();
        pq.pop();
        long long n2 = pq.top();
        pq.pop();
        
        long long sum = n1 + n2;
        ans += sum;
        pq.push(sum);
    }

    return ans;
}

//* convert BST to min heap (left < right)
//? calculate inorder
void inorder(Node* root, std :: vector<int>& nums) {

    //^ base case
    if(!root) {
        return;
    }

    //~ inorder traversal
    inorder(root -> left);
    nums.push_back(root -> data);
    inorder(root -> right);
}

Node* buildMinHeapFromSortedArray(std::vector<int>& arr, int& index) {
    if (index >= arr.size()) {
        return NULL;
    }

    //^ create node
    Node* root = new Node(arr[index]);
    index++;

    //~ recursive calls
    root->left = buildMinHeapFromSortedArray(arr, index);
    root->right = buildMinHeapFromSortedArray(arr, index);

    return root;
}

Node* BST_toHeap(Node* BST) {

    //^ calculate inorder sequence
    std :: vector<int> nums;
    inorder(BST, nums);

    //todo create min heap by preorder
    int index = 0;
    Node* newRoot = buildMinHeapFromSortedArray(nums, index);

    return newRoot;
}



int main() {

    Heap h;
    h.insert(10);
    h.insert(16);
    h.insert(8);
    h.insert(25);

    h.print();

    std :: vector<int> nums = {-1, 786, 50, 313, 28, 21, 12, 25, 16, 11, 10};
    std :: vector<int> n2 = {-1, 12, 7, 6, 5, 4, 1};

    std :: vector<long long> vec = {4, 3, 2, 6};
    std :: cout << minRopes(vec);    

    return 0;
}