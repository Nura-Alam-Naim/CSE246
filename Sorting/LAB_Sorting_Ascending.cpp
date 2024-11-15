//|ADMIRAL_AUDITORE|//
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vl;
#define nl "\n"
#define sp ' '
#define yes cout << "YES" << nl
#define no cout << "NO" << nl
#define all(v) v.begin(), v.end()
#define pb push_back
#define ff first
#define ss second
const ll N = 1e7 + 1;
void merge(vl &v, ll l, ll mid, ll r)
{
    ll n1 = mid - l + 1;
    ll n2 = r - mid;
    vl a1(n1 + 1), a2(n2 + 1);
    for (ll i = 0; i < n1; i++)
        a1[i] = v[l + i];
    for (ll i = 0; i < n2; i++)
        a2[i] = v[mid + 1 + i];
    a1[n1] = LLONG_MAX;
    a2[n2] = LLONG_MAX;
    ll i = 0, j = 0, n = 0, k = l;
    while (n++ < n1 + n2)
        a1[i] <= a2[j] ? v[k++] = a1[i++] : v[k++] = a2[j++];
}
void mergeSort(vl &v, ll l, ll r)
{
    if (r <= l)
        return;
    ll mid = (l + r) / 2;
    mergeSort(v, l, mid);
    mergeSort(v, mid + 1, r);
    merge(v, l, mid, r);
}
ll partition(vl &v, ll l, ll r)
{
    ll pivot = v[l];
    ll i = l, j = r;
    while (i < j)
    {
        while (v[i] <= pivot)
            i++;
        while (v[j] > pivot)
            j--;
        if (i < j)
            swap(v[i], v[j]);
    }
    swap(v[l], v[j]);
    return j;
}
void quickSort(vl &v, ll l, ll r)
{
    if (l < r)
    {
        ll j = partition(v, l, r);
        quickSort(v, l, j);
        quickSort(v, j + 1, r);
    }
}
void solve()
{
    vl mergeS(N);
    vl quickS(N);
    for (ll i = 0; i < N;i++)
        mergeS[i] = rand();
    for (ll i = 0; i < N; i++)
        quickS[i] = mergeS[i];
    time_t start, end;
    time(&start);
    mergeSort(mergeS, 0, N - 1);
    time(&end);
    cout << "Exection time for Merge Sort is: " << fixed << setprecision(6) << (double)(end - start) << " seconds" nl;
    time(&start);
    mergeSort(quickS, 0, N);
    time(&end);
    cout << "Exection time for Quick Sort is: " << fixed << setprecision(6) << (double)(end - start) << " seconds" nl;
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