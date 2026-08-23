class Solution {
public:

    int fun(int n) {
        int sum = 0;

        while(n > 0) {
            int d = n % 10;
            sum += d * d;
            n = n / 10;
        }

        return sum;
    }

    bool isHappy(int n) {

        int slow = n;
        int fast = n;

        do {
            slow = fun(slow);
            fast = fun(fun(fast));

        } while(slow != fast);

        return slow == 1;
    }
};