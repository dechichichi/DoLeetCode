class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int l=0,r=k-1;
        vector<int> ans;
        int tmp=0;
        while(l<k-1){
        ans.push_back(-1);
        tmp+=nums[l];
        l++;
        }
        while(r<2*k){
            tmp+=nums[r];
            r++;
        }
        ans.push_back(tmp);
        for(int i=k;i<nums.size()-k;i++){
            tmp-=nums[i-k];
            tmp+=nums[i+k-1];
            nums.push_back(tmp);
        }
        for(int i=0;i<k-1;i++)nums.push_back(-1);
        for(auto &i:nums){
            if(i!=-1)i=i/k;
        }
        return ans;
    }
};
