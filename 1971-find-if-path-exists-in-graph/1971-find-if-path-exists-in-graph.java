import java.util.*;

class Solution {
    public boolean validPath(int n, int[][] edges, int source, int destination) {
        
        List<List<Integer>> adj = new ArrayList<>();
        
        for(int i = 0; i < n; i++){
            adj.add(new ArrayList<>());
        }
        
        for(int[] e : edges){
            adj.get(e[0]).add(e[1]);
            adj.get(e[1]).add(e[0]);
        }
        
        boolean[] visited = new boolean[n];
        
        return dfs(adj, visited, source, destination);
    }
    
    private boolean dfs(List<List<Integer>> adj, boolean[] visited, int src, int dest){
        
        if(src == dest) return true;
        
        visited[src] = true;
        
        for(int nei : adj.get(src)){
            if(!visited[nei]){
                if(dfs(adj, visited, nei, dest)) return true;
            }
        }
        
        return false;
    }
}
