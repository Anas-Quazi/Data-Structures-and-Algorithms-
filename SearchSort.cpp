#include <iostream>
#include <vector>

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

int main() {

    return 0;
}