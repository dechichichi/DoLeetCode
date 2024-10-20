class Solution {
public:
    bool isPalindrome(int x) {
    if(x<0)return false;
    long ans=0;
    long tag=x;
    while(x){
        ans=ans*10+x%10;
        x/=10;
    }    
    if(ans==tag)return true;
    else return false;
    }
};
