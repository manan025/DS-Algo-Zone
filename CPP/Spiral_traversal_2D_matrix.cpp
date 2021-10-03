//Given an m x n matrix, return all elements of the matrix in spiral result.

/*Algorithm:

    i) First we will iterate in to first row from left to right push back all the elements into a vector. After iterating, we change the top to second row (top++).
    ii) Then we will iterate from new top to bottom and push back only right most elements of each row. After iterating, we change the right to second last column (right--).
    iii) Then we will iterate in bottom row from right to left and pushback all the elements from new right to left. After iterating, we change the bottom to second last row (bottom--).
    iv) Then we will iterate from new bottom to new top and push back only left most element. After iterating, we change the left to second column (left++).
    v) Repeat all these steps until left = right and top = bottom.

*/

#include <bits/stdc++.h>
using namespace std;

vector<int> spiralresult(vector<vector<int>> matrix)
{
    int n = matrix.size(); // size of row
    int m = matrix[0].size(); //size of column

    int left = 0, right = m - 1, bottom = n - 1, top = 0; 

    int direction = 1; //four direction ->  right to left(1) , top to bottom(2) , left to right(3) , bottom to top(4)

    vector<int> res; // to store the resultant vector

    while (left <= right && top <= bottom)
    {
        if (direction == 1) 
        {
            for (int i = left; i <= right; i++) //traversing left to right
                res.push_back(matrix[top][i]);
            direction = 2;
            top++; // removing the top row after traversing it

        }

        else if (direction == 2) //traversing top to bottom
        {
            for (int i = top; i <= bottom; i++)
                res.push_back(matrix[i][right]);
            direction = 3;
            right--; // removing the right-most column after traversing it
        }

        else if (direction == 3) // traversing right to left
        {
            for (int i = right; i >= left; i--)
                res.push_back(matrix[bottom][i]);
            direction = 4;
            bottom--; // removing the bottom-most row after traversing it
        }

        else if (direction == 4)  //traversing bottom to top
        {
            for (int i = bottom; i >= top; i--)
                res.push_back(matrix[i][left]);
            direction = 1;
            left++; // removing the leftmost column after traversing it
        }
    }
    return res;
}

int main()
{
    int n, m;
    cout << "Enter Number of rows: ";
    cin >> n;
    cout << "\n Enter Number of Columns: ";
    cin >> m;

    //A vector of vector<int> to store the a 2D matrix where each vector represents a row
    vector<vector<int>> v;
    int a;

    //taking input
    cout << "\n Enter elements of 2D matrix row-wise :";
    for (int i = 0; i < n; i++)
    {
        vector<int> row;
        for (int j = 0; j < m; j++)
        {
            cin >> a;
            row.push_back(a);
        }
        v.push_back(row);
    }

    //vector to hold the spiral-traversal Array
    vector<int> res;
    res = spiralresult(v);

    //printing the output
    cout << "\n";

    for (auto i : res)
    {
        cout << i << " ";
    }
}

/*

sample input output:

input:

4 4
1  2  3  4
5  6  7  8
9  10 11 12
13 14 15 16

Output:
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10

Input 2:
3 4
1 2 3 4
5 6 7 8
9 10 11 12

Output 2:
1 2 3 4 8 12 11 10 9 5 6 7

Time Complexity: O(n*m)
Space Complexity: O(n*m)






*/
