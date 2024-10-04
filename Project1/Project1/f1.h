#pragma once
#ifndef TRAVELLING_SALESMAN_H
#define TRAVELLING_SALESMAN_H

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

// ��������� ��� ������������� ������
struct City {
    int x;
    int y;
};
// ������� ��� ���������� ���������� ����� ����� ��������
int distance(const City&, const City&);

// ����������� ������� ��� ������ ������������ �������� (������ ��������)
int findOptimalRoute(const vector<City>&, int, int, int);
#endif // !1