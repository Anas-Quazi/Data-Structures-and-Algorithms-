#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

void print_array(std :: vector<int> &vec, int n)   {
    for (int i = 0; i < n; i++)
    {
        std :: cout << "+-----";
    }
    std :: cout << "+\n";

    for (int i = 0; i < n; i++)
    {
        std :: cout << "| " << vec[i] << "  ";
    }
    std :: cout << "|\n";

    for (int i = 0; i < n; i++)
    {
        std :: cout << "+-----";
    }
    std :: cout << "+\n";
}


//! backracking ---------------------------------------------------------------------

//* print all subsets (maybe not effecient without backtracking)
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
    return powerSet;
}

//* using recursion (backtracking)
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

    ans.pop_back(); //~ backtrack

    //^ exclude
    recSubSet(vec,ans,i+1);

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


int main() {

    int n;
    std :: cout << "enter size of array :  ";
    std :: cin >> n;

    std :: vector<int> arr;
    std :: vector<int> ans;

    int i=n;
    int val;
    std :: cout << "enter " << n << " values ";
    while(i!=0) {
        std :: cin >> val;
        arr.push_back(val);
        i--;
    }

    print_array(arr,n);

    std::vector<std::vector<char>> grid = {
    {'5', '3', '-', '-', '7', '-', '-', '-', '-'},
    {'6', '-', '-', '1', '9', '5', '-', '-', '-'},
    {'-', '9', '8', '-', '-', '-', '-', '6', '-'},
    {'8', '-', '-', '-', '6', '-', '-', '-', '3'},
    {'4', '-', '-', '8', '-', '3', '-', '-', '1'},
    {'7', '-', '-', '-', '2', '-', '-', '-', '6'},
    {'-', '6', '-', '-', '-', '-', '2', '8', '-'},
    {'-', '-', '-', '4', '1', '9', '-', '-', '5'},
    {'-', '-', '-', '-', '8', '-', '-', '7', '9'}
    };

    std :: vector<std :: vector<int>> maze = {{0,11,16,5,20},{17,4,19,10,15},{12,1,8,21,6},{3,18,23,14,9},{24,13,2,7,22}};

    int r = maze.size(), c = maze[0].size();

    //* print matrix
    std :: cout << "\n\n2D Array :\n";
    for(int i=0; i<r; i++) {
        std :: cout << std :: endl;
        for(int j=0; j< c; j++) {
            std :: cout << maze[i][j] << " ";
        }
    }

    std :: set<std :: vector<int>> s;

    std :: string str = "aab";
    std :: vector<std :: string> part;

    int count = 0;

    std :: cout << knightsTour(maze, 0, 0, maze.size(), 0);


    return 0;

}
