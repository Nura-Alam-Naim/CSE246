#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<int,int>& a , const pair<int,int>& b)
{
    return a.second < b.second;
}

int main()
{
    vector<pair<int,int>>v;

    int n;
    cout<<"number of input: ";
    cin>>n;

    for(int i=0;i<n;i++)
    {
        int start,end;
        cin>>start>>end ;
        v.push_back({start,end});
    }

    sort(v.begin(),v.end(),cmp);

     vector<pair<int, int>> v1;
     v1.push_back(v[0]);
    int end = v[0].second;

    int count = 1;


    for (int i = 1; i < v.size(); i++) {
    if (v[i].first >= end) {
        v1.push_back(v[i]);
        //Endtime += v[i].second;
        end = v[i].second;
        count++;
    }
}


    for (int i = 0; i < n; i++) {
     cout << "(" << v1[i].first << "," << v1[i].second << ")"  ;
    }

    cout << "Total activities: " << count << endl;

}
