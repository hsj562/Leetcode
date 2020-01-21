class Solution {
public:
    void trans(int *num, string *ret, int bound, string str) {
        if(*num >= bound) {
            *num -= bound;
            *ret += str;
        }
    }
    string intToRoman(int num) {
        const int M = 1000, D = 500, C = 100, L = 50, X = 10, V = 5, I = 1;
        int no = num / M;
        num %= M;
        string ret(no, 'M');
        trans(&num, &ret, 900, "CM");
        
        no = num / D;
        num %= D;
        ret += string(no, 'D');
        trans(&num, &ret, 400, "CD");
        
        no = num / C;
        num %= C;
        ret += string(no, 'C');
        trans(&num, &ret, 90, "XC");
        
        no = num / L;
        num %= L;
        ret += string(no, 'L');
        trans(&num, &ret, 40, "XL");

        no = num / X;
        num %= X;
        ret += string(no, 'X');
        trans(&num, &ret, 9, "IX");

        no = num / V;
        num %= V;
        ret += string(no, 'V');
        trans(&num, &ret, 4, "IV");

        no = num;
        ret += string(no, 'I');
        return ret;
    }
};