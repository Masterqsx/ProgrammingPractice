class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0) return;
        int end1=m-1;
        int end2=n-1;
        int end_new=m+n-1;
        while(end_new>=0){
            if((end1>=0)&&(end2>=0)){
                nums1[end_new]=nums1[end1]>nums2[end2]?nums1[end1]:nums2[end2];
                if(nums1[end1]>nums2[end2]){
                    nums1[end_new]=nums1[end1];
                    end1--;
                }
                else{
                    nums1[end_new]=nums2[end2];
                    end2--;
                }
            }
            else if(end1>=0){
                nums1[end_new]=nums1[end1];
                end1--;
            }
            else{
                nums1[end_new]=nums2[end2];
                end2--;
            }
            end_new--;
        }
    }
};