#include<bits/stdc++.h>
using namespace std;
bool isSafe(int x, int y, int row, int col, int arr[][3],vector<vector<bool>>&visited)
{
    if( ((x>=0 && x<row) && (y>=0 && y<col)) && (arr[x][y] == 1)&& (visited[x][y] == false))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void solveMaze(int arr[3][3], int row,int col, int srcx, int srcy,vector<vector<bool>>&visited,vector<string>&path,string output)
{
    //base case
    if(srcx == row-1 && srcy == col-1)
    {
        //answer found
        path.push_back(output);
        return;
    }

    //Down -> i+1,j
    if(isSafe(srcx+1,srcy,row,col,arr,visited))
    {
        visited[srcx+1][srcy] = true;
        solveMaze(arr,row,col,srcx+1,srcy,visited,path,output+'D');

        visited[srcx+1][srcy] = false;
    }

    // Left -> i,j-1
    if(isSafe(srcx,srcy-1,row,col,arr,visited))
    {
        visited[srcx][srcy-1] = true;
        solveMaze(arr,row,col,srcx,srcy-1,visited,path,output+'L');

        visited[srcx][srcy-1] = false;
    }

    // Right -> i, j+1
    if(isSafe(srcx,srcy+1,row,col,arr,visited))
    {
        visited[srcx][srcy+1] = true;
        solveMaze(arr,row,col,srcx,srcy+1,visited,path,output+'R');

        visited[srcx][srcy+1] = false;
    }

    //Up -> i-1,j
    if(isSafe(srcx-1,srcy,row,col,arr,visited))
    {
        visited[srcx-1][srcy] = true;
        solveMaze(arr,row,col,srcx-1,srcy,visited,path,output+'U');

        visited[srcx-1][srcy] = false;
    }
}

int main()
{
    int maze[3][3] = {{1,0,0},
                      {1,1,0},
                      {1,1,0}};
    
    if(maze[0][0] == 0) 
    {
        cout<<"No path exist "<<endl;
        return 0;
    }

    int row = 3;
    int col = 3;
    vector<vector<bool>>visited(row,vector<bool>(col,false));

    //src ke value ko true mark kr dete h
    visited[0][0] = true;

    vector<string>path;
    string output = "";
    solveMaze(maze,row,col,0,0,visited,path,output);

    cout<<"Printing output: "<<endl;
    for(auto i : path)
    {
        cout<<i<<" ";
    }
    

    if(path.size() == 0)
    {
        cout<<"No path exists "<<endl;
    }

    return 0;
}