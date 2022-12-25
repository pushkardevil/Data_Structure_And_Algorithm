

#include <bits/stdc++.h>
using namespace std;

int power(int m , int n){
	int res=1;
	while(n ){
		if(n%2 == 1){
			res=res*m;
			n--;
		}
		else{
			m=m*m;
			n=n/2;
		}
	}
	
	cout<<res<<endl;
}

int main()
{
	int m=5;
	int n=2;
	
	power(m , n);
	
	return 0;
}
