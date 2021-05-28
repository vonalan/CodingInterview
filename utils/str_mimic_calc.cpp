#include <string>

using namespace std;


string str_mimic_add(string num1, string num2) {
    // 用字符串模拟数字加法
    int N = num1.size(), M = num2.size();
    if (N == 0 || M == 0) {return ""; }
    string res(max(N, M) + 1, '0');

    int pos = 0;
    int sum = 0, car = 0;
    while (pos < max(M, N)) {
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


bool is_gt_int_max(string cur) {
    // 和INT_MAX进行比较
    string int_max = "2147483647";
    if (cur.size() > int_max.size()) {return true; }
    if (cur.size() == int_max.size()) {
        for (int i = 0; i < cur.size(); ++i) {
            if (cur[i] < int_max[i]) {break; }
            if (cur[i] > int_max[i]) {return true; }
        }
    }
    return false;
}