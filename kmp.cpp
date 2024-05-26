#include <bits/stdc++.h>
#define nn "\n"
#define ll long long
#define pb push_back
#define pll pair<ll, ll>
#define vll vector<ll>
#define all(_obj) _obj.begin(), _obj.end()
#define fr(x, y) for (ll x = 0; x < y; x++)
#define nach_basanti                  \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define inp(x) \
    ll x;      \
    cin >> x;
#define inpv(v, n) \
    vll v(n);      \
    fr(i, n) cin >> v[i];
#define printv(v) fr(i, v.size()) cout << v[i] << " ";
#define yes cout << "YES"
#define no cout << "NO"
#define home return;
const ll mod = 1e9 + 7;
using namespace std;
vll giveLPS(string &s)
{
    int n = s.size();
    vector<ll> lps(n);
    for (ll i = 1; i < n; i++)
    {
        ll previdx = lps[i - 1];
        while (previdx > 0 && s[i] != s[previdx])
        {
            previdx = lps[previdx - 1];
        }
        if (s[i] == s[previdx])
            lps[i]++;
        lps[i] += previdx;
    }
    return lps;
}
void solve()
{
    inp(n);inp(m);
    string s,t;
    cin>>s>>t; 
    string temp=s+'#'+t;
    vll lps=giveLPS(temp);
    vll ans;
    for(ll i=0;i<lps.size();i++){
        cout<<lps[i]<<" ";
        if(lps[i]==n){
            ans.push_back(i-2*n);
        }
    }
    cout<<endl;
    for(auto &it:ans)cout<<it<<" ";
}
int32_t main()
{
    nach_basanti;
    inp(t);
    fr(i, t)
    {
        solve();
        cout << nn;
    }
    return 0;
}