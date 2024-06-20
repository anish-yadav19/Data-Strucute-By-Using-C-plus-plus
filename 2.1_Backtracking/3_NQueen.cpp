#include<bits/stdc++.h>
using namespace std;


void printSolution(vector<vector<char>>&board,int n)
{
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            cout<<board[i][j]<<" ";
            
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}

bool isSafe(int row,int col,vector<vector<char>>&board,int n)
{
    // check karna chahte ha , ki kya main current cell [row,col] pr queen rakh saktha hu ya nahi

    int i = row;
    int j = col;
    
    //check row
    while(j>=0)
    {
        if(board[i][j] == 'Q')
        {
            return false;
        }
        j--;
    }

    //check upper left diagonal

    i = row;
    j = col;
    while(i>=0 && j>=0)
    {
        if(board[i][j] == 'Q')
        {
            return false;
        }
        i--;
        j--;
    }

    // check bottom left diagonal
    i = row;
    j = col;
    while(i<n && j>=0)
    {
        if(board[i][j] == 'Q')
        {
            return false;

        }
        i++;
        j--;
    }

    // kahin pr bhi queen nhi mili , iska mtlab h ki ye position safe hai then return true;
    return true;

}
void solve(vector<vector<char>>&board,int col,int n)
{
    //base case
    if(col>=n)
    {
        printSolution(board,n);
    }

    // 1 casesolve krna h , baaki rec solve kr lega
    for(int row = 0;row<n;row++)
    {
        if(isSafe(row,col,board,n))
        {
            // rakh do
            board[row][col] = 'Q';
            //recursion solution laega
            solve(board,col+1,n);

            //backtracking
            board[row][col] = '-';
        }
    }
}
int main()
{
    int n = 4;
    vector<vector<char>>board(n,vector<char>(n,'-'));
    int col = 0;
    // 0 -> empty cell
    // 1 -> queen at the cell
    solve(board,col,n);

    return 0;

}