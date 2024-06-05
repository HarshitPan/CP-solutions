/*
Solution -> 

here , we can combine any subarray of a to any subarray of b,
so we take largest subarray Of A with Value X + largest subarray Of B with Value X

we create two map to add maximum subarray for any element in A and B

we itereate in value of mapA and if that element is in mapB then add them or take a single one, do that for mapB

the largest among all those is our answer
*/


#include<bits/stdc++.h>
using namespace std;
#define int long long int

void solve(){
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    vector<int> c(2*n,0);

    int i=0;
    int j=0;
    int maxi=0;
    
    map<int,int> mp1,mp2;
    int val=a[0];
    int curr=1;
    for(int i=1;i<n;i++){
        if(a[i]==a[i-1]){
            curr++;
        }
        else {
            mp1[val] = max(mp1[val],curr);
            curr=1;
            val=a[i];
        }
    }
    mp1[val] = max(mp1[val],curr);
    val=b[0];
    curr=1;
    for(int i=1;i<n;i++){
        if(b[i]==b[i-1]){
            curr++;
        }
        else {
            mp2[val] = max(mp2[val],curr);
            curr=1;
            val=b[i];
        }
    }
    mp2[val] = max(mp2[val],curr);


    for(auto i:mp1){
        if(mp2.count(i.first)){
            maxi=max(maxi,i.second + mp2[i.first]);
        }
        else maxi=max(maxi,i.second);
    }
    
    for(auto i:mp2){
        if(mp1.count(i.first)){
            maxi=max(maxi,i.second + mp1[i.first]);
        }
        else maxi=max(maxi,i.second);
    }
    cout<<maxi<<endl;
}
signed main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}