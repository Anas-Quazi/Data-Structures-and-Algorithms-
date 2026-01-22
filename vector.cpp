#include <iostream>
#include <vector>

using namespace std;

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

//* function to print all subarrays of given array
void print_subarray(vector<int> &arr, int n)
{
    int start, end;

    for (start = 0; start < n; start++)
    {
        for (end = start; end < n; end++)
        {
            for (int i = start; i <= end; i++)
            {
                cout << arr[i];
            }
            cout << " ";
        }
        cout << endl;
    }
}

//* function for linear search
int linear_search(vector<int> &arr, int n)
{
    int key;
    //^ input key element
    cout << "enter key to search :  ";
    cin >> key;

    //^ searching element sequentially
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

//* binary search
int binary_search(vector<int> &arr, int low, int high, int key)
{
    if (low > high)
    {
        return -1; //^ key not found
    }

    //^ calculating mid
    int mid = low + (high-low) / 2;

    if (key == arr[mid])
    {
        return mid;
    }
    else if (key > arr[mid]) //^ search in right half
    {
        return binary_search(arr, mid + 1, high, key);
    }
    else //^ search in left half
    {
        return binary_search(arr, low, mid - 1, key);
    }
}

//* function for bubble sort
void bubble_sort(vector<int> &vec, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool isSwap = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (vec[j] > vec[j + 1])
            {
                swap(vec[j], vec[j + 1]);
                isSwap = true;
            }
        }
        if (!isSwap)
        {
            cout << "array is already sorted" << endl; //^ sorted array
            return;
        }
    }

    cout << "\n\narray after sorting :  " << endl;
    print_array(vec, n);
}

//* selection sort
void selection_sort(vector<int> &vec, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (vec[j] < vec[min])
            {
                min = j;
            }
        }
        swap(vec[i], vec[min]);
    }

    cout << "\n\narray after sorting :  " << endl;
    print_array(vec, n);
}

//* insertion sort
void insertion_sort(vector<int> &vec, int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = vec[i];
        int j = i - 1;
        while (j >= 0 && vec[j] > key)
        {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = key;
    }

    cout << "\n\narray after sorting :  " << endl;
    print_array(vec, n);
}

//* function to merge subarrays
void merge(vector<int> &vec, int st, int mid, int end)
{
    vector<int> temp;

    int i = st, j = mid + 1; //^ initialize i & j to the start & mid+1 respectively

    while (i <= mid && j <= end) //^ comparing ith & jth values till i<mid & j<end
    {
        if (vec[i] <= vec[j])
        {
            temp.push_back(vec[i]);
            i++;
        }
        else
        {
            temp.push_back(vec[j]);
            j++;
        }
    }

    while (i <= mid) //^ while loop for remaining values of left subarray
    {
        temp.push_back(vec[i]);
        i++;
    }

    while (j <= end) //^ while loop for remaining values of right subarray
    {
        temp.push_back(vec[j]);
        j++;
    }

    for (int idx = 0; idx < temp.size(); idx++) //^ copy values from temporary array to original array
    {
        vec[idx + st] = temp[idx];
    }
}

//* merge sort
void merge_sort(vector<int> &vec, int st, int end, int n)
{
    if (st < end)
    {
        int mid = st + (end - st) / 2;

        merge_sort(vec, st, mid, n); //^ calling recursively for left half
        merge_sort(vec, mid + 1, end, n); //^ calling recursively for right half
        merge(vec, st, mid, end); //^ calling merge function to merge subarray in sorted manner
    }
}

//* function for partition
int partition(vector<int> &vec, int st, int end)
{
    int i = st - 1, pivot = vec[end];

    for (int j = st; j < end; j++)
    {
        if (vec[j] <= pivot)
        {
            i++;
            swap(vec[j], vec[i]);
        }
    }

    i++;
    swap(vec[end], vec[i]);
    return i;
}

//* quick sort algorithm
void quick_sort(vector<int> &vec, int st, int end)
{
    if (st < end)
    {
        int pivot = partition(vec, st, end); //^ calling partition function for pivot index
        quick_sort(vec, st, pivot - 1); //^ calling recursively for left half
        quick_sort(vec, pivot + 1, end); //^ calling recursively for right half
    }
}

//! leetcode

//* two sum target
void two_sum(vector<int> &nums, int target) {
    int i, j;
    vector<int> temp;
    for (i; i < nums.size(); i++)
    {
        for (j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
            {
                temp.push_back(i);
                temp.push_back(j);
                break;
            }
        }
    }
    cout << temp[0] << " , " << temp[1];
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
    print_array(result,n);

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

// //* money in bank : leetcode 1716
// int money(int n) {
//     int invs = 0;

//     int week = n / 7;
// }

// //* remove duplicate from sorted array : leetcode 16
// int removeDup(std :: vec) {

// } 

//* pair sum 
std :: vector<int> pairSum(std :: vector<int> &nums, int tar) {

    int n = nums.size();
    std :: vector<int> ans;

    //? two pointer approach
    int st = 0, end = n-1;

    while(st <= end) {
        int sum = nums[st] + nums[end];

        if(sum == tar) {
            ans.push_back(nums[st]);
            ans.push_back(nums[end]);
            break;
        }
        else if(sum < tar) {
            st++;
        }
        else {
            end--;
        }
    }

    std :: cout << ans[0] << " " << ans[1] << "\n";

    return ans;
}

//* majority element (moore's algorithm) : leetcode 169
int majorityElement(std :: vector<int> &nums) {

    int freq = 0, ans =0;

    for(int i=0; i<nums.size(); i++) {

        if(freq == 0) {
            ans = nums[i];
        }
        if(ans == nums[i]) {
            freq++;
        }
        else {
            freq--;
        }
    }

    return ans;
}

//* main function
int main()
{
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

    //* display array after adding all values
    cout << "\n\narray :    \n";

    print_array(vec, n);

    pairSum(vec, 22);

    return 0;
}
