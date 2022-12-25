// T.C----O(sqrt(n)).

#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n){
	if(n ==1){
		return false;
	}
	
	for(int i=2;i*i<=n;i++){
		if(n%2 == 0){
			return false;
		}
	}
	return true;
}
int main(){
	int n;
	cin>>n;
	
	cout<<isPrime(n)<<endl;
	return 0;
}
