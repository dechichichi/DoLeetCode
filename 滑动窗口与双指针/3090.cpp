class Solution {
public:
    int maximumLengthSubstring(string s) {
        int a[26]={0};
        int l=0,r=0;
        int ans=0;
        while(r<s.size()){
            a[s[r]-'a']++;
            if(a[s[r]-'a']<=2)r++;
            else {
                ans=max(ans,r-l);
                while(a[s[r]-'a']>2){
                    a[s[l]-'a']--;
                    l++;
                }
                r++;
            }
        }
        ans=max(r-l,ans);
        return ans;
    }
};
