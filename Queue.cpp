#include <iostream>
#include <list>
#include <queue>
#include <deque>
#include <stack> 
#include <vector>
#include <unordered_map>
#include <numeric>

//& [ 1 2 3 4 5 6 ]
//?   F         R

//? class(es) for Linked List
class Node {

public:    
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }

};

class Queue {

    Node* head;
    Node* tail;

public:

    //^ constructor
    Queue() {
        head = tail = NULL;
    }

    //* push from rear (enqueue)
    void push(int val) {

        Node* newNode = new Node(val);

        //^ if LL is empty
        if(empty()) {
            head = tail = newNode;
        }
        else {
            tail -> next = newNode;
            tail = newNode;
        }

    }

    //* pop from front (dequeue)
    void pop() {

        if(empty()) {
            std :: cout << "Queue is empty!\n";
            return;
        }
        
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
    }

    //* get front value
    int front() {
        return head -> data;
    }

    //* check if empty
    bool empty() {
        return head == NULL;
    }

    //* print queue
    void printQueue() {

        Node* temp = head;

        std :: cout << "\nQueue : \n";
        //^ print top border for all nodes
        while (temp != nullptr)
        {
            std :: cout << "+------+     ";
            temp = temp->next;
        }
        std :: cout << std :: endl;

        //^ print data inside each node
        temp = head;
        while (temp != nullptr)
        {
            std :: cout << "|  " << temp->data;
            if (temp->data < 10) std :: cout << "   ";  //~ spacing for single digits
            else if (temp->data < 100) std ::  cout << "  ";
            else std :: cout << " ";
            std :: cout << "|";
            temp = temp->next;
        }
        std :: cout << "NULL" << std :: endl;

        //^ print bottom border for all nodes
        temp = head;
        while (temp != nullptr)
        {
            std :: cout << "+------+     ";
            temp = temp->next;
        }
        std :: cout << std :: endl;
    }

};

//? class for deque
class Deque {

    Node* head;
    Node* tail;

public:

    //^ constructor
    Deque() {
        head = tail = NULL;
    }

    //* push from rear (enqueue)
    void push_back(int val) {

        Node* newNode = new Node(val);

        //^ if LL is empty
        if(empty()) {
            head = tail = newNode;
        }
        else {
            tail -> next = newNode;
            tail = newNode;
        }

    }

    //* push from front
    void push_front(int val) {

        Node* newNode = new Node(val); 

        //todo check if LL is empty or not
        if(head == NULL) {
            head = tail = newNode;
        }

        else {
            newNode -> next = head; //~ point newNode of next to head for connection

            head = newNode; //~ update head pointer to newNode
        }

    }

    //* pop from front (dequeue)
    void pop_front() {

        if(empty()) {
            std :: cout << "Queue is empty!\n";
            return;
        }
        
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
    }

    //* pop from back
    void pop_back() {
        if(head == NULL) {
            std :: cout << "list is empty";
            return;
        }

        Node* temp = head;

        while(temp -> next != tail) {
            if(temp == NULL) {
                std :: cout << "invalid position\n";
                return;
            }

            temp = temp -> next;
        }

        temp -> next = NULL;
        delete tail;
        tail = temp;
    }

    //* get front value
    int front() {
        return head -> data;
    }

    //* get rear value
    int rear() {
        return tail-> data;
    }

    //* check if empty
    bool empty() {
        return head == NULL;
    }

    //* print deque
    void printDeQue() {

        Node* temp = head;

        std :: cout << "\nQueue : \n";
        //^ print top border for all nodes
        while (temp != nullptr)
        {
            std :: cout << "+------+     ";
            temp = temp->next;
        }
        std :: cout << std :: endl;

        //^ print data inside each node
        temp = head;
        while (temp != nullptr)
        {
            std :: cout << "|  " << temp->data;
            if (temp->data < 10) std :: cout << "   ";  //~ spacing for single digits
            else if (temp->data < 100) std ::  cout << "  ";
            else std :: cout << " ";
            std :: cout << "|";
            temp = temp->next;
        }
        std :: cout << "NULL" << std :: endl;

        //^ print bottom border for all nodes
        temp = head;
        while (temp != nullptr)
        {
            std :: cout << "+------+     ";
            temp = temp->next;
        }
        std :: cout << std :: endl;
    }

};

//^ circular queue using array
class CircularQueue {

    int* cQueue;
    int crtSize = 0, capacity;
    int frt, rear;

public:

    CircularQueue(int size) {

        capacity = size;
        cQueue = new int[capacity];
        frt = 0;
        rear = -1;

    }

    void push(int val) {

        if(crtSize == capacity) return;

        rear = (rear + 1) % capacity;
        cQueue[rear] = val;
        crtSize ++;

    }

    void pop() {
        
        if(crtSize == 0) return;

        frt = (frt + 1) % capacity;
        crtSize --;
    }

    int front() {
        if(crtSize == 0) return -1;

        return cQueue[frt];
    }

    bool empty() {
        return crtSize == 0;
    }

};

//^ implement stack (LIFO) using two queues
class StackUsingQueue {

public:

    std :: queue<int> q1;
    std :: queue<int> q2;

    void push(int val) {

        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        q1.push(val);

        while(!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    int pop() {
        int ans = q1.front();
        return ans; 
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
}; 

//^ implement queue (FIFO) using two stacks
class QueueUsingStack {

public:
    std :: stack<int> s1;
    std :: stack<int> s2;

    void push(int val) {

        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(val);

        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop() {
        int x = s1.top();
        s1.pop();
        return x;
    }

    int front() {
        return s1.top();
    }

    bool empty() {
        return s1.empty();
    }
};

//^ first unique character in string : leetcode 387
int firstUnique(std :: string str) {

    std :: unordered_map<char, int> m;
    std :: queue<int> que;

    for(int i=0; i<str.size(); i++) {
        
        //? if exist
        if(m.find(str[i]) == m.end()) {
            que.push(i);
        }
    
        //todo increase ferquency
        m[str[i]]++;

        //todo remove duplicate elements
        while(que.size() > 0 && m[str[que.front()]] > 1) {
            que.pop();
        }

    }

    return que.empty() ? -1 : que.front();
}


//^ gas station problem : leetcode 134
int gasStation(std :: vector<int> &gas, std :: vector<int> &cost) {

    int totalGas = std :: accumulate(gas.begin(), gas.end(), 0);
    int totalCost = std :: accumulate(cost.begin(), cost.end(), 0);

    //~ no soln exist
    if(totalGas < totalCost) return -1;

    //~ unique soln exist
    int start = 0;
    int crtGas = 0;

    for(int i=0; i<gas.size(); i++) {
        crtGas += (gas[i] - cost[i]);

        if(crtGas < 0) {
            start = i+1;
            crtGas = 0;
        }
    }
    
    return start;
}  

//^ Sliding window maximum : leetcode 239
std :: vector<int> windowMax(std :: vector<int> &nums, int k) {

    //? answer array
    std :: vector<int> ans;

    //? deque for comparison ans storing answer
    std :: deque<int> dq;

    //& traverse first window
    for(int i=0; i<k; i++) {

        while(dq.size() > 0 && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }
        dq.push_back(i);

    }

    //& traverse next window(s)
    for(int i=k; i<nums.size(); i++) {

        ans.push_back(nums[dq.front()]);

        //todo remove non viable values
        while(dq.size() >0 && nums[dq.front()] <= i-k) {
            dq.pop_front();
        }

        //todo remove smaller values
        while(dq.size() > 0 && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
    
    }
    ans.push_back(nums[dq.front()]);

    std :: cout << "window maximum :     \n";
    for(int val : ans) {
        std :: cout << val << " ";
    }
    std :: cout << "\n";

    return ans;
}


int main() {

    Deque q;

    q.push_back(41);
    q.push_back(11);
    q.push_front(6);
    q.push_back(16);
    q.push_front(50);

    q.pop_front();

    std :: vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};

    windowMax(arr, 3);

    return 0;

}

