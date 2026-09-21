class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        double mx=sum/(double)k;
        int low=0, high=k-1;
        while(high<nums.size()){
            mx=max(mx,sum/(double)k);
            low++;
            high++;
            sum-=nums[low-1];
            if(high==nums.size()){
                break;
        }
        sum+=nums[high];
    }
    return mx;
    }
};