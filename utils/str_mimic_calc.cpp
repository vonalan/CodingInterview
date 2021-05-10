#include <string>

using namespace std;


string str_mimic_add(string num1, string num2) {
    // 用字符串模拟数字加法
    int N = num1.size(), M = num2.size();
    if (N == 0 || M == 0) {return ""; }
    string res(max(N, M) + 1, '0');

    int pos = 0;
    int sum = 0, car = 0;
    while (N - 1 - pos >= 0 || M - 1 - pos >= 0) {
        int lft = 0, rht = 0;
        if (N - 1 - pos >= 0) {lft = num1[N - 1 - pos] - '0'; }
        if (M - 1 - pos >= 0) {rht = num2[M - 1 - pos] - '0'; }

        sum = lft + rht + car;
        car = sum / 10; // 进位
        sum = sum % 10; // 数字
        res[max(N, M) - pos] = sum + '0';

        pos++;
    }
    res[0] = car + '0';

    if (res[0] == '0') {
        res = res.substr(1, res.size() - 1);
    }
    return res;
}