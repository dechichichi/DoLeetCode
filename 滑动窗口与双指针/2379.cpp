class Solution {
public:
    int minimumRecolors(string blocks, int k) {
      int ans=k;
      int len=0;
      int tmp=0;
      for(;len<k;len++){
        tmp+=blocks[len]=='W'?1:0;
      }
      ans=min(ans,tmp);
      while(len<blocks.size()){
        tmp-=blocks[len-k]=='W'?1:0;
        tmp+=blocks[len]=='W'?1:0;
        len++;
        ans=min(tmp,ans);
      }  
      return ans;
    }
};
