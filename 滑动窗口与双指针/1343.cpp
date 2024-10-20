class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum=k*threshold;
        int tmp=0;
        int ans=0;
        int l=0;
        while(l<k){
            tmp+=arr[l];
            l++;
        }
        ans+=(tmp>=sum)?1:0;
        while(l<arr.size()){
            tmp-=arr[l-k];
            tmp+=arr[l];
            ans+=(tmp>=sum)?1:0;
            l++;
        }
        return ans;
    }
};
