class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.size()<k)return false;
        map<string,bool> mp;
        for(int i=0;i<=s.size()-k;i++){
            string str=s.substr(i,k);
            mp[str]=true;
        }
        return mp.size()==pow(2,k);
    }
};
