class Solution {
    public int numIslands(char[][] grid) {
        int m=grid.length;
        int n=grid[0].length;
        int[][] visited=new int[m][n];
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '1' && visited[i][j] == 0){
                    visited[i][j]=1;
                    count++;
                    dfs(i,j,m,n,grid,visited);

                }


            }        
    }
    return count;
    
}
    public void dfs(int row,int column,int m,int n,char[][]grid,int[][]visited){
        int[] delRow={-1,0,+1,0};
        int[] delColumn={0,1,0,-1};
        visited[row][column]=1;
        for(int i=0;i<4;i++){
            int newRow=row+delRow[i];
            int newColumn=column+delColumn[i];
            if(newRow >= 0 && newRow < m && newColumn >= 0 && newColumn < n && grid[newRow][newColumn] == '1' &&
   visited[newRow][newColumn] == 0) {

                dfs(newRow,newColumn,m,n,grid,visited);
            }
        }
        return;


    }

}
