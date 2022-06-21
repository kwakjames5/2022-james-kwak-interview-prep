class Solution {
public:
    int maximumTop(vector<int>& A, int k) {
        int N = A.size();
        if (k == 0) return N >= 1 ? A[0] : -1; 
        if (k == 1) return N == 1 ? -1 : A[1];
        if (N == 1) return k % 2 == 0 ? A[0] : -1; 
        int mx = *max_element(begin(A), begin(A) + min(k - 1, N)); 
        if (k < N) mx = max(mx, A[k]); 
        return mx;
    }
};