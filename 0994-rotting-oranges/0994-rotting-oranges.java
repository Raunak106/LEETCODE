import java.util.*;

class Solution {
    public int orangesRotting(int[][] grid) {

        int m = grid.length;
        int n = grid[0].length;

        Queue<int[]> q = new LinkedList<>();
        int fresh = 0;
        int time = 0;

        // Step 1: Add rotten oranges to queue
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.add(new int[]{i, j});
                }
                if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        int[] delRow = {-1, 0, 1, 0};
        int[] delCol = {0, 1, 0, -1};

        // Step 2: BFS
        while(!q.isEmpty() && fresh > 0){

            int size = q.size();
            time++;

            for(int k = 0; k < size; k++){

                int[] cell = q.poll();
                int r = cell[0];
                int c = cell[1];

                for(int i = 0; i < 4; i++){

                    int nr = r + delRow[i];
                    int nc = c + delCol[i];

                    if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        fresh--;
                        q.add(new int[]{nr, nc});
                    }
                }
            }
        }

        return fresh == 0 ? time : -1;
    }
}
