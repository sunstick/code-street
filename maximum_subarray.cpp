class Solution {
public:
    int maxSubArray(int A[], int n) {
        int sum = 0;
        int maxsum = 0;
        
        int maxelem = INT_MIN;
        
        for(int i = 0; i < n; i++) {
            if(sum < 0) sum = 0;
            
            sum += A[i];
            maxsum = max(maxsum, sum);
            maxelem = max(maxelem, A[i]);
        }
        
        if(maxelem < 0)
            return maxelem;
        
        return maxsum;
    }
};