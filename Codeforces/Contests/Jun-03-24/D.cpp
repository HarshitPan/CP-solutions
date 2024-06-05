#include<bits/stdc++.h>
using namespace std;
#define int long long int

bool check(vector<int> a,int i){
    
    int hcf=1;
    int n=a.size();
    if(i!=0)a[i]=a[i-1];
    for(int j=(i==0?2:1);j<n;j++){
        if(j==i) continue;
        int curr=__gcd(a[j],a[j-1]);
        if(curr<hcf) return false;
        hcf=curr;
    }
    return true;
}
bool solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int hcf=1;
    for(int i=1;i<n;i++){
        int curr = __gcd(a[i],a[i-1]);
        if(curr<hcf){
            return check(a,i) || check(a,i-1) || check(a,i-2);
        }
        else hcf=curr;
    }
    // cout<<"REACHED WITHOUT ERROR ";
    return true;
}
signed main(){
    int t;
    cin>>t;
    while(t--){
        bool check=solve();
        if(check) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
    return 0;
}