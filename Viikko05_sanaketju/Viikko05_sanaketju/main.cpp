#include <iostream>

using namespace std;

string s[20];
long dp[1<<20][26];
const int M = 1000000007;

int main() { 
    cin.sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    long long sum = 0;
    int j;
    for (int b = 0; b < (1<<n); b++) {
        for (int i = 0; i < n; i++) {
            if(b & (1<<i)) {
                j = b^(1<<i);
                if(j == 0) {
                    dp[b][s[i].back()-'A']++;
                } else {
                    dp[b][s[i].back()-'A'] += dp[j][s[i].front()-'A'];
                    dp[b][s[i].back()-'A'] %=M;
                }
            }
        }
    }
    for (int i = 'A'; i <= 'Z'; i++) {
        sum+=dp[(1<<n)-1][i-'A'];
        sum%=M;
    }
    cout << sum << "\n";
}
