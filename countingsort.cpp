#include<iostream>
#include<vector>

using namespace std;

void countingSort(vector<int>& arr, int range) // Создание вспомогательного массива для подсчёта
{
    vector<int> count(range + 1, 0); 
    vector<int> result(arr.size()); // Создание массива для результата с таким же размером, как у входного массива

    for (int i = 0; i < arr.size(); i++) 
    {
        count[arr[i]]++; // Подсчёт количества каждого элемента
    }

    for (int i = 1; i <= range; i++) 
    {
        count[i] += count[i - 1]; // Преобразование count так, чтобы каждый элемент указывал на правильную позицию элемента в результирующем массиве
    }

    for (int i = arr.size() - 1; i >= 0; i--) 
    {
        result[count[arr[i]] - 1] = arr[i]; // Помещение элемента на правильное место в результирующем массиве
        count[arr[i]]--; // Уменьшение счётчика для текущего элемента
    }

    arr = result; // Копирование отсортированного массива в исходный
}

int main() 
{
    vector<int> arr = {3, 5, 7, 9, 5, 7, 3, 2, 1, 1, 8, 6, 0, 2}; // Инициализация вектора arr заданными числами
    countingSort(arr, 9); // Вызов функции сортировки подсчётом, задав диапазон чисел от 0 до 9
    for (int i = 0; i < arr.size(); i++) 
    {
        cout << arr[i] << " "; // Вывод отсортированных элементов вектора
    }
    return 0;
}