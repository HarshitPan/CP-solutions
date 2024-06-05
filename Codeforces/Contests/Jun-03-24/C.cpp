#include<bits/stdc++.h>
using namespace std;
// #define int long long int

string solve(){
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    int m;
    cin>>m;
    vector<int> d(m,0);
    for(int i=0;i<m;i++) cin>>d[i];
    // vector<int> c(m,-1);
    map<int,int> mp;
    for(auto i:d){
        mp[i]++;
    }
    for(int i=0;i<n;i++){
        if(a[i]!=b[i]){
            if(!mp.count(b[i])) return "NO"; 
            else {
                mp[b[i]]--;
                if(mp[b[i]]==0) mp.erase(b[i]);
            }
        }
    }

    int last = d[m-1];

    for(int i=0;i<n;i++){
        if(last==b[i]) return "YES";
    }
    return "NO";
}
signed main(){
    int t;
    cin>>t;
    while(t--) cout<<solve()<<endl;
    return 0;
}