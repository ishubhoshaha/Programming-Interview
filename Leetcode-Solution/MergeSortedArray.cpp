class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m+n-1,k;
        k = i;
        m--;
        n--;
        while(m>=0 and n>=0){
            if (nums1[m]>nums2[n]){
                nums1[i] = nums1[m];
                m--;
            }
            else if (nums1[m]<nums2[n]){
                nums1[i] = nums2[n];
                n--;
            }
            else{
                nums1[i--] = nums2[n];
                nums1[i] = nums2[n];
                m--;
                n--;
            }
            i--;
        }
        while(n>=0){
            nums1[i--] = nums2[n--];
        }
    }
};
