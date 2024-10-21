class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int tmp=0;
        int ans=0;
        int n=cardPoints.size();
        for(int i=0;i<k;i++){
            tmp+=cardPoints[i];
        }
        ans=tmp;
        for(int i=0;i<k;i++){
            tmp-=cardPoints[k-1-i];
            tmp+=cardPoints[n-1-i];
            ans=max(ans,tmp);
        }
        return ans;
    }
};
