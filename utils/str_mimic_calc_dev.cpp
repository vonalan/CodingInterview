#include <string>
#include <iostream>

using namespace std;


string add_core(string num1, string num2) {
    int M = num1.size(), N = num2.size();
    if (M == 0 || N == 0) {return ""; }
    string res(max(M, N) + 1, '0');

    int pos = 0;
    int sum = 0, carry = 0;
    while (pos < max(M, N)) {
        int lft = 0;
        if (pos < M) {
            lft = num1[M - 1 - pos] - '0';
        }
        int rht = 0;
        if (pos < N) {
            rht = num2[N - 1 - pos] - '0';
        }
        sum = lft + rht + carry;
        res[max(M, N) - pos] = sum % 10 + '0';
        carry = sum / 10;

        ++pos;
    }
    res[0] = carry + '0';

    if (res[0] == '0') {
        return res.substr(1, res.size() - 1);
    }
    return res;
}


string sub_core(string num1, string num2) {
    // num1的长度 >= num2的长度
    int M = num1.size(), N = num2.size();
    if (M == 0 || N == 0) {return ""; }
    string res(M, '0');

    int pos = 0;
    int sum = 0, carry = 0;
    while (pos < M) {
        int lft = 0;
        if (pos < M) {
            lft = num1[M - 1 - pos] - '0';
        }
        int rht = 0;
        if (pos < N) {
            rht = num2[N - 1 - pos] - '0';
        }
        sum = lft - carry - rht;
        res[M - pos - 1] = (sum < 0 ? -sum : sum) + '0';
        carry = (sum < 0 ? -1 : 0);
        
        ++pos;
    }

    if (res[0] == '0') {
        return res.substr(1, res.size() - 1);
    }
    return res;
}


string add(string num1, string num2) {
    string lft_sign = "+";
    if (!num1.empty() && num1[0] == '-') {
        if (num1.size() == 1) {return ""; }
        lft_sign = "-"; 
        num1 = num1.substr(1, num1.size() - 1);
    }
    string rht_sign = "+";
    if (!num2.empty() && num2[0] == '-') {
        if (num2.size() == 1) {return ""; }
        rht_sign = "-"; 
        num2 = num2.substr(1, num2.size() - 1);
    }

    string res;
    if (lft_sign == rht_sign) {
        res = add_core(num1, num2);
        if (lft_sign == "-") {res = "-" + res; }
    } else {
        if (lft_sign == "-" && rht_sign == "+") {
            if (num1.size() < num2.size()) {
                res = sub_core(num2, num1);
            } else if (num1.size() == num2.size()) {
                if (num1 < num2) {res = sub_core(num2, num1); }
                else {res = "-" + sub_core(num1, num2); }
            } else {
                res = "-" + sub_core(num1, num2);
            }
        } else if (lft_sign == "+" && rht_sign == "-") {
            if (num1.size() < num2.size()) {
                res = "-" + sub_core(num2, num1);
            } else if (num1.size() == num2.size()) {
                if (num1 < num2) {res = "-" + sub_core(num2, num1); }
                else {res = sub_core(num1, num2); }
            } else {
                res = sub_core(num1, num2);
            }
        }
    }
    return res;
}


int main() {
    string num1, num2;
    while (cin >> num1 >> num2)
    {
        string res = add(num1, num2);
        cout << res << endl;
    }

    return 0;
}
