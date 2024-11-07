#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9+7;
const int base = 31;

ll hash_func(string s) {
    ll result = 0;
    ll p = 1;
    for (int i = 0; i < s.size(); i++) {
        result = (result + (s[i] * p) % mod) % mod;
        p = (p * base) % mod;
    }
    return result;
}

int main() {
    string s;
    cin>>s;
    cout<<hash_func(s);
    return 0;
}