
//Accepted	16 ms	cpp
class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if(target <= A[0]) return 0;
        else if(target > A[n-1]) return n;

        int right = 0,left = n;
        int mid;
        while(right < left)
        {
            mid = ((left-right)>>1) + right;
            if(target > A[mid]) right = mid;
            else if(target < A[mid]) left = mid;

            if((target<=A[mid] && target>A[mid-1])) return mid;
        }
        return -1;
    }
};
