class Solution {
public:
    string invert(string x){
        string Pp=x;
        for(int i=0;i<Pp.size();i++){
            if(Pp[i]=='1') Pp[i]='0';
            else Pp[i]='1';
        }
        reverse(Pp.begin(),Pp.end());
        return Pp;
    }
    char findKthBit(int n, int k) {
        vector<string> dimpy;
        dimpy.push_back("0");
        for(int i=1;i<=n;i++){
            string temp=dimpy[i-1]+"1"+invert(dimpy[i-1]);
            dimpy.push_back(temp);
        }
        string val= dimpy[n-1];
        return val[k-1];
    }
};