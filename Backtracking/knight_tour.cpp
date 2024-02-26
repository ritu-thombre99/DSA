#include <bits/stdc++.h>
using namespace std;

void print_tour(vector<vector<int>> sol)
{
    cout<<endl;
    int n = sol.size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<sol[i][j]<<" ";
        cout<<endl;
    }
}
bool util(int x,int y,int move, vector<vector<int>> &sol, vector<int> r, vector<int> c, int n)
{
    if(move == n*n)
        return true;
    for(int i=0;i<8;i++)
    {
        int row = x + r[i];
        int col = y + c[i];
        if(row<n && col<n && row>=0 && col>=0 && sol[row][col] == -1)
        {
            sol[row][col] = move;
            if(util(row,col,move+1,sol,r,c,n) == true)
                return true;
            sol[row][col] = -1;
        }
    }
    return false;
}
void find_sol(vector<vector<int>> &sol, int n)
{
    vector<int> r{ 2, 1, -1, -2, -2, -1, 1, 2 };
    vector<int> c{ 1, 2, 2, 1, -1, -2, -2, -1 };
    sol[0][0] = 0;
    if(util(0,0,1,sol,r,c,n) == true)
        print_tour(sol);
    else
        cout<<"\nNo solution\n";
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> sol;
    for(int i=0;i<n;i++)
    {
        vector<int> temp;
        for(int j=0;j<n;j++)
            temp.push_back(-1);
        sol.push_back(temp);
    }
    find_sol(sol,n);
    return 0;
}