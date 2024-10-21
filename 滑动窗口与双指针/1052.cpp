class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int bad=0;
        int good=0;
        int ans=0;
        int n=customers.size();
        for(int i=0;i<n;i++){
        if(!grumpy[i]){
            ans+=customers[i];
            customers[i]=0;
            }
        }
        bad=reduce(customers.begin(),customers.begin()+minutes);
        good=bad;
        for(int en=minutes;en<customers.size();en++){
            bad+=customers[en]-customers[en-minutes];
            good=max(good,bad);
        }
        return ans+good;
        
    }
};
