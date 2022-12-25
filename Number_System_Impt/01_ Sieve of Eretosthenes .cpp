//TIME COMPLEXITY---O(n*log(log(n)))
// SPACE COMPLEXITY--- O(n)


// C++ program to print all primes smaller than or equal to
// n using Sieve of Eratosthenes
#include <bits/stdc++.h>
using namespace std;

void SieveOfEratosthenes(int n)
{
	int is_prime[n + 1];
	for(int i=0;i<=n+1;i++){
		is_prime[i]=1;
	}

	for (int i=2;i*i<=n;i++) {
		if (is_prime[i] == 1) {
			
			for (int j =i*i;j<= n; j+= i)
				is_prime[j] = 0;
		}
	}

	// Print all prime numbers
	for (int p = 2; p <= n; p++)
		if (is_prime[p] == 1)
			cout << p << " ";
}

// Driver Code
int main()
{
	int n = 30;
	cout << "Following are the prime numbers smaller "
		<< " than or equal to " << n << endl;
	SieveOfEratosthenes(n);
	return 0;
}

