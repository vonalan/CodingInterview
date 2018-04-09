#include <iostream>

using namespace std;

// greatest common divisor, GCD
int GCD(int a, int b){
    int q, r;
    while(a % b){
        q = a / b;
        r = a % b;

        a = b;
        b = r;
    }

    return b;
}

// lowest common multiple, LCM
int LCM(int a, int b){
    return (a * b) / GCD(a, b);
}

void core(int a){
    int Y = 1;
    while(a % 2 == 0){
        a /= 2;
        Y *= 2;
    }
    if(Y == 1) cout << "No" << endl;
    else cout << a << " " << Y << endl;
}

int main(int argc, char **argv){
    int N;
    cin >> N;
    for(int i = 0; i < N; ++i){
        int temp;
        cin >> temp;
        core(temp);
    }

    return 0;
}
