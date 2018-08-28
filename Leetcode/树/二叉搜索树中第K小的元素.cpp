#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int subSize(TreeNode* root) {
		int count = 0;
		if (!root) {
			return count;
		}
		int a = subSize(root->left);
		int b = subSize(root->right);
		count = a+b + 1;
		return count;
	}
	int findLeft(TreeNode* root) {
		if (!root) {
			return 0;
		}
		return subSize(root->left) + 1;
	}

	int kthSmallest(TreeNode* root, int k) {
		TreeNode* pn = root;
		while (pn) {
			if (findLeft(pn) == k) {
				return pn->val;
			}
			else if (findLeft(pn)>k) {
				pn = pn->left;
			}
			else {
                k=k-findLeft(pn);
				pn = pn->right;
			}
		}
		return 0;
	}
};

int main()
{
	Solution s;
	TreeNode n1(4);
	TreeNode n2(2);
	TreeNode n3(5);
	TreeNode n4(1);
	TreeNode n5(3);
	n1.left = &n2;
	n2.left = &n4;
	n1.right = &n3;
	n2.right = &n5;
	cout << s.kthSmallest(&n1, 3) << endl;
	getchar();
	return 0;
}
