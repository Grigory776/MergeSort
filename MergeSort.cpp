// MergeSort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

/* В этой задаче гарантируется, что длина передаваемого
диапазона является степенью двойки, так что вектор всегда
можно разбить на две равные части. */

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end);

/* Гарантируется, что длина исходного диапазона является степенью 3. */

template <typename RandomIt>
void MergeSort2(RandomIt range_begin, RandomIt range_end);

int main()
{
    vector<int> v = { 6, 4, 7, 6, 4, 4, 0, 1, 5 };
    MergeSort2(begin(v), end(v));
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}

//template <typename RandomIt>
//void MergeSort(RandomIt range_begin, RandomIt range_end) {
//
//    if ((range_end - range_begin) < 2) return;
//
//    vector<typename RandomIt::value_type> elements(range_begin, range_end); // создаем вектор нужного типа
//
//    auto IndMiddle = (int)(elements.end() - elements.begin()) / 2;
//    RandomIt ItMiddle = elements.begin() + IndMiddle; // итератор на середину
//    
//    MergeSort(elements.begin(), ItMiddle);
//    MergeSort(ItMiddle, elements.end());
//
//    merge(elements.begin(), ItMiddle, ItMiddle, elements.end(), range_begin );
//    
//}

 /* Гарантируется, что длина исходного диапазона является степенью 3. */

template <typename RandomIt>
void MergeSort2(RandomIt range_begin, RandomIt range_end) {

    if ((range_end - range_begin) < 2) return;

    vector<typename RandomIt::value_type> elements(range_begin, range_end); // создаем вектор нужного типа

    auto IndMiddle = (int)(elements.end() - elements.begin()) / 3;
    RandomIt ItMiddle = elements.begin() + IndMiddle; // итератор на первую треть
    RandomIt ItMiddle2 = elements.begin() + IndMiddle + IndMiddle; // итератор на вторую треть

    MergeSort2(elements.begin(), ItMiddle);
    MergeSort2(ItMiddle, ItMiddle2);
    MergeSort2(ItMiddle2, elements.end());

    vector<typename RandomIt::value_type> tmp;
    merge(elements.begin(), ItMiddle, ItMiddle, ItMiddle2, back_inserter(tmp));
    merge(tmp.begin(), tmp.end(), ItMiddle2, elements.end(), range_begin);
}