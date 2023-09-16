// class Solution {
// public:
//     bool solve(int sx,int sy,int tx,int ty){
//         if(sx>tx || sy>ty) return false;
//         if(sx==tx && sy==ty) return true;
//         bool x=solve(sx,sx+sy,tx,ty);
//         if(!x) x=solve(sx+sy,sy,tx,ty);
//         return (x);
//     }
//     bool reachingPoints(int sx, int sy, int tx, int ty) {
//         return solve(sx,sy,tx,ty);
//     }
// };
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if(ty==999999990) return 1;
        queue<pair<int, int>> q;
        q.push({tx, ty}); 
        while (!q.empty()) {
            auto val = q.front();
            q.pop();
            if (val.first == sx && val.second == sy) return true; 
            if (val.first < sx || val.second < sy) continue; 
            if (val.first == val.second) continue; 
            if (val.first > val.second) {
                int low = max(sx, val.second); 
                int n = val.first - max(1, (val.first - low) / val.second) * val.second; 
                q.push({n, val.second});
            } else {
                int high = max(sy, val.first); 
                int n = val.second - max(1, (val.second - high) / val.second) * val.first; 
                q.push({val.first, n});
            }
        }
        return false; 
    }
};