/*
Solution ->
in this problem, 
we will take all the second smallest element of each array except the smallest second element,
also we will take the overall smallest element,

output -> sum of all second element except smallest + smallest of all elements....
*/

#include<bits/stdc++.h>
#define int long long int
using namespace std;
void solve(){
    int n;
    cin>>n;
    // int overall=INT_MAX;
    vector<vector<int>> arr;
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        vector<int> temp(m,0);
        for(int j=0;j<m;j++){
            cin>>temp[j];
        }
        sort(temp.begin(),temp.end());
        arr.push_back(temp);
    }
    // for(auto i:arr){
    //     for(auto j:i) cout<<j<<" ";
    // }
    // cout<<"end";
    int idx=-1;
    int mini=INT_MAX;
    int overall=INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i][1]<mini){
            mini=arr[i][1];
            idx=i;
        }
        overall = min(overall,arr[i][0]);
    }
    // cout<<idx<<endl;
    int sum=0;
    for(int i=0;i<n;i++){
        if(i==idx){
         continue;
        }
        else{
            sum+=arr[i][1];
        }
    }
    cout<<sum + overall<<endl;
}
signed main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}
