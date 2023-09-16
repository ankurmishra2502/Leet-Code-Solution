class Solution {
public:
    
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int x= abs(sx-fx);
        int y= abs(sy-fy);
        if(sx==fx && sy==fy) return t!=1;
        int k= max(x,y);
        if(k<=t) return true;
        return false;    
        }
    
};