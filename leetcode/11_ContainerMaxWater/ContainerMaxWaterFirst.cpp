class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0;
        int r=height.size()-1;
        int m=0;
        while(l<r){
            m=max((r-l)*min(height[l],height[r]),m);
            if(height[l]>height[r]){
                r--;
            }
            else if(height[l]<height[r]){
                l++;
            }
            else{
                r--;
                l++;
            }
        }
        return m;
    }
};