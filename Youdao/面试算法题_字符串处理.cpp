#include <iostream>
#include <string>
using namespace std;
bool isAlphabet(char c){
	if(c >= 'a' && c<='z'){
		return true;
	}
	if(c >='A' && c <= 'Z'){
		return true;
	}
	return false;
}

void print(string s){
	for(auto c : s){
		if(isAlphabet(c)){
			cout << c;
		}else if(c==' '){
			cout << endl;
		}else{
			cout << endl;
			cout << c << endl;
		}
	}
	cout << endl;
}

int main(){
	string s = "I'm a student!";
	string s1 = "Haha, a student!";

	print(s);
	print(s1);

	return 0;
}
