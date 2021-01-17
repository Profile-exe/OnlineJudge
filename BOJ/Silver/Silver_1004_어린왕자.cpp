#include <iostream>
#include <cmath>

using namespace std;

class Point
{
public:
	int x, y;
	explicit Point(const int x = 0, const int y = 0) : x(x), y(y) { }
};

class Circle
{
public:
	Point center;
	int r;
	explicit Circle(const int x = 0, const int y = 0, const int r = 0) : center(x, y), r(r) { }
};

double distance(const Point& a,const Point& b)
{
	return pow(a.x - b.x, 2) + pow(a.y - b.y, 2);
}

bool isInner(const Point& target,const Circle& planet)
{
	return distance(target, planet.center) < pow(planet.r, 2);
}

int main(void)
{
	int t, n;
	Point start, finish;
	
	cin >> t;
	for(auto i = 0; i < t; i++) {
		auto count = 0;	// 각 TestCase마다 초기화
		cin >> start.x >> start.y >> finish.x >> finish.y;
		cin >> n;
		
		for (auto j = 0; j < n; j++) {
			Circle planet;
			cin >> planet.center.x >> planet.center.y >> planet.r;
			
			// 출발점과 도착점을 포함하고 있는 원의 개수 - 2 * 동시에 포함하는 원의 개수
			if (isInner(start, planet)) count++;
			if (isInner(finish, planet)) count++;
			if (isInner(start, planet) && isInner(finish, planet)) count -= 2;
		}
		cout << count << endl;
	}	
	return 0;
}