/*
Solution ->
Count 1 and 0,
check original string and change 0 with 1 and vice versa
i.e. if 1 decr count0 and if 0 decr count1
if we are not remaining with count0 or count1 then len to remove is all element next to it
i.e.  n - i;

*/

#include<bits/stdc++.h>
using namespace std;
void solve(){
    string s;
    cin>>s;
    int one = 0;
    int zero= 0;
    int n=s.length();
    for(int i=0;i<s.length();i++){
        if(s[i]=='1') one++;
        else zero++;
    }

    // cout<<abs((n-one)-one)<<endl;
    // int count=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='1'){
            if(zero) zero--;
            else {
                cout<< n-i <<endl;
                return;
            }
        }
        else {
            if(one) one--;
            else {
                cout<< n-i <<endl;
                return;
            }
        }
    }
    cout<<0<<endl;

}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}