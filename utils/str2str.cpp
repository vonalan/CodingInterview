// 28. implement-strstr
// https://leetcode-cn.com/problems/implement-strstr

#include <iostream>
#include <string>
#include <vector>

using namespace std;


void show_vector(vector<int> &nums) {
    for (auto &c : nums) {cout << c << " "; }
    cout << endl;
}


vector<int> compute_next(string pattern){
    // build KMP Table
    // Knuth-Morris-Pratt算法的核心为前缀函数
    // 真前缀与真后缀的定义为不等于自身的的前缀与后缀
    // 字符串aabaaab的前缀函数值依次为-1,0,1,0,1,2,2
    // 字符串abeabf的前缀函数值依次为-1,0,0,0,1,2,0

    // next_table[pos], pattern[0:pos-1]的前缀函数值
    vector<int> next_table(pattern.size() + 1, 0);
    next_table[0] = -1;
    next_table[1] = 0;  // 长度为1的字符串没有前后缀

    int pos = 2;        // 表示next数组的索引
    int cnd = 0;        // 指针指向pattern的位置
    while (pos < next_table.size()) {
        // 如果当前字符匹配成功
        if (pattern[pos - 1] == pattern[cnd]) {
            // pattern索引比next_table索引小1
            next_table[pos++] = ++cnd;
        } else if (cnd == 0) {
            // 如果指针已经指向pattern[0]却还没有匹配成功
            next_table[pos++] = 0;
        } else {
            // 可以利用已匹配成功的信息, 让指针不进行回退, 查找next数组
            // 回到最近一个可匹配位置
            cnd = next_table[cnd];
        }
    }

    return next_table;
}


int kmp_match(string s, string p) {
    /* KMP, Knuth-Morris-Pratt
     *  https://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm
     *  which is a website about KMP algorithm, and two typical strings: S[] = "ABC ABCDAB ABCDABCDABDE", W[] = "ABCDABD".
     */
     if (p.empty()) {return 0; }

    // build KMP Table
    vector<int> next_table = compute_next(p);

    // main KMP algorithm
    int base = 0;   // s开始比较的位置
    int offset = 0; // 相对于base, 比较字符的偏移量
    while (base + offset < s.size()) {
        if (s[base + offset] == p[offset]) {
            // 当前字符匹配
            if (offset == p.size() - 1) {
                // 已匹配到p的最后一个字符
                return base;
            };
            ++offset;
        } else {
            // 检查之前已经匹配成功的部分中里是否存在相同的「前缀」和「后缀」
            // next_table[offset]对应于pattern[offset-1], 刚好满足需求
            if (next_table[offset] > -1) {
                // 如果存在，则跳转到「前缀」的下一个位置继续匹配
                base = base + offset - next_table[offset];
                offset = next_table[offset];
            } else {
                // 如果不存在，只能回到匹配串的起始位置重新开始
                ++base;
                offset = 0;
            }
        }
    }

    return -1;
}


int main() {
    string p = "c";
    vector<int> res = compute_next(p);
    show_vector(res);

    string s = "abc";
    int sidx = kmp_match(s, p);
    cout << sidx << endl;

    return 0;
}
