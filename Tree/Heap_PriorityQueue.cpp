//! heap data structure in C++

#include <iostream>
#include <vector>
#include <queue> //~ inclue priority queue header file
#include <unordered_map>
#include <unordered_set>

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
    inorder(root -> left, nums);
    nums.push_back(root -> data);
    inorder(root -> right, nums);
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

//* kth largest subarray sum
int kthSubarray(std :: vector<int>& nums, int k) {

    //^ create min heap
    std :: priority_queue<int,std :: vector<int>, std :: greater<int>> hp;

    //todo traverse array
    for(int i=0; i<nums.size(); i++) {

        int sum = 0;
        for(int j=i; j<nums.size(); j++) {

            sum += nums[j];
            if(hp.size() < k) {
                hp.push(sum);
            }
            else {

                //? is sum greater
                if(sum > hp.top()) {
                    hp.pop();
                    hp.push(sum);
                }
            }
        }
    }
    return hp.top();
}

//* relative rank : leetcode 506
std :: vector<std :: string> relRank(std ::vector<int>& score) {

    std :: vector<std :: string> ans;

    //^ max heap of pairs
    std :: priority_queue<std :: pair<int, int>> mxHeap;

    for(int i=0; i<score.size(); i++) {
        mxHeap.push({score[i], i});
    }

    //todo fill answer array from heap
    int rank = 1;
    while(!mxHeap.empty()) {

        auto [sc, idx] = mxHeap.top(); //~ get score nd index
        mxHeap.pop();

        if(rank == 1) {
            ans[idx] = "Gold Medal";
        }
        else if(rank == 2) {
            ans[idx] = "Silver Medal";
        }
        else if(rank == 3) {
            ans[idx] = "Bronze Medal";
        }
        else {
            ans.push_back(std :: to_string(rank));
        }
        rank++;
    }
    return ans;
}

//* last stone weight : leetcode 1046
int stoneWeight(std :: vector<int>& nums) {

    std :: priority_queue<int> mxHeap;

    for(int val : nums) {
        mxHeap.push(val);
    }

    while(mxHeap.size() > 1) {

        //^ largest one
        int n1 = mxHeap.top();
        mxHeap.pop();

        //^ 2nd largest
        int n2 = mxHeap.top();
        mxHeap.pop();

        //todo push n1 - n2 in priority queue
        mxHeap.push(n1 - n2);
    }
    return mxHeap.top();
}

//* merge k sorted arrays
class matrix {
public:
    
    //~ data, row nd colm
    int data;
    int row, col;

    //^ constructor
    matrix(int data, int row, int col) {
        this -> data = data;
        this -> row = row;
        this -> col = col;
    }
};

//& custom comparator
class compare {
public:
    
    bool operator() (matrix* a, matrix* b) {
        return a -> data > b -> data;
    }
};

std :: vector<int> mergeArray(std :: vector<std :: vector<int>>& kArray, int k) {

    //^ create min heap from custom comparator
    std :: priority_queue<matrix*, std :: vector<matrix*>, compare> minHeap;
    
    //todo push first val of each array into heap
    for(int i=0; i<k; i++) {
        
        //? create a node (matrix class)
        matrix* temp = new matrix(kArray[i][0], i, 0);
        minHeap.push(temp);
    }

    //? answer vector
    std :: vector<int> ans;

    while(!minHeap.empty()) {

        matrix* temp = minHeap.top();

        //todo push values into vector
        ans.push_back(temp -> data);
        minHeap.pop();

        //~ push other elements too (simultenuosly)
        int row = temp -> row;
        int col = temp -> col;

        if(col + 1 < kArray[row].size()) {

            //todo create node nd push
            matrix* next = new matrix(kArray[row][col+1], row, col+1);
            minHeap.push(next);
        }
    }
    return ans;
}

//* merge k sorted lists : leetcode 23
//& class/ structure for list node
class ListNode {
public: 

    int data;
    ListNode* next;

    //^ constructor (initialize an empty list)
    ListNode(int val) {
        data = val;
        next = NULL;
    }

};
class LL {
    //~ head nd tail pointers
    ListNode* head;
    ListNode* tail;
    
public:

    //^ constructor
    LL() {
        head = tail = NULL; //~ initialize head nd tail as NULL
    }
};
//? custom comparator
class compareLL {
public:
    bool operator() (ListNode* a, ListNode* b) {
        return a -> data > b -> data;
    }
};

ListNode* mergeK_lists(std :: vector<ListNode*>& lists) {

    //^ create min heap
    std :: priority_queue<ListNode*, std :: vector<ListNode*>, compareLL> minHeap;

    int k = lists.size();
    if(k == 0) return NULL;

    //todo push head of each LL into heap
    for(int i=0; i<k; i++) {
        if(lists[i] != NULL) {
            minHeap.push(lists[i]);
        }
    }

    ListNode* head = NULL;
    ListNode* tail = NULL;

    //^ insert in answer linked list 
    while(!minHeap.empty()) {

        //? create a node
        ListNode* top = minHeap.top();
        minHeap.pop();

        if(top -> next != NULL) {
            minHeap.push(top -> next);
        }

        //~ insert in empty LL
        if(head == NULL) {
            head = tail = top;
            minHeap.pop();
        }
        else {
            tail -> next = top;
            tail = top;
        }
    }
    return head;
}

//* design mini twitter : leetcode 355
class Twitter {
public:

    int timestamp;  //~ global counter for tweet order
    
    //^ hashMap: userId -> list of {timestamp, tweetId}
    std :: unordered_map<int, std :: vector<std :: pair<int, int>>> tweets;
    
    //^ hashMap: userId -> set of followees
    std :: unordered_map<int, std :: unordered_set<int>> following;
    
    //^ constructor
    Twitter() {
        timestamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
    }
    
    std :: vector<int> getNewsFeed(int userId) {
        
        std :: priority_queue<std :: pair<int, int>> maxHeap;  //~ heap for {timestamp, tweetId}

        for(auto& tweet : tweets[userId]) {
           maxHeap.push(tweet);
        }

        for(int followeeId : following[userId]) {
            for(auto& tweet : tweets[followeeId]) {
                maxHeap.push(tweet);
            }
        }

        //todo Get top 10 most recent
        std :: vector<int> feed;
        for(int i = 0; i < 10 && !maxHeap.empty(); i++) {
            feed.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

//* min time to fill cups : leetcode 2335
int mintime(std :: vector<int>& amount) {

    //^ create priority queue
    std :: priority_queue<int> maxHeap;
    for(int val : amount) {
        if(val > 0) {
            maxHeap.push(val);
        }
    }

    int time = 0;
    //todo pop two largest from heap and push amount[i]-1
    while(!maxHeap.empty()) {

        //? two largest
        int c1 = maxHeap.top();
        maxHeap.pop();

        int c2 = 0;
        if(!maxHeap.empty()) {
            c2 = maxHeap.top();
            maxHeap.pop();
        }

        c1--;
        c2--;

        if(c1 > 0) {
            maxHeap.push(c1);
        }
        if(c2 > 0) {
            maxHeap.push(c2);
        } 
        time++;
    }

    return time;   
}

//* k weakest row in matrix : leetcode : 1337
std :: vector<int> kWeakestRows(std :: vector<std :: vector<int>>& mat, int k) {
        
    std :: vector<std :: pair<int, int>> soldier;
    for(int i=0; i<mat.size(); i++) {
        int n = 0;
        for(int j=0; j<mat[0].size(); j++) {
            if(mat[i][j] == 1) {
                n++;
            }
        }
        soldier.push_back({n, i});
    }

    std :: priority_queue<std :: pair<int, int>, std :: vector<std :: pair<int, int>>, std :: greater<std :: pair<int, int>>> heap;

    for(auto val : soldier) {
        heap.push({val.first, val.second});
    }

    std :: vector<int> ans;

    while(ans.size() < k) {
        ans.push_back(heap.top().second);
        heap.pop();
    }

    return ans;
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