// 填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。
// 初始状态下，所有 next 指针都被设置为 NULL。
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

// 时间复杂度(N),空间复杂度(N)
// 思路：用2个队列轮流将同一层的节点按从左到右的顺序存起来，从而设置完右向指针。
struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (!root) {
			return;
		}

		queue<TreeLinkNode*> q;
		queue<TreeLinkNode*> q2;
		q.push(root);
		while (!q.empty() || !q2.empty()) {
			if (!q.empty()) {
				TreeLinkNode* lastp = nullptr;
				while (!q.empty()) {
					TreeLinkNode* pt = q.front();
					q.pop();
					if (pt->left) {
						q2.push(pt->left);
					}
					if (pt->right) {
						q2.push(pt->right);
					}
					if (lastp) {
						lastp->next = pt;
					}
					lastp = pt;
				}
			}
			if (!q2.empty()) {
				TreeLinkNode* lastp = nullptr;
				while (!q2.empty()) {
					TreeLinkNode* pt = q2.front();
					q2.pop();

					if (!pt) {
						break;
					}
					if (pt->left) {
						q.push(pt->left);
					}
					if (pt->right) {
						q.push(pt->right);
					}
					if (lastp) {
						lastp->next = pt;
					}
					lastp = pt;

				}
			}
		}
	}
};

int main(){
	Solution s;
	TreeLinkNode n(0);
	s.connect(&n);
	return 0;
}