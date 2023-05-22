class Solution {
public:
    int pivotIndex(vector<int>& nums) {
    vector<int> left;
    int lastIndex = nums.size()-1;
    int sum = 0;
    
    for(int i=lastIndex ; i>=0 ; --i)
    {
        left.push_back(sum);
        sum += nums[i];
    }
    reverse(left.begin(),left.end());
    sum = 0;
    for(int i=0; i<=lastIndex; ++i)
    {
        if(left[i] == sum)
            return i;
        sum += nums[i];
    }

    return -1;
    }
};