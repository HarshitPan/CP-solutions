/*
Solution -> 
for the question, we have to take the minimum price we can get to tell the next person,
if the price to call from one person to another is greater than p i.e. call of chief, then chief will call everyone
other than that, 
chief will tell the person who will tell with smallest price,
after that the cycle will start and all the people with price less will tell others, 
but if there are some people left, than chief will call them as the people eligible to call will only be those with higher price...
*/
#include<bits/stdc++.h>
#define int long long int
using namespace std;
void solve(){
    int n,p;
    cin>>n>>p;
    vector<vector<int>> arr(n,{0,0});
    for(int i=0;i<n;i++){
        cin>>arr[i][1];
    }
    for(int i=0;i<n;i++){
        cin>>arr[i][0];
    }
    sort(arr.begin(),arr.end());
    if(arr[0][0]>=p){
        cout<< p * n <<endl;
        return;
    }
    int total=1;
    int res=p;
    // int 
    for(int i=0;i<n;i++){
        int price= arr[i][0];
        if(price>=p) break;
        int provide = arr[i][1];
        total+=provide;

        if(total>=n){
            total-=provide;

            int rem = n-total;
            // cout<<"here";
            cout<<res + rem * price<<endl;
            return; 
        }
        else {
            res = res + (provide * price);
        }
    }
    int rem = n-total;
    cout<< res + rem*p <<endl;
    // cout<<"kast";
    
}
signed main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}