#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include "f1.h"
using namespace std;

// Функция для вычисления расстояния между двумя городами
int distance(const City& city1, const City& city2) {
    return abs(city1.x - city2.x) + abs(city1.y - city2.y);
}

// Рекурсивная функция для поиска оптимального маршрута (жадный алгоритм)
int findOptimalRoute(const vector<City>& cities, int currentCity, int visited, int totalDistance) {
    // Базовый случай: все города посещены
    if (visited == (1 << cities.size()) - 1) {
        return totalDistance + distance(cities[currentCity], cities[0]);
    }
    int bestDistance = numeric_limits<int>::max();
    // Проходим по всем непосещенным городам
    for (int i = 0; i < cities.size(); ++i) {
        // Проверка, посещен ли город
        if (!(visited & (1 << i))) {
            // Рекурсивно вызываем функцию для следующего города
            int newDistance = findOptimalRoute(cities, i, visited | (1 << i), totalDistance + distance(cities[currentCity], cities[i]));
            // Обновляем минимальное расстояние
            bestDistance = min(bestDistance, newDistance);
        }
    }
    return bestDistance;
}