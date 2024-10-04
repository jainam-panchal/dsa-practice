class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        
        int n = skill.size();
        sort(skill.begin() , skill.end());

        long long ans = skill[0] * skill[n-1];
        int currSkillSum = skill[0] + skill[n-1];
        
        int i=1 , j=n-2;
        while(i < j) {
            if(skill[i] + skill[j] != currSkillSum) return -1;
            ans += skill[i] * skill[j];
            i++; j--;
        }
        
        return ans;
    }
};