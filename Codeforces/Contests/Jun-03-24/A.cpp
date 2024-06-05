#include<bits/stdc++.h>
using namespace std;
#define int long long int

void solve(){
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    vector<int> count(7,0);
    for(int i=0;i<s.length();i++){
        int idx =s[i]-'A';
        count[idx]++;
    }
    int total=0;
    for(auto i:count){
        // cout<<i<<" ";
        if(i<m){
            total+= (m-i);
        }
    }
    // cout<<endl;
    cout<<total<<endl;
}
signed main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}