class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sand) {
        
       stack<int> st;
       queue<int> q;
       for(auto x:students){
           q.push(x);
       } 
       reverse(sand.begin(),sand.end());
       for(auto x:sand){
           st.push(x);
       }
       int count =students.size()*3;
           while(count>=0 && !q.empty() && !st.empty()){
               if(q.front()==st.top()){
                   q.pop();
                   st.pop();
                   
               }
               else {
                   auto x= q.front();
                   q.pop();
                   q.push(x);
                   count--;
               }
               
           }
       return st.size();
    }
};