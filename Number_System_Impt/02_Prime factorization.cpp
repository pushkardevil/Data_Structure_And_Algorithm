//TIME COMPLEXITY---O(sqrt(N))
// SPACE COMPLEXITY--- 


#include <bits/stdc++.h>
using namespace std;

void primefactorization(int n){
	for(int i=2;i*i<=n;i++){
		if(n%i == 0){
			int cnt=0;
			while(n%i == 0){
				cnt++;
				n=n/i;
			}
			cout<<i<<"^"<<cnt<<endl;
		}
		
	}
	if(n > 1){
		cout<<n<<"^"<<1<<endl;
	}
}

int main()
{
	int n = 11;
	cout << "Following are the prime numbers smaller "
		<< " than or equal to " << n << endl;
	primefactorization(n);
	return 0;
}







////////////////////////////////////////////////////--------------BRUTE FORCE APPROACH --------------////////////////////////////////////////////////////////////////
//TIME COMPLEXITY---O(n)-----in worst case
// SPACE COMPLEXITY--


#include <bits/stdc++.h>
using namespace std;

void primefactorization(int n){
	for(int i=2;i<=n;i++){
		if(n%i == 0){
			int cnt=0;
			while(n%i == 0){
				cnt++;
				n=n/i;
			}
			cout<<i<<"^"<<cnt<<endl;
		}
	}
}

int main()
{
	int n = 30;
	cout << "Following are the prime numbers smaller "
		<< " than or equal to " << n << endl;
	primefactorization(n);
	return 0;
}

