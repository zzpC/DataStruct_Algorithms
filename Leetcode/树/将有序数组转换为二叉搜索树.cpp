#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums){
		if(nums.empty()){
			return nullptr;
		}
		TreeNode* root=new TreeNode(0);
		subArrayToBST(0,nums.size()-1,root,nums);
		return root;

	}

	void subArrayToBST(int start,int end,TreeNode* root,vector<int>& nums){
		int index=(start+end)/2;
		root->val=nums[index];
		if(start==end){
			return;
		}
		if(index!=start){
			root->left=new TreeNode{0};
			subArrayToBST(start,index-1,root->left,nums);
		}
		if(index!=end){
			root->right=new TreeNode(0);
			subArrayToBST(index+1,end,root->right,nums);
		}	
		
	}
	void print(TreeNode* node){
		cout << "开始执行二叉搜索树的先序遍历: ";
		printCore(node);
		cout << endl;
	}
	void printCore(TreeNode* node){
		if(node){
			printCore(node->left);
			cout << node->val << " ";
			printCore(node->right);
		}
	
	}

};
int main(){
	Solution s;
	vector<int> vec={};
	vector<int> vec1={-10,-3,0,5,7};
	vector<int> vec2={-3,6};
	vector<int> vec3={9};
	s.print(s.sortedArrayToBST(vec));
	s.print(s.sortedArrayToBST(vec1));
	s.print(s.sortedArrayToBST(vec2));
	s.print(s.sortedArrayToBST(vec3));
	return 0;
}

