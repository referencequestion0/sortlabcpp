#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); i++) { // Начинаем с первого элемента, считая его отсортированным
        int key = arr[i]; // Запоминаем текущий элемент
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key) { // Пока не дошли до начала массива или не нашли элемент меньше key
            arr[j + 1] = arr[j]; // Сдвигаем больший элемент вправо
            j--;
        }
        
        arr[j + 1] = key; // Вставляем key в отсортированную часть массива
    }
}

int main() {
    vector<int> arr = {3, 5, 7, 9, 54, 4, 21, 88, 78, 98}; // Инициализация вектора arr заданными числами
    insertionSort(arr); // Вызов функции сортировки вставкой
    for (size_t i = 0; i < arr.size(); i++) {
        cout << arr[i] << " "; // Вывод отсортированных элементов вектора
    }
    return 0;
}
