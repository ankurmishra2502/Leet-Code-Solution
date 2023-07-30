class Solution {
public:
    int newRow[4]={-1, 0, 1, 0};
    int newCol[4]={0, 1, 0, -1};
    bool solve(vector<vector<char>>& board,int row,int col,string word,string &temp,vector<vector<int>> &vis,int ind){
        if(ind==word.size()) return true;
        
        for(int j=0;j<4;j++){
            int nR= row+newRow[j];
            int nC= col+newCol[j];
           if(nR>=0 && nR< board.size() && nC>=0 && nC<board[0].size() && !vis[nR][nC] && board[nR][nC]== word[ind]){
               temp+=board[nR][nC];
               vis[nR][nC]=1;
               if(solve(board,nR,nC,word,temp,vis,ind+1)) return true;
               vis[nR][nC]=0;
               temp.pop_back();
           }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    vector<vector<int>> vis(board.size(), vector<int> (board[0].size()));
                    vis[i][j] = 1;
                    string temp=to_string(word[0]);
                    if(solve(board,i,j,word,temp,vis,1)){
                        return true;
                        break;
                    }
                }
            }
        }
        return false;
    }
};