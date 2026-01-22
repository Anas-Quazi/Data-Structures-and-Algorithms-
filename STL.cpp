#include <iostream>

// ! Standard Template Library In C++ (CONTAINERS AND ALGORITHMS)

// ? sequential containers in C++

// * vectors (dynamic array (one sided))
#include <vector> // * including vectors header file

// todo : functions for vector operation (sub-function of vector_main())

// * function for insertion
void vector_insert(std ::vector<int> &vec)
{

    // ^ adding some values
    vec.push_back(6);
    vec.push_back(10);
    vec.push_back(16);
    vec.emplace_back(25);

    // ^ insert at a particular index
    vec.insert(vec.begin() + 1, 28);
    vec.insert(vec.begin() + 3, 11);
}

// * function for earasing values
void vector_erase(std ::vector<int> &vec)
{

    // ^ earse a particular value
    vec.erase(vec.begin() + 1);
    vec.pop_back();
}

// * function for accessing values
void vector_access(std ::vector<int> &vec)
{

    // ^ accesing values using index
    std ::cout << vec.at(0) << std ::endl;
    std ::cout << vec[1] << std ::endl;

    // ^ accesing front & back values
    std ::cout << vec.front() << std ::endl;
    std ::cout << vec.back() << std ::endl;
}

// * function for checking size, capacity nd isEmpty
void vector_size(std ::vector<int> &vec)
{

    // ^ size nd capacity
    std ::cout << vec.size() << std ::endl;
    std ::cout << vec.capacity() << std ::endl;

    // ^ cheking if vector is empty or not
    std ::cout << "is empty : " << vec.empty() << std ::endl;
}

// * function for iteration
void vector_iterator(std ::vector<int> &vec)
{

    // ^ creating an iterator for travese (forward)
    std ::vector<int>::iterator itr;
    for (itr = vec.begin(); itr != vec.end(); itr++)
    {
        std ::cout << *(itr) << std ::endl; // ^ cout derefrence pointer(itr)
    }

    // ^ iterator for backward traverse
    for (auto itr = vec.rbegin(); itr != vec.rend(); itr++)
    {
        std ::cout << *(itr) << std ::endl;
    }
}

// * function for display vector
void vector_dispaly(std ::vector<int> &vec)
{

    // ^ display using for each loop
    std ::cout << "[   ";
    for (int val : vec)
    {
        std ::cout << val << "   ";
    }
    std ::cout << "]";
}

// * main function for vector container
void vector_main()
{

    // ^ creating a vector
    std ::vector<int> vec;

    // ^ calling vector functions
    vector_insert(vec);
    vector_access(vec);
    vector_dispaly(vec);
    vector_iterator(vec);
}

//! list (doubly linked list)
#include <list> // ~ including list header file

//& functions for list operations (sub-functions of list_main())

// * function for inserting values
void list_insert(std ::list<int> &my_list)
{

    // ^ adding values using push/emplace back nd front
    my_list.push_back(12);
    my_list.push_back(10);
    my_list.push_front(16);
    my_list.push_back(313);
    my_list.push_front(786);
    my_list.emplace_back(25);
    my_list.emplace_front(11);
}

// * function for erasing/pop values
void list_erase(std ::list<int> &my_list)
{
    my_list.pop_back();
    my_list.pop_front();
}

// * function for display list
void list_dispaly(std ::list<int> &my_list)
{

    // ^ cout using for each loop
    std ::cout << "[   ";
    for (int val : my_list)
    {
        std ::cout << val << "   ";
    }
    std ::cout << "]";
}

// * main function for list container
void list_main()
{

    // ^ creating list
    std :: list<int> my_list;

    // ^ calling list functions
    list_insert(my_list);
    list_erase(my_list);
    list_dispaly(my_list);
}

// * deque (dynamic array (double sided))
#include <deque> // * including header file for deque

// * functions for deque operations (sub-functions of deque_main())

// * function for inserting values (same as list)
void deque_insert(std ::deque<int> &deq)
{

    // ^ adding values using push/emplace back nd front
    deq.push_back(12);
    deq.push_back(10);
    deq.push_front(16);
    deq.push_back(313);
    deq.push_front(786);
    deq.emplace_back(25);
    deq.emplace_front(11);
}

// * function for erasing/pop values (same as list)
void deque_erase(std ::deque<int> &deq)
{
    deq.pop_back();
    deq.pop_front();
}

// * dispaly deque
void deque_display(std ::deque<int> &deq)
{

    std ::cout << "[  ";
    for (int val : deq)
    {
        std ::cout << val << "  ";
    }
    std ::cout << "]";
}

// * accessing values from deque using indices (not possible in lists)
void deque_access(std ::deque<int> &deq)
{
    std ::cout << deq[0] << std ::endl;
    std ::cout << deq[3] << std ::endl;
}

// * main function for deque
void deque_main()
{
    // ^ creating deque
    std ::deque<int> deq;

    // ^ calling functions
    deque_insert(deq);
    deque_erase(deq);
    deque_display(deq);
    deque_access(deq);
}

// * pair (like python's dictionary)

// * accessing values from pair
void pair_access(std ::pair<std ::string, int> &p)
{

    std ::cout << p.first << std ::endl;
    std ::cout << p.second << std ::endl;
}

// * pair of pair
void pair_of_pair()
{

    std ::pair<int, std ::pair<char, int>> pr = {11, {'a', 25}};

    // ^ accessing values
    std ::cout << pr.first << std ::endl;
    std ::cout << pr.second.first << std ::endl;
    std ::cout << pr.second.second << std ::endl;
}

// * inserting in vector of pair (pushback vs empalce back)
void pair_insert(std ::vector<std ::pair<int, float>> &vect)
{

    vect.push_back({4, 9.2}); // ^ only insert (we need to create pair)
    vect.emplace_back(5, 28); // ^ creates in-place objects
}

// * dispaly vector of pair
void pair_display(std ::vector<std ::pair<int, float>> &vect)
{

    std ::cout << "[  ";
    for (auto p : vect)
    { // ^ used auto instead of std :: pair<int, float>
        std ::cout << "( " << p.first << ", ";
        std ::cout << p.second << " )  ";
    }
    std ::cout << "]" << std ::endl;
}

// * vector of pair
void vec_pair()
{

    std ::vector<std ::pair<int, float>> vect = {{1, 3.14}, {2, 3.13}, {3, 78.6}};

    // ^ calling insert & display
    pair_insert(vect);
    pair_display(vect);
}

// * main function for pairs
void pair_main()
{

    // ^ craeting a pair
    std ::pair<std ::string, int> p = {"razvi", 16};

    // ^ calling other function(s)
    pair_access(p);
    pair_of_pair();
    vec_pair();
}

// * non-sequential (adapter) containers

// & stack (LIFO)
#include <stack>

// * insertion in stack
void stack_insert(std ::stack<int> &stk)
{

    // ^ insert values using push nd emplace
    stk.push(1);
    stk.push(6);
    stk.push(10);
    stk.emplace(11);
    stk.emplace(28);
    stk.emplace(12);
    stk.push(25);
}

// ^ poping values from stack & returning top value
void stack_pop(std ::stack<int> &stk)
{

    int x = stk.top();
    stk.pop();
    std ::cout << "value : " << x << "  popped from stack!" << std ::endl;

    std ::cout << "the new top is : " << stk.top() << std ::endl;
}

// ^ function to check siz end is empty?
void stack_size(std ::stack<int> &stk)
{

    std ::cout << "size of stack is : " << stk.size() << std ::endl;
    std ::cout << "is stack empty : " << stk.empty() << std ::endl;
}

// ^ swap values of one stack with another
void stack_swap(std ::stack<int> &stk)
{
    std ::stack<int> s2;
    s2.swap(stk);
}

// * display stack
void stack_dispaly(std ::stack<int> &stk)
{

    while (!stk.empty())
    {
        std ::cout << " | " << stk.top() << " | " << std ::endl;

        stk.pop();
    }
}

// * main function for stack
void stack_main()
{

    // ^ creating a stack
    std ::stack<int> stk;

    // ^ calling sub-functions
    stack_insert(stk);
    stack_pop(stk);
    stack_size(stk);
    stack_dispaly(stk);
}

// * queue (FIFO)
#include <queue>

// * function for insertion (same as stack, but from last)
void queue_insert(std ::queue<int> &que)
{

    // ^ insert using push function
    que.push(21);
    que.push(99);
    que.push(16);
    que.push(7);
    que.emplace(12);
}

// * function for popping value (from start)
void queue_pop(std ::queue<int> &que)
{

    que.pop();
}

// * function to access front nd rear of the queue
void queue_front_rear(std ::queue<int> &que)
{

    std ::cout << "front : " << que.front() << std ::endl;
    std ::cout << "rear : " << que.back() << std ::endl;
}

// * size nd empty
void queue_size(std ::queue<int> &que)
{

    std ::cout << "size of queue " << que.size() << std ::endl;
    std ::cout << "is queue empty : " << que.empty() << std ::endl;
}

// * display queue using whiel loop
void queue_display(std ::queue<int> &que)
{

    std ::cout << "|  ";
    while (!que.empty())
    {
        std ::cout << que.front() << "  ";
        que.pop();
    }
    std ::cout << "|" << std ::endl;
}

// * main function for queue
void queue_main()
{

    std ::queue<int> que;

    // ^ calling other functions
    queue_insert(que);
    queue_front_rear(que);
    queue_pop(que);
    queue_display(que);
}

// * priority queue

// * function for insertion
void priority_queue_insert(std ::priority_queue<int> &pq)
{

    // ^ insert using push function
    pq.push(12);
    pq.push(99);
    pq.push(313);
    pq.push(1500);
    pq.emplace(92);
}

// * function for popping value (from start)
void priority_queue_pop(std ::priority_queue<int> &pq)
{

    pq.pop();
}

// * function to access top of the priority queue
void priority_queue_top(std ::priority_queue<int> &pq)
{

    std ::cout << "top : " << pq.top() << std ::endl;
}

// * size nd empty
void priorirty_queue_size(std ::priority_queue<int> &pq)
{

    std ::cout << "size of queue " << pq.size() << std ::endl;
    std ::cout << "is queue empty : " << pq.empty() << std ::endl;
}

// * display queue using whiel loop
void priority_queue_display(std ::priority_queue<int> &pq)
{

    std ::cout << "|  ";
    while (!pq.empty())
    {
        std ::cout << pq.top() << "  ";
        pq.pop();
    }
    std ::cout << "|" << std ::endl;
}

// * priority queue in reverse order
void reverse_priority_queue()
{

    std ::priority_queue<int, std ::vector<int>, std ::greater<int>> rpq;

    // ^ insertion in reverse priority queue
    rpq.push(12);
    rpq.push(99);
    rpq.push(313);
    rpq.push(1500);
    rpq.emplace(92);

    std ::cout << "|  ";
    while (!rpq.empty())
    {
        std ::cout << rpq.top() << "  ";
        rpq.pop();
    }
    std ::cout << "|" << std ::endl;
}

// * main function for priority queue
void priority_queue_main()
{

    // ^ careting a priority queue
    std ::priority_queue<int> pq;

    // ^ aclling sub functions
    priority_queue_insert(pq);
    priority_queue_top(pq);
    priority_queue_pop(pq);
    priorirty_queue_size(pq);
    priority_queue_display(pq);
}

// * map (sort key in assending order) , time complexity : O(logn)
#include <map>

// * insert
void map_insert(std ::map<std ::string, int> &mp)
{

    mp.insert({"Villareal", 16});
    mp.emplace("Real Betis", 15);
}

// * erase key
void map_erase(std ::map<std ::string, int> &mp)
{

    mp.erase("Athletic Club");
}

// * count number of keys
void map_count(std ::map<std ::string, int> &mp)
{

    std ::cout << mp.count("Barcelona") << std ::endl; // ^ retirn number with key name
    std ::cout << mp["Barcelona"] << std ::endl;       // ^ return value of key
}

// * function to find key
void map_find(std ::map<std ::string, int> &mp)
{

    mp.find("Atletico");
}

// * size nd empty
void map_size(std ::map<std ::string, int> &mp)
{

    std ::cout << "size of map : " << mp.size() << std ::endl;
    std ::cout << "is mzp empty : " << mp.empty() << std ::endl;
}

// * dispalay map
void map_display(std ::map<std ::string, int> &mp)
{

    std ::cout << std ::endl;
    for (auto val : mp)
    {
        std ::cout << val.first << "  " << val.second << std ::endl;
    }
    std ::cout << std ::endl;
}

// * main function for map
void map_main()
{

    // ^ craeting a map
    std ::map<std ::string, int> mp;

    // ^ adding key value pairs
    mp["Real Madrid"] = 28;
    mp["Atletico"] = 25;
    mp["Barcelona"] = 21;
    mp["Athletic Club"] = 19;

    // ^ calling sub-functions
    map_insert(mp);
    map_find(mp);
    map_erase(mp);
    map_count(mp);
    map_size(mp);
    map_display(mp);
}

// * multi map

// * insert
void multimap_insert(std ::multimap<std ::string, float> &mmp)
{

    mmp.insert({"Gemini", 4.2});
    mmp.emplace("Chat GPT", 4.8);
    mmp.insert({"Copilot", 4.1});
    mmp.insert({"Grok", 4.6});
    mmp.emplace("Deep Seek", 4.0);

    // ^ multiple keys

    mmp.insert({"Chat GPT", 4.4});
    mmp.emplace("Gemini", 4.0);
}

// * display multimap
void multimap_display(std ::multimap<std ::string, float> &mmp)
{

    for (auto val : mmp)
    {
        std ::cout << val.first << "  " << val.second << std ::endl;
    }
    std ::cout << std ::endl;
}

// * main function for multi map
void multimap_main()
{

    // ^ creating a multimap
    std ::multimap<std ::string, float> mmp;

    // ^ calling sub-functions
    multimap_insert(mmp);
    multimap_display(mmp);
}

// * unordered map (not sorted) , time complexity : O(1)
#include <unordered_map>

// * insert
void unoredered_map_insert(std ::unordered_map<std ::string, float> &ump)
{

    ump.insert({"Java", 4.5});
    ump.emplace("SQL", 4.2);
}

// * erase key
void unordered_map_erase(std ::unordered_map<std ::string, float> &ump)
{

    ump.erase("C");
}

// * dispalay map
void unordered_map_display(std :: unordered_map<std :: string, float> &ump)
{

    std :: cout << std :: endl;
    for (auto val : ump)
    {
        std :: cout << val.first << "  " << val.second << std :: endl;
    }
    std :: cout << std :: endl;
}

// * main function for unordered map
void unordered_map_main()
{

    // ^ creating unordered map
    std ::unordered_map<std ::string, float> ump;

    // ^ adding key value pairs
    ump["C++"] = 4.7;
    ump["Python"] = 4.4;
    ump["C"] = 4.1;

    // ^ calling sub functions
    unoredered_map_insert(ump);
    unordered_map_display(ump);
    unordered_map_erase(ump);
}

// * set (array without duplicate values) , sorted with time complexity : O(logn)
#include <set>

// * insert
void set_insert(std ::set<int> &s)
{
    s.insert(16);
    s.insert(25);
    s.emplace(28);
    s.insert(11);
    s.emplace(16);
    s.emplace(3);
}

// * erase
void set_erase(std ::set<int> &s)
{
    s.erase(3);
}

// * lower bound (minimmun)
void set_lower_bound(std ::set<int> &s)
{
    std ::cout << "lower bound : " << *(s.lower_bound(11)) << std ::endl;
}

// * upper bound (greatr than key)
void set_upper_bound(std ::set<int> &s)
{
    std ::cout << "upper bound : " << *(s.upper_bound(11)) << std ::endl;
}

void set_display(std ::set<int> &s)
{
    for (int val : s)
    {
        std ::cout << val << "  ";
    }
    std ::cout << std ::endl;
}

// * main function for set
void set_main()
{
    // ^ creating a set
    std ::set<int> s;

    // ^ calling sub-functions
    set_insert(s);
    set_erase(s);
    set_lower_bound(s);
    set_upper_bound(s);
    set_display(s);
}

// * unordered set (unsorted) , time complexity O(1)
#include <unordered_set>

// * insert
void unordered_set_insert(std ::unordered_set<int> &us)
{
    us.insert(16);
    us.insert(25);
    us.emplace(28);
    us.insert(11);
    us.emplace(16);
    us.emplace(3);
}

// * erase
void unordered_set_erase(std ::unordered_set<int> &us)
{
    us.erase(3);
}

// * dispaly
void unordered_set_display(std ::unordered_set<int> &us)
{
    for (int val : us)
    {
        std ::cout << val << "  ";
    }
    std ::cout << std ::endl;
}

// * main
void unordered_set_main()
{
    std ::unordered_set<int> us;

    // ^ calling sub-functions
    unordered_set_insert(us);
    unordered_set_erase(us);
    unordered_set_display(us);
}

// ? STL Algorithms

// ^ including algorithm headrer file
#include <algorithm>

//! sorting

// * assending order
void sort_assend(std :: vector<int> &vec)
{
    std :: sort(vec.begin(), vec.end());

    std :: cout << "assending sorted array :  [  ";
    for (int val : vec)
    {
        std :: cout << val << "  ";
    }
    std :: cout << "]" << std :: endl;
}

// * desending order
void sort_desend(std ::vector<int> &vec) {
    
    std :: sort(vec.begin(), vec.end(), std :: greater<int>());

    std :: cout << "desending sorted array :  [  ";
    for (int val : vec)
    {
        std :: cout << val << "  ";
    }
    std :: cout << "]" << std :: endl;
}

// * creating a custom comparitor for sorting on basis of 2nd value
bool custom_comparitor(std :: pair<int, int> p1, std :: pair<int, int> p2)
{
    // ^ sorting on the basis of second val
    if (p1.second < p2.second)
        return true;
    if (p1.second > p2.second)
        return false;

    // ^ if second value is equal
    if (p1.first < p2.first)
        return true;
    else
        return false;
}

// * sorting of pair values
void sort_pair()
{
    std ::vector<std ::pair<int, int>> vp = {{7, 1}, {5, 2}, {4, 18}, {1, 13}};

    // ^ (sort on the basis of first value of each pair)
    std ::sort(vp.begin(), vp.end());

    std ::cout << "sorted pair(1st) : ";
    for (auto val : vp)
    {
        std ::cout << "{" << val.first << ", " << val.second << "}" << std ::endl;
    }
    std ::cout << std ::endl;

    // ^ (sort on the basis of second value of each pair)
    std ::sort(vp.begin(), vp.end(), custom_comparitor);

    std ::cout << "sorted pair(2nd) : ";
    for (auto val : vp)
    {
        std ::cout << "{" << val.first << ", " << val.second << "}" << std ::endl;
    }
    std ::cout << std ::endl;
}

// * other algorithms

// * reverse
void reverse_vec(std ::vector<int> &vec)
{
    std ::reverse(vec.begin(), vec.end() - 1);

    std ::cout << "reverse array :  [  ";
    for (int val : vec)
    {
        std ::cout << val << "  ";
    }
    std ::cout << "]" << std ::endl;
}

// * permutation
void permutation()
{

    std ::string str = "afs";

    // ^ next permutaion
    std ::next_permutation(str.begin(), str.end());
    std ::cout << str << std ::endl;

    // ^ previos permutation
    std ::prev_permutation(str.begin(), str.end());
    std ::cout << str << std ::endl;
}

// * max or min
void min_max_swap()
{

    // ^ max
    std ::cout << std ::max(16, 7) << std ::endl;

    // ^ min
    std ::cout << std ::min(25, 11) << std ::endl;

    // ^ swap
    int num1 = 313, num2 = 786;
    std ::swap(num1, num2);

    std ::cout << "num1 = " << num1 << std ::endl
               << "num2 = " << num2 << std ::endl;
}

// * max nd min element in a array/vector
void min_max_vector(std ::vector<int> &vec)
{

    std ::cout << "max element of vec : " << *(max_element(vec.begin(), vec.end())) << std ::endl;
    std ::cout << "min element of vec : " << *(min_element(vec.begin(), vec.end())) << std ::endl;
}

// * binary search
void bin_search(std ::vector<int> &vec)
{

    std ::cout << std ::binary_search(vec.begin(), vec.end(), 11);
}

// * count set bits
void set_bit()
{
    int n = 16;
    long int m = 313;
    long long int o = 786;

    std ::cout << __builtin_popcount(n) << std ::endl;
    std ::cout << __builtin_popcountl(m) << std ::endl;
    std ::cout << __builtin_popcountll(o) << std ::endl;
}

// * impelement a vector for algorithms
void vec_algorithm()
{
    std ::vector<int> vec;

    vec.push_back(6);
    vec.push_back(10);
    vec.push_back(16);
    vec.emplace_back(25);

    // ^ insert at a particular index
    vec.insert(vec.begin() + 1, 28);
    vec.insert(vec.begin() + 3, 11);

    reverse_vec(vec);
    sort_assend(vec);
    sort_desend(vec);
    sort_pair();
    min_max_vector(vec);
    bin_search(vec);
}

// * main function (driver's code) :
int main()
{

    // ^ calling container function(s)

    vector_main();
    list_main();
    pair_main();
    deque_main();

    stack_main();
    queue_main();

    map_main();
    unordered_map_main();
    multimap_main();

    set_main();
    unordered_set_main();

    // ^ calling algorithm function(s)

    vec_algorithm();
    set_bit();
    min_max_swap();
    permutation();

    return 0;
}
