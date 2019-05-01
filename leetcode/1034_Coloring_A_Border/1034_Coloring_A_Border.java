class Solution {
    public void dfs(int[][] grid, int i, int j, boolean[][] marked, boolean[][] visited) {
        visited[i][j] = true;
        int count = 0;
        if (i + 1 >= 0 && i + 1 < grid.length && grid[i + 1][j] == grid[i][j]) {
            count++;
            if (!visited[i + 1][j]) dfs(grid, i + 1, j, marked, visited);
        }
        if (i - 1 >= 0 && i - 1 < grid.length && grid[i - 1][j] == grid[i][j]) {
            count++;
            if (!visited[i - 1][j]) dfs(grid, i - 1, j, marked, visited);
        }
        if (j + 1 >= 0 && j + 1 < grid[0].length && grid[i][j + 1] == grid[i][j]) {
            count++;
            if (!visited[i][j + 1]) dfs(grid, i, j + 1, marked, visited);
        }
        if (j - 1 >= 0 && j - 1 < grid[0].length && grid[i][j - 1] == grid[i][j]) {
            count++;
            if (!visited[i][j - 1]) dfs(grid, i, j - 1, marked, visited);
        }
        if (count < 4) marked[i][j] = true; 
    }
    
    public int[][] colorBorder(int[][] grid, int r0, int c0, int color) {
        boolean[][] marked = new boolean[grid.length][grid[0].length];
        boolean[][] visited = new boolean[grid.length][grid[0].length];
        dfs(grid, r0, c0, marked, visited);
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if (marked[i][j]) grid[i][j] = color;
            }
        }
        return grid;
    }
}
