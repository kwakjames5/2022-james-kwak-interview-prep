class Solution {
public:
    int fib(int N) {
        if(N == 0 || N == 1)
        {
            return N;
        }
        
        int a = 0;
        int b = 1;
        int fib = 0;
        
        for(int i = 2; i <= N; i++)
        {
            fib = a + b;
            a = b;
            b = fib;
        }
        
        return fib;
    }
};