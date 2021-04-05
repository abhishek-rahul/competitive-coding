class Solution {
public:
    int dx[4] = { 1 , -1 ,0 , 0};
    int dy[4] = { 0 , 0 , 1 , -1};
    void dfs(int r, int c, int n, int m,bool visited[105][105],vector<vector<int>>& grid,int& flag)
    {
        int tempr , tempc ;
        if(r>=0 && r<n && c>=0 && c<m && grid[r][c]==0)
        {
            if(r == 0 || r==n-1 || c==0 || c==m-1)
                flag = 1;
            visited[r][c]=true;
            for(int i=0;i<4;i++)
            {
                tempr = r + dx[i];
                tempc = c + dy[i];
                if(tempr>=0 && tempr<n && tempc>=0 && tempc<m && grid[tempr][tempc]==0 && visited[tempr][tempc]==false)
                    dfs(tempr,tempc,n,m,visited,grid,flag);
            }
      } 
    }
    int closedIsland(vector<vector<int>>& grid) {
       bool visited[105][105];
       for(int i=0;i<=100;i++)
       {
           for(int j=0;j<=100;j++)
           {
               visited[i][j]=false;
           }
        }
        int n,m;
        n = grid.size();
        m = grid[0].size();
        
        int ans = 0,flag;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0 && visited[i][j]==false)
                {
                    flag = 0;
                    dfs(i,j,n,m,visited,grid,flag);
                    if(flag==0)
                        ans++;
                }
            }
        }
       return ans; 
      
    }
};
