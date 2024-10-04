#include "f1.h"
using namespace std;

void main() {
    setlocale(LC_ALL, "Russian");
    int numCities;
    cout << "Введите количество городов: ";
    cin >> numCities;
    vector<City> cities(numCities);
    cout << "Введите координаты городов (x y):\n";
    for (int i = 0; i < numCities; ++i) {
        cin >> cities[i].x >> cities[i].y;
    }
    // Вычисляем минимальное расстояние
    int optimalDistance = findOptimalRoute(cities, 0, 1, 0);
    cout << "Минимальное расстояние: " << optimalDistance << endl;
}