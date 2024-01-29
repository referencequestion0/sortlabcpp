#include <iostream>
#include <vector>
using namespace std;

int getMax(const vector<int>& arr) 
{
    int max = arr[0];
    for (size_t i = 1; i < arr.size(); i++) 
    {
        if (arr[i] > max) 
        {
            max = arr[i];
        }
    }
    return max;
}

void countSort(vector<int>& arr, int exp) 
{
    const int n = arr.size();
    vector<int> output(n, 0);
    vector<int> count(10, 0);

    for (int i = 0; i < n; i++) 
    {
        count[(arr[i] / exp) % 10]++; // Подсчёт количества встречающихся цифр
    }

    for (int i = 1; i < 10; i++) 
    {
        count[i] += count[i - 1]; // Преобразование count так, чтобы каждый элемент указывал на правильную позицию элемента в результирующем массиве
    }

    for (int i = n - 1; i >= 0; i--) 
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i]; // Построение отсортированного массива
        count[(arr[i] / exp) % 10]--; // Уменьшение счётчика для текущей цифры
    }

    for (int i = 0; i < n; i++) 
    {
        arr[i] = output[i]; // Копирование отсортированного массива в исходный
    }
}

void radixSort(vector<int>& arr) 
{
    int max = getMax(arr);
    for (int exp = 1; max / exp > 0; exp *= 10) // Проход по разрядам чисел
    { 
        countSort(arr, exp); // Сортировка подсчётом для текущего разряда
    }
}

int main() 
{
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66}; // Инициализация вектора arr заданными числами
    radixSort(arr); // Вызов функции цифровой сортировки
    for (size_t i = 0; i < arr.size(); i++) 
    {
        cout << arr[i] << " "; // Вывод отсортированных элементов вектора
    }
    return 0;
}