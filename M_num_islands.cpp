class Solution {
    void dfs(vector<vector<char>>& grid, int i, int j)
    {
        int r=grid.size(), c=grid[0].size();
        
        // CHECK GRID LAST BECAUSE YOU NEED TO CHECK THE I AND J FIRST AND SEE IF IT IS A LEGAL POSITION
        // IF IT ISN'T THE GRID[I][J] WILL ERROR
        if(i<0 || i>r-1 || j<0 || j>c-1 || (grid[i][j] -'0') != 1)
        {
            return;
        }
        
        grid[i][j] = 'checked'; // marking visited
        
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
    }
    
    public:
    int numIslands(vector<vector<char>>& grid) {
        int num_islands = 0;
        int r=grid.size(), c=grid[0].size();
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if((grid[i][j] - '0')==1)
                {
                    dfs(grid, i, j);
                    num_islands++;
                }
            }
        }
        
        return num_islands;
    }
};

