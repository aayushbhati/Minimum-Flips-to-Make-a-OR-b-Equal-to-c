class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count = 0;
        string s1 = "", s2 = "", s3 = "";
        
        while (a != 0) {
            int d = a % 2;
            s1 = char(d + '0') + s1;   
            a /= 2;
        }
        while (b != 0) {
            int d = b % 2;
            s2 = char(d + '0') + s2;   
            b /= 2;
        }
        while (c != 0) {
            int d = c % 2;
            s3 = char(d + '0') + s3;   
            c /= 2;
        }

        int i = s1.size() - 1, j = s2.size() - 1, k = s3.size() - 1;

        while (i >= 0 || j >= 0 || k >= 0) {
            int bitA, bitB, bitC;

            if (i >= 0) bitA = s1[i] - '0';
            else bitA = 0;

            if (j >= 0) bitB = s2[j] - '0';
            else bitB = 0;

            if (k >= 0) bitC = s3[k] - '0';
            else bitC = 0;

            if ((bitA | bitB) != bitC) {
                if (bitC == 1) count++;
                else count += (bitA + bitB);
            }

            i--; j--; k--;
        }
        return count;
    }
};
