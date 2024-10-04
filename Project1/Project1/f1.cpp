#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include "f1.h"
using namespace std;

// ������� ��� ���������� ���������� ����� ����� ��������
int distance(const City& city1, const City& city2) {
    return abs(city1.x - city2.x) + abs(city1.y - city2.y);
}

// ����������� ������� ��� ������ ������������ �������� (������ ��������)
int findOptimalRoute(const vector<City>& cities, int currentCity, int visited, int totalDistance) {
    // ������� ������: ��� ������ ��������
    if (visited == (1 << cities.size()) - 1) {
        return totalDistance + distance(cities[currentCity], cities[0]);
    }
    int bestDistance = numeric_limits<int>::max();
    // �������� �� ���� ������������ �������
    for (int i = 0; i < cities.size(); ++i) {
        // ��������, ������� �� �����
        if (!(visited & (1 << i))) {
            // ���������� �������� ������� ��� ���������� ������
            int newDistance = findOptimalRoute(cities, i, visited | (1 << i), totalDistance + distance(cities[currentCity], cities[i]));
            // ��������� ����������� ����������
            bestDistance = min(bestDistance, newDistance);
        }
    }
    return bestDistance;
}