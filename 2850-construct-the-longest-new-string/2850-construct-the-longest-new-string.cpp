class Solution {
public:
    int longestString(int x, int y, int z) {
        int xy= min(x,y);
        int ex=0;
        if(x!=y) ex=1;
        return (xy*2+ex+z)*2;
    }
};