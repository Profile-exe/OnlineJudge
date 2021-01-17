#include <iostream>

using namespace std;

//최대공약수를 구해서 최대공약수를 이용해 최소공배수를 구함 

int gcd(int a, int b) {

	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main(void) {
	int t;
	int n1, n2;

	cin >> t;

	while (t--) {
		cin >> n1 >> n2;
		auto gc = gcd(n1, n2);
		auto answer = n1 * n2 / gc;
		cout << answer << '\n';
	}
	return 0;
}