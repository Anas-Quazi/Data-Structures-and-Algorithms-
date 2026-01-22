//* hashing in C++ 

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <list>

//? input size for array :
//? globally : 10^7(int) & 10^8(bool)
//? inside main : 10^6(int) & 10^7(bool)

//* count frequency of each element : O(n)
int countFreq(std :: vector<int> &arr ,int n, int size) {
    
    int cnt = 0;

    for(int i=0; i<size; i++) {
        if(arr[i] == n) {
            cnt ++;
        }
    }

    return cnt;
}

//* number hashing (calc freq)
//* number hashing (calc freq)
void hashFuncInt(std::vector<int> &arr, int n) {
    
    //! precomputation
    //^ create hash array (assuming max value won't exceed 10^7)
    std::vector<int> hash(10000001, 0);

    for(int i = 0; i < n; i++) {
        hash[arr[i]]++;
    }

    //^ how many queries?
    int q;
    std::cout << "enter number of queries\n";
    std::cin >> q;

    //^ while q>0 do and q--
    while(q--) {
        int num;
        std::cout << "enter a number\n";
        std::cin >> num;

        //! fetch (from hash array)
        std::cout << num << " appear " << hash[num] << " times\n";
    }
}

//* character hashing
void hashFuncChar(std :: string str) {

    //! pre computation
    int hash[256] = {0};

    //todo calc frequency using ASCII value
    for(int i=0; i<str.size(); i++) {
        hash[str[i]]++;
    }

    int q;
    std :: cout << "number of queries? \n";
    std :: cin >> q;

    while(q--) {

        char ch;
        std :: cout << "enter number :  ";
        std :: cin >> ch;

        //! fetch
        std :: cout << ch << " appear " << hash[ch] << " times\n";
    }
}

//* hashmap from c++ stl (beneficial for space complexity) 
void hashMapInt(std :: vector<int> &arr, int n) {

    //! pre compute
    std :: unordered_map<long int, long int> mp;
    for(int i=0; i<n; i++) {
        mp[arr[i]]++;
    }

    for(auto it : mp) {
        std :: cout << it.first << " --> " << it.second << "\n";
    }

    //^ how many queries?
    int q;
    std :: cout << "enter number of queries\n";
    std :: cin >> q;

    //^ while q>0 do and q--
    while(q--) {
        int num;
        std :: cout << "enter a number\n";
        std :: cin >> num;

        std :: cout << num << " appear " << mp[num] << " times\n";
    }
}

//* hashmap for characters
void hashMapChar(std :: string str) {

    //! pre compute
    std :: unordered_map<char, int> mp;
    for(int i=0; i<str.size(); i++) {
        mp[str[i]]++;
    }
    
    //^ how many queries?
    int q;
    std :: cout << "enter number of queries\n";
    std :: cin >> q;

    //^ while q>0 do and q--
    while(q--) {
        char ch;
        std :: cout << "enter a character\n";
        std :: cin >> ch;

        //! fetch
        std :: cout << ch << " appear " << mp[ch] << " times\n";
    }
}

//& design hashmap from scratch
class MyHashMap {
public:
    int size = 1000;
    std :: vector<std :: vector<std :: pair<int, int>>> table;
    
    MyHashMap() {
        table.resize(size);
    }

    int hash(int key) {
        return key % size;
    }
    
    void put(int key, int value) {
        int idx = hash(key);

        for(auto &[a,b] : table[idx]) {
            if(a == key) {
                b = value;
                return;
            }
        }
        table[idx].push_back({key, value});
    }
    
    int get(int key) {
        int idx = hash(key);
        for(auto &[a,b] : table[idx]) {
            if(a == key) {
                return b;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int idx = hash(key);
        for(int i=0; i< table[idx].size(); i++) {
            if(table[idx][i].first == key) {
                table[idx].erase(table[idx].begin() + i);
                return;
            }
        }
    }
};

//& Hashing techniques :

//* division method 
void divisionHash(std :: vector<int> &arr, int n) {

}

//* collision nd chaining 
class HashTableChaining {

private:
    int size;
    std :: vector<std :: list<int>> table;

    //^ hash function (division method)
    int hashFunc(int key) {
        return key % size;
    }

public:
    //^ constructor 
    HashTableChaining(int s) {
        size = s;
        table.resize(size);
    }

    //~ Insert
    void insert(int key) {
        int index = hashFunc(key);
        table[index].push_back(key);
    }

    //~ delete
    void remove(int key) {
        int index = hashFunc(key);
        table[index].remove(key);
    }

    //~ search (if exist)
    bool exist(int key) {
        int index = hashFunc(key);
        for(auto it : table[index]) {
            if(it == key) return true;
        }
        return false;
    }

    //& search index
    void search(int key) {
        int index = hashFunc(key);
        bool found = false;
        int pos = 1;
        
        for(auto j : table[index]) {
            if(j == key) {
                std :: cout << "key found at : " << index << " index and " << pos << " position in chain\n";
                found = true;
                break;
            }
            pos++;
        }
        
        if(!found) std :: cout << "not found\n";
    }

    //~ dispaly table
    void display() {

        //? traverse buckets
        for(int i=0; i<size; i++) {
            std :: cout << "Index : " << i << ": ";
            //? traverse linked list
            for(auto it : table[i]) {
                std :: cout << it << " -> ";
            }
            std :: cout << "NULL\n";
        }
    }
};

//! leetcode problems

//* two sum : leetcode 1
std :: vector<int> twoSum(std :: vector<int> &nums, int tar) {
    
    //^ create hashtable (element : index)
    std :: unordered_map<int, int> mp;
    std :: vector<int> ans;

    //~ traverse array for first val
    for(int i=0; i<nums.size(); i++) {

        int first = nums[i];
        int second = tar - first;

        if(mp.find(second) != mp.end()) {
            ans.push_back(i);
            ans.push_back(mp[second]);
            break;
        }
        
        mp[first] = i;
    }

    return ans;
}

//* majority element : leetcode 169
int majorityElement(std :: vector<int>& nums) {

    int n = nums.size();
    int ans;
    
    //^ use map for frequency
    std :: unordered_map<int, int> m;
    for(int i=0; i< nums.size(); i++) {
        m[nums[i]]++;
    }

    //! nothing... just verification
    for(auto val : m) {
        std :: cout << val.first << " " << val.second << "\n";
    }

    //? is appearing >n/2 times?
    for(auto val : m) {
        if(val.second > n/2) {
            ans = val.first;
        }
    }

    return ans;
}

//* anagram strings
bool isAnagram(std :: string s, std :: string t) {

    if(s.length() != t.length()) return false;
    
    //? unordereded map
    std :: unordered_map<char, int> m1;
    std :: unordered_map<char, int> m2;

    //^ calc freq of string s
    for(int i=0; i<s.length(); i++) {
        m1[s[i]]++;
    }

    //^ calc freq of string t
    for(int i=0; i<t.length(); i++) {
        m2[t[i]]++;
    }

    //! nothing... just verification
    for(auto val : m1) {
        std :: cout << val.first << " " << val.second << "\n";
    }
    std :: cerr << "\n";
    //! nothing... just verification
    for(auto val : m2) {
        std :: cout << val.first << " " << val.second << "\n";
    }

    bool isAnag = true;
    for(int i=0; i<m1.size(); i++) {
        if(m1[i] != m2[i]) isAnag = false;
    }

    return isAnag;
}

//* roman to intiger
int romanToInt(std :: string s) {
    
    std :: unordered_map<char, int> roman = {
        {'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D', 500}, {'M', 1000}
    };

    int ans = 0;
    for(int i=0; i<s.length(); i++) {

        int crt = roman[s[i]];
        int next = (i+1 < s.length()) ? roman[s[i+1]] : 0;

        if(crt < next) {
            ans -= crt;
        }
        else {
            ans += crt;
        }
    }

    return ans;
}

//* linked list cycle

//^ nothing... just structure for LL
class Node {

public:

    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }

};

class LinkedList {

public:

    Node* head;
    Node* tail;

    //! constructor
    LinkedList() {
        head = tail = NULL;
    }

    Node* getHead() {
        return head;
    }
};

bool isCycle(LinkedList LL) {
    
    Node* head = LL.getHead();

    //^ map for tracking visited
    std :: unordered_map<Node*, bool> visited;

    Node* itr = head;
    while(itr != NULL) {

        if(visited[itr] == true) {
            return true;
        }
        visited[itr] = true;
        itr = itr -> next;
    }

    return false;
    
}

//& abcabcbb
//? pwwkew
//~ bbbbb

//* longest substring without repeating characters
int lengthOfLongestSubstring(std :: string str) {

    //! if empty string
    if(str.empty()) return 0;
    
    //^ map for frequency tracking
    std :: unordered_map<char, int> m;

    //? variable to count length
    int longestSubstr = INT_MIN;

    //todo traverse string nd store frequencies
    for(int i=0; i<str.length(); i++) {
        
        //? track current length
        int crtLength = 0;
        if(m.find(str[i]) != m.end()) {
            crtLength = i - m[str[i]];
        }
        else {
            crtLength++;
        }

        longestSubstr = std :: max(longestSubstr, crtLength);
        m[str[i]] = i;
    }

    return longestSubstr;
}

//* find missing & repeating val : leetcode 2965

//* main function #42b883 #8229e2
int main() {

    //~ input size and array
    int n;
    std :: cout << "enter size of array\n";
    std :: cin >> n;
    std :: vector<int> arr;

    std :: cout << "enter " << n << " values\n";
    for(int i=0; i<n; i++) {
        int val;
        std :: cin >> val;
        arr.push_back(val);
    }

    std :: string str;
    std :: cout << "enter a string \n";
    std :: cin >> str;
    
  
    hashMapInt(arr, n);
    hashMapChar(str);

    std :: cout << "========== CHAINING ==========\n";
    HashTableChaining ht1(7);
    ht1.insert(12);
    ht1.insert(22);  //! Collision with 12
    ht1.insert(32);  //! Collision with 12, 22
    ht1.insert(15);
    ht1.insert(8);
    ht1.display();
    ht1.search(32);
    std :: cout << "Search 22: " << (ht1.exist(22) ? "Found" : "Not Found") << "\n";
    std :: cout << "Search 99: " << (ht1.exist(99) ? "Found" : "Not Found") << "\n\n";

    std :: cout << lengthOfLongestSubstring("anagram");

    return 0;
}

//todo 1) function for serch in index 
//todo 2) func(loop) for input 