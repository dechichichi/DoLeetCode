class Solution {
public:
    int maxVowels(string s, int k) {
        int c[26];
        c['a'-'a']=1;
        c['e'-'a']=1;
        c['i'-'a']=1;
        c['o'-'a']=1;
        c['u'-'a']=1;
        int tag=0;
        int ans=0;
        int n=0;
         while(n<k){
                if(c[s[n]-'a'])tag++;
                n++;
            }
        ans=max(ans,tag);
        for(int i=n;i<s.size();i++){
         if(c[s[i-n]-'a'])tag--;
         if(c[s[i]-'a'])tag++;
         ans=max(ans,tag);
        }
        return ans;
    }
};
