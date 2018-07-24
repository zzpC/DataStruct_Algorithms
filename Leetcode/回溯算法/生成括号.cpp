#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> result;
    vector<string> generateParenthesis(int n) {
        generate(0, 0, "", n);
        return result;
    }
    void generate(int left, int right, string s, int n) {
        if(right == n) {
            result.push_back(s);
        }
        else
        {
            if(left < n)
            {
                generate(left + 1, right, s + "(", n);
            }
            if(right < left)
            {
                generate(left, right + 1, s + ")", n);
            }
        }
    }
};

int main(){
	Solution s;
	for(int i=1;i<5;i++){
		vector<string> test=s.generateParenthesis(i);
		for(string& s : test){
			cout << s << " ";
		}
		cout << endl << endl;
	}
	return 0;
}
