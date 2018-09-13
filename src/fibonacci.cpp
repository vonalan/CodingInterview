#include <iostream> 
#include <vector> 
#include <map> 

/*
std::map<int, long long> results; 

long long fibonacci(int n) {
	if (n < 0) return 0; 
	if (n == 0 || n == 1) return 1; 

	if (results.find(n) != results.cend()) return results[n]; 

	long long temp = fibonacci(n - 1) + fibonacci(n - 2);
	results[n] = temp; 

	return temp; 
}
*/

// (a + b) % p == (a % p + b % p) % p; 
// (a - b) % p == (a % p - b % p) % p; 
// (a * b) % p == (a % p * b % p) % p; 
long long fibonacci(int n) {
	if (n < 0) return 0; 

	std::vector<long long> results = {1, 1};
	long long p = static_cast<long long>(1e9 + 3); 

	for (int i = 2; i < n + 1; ++i) {
		results[i % 2] = (results[(i - 2) % 2] + results[(i - 1) % 2]) % p; 
	}

	return results[n % 2]; 
}

int main() {
	int N; 
	while (std::cin >> N) {
		std::cout << fibonacci(N) << std::endl;
	}

	system("pause"); 
	return 0;
}
