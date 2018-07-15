#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        for (auto iter = s.rbegin(); iter != s.rend(); ++iter)
            switch (*iter)
            {
                case 'I': res += res >= 5 ? -1 : 1; break;
                case 'V': res += 5; break;
                case 'X': res += 10 * (res >= 50 ? -1 : 1); break;
                case 'L': res += 50; break;
                case 'C': res += 100 * (res >= 500 ? -1 : 1); break;
                case 'D': res += 500; break;
                case 'M': res += 1000; break;
            }
        return res;
    }
};
int main(){
	Solution s;
	cout << s.romanToInt("I") << endl;
	cout << s.romanToInt("IV") << endl;
	cout << s.romanToInt("VI") << endl;
	cout << s.romanToInt("IX") << endl;
	cout << s.romanToInt("XI") << endl;
	cout << s.romanToInt("XL") << endl;
	cout << s.romanToInt("LX") << endl;
	cout << s.romanToInt("CX") << endl;
	cout << s.romanToInt("XC") << endl;
	cout << s.romanToInt("CD") << endl;
	cout << s.romanToInt("DC") << endl;
	cout << s.romanToInt("CM") << endl;
	cout << s.romanToInt("MC") << endl;
	cout << s.romanToInt("IVC") << endl;
	return 0;
}
