// Also called as Boyer-Moore Voting Algorithm

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int i,count=1,index=0;
        
        for(i=0;i<n;i++){
            if(nums[i]==nums[index])  count++;
            else count--;
            
            if(count==0)
            {
                count=1;
                index=i;
            }
        }
        
        return nums[index];
    }
};
