#include <iostream>
#include <vector>

//! sorting (recursive quick sort) --------------------------------------------------

//* partition function
int partition(std :: vector<int> &vec, int st, int end) {
    int i =st-1, pivot = vec[end];

    for(int j=st; j<end; j++) {
        if(vec[j] <= pivot) {
            i++;
            std :: swap(vec[j], vec[i]);
        }
    }
    i++;
    std :: swap(vec[end], vec[i]);

    return i; //^ return point of partition i.e pivot
}

//* quick sort
void quickSort(std :: vector<int> &vec, int st, int end) {

    //^ base case
    if(st < end) {
        int pivot = partition(vec,st,end);
        quickSort(vec,0,pivot-1); //~ call recursively for left half
        quickSort(vec,pivot+1,end); //~ call recursively for right half 
    }
}

//! recursion -----------------------------------------------------------------------

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

//! backracking ---------------------------------------------------------------------

//* print all subsets
std :: vector<std :: vector<int>> subset(std :: vector<int> &vec) {

    //^ create vector of vectors for returning
    std :: vector<std :: vector<int>> powerSet;

    

    //todo -- traverse whole array (with inner loop), first with single elements then increase window size till array size (with outer loop)

    //^ window size
    for(int i=0; i<vec.size(); i++) {
        //^ travese array
        for(int j=0; j<vec.size(); j++) {
            
        }
    }

}

//* using recursion
void recSubSet(std :: vector<int> &vec, std :: vector<int> &ans, int i) {

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
    recSubSet(vec,ans,i+1);

    //^ exclude
    ans.pop_back(); //~ backtrack
    recSubSet(vec,ans,i+1);

}

//* subset-II (without duplication) (leetcode 90)
void subSet2(std :: vector<int> &vec, std :: vector<int> &ans, int i) {
    
    //^ sorting the array
    quickSort(vec,0,vec.size()-1);

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

        ans.pop_back();           

    //todo check for the duplications
    int idx = i+1;
    while(idx < vec.size() && vec[idx] == vec[idx-1]) {
        idx++;
    }
    subSet2(vec,ans,idx); 
}



int main() {

    int n;
    std :: cout << "enter size of array :  " << std :: endl;
    std :: cin >> n;

    std :: vector <int> arr;

    std :: vector<int> ans;

    int i=n;
    int val;

    std :: cout << "enter " << n << " values ";
    while(i!=0) {
        std :: cin >> val;
        arr.push_back(val);
        i--;
    }

    std :: cout << "\n";
    subSet2(arr,ans,0);
   
    return 0;
}