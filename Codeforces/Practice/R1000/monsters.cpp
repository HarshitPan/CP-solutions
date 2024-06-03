/*
Solution ->
if we decrease an element, 
at the end it will remain a[i] % k;
now if we do this for all value bigger than k,
all element will be converted to element % k;

now we can take values which are bigger like k-1 first than k-2, etc.

Catch Phrase -> reminder 0 will be given most priority 
i.e. take 0 then k-1 then k-2 , etc/
we can do this with the help of a custom comparator...

taking 0 is due to a very specific reason,
i.e. before becoming 0, the value should have been k as we decr value k time so 0 + k = k
 this signifies that the element is the biggest i.e. K when we remove them
*/


#include<bits/stdc++.h>
#define int long long int 

using namespace std;


bool comp(pair<int,int> a,pair<int,int> b){
    if(a.first==b.first){
        return a.second<b.second;
    }
    if(a.first == 0) return true;
    if(b.first == 0) return false;
    return a.first>b.first;
}

void solve(){
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        a[i] = {temp,i+1};
        // cin>>a[i].second;
    }
    if(k==1){
        for(int i=1;i<=n;i++) cout<<i<<" ";
        cout<<endl;
        return;
    }
    vector<int> res;

    for(int i=0;i<n;i++){
        a[i].first = a[i].first % k;
    }

    // for(auto i:a) {
    //     cout<<i.first<<" "<<i.second<<" : ";
    // }
    // cout<<endl;
    sort(a.begin(),a.end(),comp);
    for(int i=0;i<n;i++)
    {
        cout<<a[i].second<<" ";
    }
    cout<<endl;
    
}
signed main()
{
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}