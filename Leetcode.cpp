#include <iostream>
#include <vector>
using namespace std;


//! Array/ vector
class Array {

    int n, val;

    //^ initialize an empty vector
    vector<int> vec;

    //^ input size
    cout << "enter size of array :   " << endl;
    cin >> n;

    //^ input values
    int i = n;
    cout << "enter " << n << " values : " << endl;
    while (i != 0)
    {
        cin >> val;
        vec.push_back(val); //todo pushing values in vector/array

        i--; //todo decrease i by 1
    }

    //* asking user if they want to add more values

    //* repeating statement untill flag=0
    while (true)
    {
        //* input user's choice
        cout << "want to add more elements?" << endl;
        string ans;
        cin >> ans;

        //* if yes then add new value
        if (ans == "yes")
        {
            int more;

            //* asking how many more values?
            cout << "how many values to add? " << endl;
            cin >> more;

            cout << "enter " << more << " values" << endl;
            for (i = 0; i < more; i++)
            {
                cin >> val;
                vec.push_back(val);
            }

            //* increasing size
            n += more;
        }
        //* else break the loop
        else
        {
            break;
        }
    }

    //* function to print the array
    void print_array(vector<int> &vec, int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << "+-----";
        }
        cout << "+\n";

        for (int i = 0; i < n; i++)
        {
            cout << "| " << vec[i] << "  ";
        }
        cout << "|\n";

        for (int i = 0; i < n; i++)
        {
            cout << "+-----";
        }
        cout << "+\n";
    }

public:
    //* kadane's algorithm
    int kdn_subarray(vector<int> &arr, int n)
    {
        int max_sum = INT_MIN; //^ initialize max_sum from minus infinity
        int crt_sum = 0;
        for (int i = 0; i < n; i++)
        {
            crt_sum += arr[i];
            max_sum = max(crt_sum, max_sum);

            if (crt_sum < 0)
            {
                crt_sum = 0;
            }
        }

        cout << "maximum subarray :     ";
        return max_sum;
    }

    //* function for max sub array (brute force approach)
    int max_subarray(vector<int> &arr, int n)
    {
        int start, end;
        int max_sum = INT_MIN;

        for (start = 0; start < n; start++)
        {
            int crt_sum = 0;
            for (end = start; end < n; end++)
            {
                crt_sum += arr[end];
                max_sum = max(crt_sum, max_sum);
            }
        }

        cout << "maximum subarray sum is :  ";
        return max_sum;
    }

    //* stock buy and sell problem : leetcode 121
    int stock(vector<int> &price)
    {
        //^ using plan B (brute force approach)

        int max_profit = 0;
        for (int i = price.size() - 1; i >= 0; i--)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                int profit = price[i] - price[j];
                if (profit > max_profit)
                {
                    max_profit = profit;
                }
            }
        }

        return max_profit;
    }

    //* optimized : O(n) complexity
    int buy_sell(vector<int> &price)
    {
        int max_profit = 0;
        int best_buy = price[0];

        for (int i = 0; i < price.size() + 1; i++)
        {
            if (price[i] > best_buy)
            {
                max_profit = max(max_profit, price[i] - best_buy);
            }
            best_buy = min(best_buy, price[i]);
        }

        return max_profit;
    }

    //* product of array except itself
    std ::vector<int> productOfArray(std ::vector<int> &vec)
    {
        //^ [1,2,3,4]
        std ::vector<int> temp;

        for (int i = 0; i < vec.size(); i++)
        {
            int prod = 1;
            for (int j = 0; j < vec.size(); j++)
            {
                if (j != i)
                {
                    prod *= vec[j];
                }
            }
            temp.push_back(prod);
        }

        return temp;
    }

    //* optimized soln for product of array except self
    void prod_ofArray(std ::vector<int> &nums)
    {
        int n = nums.size();

        std ::vector<int> left(n, 1);
        left[0] = 1;
        std ::vector<int> right(n, 1);
        right[n - 1] = 1;

        //^ [1, 2, 3, 4]

        //^ loop for left products
        for (int i = 1; i < nums.size(); i++)
        {
            left[i] = left[i - 1] * nums[i - 1];
        }

        //^ loop for right products
        for (int i = n - 2; i >= 0; i--)
        {
            right[i] = right[i + 1] * nums[i + 1];
        }

        std ::vector<int> product(n, 1);

        //^ loop for multiplication of left and right array product
        for (int i = 0; i < n; i++)
        {
            product[i] = left[i] * right[i];
        }

        //^ print array
        for (int i = 0; i < n; i++)
        {
        std:;
            cout << "+-----";
        }
        std ::cout << "+\n";
        for (int i = 0; i < n; i++)
        {
            std ::cout << "| " << product[i] << "  ";
        }
        std ::cout << "|\n";

        for (int i = 0; i < n; i++)
        {
            std ::cout << "+-----";
        }
        std ::cout << "+\n";
    }

    //* sliding window algorithm
    int max_sum_subarray(std :: vector<int> &vec) {
        int n = vec.size();
        int window_size = 3;
        
        //& [11, 6, 16, 25, 28, 12, 10, 12] ---> ans=69, idx (2,4);
        //&  0   1  2   3   4   5   6   7
        int max_sum = 0;

        for(int i=0;i<=n-window_size;i++) {
            int crt_sum = 0;
            for(int j=0;j<window_size;j++) {
                crt_sum += vec[i+j]; 
            }
            max_sum = max(max_sum, crt_sum);
        }

        return max_sum;
    }

    //* sliding window max average (brute force approach)
    double max_avg_b(std :: vector<int> &vec) {
        int k = 4;
        int n = vec.size();
        double max_avg;

        for(int i=0;i<=n-k;i++) {
            double crt_sum=0;
            double crt_avg = 0;
            for(int j=0;j<k;j++) {
                crt_sum += vec[i+j];
                crt_avg = crt_sum/k;
            }
            max_avg = max(max_avg, crt_avg);
        }

        return max_avg;
    }

    //* optimized : O(n)
    double max_avg(std :: vector<int> &vec) {

        //! [4, 7, 1, 8, 3, 5, 11, 25, 16, 786] k=3 ---> ans = 16/6=2.67

        int n = vec.size(),k=4;
        double sum = 0;

        //^ calculate sum for 1st k elements window
        for(int i=0;i<k;i++) {
            sum += vec[i];
        }

        double maxSum = sum; //^ initialize maxSum as 1st window sum

        //^ slide window for next k element sum
        for(int i=k; i<n; i++) {
            sum -= vec[i-k]; //^ remove current element(leaving window)
            sum += vec[i]; //^ add entering element to the window sum

            maxSum = max(maxSum, sum);
        }
        double maxAvg = maxSum/k;

        return maxAvg;

    }

    //* defuse bomb problem from leetcode (on the special date : 9/11)
    void decrypt(vector<int>& code, int k) {
        int n = code.size();
        std :: vector<int> result(n,0);

        if(k==0) {
            for(int i=0;i<n;i++) {
                result[i] = 0;
            }
        }
        else if(k>0) {
            for(int i=0;i<n;i++) {
                int x = 0;
                for(int j=1;j<=k;j++) {
                    x += code[j % n]; 
                }
                result[i] = x;
            }
        }
        else if(k<0) {
            for(int i=0; i<n; i++) {
                code[i] = 0;
                int x = 0;
                for(int j=1;j<=-k;j++) {
                    x += code[(i-j+n) % n];
                }
                result[i] = x;
            }
        }
        // print_array(result,n);

        } 

    //* peak index in mountain array (leetcode 852)
    int peakIdx(std :: vector<int> &mount) {
        int low=1,high=mount.size()-1;

        while(low<high) {
            int mid = low+(high-low)/2;
            if(mount[mid] > mount[mid-1] && mount[mid] > mount[mid+1]) {
                return mid;
            }
            //^ search in right sub-array
            else if(mount[mid] > mount[mid-1]) { 
                low = mid+1;
            }
            //^ search in left sub-array
            else {
                high = mid-1;
            }
        }
        return 0;
    } 


    //~ for odd L/R
    //*&   [1, 1, 2, 3, 3, 4, 4]
    //&    0  1  2  3  4  5  6
    //& mid = 3(3) target in left : else if(vec[mid]=vec[mid+1])


    //& [1, 1, 2, 2, 3, 4, 4]
    //&  0  1  2  3  4  5  6
    //& mid = 3(2) target in right : else (vec[mid]=vec[mid-1]) 


    //~ for even L/R
    //& [1, 1, 2, 3, 3, 4, 4, 5, 5]
    //&  0  1  2  3  4  5  6  7  8
    //& mid=4(3) target in left : else if (vec[mid] == vec[mid-1])

    //& [1, 1, 2, 2, 3, 3, 4, 5, 5]
    //&  0  1  2  3  4  5  6  7  8  
    //& mid=4(3) target in right: else (vec[mid] == vec[mid+1])


    //* single element in sorted array
    int singleElement(std :: vector<int> &vec) {
        int n =vec.size();
        int low=0, high=n;

        while(low<=high) {
            int mid = low + (high-low)/2;

            //^ if answer is 1st or last
            if(mid == 0 && vec[mid]!=vec[mid+1]) {
                return vec[0];
            }

            if(mid == n-1 && vec[mid] != vec[mid-1]) {
                return vec[n-1];
            }

            //^ if found at mid
            if(vec[mid]!= vec[mid-1] && vec[mid]!= vec[mid+1]) {
                return vec[mid];
            }

            if(mid % 2 == 0) {
                if(vec[mid] == vec[mid-1]) {
                    high = mid-1;
                }
                else {
                    low = mid+1;
                }
            }
            else {
                //^ search in right half of array
                if(vec[mid]==vec[mid-1]) {
                    low = mid+1;
                }

                //^ search in left half of array
                else {
                    high = mid-1;
                }
            }
            
        }
        return 0;
    }

    //* money in bank : leetcode 1716
    int money(int n) {
        int invs = 0;

        int week = n / 7;
    }

    //* remove duplicate from sorted array : leetcode 16
    int removeDup() {

    }

    //* plus one (leetcode 66)
    std :: vector<int> plusOne(std :: vector<int> &vec) {

        int n = vec.size()-1;

        while(n >= 0) {
            if()
        }
    }
}; 

class LinkedList {

public:
        //^ reverse Linked List : leetcode 206
    void reverse() {

        //! create three pointers
        Node* prev = NULL;
        Node* crt = head;
        Node* next = NULL;

        //? 4 steps to reverse a LL
        while(crt != NULL) {
            //* 1) make next = crt -> next
            next = crt -> next;

            //* 2) set crt -> next = prev
            crt -> next = prev;

            //* 3) update prev to crt
            prev = crt;

            //* 4) update crt to next
            crt = next;

        }
        head = prev; //~ updating head
    }

    //^ middle of linked list : leetcode 876
    void middle() {

        Node* temp = head;
        int mid  = size/2 +1;
        
        for(int i=1; i<mid; i++) {
            temp = temp -> next;
        }

        while(temp != NULL) {
            std :: cout << temp -> data << " ";
            temp = temp -> next;
        }
        std :: cout << "\n";

    }

    //^ middle of LL (opttimized using slow & fast pointers)
    void middleSF() {
        Node* slow = head;
        Node* fast = head;

        while(fast != NULL && fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        std :: cout << "middle node : " << slow -> data;
    }

    //^ cycle/loop in LL : leetcode 141
    bool cycleLL() {

        Node* slow = head;
        Node* fast = head;

        while(fast != NULL && fast -> next != NULL) {
            
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast) {
                return true;
            }
        }
        return false;
    }

    //^ detect cycle/ loop in LL : leetcode 142
    Node *detectCycle() {

        Node* slow = head;
        Node* fast = head;
        bool isCycle = false;

        while(fast != NULL && fast -> next != NULL) {
            
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast) {
                isCycle = true;
                break;
            }
        }
        if(!isCycle) {
            return NULL;
        }

        slow = head;
        Node* prev = NULL;
        while(slow != fast) {
            slow = slow -> next;
            prev = fast;
            fast = fast -> next;
        }

        prev -> next = NULL;
        return slow;
    }

    //^ merge two sorted lists : leetcode 21
    void mergeList(Node* head1, Node* head2) {

        SinglyLinkedList sorted;

        //* sort nodes based on data 
        while(head1 != NULL && head2 != NULL) {

            if((head1 -> data) <= (head2 -> data)) {
                sorted.pushBack(head1 -> data);
                head1 = head1 -> next;
            }
            
            else {
                sorted.pushBack(head2 -> data);
                head2 = head2 -> next;
            }
        }

        //* sort remaining nodes
        while(head1 != NULL) {
            sorted.pushBack(head1 -> data);
            head1 = head1 -> next;
        }

        while(head2 != NULL) {
            sorted.pushBack(head2 -> data);
            head2 = head2 -> next;
        }

        sorted.printLinkedList();
    }

    //* merge LL using recrusion
    void mergeLL_rec(Node* head1, Node* head2, SinglyLinkedList& sorted) {


        if(head1 == NULL && head2 == NULL) {
            sorted.printLinkedList();
            return;
        }

        if(head1 == NULL) {
            sorted.pushBack(head2->data);
            mergeLL_rec(NULL, head2->next, sorted);
        }

        else if(head2 == NULL) {
            sorted.pushBack(head1->data);
            mergeLL_rec(head1->next, NULL, sorted);
        }

        else if((head1 -> data) <= (head2 -> data)) {
            sorted.pushBack(head1 -> data);
            mergeLL_rec(head1 -> next, head2, sorted);
        }

        else {
            sorted.pushBack(head2 -> data);
            mergeLL_rec(head1, head2 -> next, sorted);
        }
    }

    //^ copy list with random pointer : leetcode 138
    void copyLL() {

        SinglyLinkedList copy;

        Node* newHead = new Node(head -> data);
        copy.pushBack(newHead -> data);

        //* two pointers for traversing old and new LL
        Node* oldTemp = head -> next;
        Node* newTemp = newHead;

        while(oldTemp != NULL) {
            Node* copyNode = new Node(oldTemp -> data);
            copy.pushBack(copyNode -> data);

            newTemp -> next = copyNode;

            oldTemp = oldTemp -> next;
            newTemp = newTemp -> next;
        }

        copy.printLinkedList();
    }


    //^ add two linked lists 
    void addLL(Node* head1, Node* head2) {
        SinglyLinkedList sum;

        while(head1 != NULL && head2 != NULL) {
            int val = (head1 -> data) + (head2 -> data);

            if(val < 10) {
                sum.pushBack(val);
            }
            else {
                sum.pushBack(val % 10);
            }

            head1 = head1 -> next;
            head2 = head2 -> next;
        }
        sum.printLinkedList();
    }

    //^ add two numbers : leetcode 2
    void addTwo() {
        
    }

    //^ palindrome linked list : leetcode 234

    //todo   7 8 6 5 6 8 7
    void isPalindrome(SinglyLinkedList list) {
        SinglyLinkedList copy;

        Node* temp = list.getHead();
        while(temp != NULL) {
            copy.pushBack(temp -> data);
            temp = temp -> next;
        }

        list.reverse();

        Node* h1 = copy.getHead();
        Node* h2 = list.getHead();

        bool palind = true;
        while(h1 != NULL && h2 != NULL) {
            if((h1 -> data) != (h2 -> data)) {
                palind = false;
                break;
            }
            h1 = h1 -> next;
            h2 = h2 -> next;
        }
        if(palind) {
            std :: cout << "\n\npalindrome";
        }
        else {
            std :: cout << "\n\nnot palindrome";
        }
    }

    //^ reverse nodes in k-Group
    Node* reverseKgroups(Node* h,int k) {
        SinglyLinkedList revK;

        //* check if k nodes exist in our LL
        Node* temp = h;
        int cnt = 0;
        while(cnt < k) {

            if(temp == NULL) {
                return h;
            }
            temp = temp -> next;

        }

        //& recursively call for rest of LL
        Node* prevNode = reverseKgroups(temp,k);

        //* update temp
        temp = h; cnt = 0;

        //& reverse current group
        while(cnt < k) {
            Node* next = temp -> next;
            temp -> next = prevNode;

            prevNode = temp;
            temp = next;

            cnt++;
        }
        return prevNode;
    }

    //^ remove duplicate from sorted list
    void removeDupl() {

        Node* temp = head;
        
        while(temp != NULL && (temp -> next) != NULL ) {

            if((temp-> data) == ((temp -> next) -> data) && temp -> next != NULL) {

                Node* dupl = temp -> next;
                temp -> next = dupl -> next;
                dupl -> next = NULL;

                std :: cout << "\nduplicate " << dupl -> data <<  " removed...\n";
            }

            temp = temp -> next;
        }
    }

    //^ swap nodes in pairs : leetcode 24
    Node* swapNodes(Node* h) {

        //* check if only one or zero nodes in LL
        if(h == NULL || h -> next == NULL) {
            return h;
        }

        //* creating pointers for traversal & connection
        Node* first = head;
        Node* second = head -> next;

        Node* prev = NULL; 

        //& loop for rearranging connections
        while(first != NULL && second != NULL) {
            Node* third = second -> next;

            //todo reverse connections
            second -> next = first;
            first -> next = third;

            //todo check if prev is NULL
            if(prev != NULL) {
                prev -> next = second;
            }
            else {
                h = second;
            }

            //todo update values
            prev = first;
            first = third;
            if(third != NULL) {
                second = third -> next;
            }
            else {
                second = NULL;
            }
        }
        return h;
    }

    //^ LRU cache : leetcode 146

};

class Stack {

public: 
    //* stock span problem : leetcode 901
    std :: vector<int> stock(std :: vector<int> price) {

        //^ use vector for storing span values
        std :: vector<int> ans(price.size(),0);

        //^ use for calculating previos high price
        std :: stack<int> s;

        for(int i=0; i<price.size(); i++) {

            //^ removing <= values from stack
            while(s.size() > 0 && price[s.top()] <= price[i]) {
                s.pop();
            }

            if(s.empty()) {
                ans[i] = i+1;
            }

            else {
                ans[i] = i - s.top(); //~ i - prevHigh
            }

            s.push(i);
        }


        std :: cout << "span for given stocks : \n";
        for(int val : ans) {
            std :: cout << val << " ";
        }
        std :: cout << "\n\n";

        return ans;
    }


    //* baseball scorecard : leetcode 682
    int calcScore(std :: vector<std :: string> match) {

        //^ stack for recording score
        std :: stack<int> s;

        for(int i=0; i<match.size(); i++) {
            
            //~ add top & top-1
            if(match[i] == "+") {
                int first = s.top();
                s.pop();
                int second = s.top();
                s.push(first);  //& put first back
                
                int add = first + second;
                s.push(add);    //& push only the sum
            }

            //~ add double of current top
            else if(match[i] == "D") {
                int dbl = s.top() * 2;
                s.push(dbl);
            }

            //~ remove top(latest) 
            else if(match[i] == "C") {
                s.pop();
            }

            //~ else add intiger in stack
            else {
                s.push(std :: stoi(match[i]));
            }
        }


        int score = 0;
        while(!s.empty()) {
            score += s.top();
            s.pop();
        }

        return score;
    }

    //* next greater element simple
    std :: vector<int> nextGreat(std :: vector<int> &vec) {

        //^ create stack for checking next greater
        std :: stack<int> s; 

        //^ answer array for storing answer values
        std :: vector<int> ans;

        //todo traverse array backward 
        for(int i=vec.size()-1; i>=0; i--) {

            if(s.empty()) {
                ans.push_back(-1);
            }

            else if(vec[i] < s.top()) {
                ans.push_back(s.top());
            }

            else {

                while(!s.empty() && vec[i] >= s.top()) {
                    s.pop();
                }

                if(s.empty()) {
                    ans.push_back(-1);
                } 
                else {
                    ans.push_back(s.top());
                }
            }
            s.push(vec[i]);
        }

        std :: reverse(ans.begin(), ans.end());

        //^ print nd verify answer
        std :: cout << "\nnext greater : \n";
        for(int val : ans) {
            std :: cout << val << " ";
        }
        std :: cout << "\n";

        return ans;
    }

    //* next greater element I : leetcode 496
    std :: vector<int> nextGreat_1(std :: vector<int> nums1, std :: vector<int> nums2) {

        //^ stack for finding next greater
        std :: stack<int> s;

        //^ create unordered map for storing nums2 vals nd their next greater
        std :: unordered_map<int, int> map;

        //todo traverse nums1 array backward
        for(int i=nums2.size(); i>=0; i--) {
            while(s.size() > 0 && s.top() <= nums2[i]) {
                s.pop();
            }

            if(s.empty()) {
                map[nums2[i]] = -1;
            }
            else {
                map[nums2[i]] = s.top();
            }

            s.push(nums2[i]);
        }

        //^ answer array
        std :: vector<int> ans;
        for(int i=0; i<nums1.size(); i++) {
            ans.push_back(map[nums1[i]]);
        }

        //^ print nd verify answer
        std :: cout << "\nnext greater : \n";
        for(int val : ans) {
            std :: cout << val << " ";
        }
        std :: cout << "\n";

        return ans;
    }

    //* next greater element II : leetcode 503
    std :: vector<int> nextGreat_2(std :: vector<int> &vec) {

        
        int n = vec.size();
        
        //^ create stack for checking next greater
        std :: stack<int> s; 

        //^ answer array for storing answer values
        std :: vector<int> ans(n,-1);

        //todo traverse backward in circular (twice)
        for(int i= 2*n-1; i>=0; i--) {
            while(s.size() > 0 && s.top() <= vec[i%n]) {
                s.pop();
            }

            if(s.empty()) {
                ans[i%n] = -1;
            }
            else {
                ans[i%n] = s.top();
            }
            s.push(vec[i%n]);
        }

        //^ print nd verify answer
        std :: cout << "\nnext greater : \n";
        for(int val : ans) {
            std :: cout << val << " ";
        }
        std :: cout << "\n";

        return ans;
    }

    //* previos smaller 
    std :: vector<int> prevSmall(std :: vector<int> &vec) {

        //^ answer array
        std :: vector<int> ans(vec.size(),-1);
        
        //^ stack
        std :: stack<int> s;

        //todo traverse array forward
        for(int i=0; i<vec.size(); i++) {
            while(s.size() > 0 && s.top() >= vec[i]) {
                s.pop();
            }

            if(s.empty()) {
                ans[i] = -1;
            }
            else {
                ans[i] = s.top();
            }

            s.push(vec[i]);
        }

        //^ print nd verify answer
        std :: cout << "\nnext greater : \n";
        for(int val : ans) {
            std :: cout << val << " ";
        }
        std :: cout << "\n";

        return ans; 
    }

    //? design mini stack : leetcode 155
    class minStack {
        
        std :: stack<std :: pair<int, int>> stk;

    public:

        void push(int val) {
            
            if(stk.empty()) {
                stk.push({val, val});
            }
            else {
                int minVal = std :: min(val, stk.top().second);
                stk.push({val,minVal});
            }

        } 

        void pop() {
            stk.pop();     
        }

        int top() {
            return stk.top().first;
        }

        int getMin() {
            return stk.top().second;
        }
    };

    //? design min stack (optimized) : leetcode 155
    class minStackOptm {
        
        std :: stack<long long int> stk;

    public:

        //& global min val
        long long int minVal = INT_MAX;

        //^ push function
        void push(int val) {

            //todo is empty
            if(stk.empty()) {
                stk.push(val);
                minVal = val;
            }
            
            //todo if val is lesser update minval & use formula
            if(val < minVal) {
                stk.push(2*val - minVal);
                minVal = val;
            }
            else {
                stk.push(val);
            }

        } 

        //^ pop function with minVal trackinh=g using formula
        void pop() {

            //todo only if top is less than minVal
            if(stk.top() < minVal) {
                minVal = 2*minVal - stk.top(); //~ update minVal
            }

            stk.pop();     
        }

        //^ return top
        int top() {
            
            //todo if top val is derived from formula
            if(stk.top() < minVal) {
                return minVal;
            } 
            else {
                return stk.top();
            }
        }

        int getMin() {
            return minVal;
        }
    };

};

class String {

public: 
    bool validPalindrome(std :: string str) {
        std :: string new_str = "";

        if(new_str.empty()) {
            return true;
        }
        else { 

            for(char ch : str) {
            new_str += std :: tolower(ch);
            }

            for(int i=0;i<new_str.length();) {

                if(!((new_str[i] >= 'a' && new_str[i] <= 'z') || (new_str[i] >= '0' && new_str[i] <= '9'))) {
                new_str.erase(i,1);
                }
                else {
                i++;
                }
            }

        std :: cout << new_str << "\n";

        std ::string rev_str = new_str;

        reverse(rev_str.begin(), rev_str.end());
        std ::cout << rev_str << std ::endl;

        if(rev_str == new_str) return true;
        else return false;
        }

    }



    void remove_all_Occurance(std :: string str) {
        std :: string part = "abc";
        int len = part.length();

        int i=0;
        while(i<str.length()) {
            
            if(str.find(part) < str.length()) {
                int x = str.find(part);
                str.erase(x,len);
            }

            i++;
        }

        std :: cout << str << std :: endl;
        
    } 

    //* function to check equality of both frequency arrays
    bool isFreqSame(int freq[],int windFreq[]) {
        for(int i=0;i<26;i++) {
            if(freq[i]!=windFreq[i]) {
                return false;
            }
        }
        return true;
    }

    //* is there substring permutation in given string
    bool permutationString(std :: string str) {
        std :: string sub_str = "aabc";

        int freq[26] = {0};
        int windFreq[26] = {0};

        //^ calculating freq for sub-string
        for(char ch : sub_str) {
            freq[ch - 'a']++; //^ a->0 , b->1 ... z->25 (the sum of all frequencies will help for permutations) 
        }

        int windSize = sub_str.length();

        //^ initial windowFreq
        for(int i=0;i<sub_str.length();i++) {
            windFreq[str[i]-'a']++;
        }
        if(isFreqSame(freq,windFreq)) return true;

        //^ if not then slide the window
        for(int i=windSize;i<str.length();i++) {
            windFreq[str[i-windSize] - 'a']--; //! remove left most
            windFreq[str[i] - 'a']++; //! add right most

            if(isFreqSame(freq,windFreq)) return true;
        }
        return false;
    }

    // * max sum in array using slinding window


    //* reverse words in string ( leetcode 151)
    void reverseWord(std :: string str) {

        //& Muhammad Anas Razvi -----> Razvi Anas Muhammad

        int n = str.length();
        //^ reverse whole string (two pointer approach)
        int st=0,end=str.length()-1;
        while(st<end) {
            std :: swap(str[st],str[end]);
            st++; end--;
        }

        std :: cout << "reverse string :   " << str << "\n word:    ";

        std :: string ans = "";
        //^ string reverse done, now reverse single words one by one
        //! work on linear time complexity bcoz we use same iterator(i) in both loop
        for(int i=0;i<n;i++) {
            std :: string word = "";
            while(i<n && str[i]!=' ') {
                word += str[i];
                i++;
            }
            std :: reverse(word.begin(),word.end());
            if(word.length()>0) {
                ans += " " + word;
            }
        }
        ans.erase(0,1);


        std :: cout << "\nstring after reversing the words:   " << ans;

    } 

    int compress(std :: vector<char> carr) {

        //~ first run a loop, start from 1st idx then check if next some values are same as that element? if yes then count frequency and store it in answer vector with that character then move to next

        //& ["a","a","b","b","c","c","c"]

        int n = carr.size();
        int idx = 0;
        std :: vector<char> ans;
        for(int i=0;i<n;i++) {
                char ch = carr[i];
                int freq = 0;
            
                while(i<n && carr[i]==ch) {
                    freq++;i++;
                }
            
                if(freq==1) {
                    carr[idx++] = ch; 
                }
                else {
                    carr[idx++] = ch;
                    std :: string s = std :: to_string(freq);

                    for(char digit : s) {
                        carr[idx++] = digit;
                    }
                }
                i--;
        }

        std :: cout << "compressed array : \n";
        for(char ch : carr) {
            std :: cout << ch << " ";
        }

        carr.resize(idx);

        return idx;
    }
};

class Recursion_Backtrack {

public:
    //* power of two using recursion (leetcode 231)
    bool powerTwo(int n) {

        //^ base case
        if(n == 1) {
            return true;
        }

        if(n <= 0 || n%2 != 0) {
            return false;
        }
        
        return powerTwo(n/2);
    }

    //* fibonacci series (leetcode )
    int fibonacci(int n) {
        if(n==0 || n==1) {
            return n;
        }

        return fibonacci(n-1) + fibonacci(n-2);
    }


    void add_element(int arr[],int n,int i) {
        if(i==n) {
            return;
        }
        std :: cin >> arr[i];

        return add_element(arr,n,i+1);
    }

    std :: vector print_element(vector <int> &arr,int n,int i) {
        if(i==n) {
            return;
        }
        std :: cout << arr[i] << " ";

        return print_element(arr,n,i+1);
    }

    int sum_of_array(int arr[],int n,int i) {
        if(i==n) 
            return 0;

        return arr[i] + sum_of_array(arr,n,i+1);
    }

    //* check if array is sorted or not
    bool isSorted(std :: vector<int> &vec, int n) {
        
        //^ base case
        if(n==0 || n==1) {
            return true;
        }
        if(vec[n-2] > vec[n]) {
            return false;
        }

        return isSorted(vec,n-1);
    }

    //* recursive binary search
    int recBinarySearch(std :: vector<int> &vec, int low, int high, int key) {
        //^ calculating mid value
        if(low <= high) {
            int mid = low + (high-low)/2;
        

            //^ if key is found at mid
            if(vec[mid]==key) {
                return mid;
            }
            //^ search in right
            else if(vec[mid]<key) {
                recBinarySearch(vec,mid+1,high,key);
            }
            //^ search in left
            else {
                recBinarySearch(vec,low,mid-1,key);
            }
        }
        //^ if not found
        return -1;
    }

    //* subset-II (without duplication) (leetcode 90)
    void subSet2(std :: vector<int> &vec, std :: vector<int> &ans, int i) {
        
        //^ sorting the array
        std :: sort(vec.begin(),vec.end());

        //^ base case
        if(i == vec.size()) {
            for(int val : ans) {
                std :: cout << val << " ";
            }
            std :: cout << std :: endl;
            return;
        }

        //^ include
        ans.push_back(vec[i]);
        subSet2(vec,ans,i+1);

        ans.pop_back();    //~ backtrack

        //todo check for the duplications
        int idx = i+1;
        while(idx < vec.size() && vec[idx] == vec[idx-1]) {
            idx++;
        }
        //^ exclude
        subSet2(vec,ans,idx); 
    }

    //* permutations of array (leetcode 44)
    void permutation(std :: vector<int>& vec, std :: vector<int>& ans, int i) {

        //^ base case
        if(i == vec.size()) {
            for(int val : vec) {
                std :: cout << val << " ";
            }
            std :: cout << std :: endl;
            return;
        }

        for(int j=i; j<vec.size(); j++) {
            std :: swap(vec[j], vec[i]); //~ swap with another position for permutation
            permutation(vec,ans,i+1); //~ recursive call for next index

            std :: swap(vec[j],vec[i]); //!backtracking
        }
    }

    //* N-Queens algorithm chess problem -> plz recite astaghfar before this program
    bool isSafe(std :: vector<std :: string>& board, int row, int colm, int n) {

        int i,j;

        //^ check for columns
        for(i=0; i<n; i++) {
            if(board[i][colm] == 'Q') return false;
        }

        //^ check for upper left diagonals
        for(i=row-1, j=colm-1; i>=0 && j>=0; i--, j--) {
            if(board[i][j] == 'Q') return false;
        }

        //^ check for upper right diagonals
        for(i=row-1, j=colm+1; i>=0 && j<n; i--, j++) {
            if(board[i][j] == 'Q') return false;
        }

        return true;
    }

    void printBoard(const std::vector<std::string>& board, int n, int& solutionCount) {
        solutionCount++;
        std::cout << "\nSolution " << solutionCount << ":\n";
        
        //^ Print top border
        for(int i = 0; i < n; i++) {
            std::cout << "+-------";
        }
        std::cout << "+\n";
        
        //^ Print rows with side borders
        for(int i = 0; i < n; i++) {
            std::cout << "|";
            for(int j = 0; j < n; j++) {
                std::cout << "   " << board[i][j] << "   |";
            }
            std::cout << "\n";
            
            //^ Print horizontal line after each row
            for(int k = 0; k < n; k++) {
                std::cout << "+-------";
            }
            std::cout << "+\n";
        }
        std::cout << "\n";
    }

    void nQueens(std :: vector<std :: string>& board, int row, int n, int& solutionCount) {

        //^ base case
        if(row == n) {
            printBoard(board, n, solutionCount);
            return;
        }

        for(int j=0; j<n; j++) {
            if(isSafe(board, row, j, n)) {
                board[row][j] = 'Q';
                nQueens(board, row+1, n, solutionCount); //~ recursive call
                board[row][j] = '-'; //~ backtrack
            }
        }
    }

    void nQueenMain() {

        int n;
        std :: cout << "\nenter size of board :   ";
        std :: cin >> n;

        std :: vector<std :: string> board(n, std :: string(n,'-'));
        std :: vector<std :: vector<std :: string>> ans;

        int solutionCount = 0;

        std :: cout << "\n\nall solutions for " << n << " queens : \n\n\n";

        nQueens(board,0,n, solutionCount);

        std::cout << "Total solutions found: " << solutionCount << std::endl;
    }

    //* Sudoku solver
    bool isSafeSD(std :: vector<std :: vector<char>>& grid, int row, int colm, char dig) {

        //^ check for rows
        for(int i=0; i<9; i++) {
            if(grid[row][i] == dig) return false;
        }

        //^ check for columns
        for(int j=0; j<9; j++) {
            if(grid[j][colm] == dig) return false;
        }

        //^ check for sub-grid
        int startRow = row - row % 3;
        int startCol = colm - colm % 3;

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(grid[startRow + i][startCol + j] == dig) return false;
            }
        }

        return true;
    }

    void printGrid(const std::vector<std:: vector<char>>& grid) {
    
        //^ Print top border
        for(int i = 0; i < 9; i++) {
            std::cout << "+-------";
        }
        std::cout << "+\n";
        
        //^ Print rows with side borders
        for(int i = 0; i < 9; i++) {
            std::cout << "|";
            for(int j = 0; j < 9; j++) {
                std::cout << "   " << grid[i][j] << "   |";
            }
            std::cout << "\n";
            
            //^ Print horizontal line after each row
            for(int k = 0; k < 9; k++) {
                std::cout << "+-------";
            }
            std::cout << "+\n";
        }
        std::cout << "\n";
    }

    void sudokuSolver(std :: vector<std :: vector<char>>& grid, int row, int colm) {
        
        //^ base case
        if(row == 9) {
            //& print grid / return soln
            printGrid(grid);
            return;
        }
        
        //^ if there's already a digit on the cell
        if(grid[row][colm] != '-') {

            //~ recursive call
            if(colm == 9) {
                sudokuSolver(grid, row+1, 0);
                return;
            }
            else {
                sudokuSolver(grid, row, colm+1);
            }
        }

        else {
            for(int j=1; j<=9; j++) {
                if(isSafeSD(grid, row, colm, j + '0')) {
                    grid[row][colm] = j + '0'; //~ if safe then put it on grid

                    //~ recursive call
                    if(colm == 9) {
                        sudokuSolver(grid, row+1, 0); 
                        return;
                    }
                    else {
                        sudokuSolver(grid, row, colm+1);
                    }
                }
                //! backtrack
                grid[row][colm] = '-';
            }
        }
    }

    //* cat in maze : leetcode i don't knoww
    void findPath(std :: vector<std :: vector<int>>& maze, int row, int colm, std :: string path) {

        int n = maze.size();

        if(row < 0 || colm < 0 || row >= n || colm >= n || maze[row][colm] == 0 || maze[row][colm] == -1) {
            return;
        }

        if(row == n-1 && colm == n-1) {
            std :: cout << path << std :: endl;
            return;
        }

        maze[row][colm] = -1; //todo visited

        //^ call for down
        findPath(maze, row+1, colm, path + 'D');

        //^ call for up
        findPath(maze, row-1, colm, path + 'U');

        //^ call for left
        findPath(maze,row, colm-1, path + 'L');

        //^ call for right
        findPath(maze, row, colm+1, path + 'R');

        maze[row][colm] = 1; //todo backtracking (unvisit)

    }

    void catInMaze(std :: vector<std :: vector<int>>& maze) {
        int n = maze.size();

        std :: string path = "";

        findPath(maze, 0, 0, path);
    }

    //* combination sum : leetcode 39
    void combSum(std :: vector<int>& arr, std :: vector<int>& comb, int tar, int i) {

        int n = arr.size();

        //^ base case(s)
        if(tar == 0) {
            std :: cout << "combination : \n";
            for(int val : comb) {
                std :: cout << val << " ";
            }
            std :: cout << "\n";
            return;
        }

        if(i == n || tar < 0) {
            return;
        }

        comb.push_back(arr[i]);
        combSum(arr, comb, tar - arr[i] , i+1); //~ recursive call (single inc.)
        combSum(arr, comb, tar - arr[i], i); //~ recursive call (multiple inc.)
        comb.pop_back(); //! backtracking
        combSum(arr, comb, tar, i+1); //~ recursive call (excl.)
        
    }


    //* palindrome partitioning : leetcode 131
    bool isPalindrome(std :: string str) {
        std :: string s2 = str;
        std :: reverse(s2.begin(), s2.end());

        return str == s2; 
    }

    void palindromePart(std :: string str, std :: vector<std :: string> &part) {

        if(str.size() == 0) {
            std :: cout << "partition :     \n";
            for(std :: string p : part) {
                std :: cout << p << " ";
            }
            std :: cout << "\n";
            return;
        } 

        for(int i=0; i<str.size(); i++) {
            std :: string strPart = str.substr(0, i+1);
            if(isPalindrome(strPart)) {
                part.push_back(strPart);
                palindromePart(str.substr(i+1), part); //~ recursive call
                part.pop_back(); //! backtracking
            }
        }
    }

    //* count inversions (brute force)
    void countInv(std :: vector<int> arr, int i, int& count) {

        if (i == arr.size()) {
            std::cout << "count = " << count;
            return;
        }

        //^ loop for checking inversions
        for(int j=i+1; j<arr.size(); j++) {
            if(arr[i] > arr[j]) {
                count ++;
            }
        }
        countInv(arr, i+1, count); //~ recursive call

    }

    //* count inversions (optimized using merge sort)
    int merge(std :: vector<int>& arr, int st, int mid, int end) {

        std :: vector<int> temp;
        int i = st, j = mid+1, invCnt = 0;

        while(i <= mid && j <= end) {

            if(arr[i] <= arr[j]) {
                temp.push_back(arr[i]);
                i++;
            }

            else {
                temp.push_back(arr[j]);
                j++;

                invCnt += (mid - i + 1);
            }
        }

        while(i <= mid) {
            temp.push_back(arr[i]);
            i++;
        }

        while(j <= end) {
            temp.push_back(arr[j]);
            j++;
        }

        for(int i=0; i<temp.size(); i++) {
            arr[i+st] = temp[i];
        }

        return invCnt;
    }


    int inversions(std :: vector<int>& arr, int st, int end) {
        if(st < end) {
            int mid = st + (end-st)/2;

            int leftInvCnt = inversions(arr, st, mid);
            int rightInvCnt = inversions(arr, mid+1, end);

            int invCnt = merge(arr, st, mid, end);

            return leftInvCnt + rightInvCnt + invCnt;
        }

        return 0;
    }

    //* knight's tour : leetcode 2596
    bool knightsTour(std :: vector<std :: vector<int>>& grid, int r, int c, int n, int ev) {

        //& base case(s) for fasle value
        if(r < 0 || c < 0 || r >= n || c >= n || grid[r][c] != ev) {
            return false;
        }

        //& base case(s) for true value
        if(ev == (n*n - 1)) {
            return true;
        }

        //^ recursive call for all 8 possible moves of knight :
        int ans1 = knightsTour(grid, r-2, c+1, grid.size(), ev+1);
        int ans2 = knightsTour(grid, r-1, c+2, grid.size(), ev+1);
        int ans3 = knightsTour(grid, r+1, c+2, grid.size(), ev+1);
        int ans4 = knightsTour(grid, r+2, c+1, grid.size(), ev+1);
        int ans5 = knightsTour(grid, r+2, c-1, grid.size(), ev+1);
        int ans6 = knightsTour(grid, r+1, c-2, grid.size(), ev+1);
        int ans7 = knightsTour(grid, r-1, c-2, grid.size(), ev+1);
        int ans8 = knightsTour(grid, r-2, c-1, grid.size(), ev+1);

        return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8;
    }

};

class Matrix {

public:
    //^ Search in 2D matrix (binary search) leetcode 74
    void binarySearch(int mat[][4], int row, int column) {

        //* input target
        int tar;
        std :: cout << "enter target element :  ";
        std :: cin >> tar;

        //* binary search on rows 
        int stRow = 0;
        int endRow = row - 1;
        bool isFind = false;

        while(stRow <= endRow) {

            //! calculating mid
            int midRow = stRow + (endRow - stRow) / 2;
            
            if(tar >= mat[midRow][0] && tar <= mat[midRow][column-1]) {
                //* binary search for columns on this row
                searchInRow(mat, tar, midRow,column, isFind);
                if(isFind) break;
                else break;
            }

            else if(tar > mat[midRow][column-1]) {
                stRow = midRow+1;
            }

            else {
                endRow = midRow-1;
            }
        }

        if(!isFind) {
            std :: cout << "target didn't exist in matrix";
        }
    }

    //^ search in 2D array leetcode 240
    bool searchMatrix(std :: vector<std :: vector<int>> mat, int tar) {
        int m = mat.size(), n = mat[0].size();
        int r=0, c=n-1;

        while(c>=0 && r<m) {

            if(tar == mat[r][c]) {
                return true;
            }

            else if(tar < mat[r][c]) {
                c--;
            }
            else {
                r++;
            }
        }
        return false;
    }

    //^ spiral matrix traverse : Leetcode 54
    void spiral(std :: vector<std :: vector<int>> mat) {

        int m = mat.size(), n = mat[0].size();

        int firstRow = 0, firstCol = 0;
        int lastRow = m-1, lastCol = n-1;

        while(firstRow <= lastRow && firstCol <= lastCol) {

            //* for top row
            for(int i = firstCol; i <= lastCol; i++) {
                std :: cout << mat[firstRow][i] << " ";
            }
            
            //* for right column
            for(int j = firstRow+1; j <= lastRow; j++) {
                std :: cout << mat[j][lastCol] << " ";
            }

            //* for bottom row
            for(int i = lastCol-1; i >= firstCol; i--) {
                if(firstRow == lastRow) {
                    break;
                }
                std :: cout << mat[lastRow][i] << " ";
            }

            //* for left column
            for(int j = lastRow-1; j >= firstRow+1; j--) {
                if(firstCol == lastCol) {
                    break;
                }
                std :: cout << mat[j][firstCol] << " ";
            }
            firstRow++;
            lastCol--;
            lastRow--;
            firstCol++;
        }
    }
}


int main() {

    //! blah blah blah

    return 0;
}