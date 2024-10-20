class Solution {
public:
    int reverse(int x) {
        int tag=x>0?0:1;
        int gg=0;
        if(x==INT_MIN){
            x+=1;
            gg++;
        }
        x=x>0?x:-x;
        int ans=0;
        while(x){
        if(ans>(INT_MAX-x%10)/10)return 0;
            ans=ans*10+x%10;
            x/=10;
        }
        if(tag)ans=-ans;
        return ans-gg;
    }
};
