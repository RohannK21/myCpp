class Solution {
public:
    bool isvalid(vector<int> nums,int n, int k,int mid){
        int s=1; int pages=0;
        for(int i=0;i<n;i++){
            if(nums[i]>mid) return false;
            if(pages+nums[i]<=mid){
                pages+=nums[i];
            }else{
                s++;
                pages=nums[i];
            }
        }
        if(s>k) return false;
        else return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        if(k>n) return -1;
        int sums=0;
        for( int i:nums)sums+=i;
        int l=0;int r=sums;
        int ans=-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(isvalid(nums,n,k,m)){
                ans=m;
                r=m-1;
            }else{
                l=m+1;
            }
        }
        return ans;
    }
};