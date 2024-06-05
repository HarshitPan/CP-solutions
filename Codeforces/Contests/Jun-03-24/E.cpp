#include<bits/stdc++.h>
using namespace std;
#define int long long int
void swap2(vector<vector<int>>& a,int i,int i2,int j,int j2){
    for(int x=0;x<a.size();x++)
    {
        swap(a[x][j],a[x][j2]);
    }
    for(int x=0;x<a[0].size();x++)
    {
        swap(a[i][x],a[i2][x]);
    }
}
bool solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n,vector<int>(m,0));
    vector<vector<int>> b(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin>>a[i][j];
    }
    
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin>>b[i][j] , mp[b[i][j]] = i*m+j;
    }
    if(n==1 || m==1) return true;
    for(int i=0;i<n;i++){
        int x = mp[a[i][i]];
        int i2= x / m;
        int j2 = x % m;
        swap2(a,i,i2,i,j2);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]!=b[i][j]) return false;
        }
    }
    return true;
}
signed main(){
    int t;
    cin>>t;
    while(t--){
        if(solve()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}