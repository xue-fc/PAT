#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
bool isprime(ll a){
	if(a<=1) return false;
	if(a==2) return true;
	for(ll i=2;i*i<=a;i++)
		if(a%i==0)
			return false;
	return true;
}
map<ll,ll>mp;
int main(){
	cin>>n;
	ll on=n;
	ll max_=-1;
    if(n==1){
        cout<<"1=1"<<endl;
        return 0;
    }
	for(ll i=2;i<=on;i++){
		if(on%i==0&&isprime(i)==true){
			on=on/i;
			mp[i]++;
	//		cout<<i<<"="<<mp[i]<<endl;
			max_=max(max_,i);
			i--;
			if(n==1)
				break;
		}
	}
	printf("%lld=",n);
	for(auto it:mp){
		if(it.second==1)
			printf("%lld",it.first);
		else
			printf("%lld^%lld",it.first,it.second);
		if(it.first!=max_)
			cout<<"*";
	}
	cout<<endl;
	return 0;
}

