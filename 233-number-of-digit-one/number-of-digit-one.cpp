class Solution
{
public:
    int countDigitOne(int n)
    {
        int count = 0;
        long long one = 1;

        while (one <= n)
        {
            int lowerNumbers = n - (n / one) * one;
            int currentDigit = (n / one) % 10;
            int higherNumbers = n / (one * 10);

            if (currentDigit == 0)
            {
                count = count + higherNumbers * one;
            }
            else if (currentDigit == 1)
            {
                count = count + higherNumbers * one + lowerNumbers + 1;
            }
            else
            {
                count = count + (higherNumbers + 1) * one;
            }

            one *= 10;
        }

        return count;
    }
};