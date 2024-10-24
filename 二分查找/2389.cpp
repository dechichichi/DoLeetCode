class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int>ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=1;i<n;i++)nums[i]+=nums[i-1];
        for(auto &i:queries){
            int l=0,r=n-1;
            while(l<=r){
                int mid=l+(r-l)/2;
                if(nums[mid]<=i)l=mid+1;
                else r=mid-1;
            }
            ans.push_back(l);
        }
        return ans;
    }
};
