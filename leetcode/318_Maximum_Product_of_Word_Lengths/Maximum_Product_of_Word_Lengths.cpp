class Solution {
public:
    int maxProduct(vector<string>& words) {
        if (words.size() < 2) return 0;
        int hash_store[words.size()] = {0};
        for (int i=0;i<words.size();i++){
            for (char c : words[i])
                hash_store[i] |= 1<<(c-'a');
        }
        int result = 0;
        for (int i=0;i<words.size()-1;i++){
            for (int j=i+1;j<words.size();j++){
                if ((hash_store[i] & hash_store[j]) == 0){
                    result = max(result, static_cast<int>(words[i].size() * words[j].size()));
                }
            }
        }
        return result;
    }
};