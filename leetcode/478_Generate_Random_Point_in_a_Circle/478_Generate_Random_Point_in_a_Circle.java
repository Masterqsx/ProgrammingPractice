class Solution {
    private double radius;
    private double x_center;
    private double y_center;
    public Solution(double radius, double x_center, double y_center) {
        this.radius = radius;
        this.x_center = x_center;
        this.y_center = y_center;
    }
    
    public double[] randPoint() {
        double randRadius = radius * Math.sqrt(Math.random());
        double randRadian = Math.toRadians(360 * Math.random());
        double[] res = new double[2];
        res[0] = randRadius * Math.cos(randRadian) + x_center;
        res[1] = randRadius * Math.sin(randRadian) + y_center;
        
        return res;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(radius, x_center, y_center);
 * double[] param_1 = obj.randPoint();
 */
