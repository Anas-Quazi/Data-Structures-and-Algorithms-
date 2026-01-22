#include <iostream>
#include <vector>
using namespace std;

void print_array(vector<int> &vec, int n)   {
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

void decrypt(vector<int>& code, int k) {
    int n = code.size();
    vector<int> result(n, 0);

    if (k == 0) {
        // All elements become 0
        for (int i = 0; i < n; i++) {
            result[i] = 0;
        }
    } else if (k > 0) {
        // Sum next k elements (circular)
        for (int i = 0; i < n; i++) {
            int x = 0;
            for (int j = 1; j <= k; j++) {
                x += code[(i + j) % n];
            }
            result[i] = x;
        }
    } else {
        // Sum previous k elements (circular)
        for (int i = 0; i < n; i++) {
            int x = 0;
            for (int j = 1; j <= -k; j++) {
                x += code[(i - j + n) % n];
            }
            result[i] = x;
        }
    }
    print_array(result, n);
}

bool isFreqSame(int freq[], int windFreq[]) {
    for (int i = 0; i < 26; i++) {
        if (freq[i] != windFreq[i]) {
            return false;
        }
    }
    return true;
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

bool isPalindrome(int x) {
    int reverse = 0;
    if(x<0) {
        return false;
    }
    else {
        while(x!=0) {
            int temp = x % 10;
            reverse = reverse*10 + temp;
            x = x / 10;
        }
    }
 
    return x==reverse;
}


bool permutationString(std::string str) {
    std::string sub_str = "ab";
    int n = str.length();
    int k = sub_str.length();

    if (n < k) return false;

    int freq[26] = {0};
    int windFreq[26] = {0};

    // Frequency for sub_str
    for (char ch : sub_str) {
        freq[ch - 'a']++;
    }

    // Initial window frequency
    for (int i = 0; i < k; i++) {
        windFreq[str[i] - 'a']++;
    }

    if (isFreqSame(freq, windFreq)) return true;

    // Slide the window
    for (int i = k; i < n; i++) {
        windFreq[str[i - k] - 'a']--; // remove leftmost
        windFreq[str[i] - 'a']++;     // add rightmost
        if (isFreqSame(freq, windFreq)) return true;
    }

    return false;
}

//* Sudoku solver
bool isSafeSD(std :: vector<std :: vector<char>>& grid, int row, int colm, int dig) {

    //^ check for rows
    for(int i=0; i<9; i++) {
        if(grid[row][i] == dig) return false;
    }

    //^ check for columns
    for(int j=0; j<9; j++) {
        if(grid[j][colm] == dig) return false;
    }

    //^ check for sub-grid
    //& 0 1 2 --- 3 4 5 --- 6 7 8 ---> (0,2)

    //todo for rows
    if(row < 3) {
        for(int k=0; k <=2; k++) {
            // todo for columns
            if(colm < 3) {
                for(int l=0; l<=2; l++) {
                    if(grid[k][l] == dig) return false;
                }
            }

            else if(colm < 6) {
                for(int l=3; l<=5; l++) {
                    if(grid[k][l] == dig) return false;
                }
            }

            else {
                for(int l=6; l<=8; l++) {
                    if(grid[k][l] == dig) return false;
                }
            }
        }
    }

    else if(row < 6) {
        for(int k=3; k<=5; k++) {
            // todo for columns
            if(colm < 3) {
                for(int l=0; l<=2; l++) {
                    if(grid[k][l] == dig) return false;
                }
            }

            else if(colm < 6) {
                for(int l=3; l<=5; l++) {
                    if(grid[k][l] == dig) return false;
                }
            }

            else {
                for(int l=6; l<=8; l++) {
                    if(grid[k][l] == dig) return false;
                }
            }
        }
    }

    else {
        for(int k=6; k<=8; k++) {
            // todo for columns
            if(colm < 3) {
                for(int l=0; l<=2; l++) {
                    if(grid[k][l] == dig) return false;
                }
            }

            else if(colm < 6) {
                for(int l=3; l<=5; l++) {
                    if(grid[k][l] == dig) return false;
                }
            }

            else {
                for(int l=6; l<=8; l++) {
                    if(grid[k][l] == dig) return false;
                }
            }
        }
    }

    return true;
}

void sudokuSolver(std :: vector<std :: vector<char>>& grid, int row, int colm) {
    
    //^ base case
    if(row == 8) {
        //& print grid / return soln
        return;
    }
    
    //^ if there's already a digit on the cell
    if(grid[row][colm] != '-') {

        //~ recursive call
        if(colm < 9) {
            sudokuSolver(grid, row, colm+1);
        }
        else {
            sudokuSolver(grid, row+1, 0);
        }
    }

    else {
        for(int j=0; j<9; j++) {
            if(isSafeSD(grid, )) {
                grid[row][colm] = j;

                //~ recursive call
                if(colm < 9) {
                sudokuSolver(grid, row, colm+1); 
                }
                else {
                sudokuSolver(grid, row+1, 0);
                }
            }
            //! backtrack
            grid[row][colm] = '-';
        }
    }
}

int main() {
    int n, val;

    //* initialize an empty vector
    vector<int> vec;

    //* input size
    cout << "enter size of array :   " << endl;
    cin >> n;

    //* input values
    int i = n;
    cout << "enter " << n << " values : " << endl;
    while (i != 0)
    {
        cin >> val;
        vec.push_back(val); //^ pushing values in vector/array

        i--; //^ decrease i by 1
    }

    print_array(vec,n);

    std :: cout << recBinarySearch(vec,0,vec.size(),11);

    return 0;

}

