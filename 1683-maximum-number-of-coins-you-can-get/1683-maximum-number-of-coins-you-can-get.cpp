class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int start=0;
        int end=piles.size()-1;
        int count=0;
        while(start<end){
            count+=piles[end-1];
            start++;
            end=end-2;
        }
        return count;
    }
};