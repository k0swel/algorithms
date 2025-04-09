# Виды сортировок массивов
* [_Сортировка пузырьком;_](https://github.com/k0swel/types-of-sorting/tree/sort?tab=readme-ov-file#%D1%81%D0%BE%D1%80%D1%82%D0%B8%D1%80%D0%BE%D0%B2%D0%BA%D0%B0-%D0%BF%D1%83%D0%B7%D1%8B%D1%80%D1%8C%D0%BA%D0%BE%D0%BC)
* [_Сортировка выбором;_](https://github.com/k0swel/algorithms/blob/sort/%D0%A1%D0%BE%D1%80%D1%82%D0%B8%D1%80%D0%BE%D0%B2%D0%BA%D0%B0%20%D0%B2%D1%8B%D0%B1%D0%BE%D1%80%D0%BE%D0%BC/%D0%A1%D0%BE%D1%80%D1%82%D0%B8%D1%80%D0%BE%D0%B2%D0%BA%D0%B0%20%D0%B2%D1%8B%D0%B1%D0%BE%D1%80%D0%BE%D0%BC.cpp)
## Сортировка пузырьком.
Представляет собой сортировку, которая осуществляется путём перестановки соседних элементов в порядке возрастания/убывания. Не очень эффективных алгоритм, поэтому его используют лишь в образовательных целях и не рекомендуют использовать в реальных проектах.
Сложность: O(N^2).

![596b722779f8b_Yb6G53y](https://github.com/user-attachments/assets/a91fce78-c3a0-4464-93be-83ca035b1935)

[Реализация на C++](https://github.com/k0swel/types-of-sorting/blob/sort/%D0%9F%D1%83%D0%B7%D1%8B%D1%80%D1%8C%D0%BA%D0%BE%D0%B2%D1%8B%D0%B9%20%D0%B0%D0%BB%D0%B3%D0%BE%D1%80%D0%B8%D1%82%D0%BC/bubble_sort.cpp)
```
#define INCREASE > // сортировка по возрастанию
#define DECREASE < // сортировка по убыванию

void bubble_sort(std::vector<int>& massiv) {
    for (int i = 0; i < massiv.size() - 1; i++) {
        for (int j = 0; j < massiv.size() - 1 - i; j++) {
            if (massiv[j] INCREASE massiv[j + 1]) {
                int temp = massiv[j];
                massiv[j] = massiv[j + 1];
                massiv[j + 1] = temp;
            }
        }
    }
}
```

## Сортировка выбором.
_Сортировка выбором_ представляет собой вид сортировки, за счёт которого алгоритм ВЫБИРАЕТ элемент массива, который нужно разместить в конец отсортированного части.
Иллюстрация ниже демонстрирует выбор минимальногого неотсортированного элемента. Сложность: O(N^2).


![selection-600](https://github.com/user-attachments/assets/99ccc41e-ad1f-43e1-9523-1c327767786d)

[Реализация на C++](https://github.com/k0swel/algorithms/blob/sort/%D0%A1%D0%BE%D1%80%D1%82%D0%B8%D1%80%D0%BE%D0%B2%D0%BA%D0%B0%20%D0%B2%D1%8B%D0%B1%D0%BE%D1%80%D0%BE%D0%BC/%D0%A1%D0%BE%D1%80%D1%82%D0%B8%D1%80%D0%BE%D0%B2%D0%BA%D0%B0%20%D0%B2%D1%8B%D0%B1%D0%BE%D1%80%D0%BE%D0%BC.cpp)
```
    for (int first_iterator = 0; first_iterator < massiv.size(); first_iterator++) {
        int min_index = first_iterator;
        for (int i = first_iterator; i < massiv.size(); i++) {
            if (massiv[i] < massiv[min_index])
                min_index = i;
        }
        if (first_iterator != min_index) {
            int temp = massiv[first_iterator];
            massiv[first_iterator] = massiv[min_index];
            massiv[min_index] = temp;
        }
    }
```



