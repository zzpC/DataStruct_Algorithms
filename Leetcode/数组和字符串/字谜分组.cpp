// 20180903
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map<long, vector<string>> m;
        for (string str : strs) {
            vector<int> cnt(26, 0);
            long t = 0;
            int fac=1;
            for (char c : str) ++cnt[c - 'a'];
            for(int i=0;i<cnt.size();i++){
                long temp=cnt[i]*fac;
                t=t+temp;
                fac*=26;
            }
            
            m[t].push_back(str);
        }
        for (auto a : m) {
            res.push_back(a.second);
        }
        return res;
    }
};

// 原始版本
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map<string, vector<string>> m;
        for (string str : strs) {
            vector<int> cnt(26, 0);
            string t = "";
            for (char c : str) ++cnt[c - 'a'];
            for (int d : cnt) t += to_string(d) + "/";
            m[t].push_back(str);
        }
        for (auto a : m) {
            res.push_back(a.second);
        }
        return res;
    }
};