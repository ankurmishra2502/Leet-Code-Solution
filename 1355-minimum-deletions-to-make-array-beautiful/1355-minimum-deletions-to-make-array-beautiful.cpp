class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int count=0;
        stack<int> st;
        for(auto x:nums){
            if(st.size()%2!=0 && st.top()==x) count++;
            else st.push(x);
        }
        if(st.size()%2==1) count++;
        return count;
    }
};