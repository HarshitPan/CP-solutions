#include<bits/stdc++.h>
using namespace std;
#define int long long int

string solve(){
    int n,f,k;
    cin>>n>>f>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int ele = a[f-1];
    sort(a.begin(),a.end(),greater<int>());
    int limit = a[k-1];
    if(limit>ele){
        return "NO";
    }
    else if(limit<ele){
        return "YES";
    }else{
        if(k>=n) return "YES";
        if(a[k]==ele) return "MAYBE";
        else return "YES";
    }
}
signed main(){
    int t;
    cin>>t;
    while(t--) cout<<solve()<<endl;
    return 0;
}