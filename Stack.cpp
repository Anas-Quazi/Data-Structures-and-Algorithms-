//! Stack In Data Structures

#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <iomanip>
#include <algorithm>
#include <unordered_map>

class stackVec{
    std :: vector<int> stk;

public:

    //* function for push
    void push(int val) {
        stk.push_back(val);
    }

    //* function for pop
    void pop() {
        stk.pop_back();
    }

    //* function for returning top value
    int top() {
        return stk[stk.size() - 1];
    }

    //* function for checking is stack empty or not
    bool empty() {
        return stk.size() == 0;
    }

    //* display stack
    void printStack() const {
        std :: cout << "\n========= STACK =========\n\n";

        if (stk.empty()) {
            std :: cout << "| EMPTY |\n";
            std :: cout << "---------\n";
            return;
        }

        //todo Print from top to bottom
        for (int i = stk.size() - 1; i >= 0; --i) {

            if(i == stk.size() - 1) {
                std :: cout << "| " << std :: setw(3) << stk[i] << "   |  <-- TOP\n"; //^ element

                std :: cout << "+-------+\n"; //^ bottom border
            }
        
            else {
                std :: cout << "| " << std :: setw(3) << stk[i] << "   |\n"; //^ element

                std :: cout << "+-------+\n"; //^ bottom border
            }
        }

        std :: cout << "\n---------------------------------------\n";
    }
 

};

//? Implement stack using linked list (STL)
class StackList {

    std :: list<int> st;

public:

    //* push function
    void push(int val) {
        st.push_front(val);
    }

    //* pop function
    void pop() {
        st.pop_front();
    }

    //* top function
    int top() {
        return st.front();
    }

    //* empty function
    bool empty() {
        return st.size() == 0;
    }

};

//* valid paranthesis : leetcode 20
bool isValid(std :: string s) {

    std :: stack<char> stk;

    for(int i=0; i<s.size(); i++) {

        //^ opening characters
        if(s[i] == '{' || s[i] == '[' || s[i] == '(') {
            stk.push(s[i]);
        }

        //^ closing characters
        else {

            if(stk.size() == 0) {
                return false;
            }

            if(stk.top() == '(' && s[i] == ')' || stk.top() == '[' && s[i] == ']' || stk.top() == '{' && s[i] == '}') {
                stk.pop();
            }

            else {
                return false;
            }
        }
    }


    return stk.size() == 0;
}

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

//* largest rectangle in histogram (brute force)
int largeRec(std :: vector<int> &hist) {

    int maxRect = INT_MIN;

    //^ use nested loop
    for(int i=0; i<hist.size(); i++) {

        //& initialize minimum hieght
        int minHieght = hist[i];

        for(int j=i; j<hist.size(); j++) {

            //^ update current range
            minHieght = std :: min(minHieght, hist[j]);

            //^ calc area
            int width = j-i+1;
            int area = minHieght*width;

            //& update maxRect
            maxRect = std :: max(maxRect, area);

        }
    }

    return maxRect;
}


//* largest rectangle (optimized) : leetcode 84
//~ calculate maxRect for each bar
int largeRectHist(std :: vector<int> &hist) {

    int n = hist.size();
    std :: vector<int> left(n, 0);
    std :: vector<int> right(n, 0);

    //^ create stack for min hieght
    std :: stack<int> stk;

    //todo calculate right smaller
    for(int i=n-1; i>=0; i--) {
        while(stk.size() > 0 && hist[stk.top()] >= hist[i]) {
            stk.pop();
        }

        //~ ternary operator for checking condition
        right[i] = stk.empty() ? n : stk.top();

        stk.push(i);
    }

    //^ remove all elements from stack
    while(!stk.empty()) {
        stk.pop();
    }

    //todo calculate left smaller
    for(int i=0; i<n; i++) {
        while(stk.size() > 0 && hist[stk.top()] >= hist[i]) {
            stk.pop();
        }

        //~ ternary operator for checking condition
        left[i] = stk.empty() ? -1 : stk.top();

        stk.push(i);
    }


    int maxRect = INT_MIN;

    for(int i=0; i<n; i++) {

        //? calculate width
        int width = right[i] - left[i] - 1;
        
        //? area for ith bar
        int crtArea = hist[i] * width; //~ hieght of ith bar

        maxRect = std :: max(maxRect, crtArea);

    }

    return maxRect;
}


//* trap rain water : leetcode 42

//? better approach O(n) (prefix array)
int trapWater(std :: vector<int> &height) {

    int n = height.size();

    //^ create two arrays for storing left/right max
    std :: vector<int> leftMax(n, 0);
    std :: vector<int> rightMax(n, 0);

    leftMax[0] = height[0];
    rightMax[n-1] = height[n-1];

    //^ store in left max 
    for(int i=1; i<n; i++) {
        leftMax[i] = std :: max(leftMax[i-1], height[i]);
    }

    //^ store in right max
    for(int i=n-2; i>=0; i--) {
        rightMax[i] = std :: max(rightMax[i+1], height[i]);
    }

    int totalWater = 0;
    //& calculating trapped water
    for(int i=0; i<n; i++) {
        totalWater += std :: min(leftMax[i],rightMax[i]) - height[i];
    }

    return totalWater;
}

//? more optimized approach (two pointers)
int trapWaterOptm(std :: vector<int> &height) {

    int n = height.size();

    int totalWater = 0;
    int l=0, r=n-1;
    int lMax = 0, Rmax = 0;

    while(l < r) {

        lMax = std :: max(lMax, height[l]);
        Rmax = std :: max(Rmax, height[r]);

        if(lMax < Rmax) {
            totalWater += lMax - height[l];
            l++;
        }
        else {
            totalWater += Rmax - height[r];
            r--;
        }

    }

    return totalWater;
}

//* celebrity problem
int celebrity(std :: vector<std :: vector<int>> mat) {
    
    int n = mat.size();

    std :: stack<int> stk;

    for(int i=0; i<n; i++) {
        stk.push(i);
    }

    while(stk.size() > 1) {
        
        int i = stk.top();
        stk.pop();

        int j = stk.top();
        stk.pop();

        if(mat[i][j] == 0) {
            stk.push(i);
        }
        else {
            stk.push(j);
        }

    }

    int celeb = stk.top();
    for(int i=0; i<n; i++) {
        if((mat[i][celeb] == 0 || mat[celeb][i] == 1) && i != celeb) {
            return -1;
        } 
    }

    return celeb;
}

//* expression conversion using stack
class Conversion {

    //& input expression string (infix)
    std :: string inf_str = "a+b*(c^d-c)";
    //& postfix
    std :: string post_str = "abcd^c-*+";
    //& prefix string 
    std :: string pre_str = "+a*b-^cdc";

    //& stack for precedence
    std :: stack<char> s;
    std :: stack<std :: string> stk;

    //& empty string after conversion (answer)
    std :: string ans = "";

    //? priority of operators...
    std :: unordered_map<char, int> pr = {{'^',3}, {'*',2}, {'/',2}, {'+',1}, {'-',1}};
    

public:

    //^ infix to postfix
    std :: string inf_postf() {

        int n = inf_str.size();

        ans.clear();
        while(!s.empty()) {
            s.pop();
        }
        
        for(int i=0; i<n; i++) {
            
            if(isalnum(inf_str[i])) {
                ans += inf_str[i];
            }
            else if(inf_str[i] == '(') {
                s.push(inf_str[i]);
            }
            else if(inf_str[i] == ')') {
                while(!s.empty() && s.top() != '(') {
                    ans += s.top();
                    s.pop();
                }
                if(!s.empty()) s.pop();
            }
            else {
                while(!s.empty() &&
                     (pr[inf_str[i]] < pr[s.top()] ||
                     (pr[inf_str[i]] == pr[s.top()] && inf_str[i] != '^'))) {
                    ans += s.top();
                    s.pop();
                }
                s.push(inf_str[i]);
            }
        }

        while(!s.empty()) {
            ans += s.top();
            s.pop();
        }
        
        std :: cout << "\ninfix to postfix exp:    " << ans << "\n";
        return ans;
    }

    //^ infix to prefix
    std :: string inf_prfx() {

        int n = inf_str.size();

        ans.clear();
        while(!s.empty()) {
            s.pop();
        }

        std :: string revStr = inf_str;
        std :: reverse(revStr.begin(), revStr.end());

        for(int i=0; i<n; i++) {
            if(revStr[i] == '(') revStr[i] = ')';
            else if(revStr[i] == ')') revStr[i] = '(';
        }

        for(int i=0; i<n; i++) {

            if(isalnum(revStr[i])) {
                ans += revStr[i];
            }
            else if(revStr[i] == '(') {
                s.push(revStr[i]);
            }
            else if(revStr[i] == ')') {
                while(!s.empty() && s.top() != '(') {
                    ans += s.top();
                    s.pop();
                }
                if(!s.empty()) s.pop();
            }
            else {
                while(!s.empty() &&
                     (pr[revStr[i]] < pr[s.top()] ||
                     (pr[revStr[i]] == pr[s.top()] && revStr[i] != '^'))) {
                    ans += s.top();
                    s.pop();
                }
                s.push(revStr[i]);
            }
        }

        while(!s.empty()) {
            ans += s.top();
            s.pop();
        }

        std :: reverse(ans.begin(), ans.end());
        std :: cout << "\n\ninfix to prefix expression :    " << ans << "\n";
        return ans;
    }

    //^ postfix to infix
    std :: string postf_inf() {

        int n = post_str.size();

        while(!stk.empty()) {
            stk.pop();
        }

        for(int i=0; i<n; i++) {

            if(isalnum(post_str[i])) {
                stk.push(std :: string(1, post_str[i]));
            }
            else {
                if(stk.size() < 2) return "Invalid Expression";

                std :: string t1 = stk.top(); 
                stk.pop();
                std :: string t2 = stk.top(); 
                stk.pop();

                std :: string conv = '(' + t2 + post_str[i] + t1 + ')';
                stk.push(conv);
            }
        }

        std :: cout << "\n\npostfix to infix expression :   " << stk.top() << "\n";
        return stk.top();
    }

    //^ prefix to infix
    std :: string pre_inf() {

        int n = pre_str.size();

        while(!stk.empty()) {
            stk.pop();
        }

        for(int i=n-1; i>=0; i--) {

            if(isalnum(pre_str[i])) {
                stk.push(std :: string(1, pre_str[i]));
            }
            else {
                if(stk.size() < 2) return "Invalid Expression";

                std :: string opr1 = stk.top(); 
                stk.pop();
                std :: string opr2 = stk.top(); 
                stk.pop();

                std :: string conv = '(' + opr1 + pre_str[i] + opr2 + ')';
                stk.push(conv);
            }
        }

        std :: cout << "\n\nprefix to infix expression :    " << stk.top() << "\n";
        return stk.top();
    }

    //^ postfix to prefix
    std :: string post_pre() {

        int n = post_str.size();

        while(!stk.empty()) {
            stk.pop();
        }

        for(int i=0; i<n; i++) {

            if(isalnum(post_str[i])) {
                stk.push(std :: string(1, post_str[i]));
            }
            else {
                if(stk.size() < 2) return "Invalid Expression";

                std :: string opr1 = stk.top(); 
                stk.pop();
                std :: string opr2 = stk.top(); 
                stk.pop();

                std :: string con = post_str[i] + opr2 + opr1;
                stk.push(con);
            }
        }

        std :: cout << "\n\npostfix to prefix expression :  " << stk.top() << "\n";
        return stk.top();
    }

    //^ prefix to postfix
    std :: string pre_post() {

        int n = pre_str.size();

        while(!stk.empty()) {
            stk.pop();
        }

        for(int i=n-1; i>=0; i--) {

            if(isalnum(pre_str[i])) {
                stk.push(std :: string(1,pre_str[i]));
            }
            else {
                if(stk.size() < 2) return "Invalid Expression";

                std :: string op1 = stk.top(); 
                
                stk.pop();
                std :: string op2 = stk.top(); stk.pop();

                std :: string con = op1 + op2 + pre_str[i];
                stk.push(con);
            }
        }

        std :: cout << "\n\nprefix to postfix expression :  " << stk.top() << "\n";
        return stk.top();
    }
};



int main() {

    StackList s;

    s.push(11);
    s.push(6);
    s.push(9);
    s.push(6);
    s.push(16);
    s.push(25);

    s.pop();
    
    s.push(4);


    //? Implement stack using C++ STL
    std :: stack<int> s2;

    // std :: string str = "{[([])]}";

    // std :: cout << isValid(str);

    std :: vector<std :: vector<int>> m = { {0, 1, 0},
                                            {0, 0, 0}, 
                                            {0, 1, 0} };

    
    Conversion exp;

    exp.inf_postf();
    exp.inf_prfx();
    exp.postf_inf();
    exp.pre_inf();
    exp.post_pre();
    exp.pre_post();

    return 0;
}