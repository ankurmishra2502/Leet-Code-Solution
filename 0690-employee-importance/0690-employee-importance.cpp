/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        map<int,Employee*>mp;
				int i=0;
				for(auto x:employees){
					mp[x->id]=x;
					i++;
				}
				int ans=0;
				queue<int> q;
				ans = mp[id]->importance;
				vector<int>temp= mp[id]->subordinates;
				if(temp.size()==0) return ans;
				for(auto x:temp) q.push(x);
				while(!q.empty()){
					int val=q.front();
					q.pop();
					ans+=mp[val]->importance;
					vector<int>temp= mp[val]->subordinates;
					for(auto x:temp) q.push(x);
				}
				return ans;
    }
};