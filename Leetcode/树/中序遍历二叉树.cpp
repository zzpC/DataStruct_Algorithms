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
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> vec;
		if(root){
			inorderCore(root,vec);
		}
		return vec;	
	}
	void inorderCore(TreeNode* root,vector<int>& vec){
		if(root->left){
			inorderCore(root->left,vec);
		}
		vec.push_back(root->val);
		if(root->right){
			inorderCore(root->right,vec);
		}
	}
};

int main(){
	TreeNode  tn(1);
	Solution s;
	s.inorderTraversal(&tn);
	return 0;
}
