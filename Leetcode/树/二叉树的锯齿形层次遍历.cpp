#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x),left(0),right(0) {}
};

class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root){
            return res;
        }
		stack<TreeNode*> A;
		stack <TreeNode*> B;
		A.push(root);
		vector<int> vec;
		while(!A.empty() || !B.empty()) {		
            if(!A.empty()){
                while(!A.empty()){
                    TreeNode* pnode=A.top();
                    A.pop();
                    if(pnode->left){
                        B.push(pnode->left);
                    }
                    if(pnode->right){
                        B.push(pnode->right);
                    }
                    vec.push_back(pnode->val);
				}
				if(!vec.empty()){
					res.push_back(vec);
				}
				vec.clear();               
            }else{
                while(!B.empty()){
				    TreeNode* pnode=B.top();
				    B.pop();
				    if(pnode->right){
					    A.push(pnode->right);
				    }
				    if(pnode->left){
                        A.push(pnode->left);
				    }
                    vec.push_back(pnode->val);
				}
				if(!vec.empty()){
					res.push_back(vec);
				}
				vec.clear();                
            }	
		}
		return res;
	}
};

int main(){
	Solution s;
	TreeNode tn(1);
	s.zigzagLevelOrder(&tn);
	return 0;
}
