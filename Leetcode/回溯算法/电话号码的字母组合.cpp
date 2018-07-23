#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> s1,s2;
        map<char,vector<string>> mp;
        mp['2']={"a","b","c"};
        mp['3']={"d","e","f"};
        mp['4']={"g","h","i"};
        mp['5']={"j","k","l"};
        mp['6']={"m","n","o"};
        mp['7']={"p","q","r","s"};
        mp['8']={"t","u","v"};
        mp['9']={"w","x","y","z"};
        for(auto &ch:digits){
            int size=s1.size();
            auto &v=mp[ch];
            for(auto &s:v){
                for(int i=0;i<size;i++){
                    string tmp=s1[i]+s;
                    s2.push_back(tmp);
                }
                if(size==0) s2.push_back(s);
            }
            swap(s1,s2);
            s2.clear();
        }
        return s1;
    }
};


int main(){

	vector<string> test={
		{""},
			{"2"},
				{"23"},
					{"987"},
						{"29"},
							{"92"}
	};
	Solution sol;
	for(string& s : test){
		vector<string> vec=sol.letterCombinations(s);
		for(string& str : vec){
			cout << str << " ";
		}
		cout << endl;
	}

	return 0;
}
