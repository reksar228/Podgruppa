#pragma once
#ifndef TRAVELLING_SALESMAN_H
#define TRAVELLING_SALESMAN_H

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

// Структура для представления города
struct City {
    int x;
    int y;
};
// Функция для вычисления расстояния между двумя городами
int distance(const City&, const City&);

// Рекурсивная функция для поиска оптимального маршрута (жадный алгоритм)
int findOptimalRoute(const vector<City>&, int, int, int);
#endif // !1