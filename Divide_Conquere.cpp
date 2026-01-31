#include <iostream>
#include <vector>

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

int main() {

}