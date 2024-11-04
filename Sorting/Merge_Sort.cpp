//|ADMIRAL_AUDITORE|//
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vl;
#define nl "\n"
#define sp ' '
const ll N = 1e6 + 1;
void merge(vl &v, ll l, ll mid, ll r)
{
    ll n1 = mid - l + 1;
    ll n2 = r - mid;
    vl a1(n1 + 1), a2(n2 + 1);
    for (ll i = 0; i < n1;i++)
        a1[i] = v[l + i];
    for (ll i = 0; i < n2;i++)
        a2[i] = v[mid + 1 + i];
    a1[n1] = LLONG_MAX;
    a2[n2] = LLONG_MAX;
    ll i = 0, j = 0, n = 0, k = l;
    while(n++<n1+n2)
        a1[i] <= a2[j] ? v[k++] = a1[i++] : v[k++] = a2[j++];
}
void mergeSort(vl &v,ll l,ll r)
{
    if (r <= l)
        return;
    ll mid = (l + r) / 2;
    mergeSort(v, l, mid);
    mergeSort(v, mid + 1, r);
    merge(v, l, mid, r);
}
void solve()
{
    vl v = {12, 11, 5, 13, 7, 6};
    ll n = (ll)v.size();
    for(auto i:v)
        cout << i << sp;
    cout << nl;
    cout << "MergeSort: ";
    mergeSort(v, 0, n - 1);
    for (auto i : v)
        cout << i << sp;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    //cin>>tc;
    while (tc--)
        solve();
}