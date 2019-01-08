class Solution {
public:
    int minMoves2(vector<int>& nums) {
        auto cmpMax = [](int a, int b) {return a < b;};
        auto cmpMin = [](int a, int b) {return a > b;};
        priority_queue<int, std::vector<int>, decltype(cmpMin)> minHeap(cmpMin);
        priority_queue<int, std::vector<int>, decltype(cmpMax)> maxHeap(cmpMax);
        for (int i = 0; i < nums.size(); i++) {
            maxHeap.push(nums[i]);
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            if (maxHeap.size() < minHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }
        int median = maxHeap.top();
        int count = 0;
        for (int n : nums) {
            count += abs(n - median);
        }
        
        return count;
    }
};
