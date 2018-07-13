#include <iostream>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
	if(s.empty()){
		return true;
	}    	    
	stack<char> stk;
	for(int i=0;i<s.length();i++){
		switch(s[i]){
			case '(':
			case '[':
			case '{':
				stk.push(s[i]);
				break;
			case ')':if(stk.empty() || stk.top()!='('){
					return false;
				}else{
					stk.pop();
				}
				break;
			case '}':if(stk.empty() || stk.top()!='{'){
					return false;
				}else{
					stk.pop();
				}
				break;
			case ']':
				if(stk.empty() || stk.top()!='['){
					return false;
				}else{
					stk.pop();
				}
				break;
			default:
				return false;
		}	
	}
	return stk.empty()?true:false;
    }
};
