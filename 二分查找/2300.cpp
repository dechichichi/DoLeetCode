class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int n=potions.size();
        vector<int>ans;
        for(auto &i:spells){
            long long tag=success/i;
            if(success%i)tag++;
            int l=0,r=n-1;
            while(l<=r){
                int mid=l+(r-l)/2;
                if(potions[mid]>=tag)r=mid-1;
                else l=mid+1;
            }
            ans.push_back(n-r-1);
        }
        return ans;
    }
};
