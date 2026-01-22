#include <iostream>
#include <vector>

//^ linear search
void linearSearch(int mat[][4], int rows, int cols) {
     
    int key;
    std :: cout << "\nenter key :    ";
    std :: cin >> key;

    bool isFind = false;
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            if(mat[i][j] == key) {
                std :: cout << "\nkey " << key << " found at : [" << i << "][" << j << "]";
                isFind =true;
                break;
            }
        }
    }

    if(isFind == false) std :: cout << "\nkey " << key << "not found!";
}

//^ max row sum
void maxRow(int mat[][4], int rows, int columns) {
    int maxRowSum = INT_MIN;
    for(int i=0; i<rows; i++) {
        int rowSum = 0;
        for(int j=0; j<columns; j++) {
            rowSum += mat[i][j];
        }
        maxRowSum = std :: max(maxRowSum, rowSum);
    }
    std :: cout << "\nmax row sum is : " << maxRowSum;
}

//^ max diagonal sum
void maxDiag(int mat[][4], int rows) {
    int maxDiagSum1 = 0;
    for(int i=0; i<rows; i++) {
        maxDiagSum1 += mat[i][i];
    }
    
    int maxDiagSum2 = 0;
    for(int j=0; j<rows; j++) {
        maxDiagSum2 += mat[j][rows-j-1];
    }

    int maxDiagSum = std :: max(maxDiagSum1, maxDiagSum2);
    std :: cout << "maximum diagonal sum is :   " << maxDiagSum;
}

//~ range fuction for checking
void searchInRow(int mat[][4], int tar, int row,int column, bool &isFind) {
    int st = 0, end = column-1;

    while(st <= end) {
        int mid = st + (end-st) / 2;

        if(tar == mat[row][mid]) {
            isFind = true;
            std :: cout << "target found at :   [" << row << "][" << mid << "]";
            return;
        }

        else if(tar >= mat[row][mid]) {
            st = mid+1;
        }

        else {
            end = mid-1;
        }
    }
}

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

int main() {

    int rows, columns;
    std :: cout << "enter number of rows :  ";
    std :: cin >> rows;
    std :: cout << "enter number of columns :   ";
    std :: cin >> columns; 
    
    // int mat[rows][4];

    std :: vector<std :: vector<int>> matrix(rows, std :: vector<int>(columns));

    //* input matrix
    for(int i=0; i<rows; i++) {
        if(i==0) {
            std :: cout << "enter " << columns << " values for " << i+1 << "st row :   ";
        }
        else if(i==1) {
            std :: cout << "enter " << columns << " values for " << i+1 << "nd row :   ";
        }
        else if(i==2) {
            std :: cout << "enter " << columns << " values for " << i+1 << "rd row :   ";
        }
        else {
            std :: cout << "enter " << columns << " values for " << i+1 << "th row :   ";
        }

        for(int j=0; j<columns; j++) {
            std :: cin >> matrix[i][j];
        }
    }

    // binarySearch(matrix, rows, columns);

    //* 2D Vector
    // std :: vector<std :: vector<int>> matrix = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};
    //& size
    int r = matrix.size();
    int c = matrix[0].size();

    //* print matrix
    std :: cout << "\n\n2D Array :\n";
    for(int i=0; i<r; i++) {
        std :: cout << std :: endl;
        for(int j=0; j< c; j++) {
            std :: cout << matrix[i][j] << " ";
        }
    }

    std :: cout << "\n\n";

    spiral(matrix);

    return 0;
}