class Solution {
public:
    int getLength(int n) {
        int count = 0;
        while (n > 0) {
            n /= 10;
            count++;
        }
        return count;
    }

    int countNumbers(vector<string>& digits, string num) {
        int result = 0;
        int index = 0;

        if (num.empty()) return 1;

        while (index < digits.size() && stoi(digits[index]) < (num[0] - '0')) {
            result += pow(digits.size(), num.length() - 1);
            index++;
        }
        if (index < digits.size() && stoi(digits[index]) == (num[0] - '0')) {
            result += countNumbers(digits, num.substr(1));
        }

        return result;
    }

    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        sort(digits.begin(), digits.end());

        int total = 0;
        int numDigits = getLength(n);

        for (int i = 1; i < numDigits; i++) {
            total += pow(digits.size(), i);
        }

        string numStr = "";
        while (n > 0) {
            numStr += to_string(n % 10);
            n /= 10;
        }
        reverse(numStr.begin(), numStr.end());

        total += countNumbers(digits, numStr);

        return total;
    }
};