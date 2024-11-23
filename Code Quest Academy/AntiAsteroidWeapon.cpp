#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

struct Point {
    double x, y, distance;
};

void getOutput();
double getDistance(double x, double y);

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		getOutput();
	}
	return 0;
}

void getOutput() {
	int n;
	scanf("%d", &n);

	Point points[n];
	// x, y, distance
	for (int i = 0; i < n; i++) {
		scanf("%lf %lf", &points[i].x, &points[i].y);
		points[i].distance = getDistance(points[i].x, points[i].y);
	}
	
	std::sort(points, points+n, [](const Point &a, const Point &b) { return a.distance < b.distance; });

	for (int i = 0; i < n; i++) {
		printf("%d %d\n", (int) points[i].x, (int) points[i].y);
	}
}

double getDistance(double x, double y) {
	return std::sqrt(std::pow(x, 2) + std::pow(y, 2));
}
