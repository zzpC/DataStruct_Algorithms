#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    if(dfs(board,i,j,word,0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, int i,int j,string word,int n){
        if(word.size()==n){
            return true;
        }
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]!=word[n] ){
            return false;
        }
        board[i][j]='#';
        bool res=dfs(board,i-1,j,word,n+1)  || dfs(board,i+1,j,word,n+1) || dfs(board,i,j-1,word,n+1) || dfs(board,i,j+1,word,n+1);           
        board[i][j]=word[n];
        return res;
    }
};
int main() {
	Solution s;
	vector<vector<char>> vec={
		{'A','B','C','E'},
		{'S','F','C','S'},
		{'A','D','E','E'}
	};
	string board="ABCCED";
	cout << s.exist(vec,board) << endl;
	
	
}
