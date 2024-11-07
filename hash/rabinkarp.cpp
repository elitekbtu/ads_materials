
#include <iostream>
#include <cmath>
#include <string>

using namespace std;
typedef long long ll;

const ll mod = 1e9+7;
const ll base = 31;

ll hash_func(string s) {
    ll result = 0;
    ll p = 1;
    for (int i = 0; i < s.size(); i++) {
        result = (result + (s[i] * p) % mod) % mod;
        p = (p * base) % mod;
    }
    return result;
}

int main(){
    string s, s1, pat;
    int cnt=0;

    cin>>s>>s1>>pat;

    ll pat_hash = hash_func(pat);
    ll s_hash = hash_func(s.substr(0, pat.length()));
    ll s1_hash = hash_func(s1.substr(0, pat.length()));

    ll base_power=1;
    for (int i=0; i < pat.length() - 1; i++){
        base_power=(base_power*base)%mod;
    }
    for (int i = 0; i <= s.length()-pat.length(); i++){
        if (pat_hash==s_hash && pat_hash==s1_hash)
        {
            cnt++;
        }
        if (i < s.length() - pat.length()){
            s_hash = ((s_hash-(s[i])*base_power) * base + (s[i + pat.length()])) % mod;
            if (s_hash < 0){
                s_hash+=mod;
            }
            s1_hash = ((s1_hash - (s1[i]) * base_power) * base + (s1[i + pat.length()])) % mod;
            if (s1_hash<0){
                s1_hash+=mod;
            }
        }
    }

    cout<<cnt;
    return 0;
}
