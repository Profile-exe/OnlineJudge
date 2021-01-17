#include <iostream>
#include <vector>
using namespace std;

int fibList[41] = { 0, 1, };

int fibonacci(int n) {
	if (fibList[n]) return fibList[n];
	if (n == 0)		 return 0;
	else if (n == 1) return 1;
	else {
		fibList[n] = fibonacci(n - 1) + fibonacci(n - 2);
		return fibList[n];
	}
}

int main(void)
{
	int T, n;
	vector<pair<int, int>> fibo;
	int test[100] = { 0, };
	
	cin >> T;
	fibonacci(40);				// 40까지 피보나치 수열 구하기
	
	fibo.emplace_back(1, 0);	// emplace_back이 성능상 push_back보다 더 유리
	for(int i = 1; i < 41; i++)	// 벡터에 담아놓기
		fibo.emplace_back(fibList[i - 1], fibList[i]);
	
	for(auto i = 0; i < T; i++) {
		cin >> n;
		cout << fibo[n].first << ' ' << fibo[n].second << endl;	// 해당 인덱스의 순서쌍 출력
	}
	
	return 0;
}