# Виды сортировок массивов

- [_Сортировка пузырьком;_](https://github.com/k0swel/types-of-sorting/tree/sort?tab=readme-ov-file#%D1%81%D0%BE%D1%80%D1%82%D0%B8%D1%80%D0%BE%D0%B2%D0%BA%D0%B0-%D0%BF%D1%83%D0%B7%D1%8B%D1%80%D1%8C%D0%BA%D0%BE%D0%BC)
- [_Сортировка выбором;_](https://github.com/k0swel/algorithms/blob/sort/%D0%A1%D0%BE%D1%80%D1%82%D0%B8%D1%80%D0%BE%D0%B2%D0%BA%D0%B0%20%D0%B2%D1%8B%D0%B1%D0%BE%D1%80%D0%BE%D0%BC/%D0%A1%D0%BE%D1%80%D1%82%D0%B8%D1%80%D0%BE%D0%B2%D0%BA%D0%B0%20%D0%B2%D1%8B%D0%B1%D0%BE%D1%80%D0%BE%D0%BC.cpp)
- [_Быстрая сортировка_](https://github.com/k0swel/algorithms/blob/sort/README.md#%D0%B1%D1%8B%D1%81%D1%82%D1%80%D0%B0%D1%8F-%D1%81%D0%BE%D1%80%D1%82%D0%B8%D1%80%D0%BE%D0%B2%D0%BA%D0%B0)

## Сортировка пузырьком.

Представляет собой сортировку, которая осуществляется путём перестановки соседних элементов в порядке возрастания/убывания. Не очень эффективных алгоритм, поэтому его используют лишь в образовательных целях и не рекомендуют использовать в реальных проектах.
Сложность: O(N^2).

![596b722779f8b_Yb6G53y](https://github.com/user-attachments/assets/a91fce78-c3a0-4464-93be-83ca035b1935)

[Реализация на C++](https://github.com/k0swel/types-of-sorting/blob/sort/%D0%9F%D1%83%D0%B7%D1%8B%D1%80%D1%8C%D0%BA%D0%BE%D0%B2%D1%8B%D0%B9%20%D0%B0%D0%BB%D0%B3%D0%BE%D1%80%D0%B8%D1%82%D0%BC/bubble_sort.cpp)

```C++
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

```C++
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

## Быстрая сортировка.

_Быстрая сортировка_ - это метод сортировки массивов, разработанный программистом Хоаром. Средняя сложность алгоритма: O (log n). Алгоритм включает в себя следующую логику:

1. Выбирается опорный элемент. Относительно которого будут сортироваться другие элементы массива (в качестве опорного элемента стоит выбрать последний элемент массива).
2. Объявляем переменную Wall. Значение переменной будет указывать на границу "стены", где лежит последний отсортированный элемент относительно опорного элемента.
3. Проходимся по всем элементам массива кроме опорного (последнего элемента). Если указатель на текущий элемент <= последнему элементу стены (massiv[Wall]), то меняем местами эти два элемента и расширяем стену на единицу (Wal++).
4. Когда мы добираемся до последнего элемента(опорного), то просто меняем местами опорный элемент и последний элемент стены (massiv[wall))
5. Рекурсивно повторяем функцию для двух половин:
   - от 0 до Wall -1;
   - от Wall + 1 до конца.

> _В пятом пункте мы не указывем индекс Wall в массив, поскольку он уже лежит на своей правильной позиции(ВСЕ элементы меньше или равные его расположены слева; ВСЕ элементы больше его расположены справа)_

[Реализация алгоритма на языке программирования C++](https://github.com/k0swel/algorithms/blob/sort/%D0%91%D1%8B%D1%81%D1%82%D1%80%D0%B0%D1%8F%20%D1%81%D0%BE%D1%80%D1%82%D0%B8%D1%80%D0%BE%D0%B2%D0%BA%D0%B0/quick%20sort.cpp)

```C++
#define INCREASING <= // сортировка по возрастанию
#define DESCREASING >= // сортировка по убыванию
void quick_sort(std::vector<int>& massiv, int left, int right) {
    if (left > right) return;
    int wall = left; // создаём левую стену, где последний элемент стены - самый первый элемент массива.
    int pivot_index = right; // создаём индекс элемент, относительно которого мы будем сортировать числа
    int pivot_value = massiv[pivot_index]; // создаём элемент, относительно которого мы будем сортировать.
    int current_pos = left; // указываем текущую позицию указателя.

    for (; current_pos < right; current_pos++) {
        if (massiv[current_pos] INCREASING pivot_value) { // если значение указателя меньше значения pivot'a
            std::swap(massiv[current_pos], massiv[wall]); // то мы меняем местами последний элемент стены (wall) и элемент указателя.
            wall++; // достраиваем стену
        }
    }
    // все элементы, которые меньше или равны опорному элементу, расположены в стене, а которые больше - за пределами стены
    std::swap(massiv[wall], massiv[pivot_index]); // т.к элементы меньше опорного расположены в стене, то мы меняем местами элемент конца стены и опорный элемент
    quick_sort(massiv, left, wall - 1); // в параметры не включаем конец стены, потому что он уже расположен в правильной позиции
    quick_sort(massiv, wall + 1, right); // (ВСЕ элементы слева <= опорному, ВСЕ элементы справа > опорного)

}
```

[_Видео, иллюстрирующее алгоритм быстрой сортировки_](https://www.youtube.com/watch?v=4s-aG6yGGLU&t=166s) ![youtube16](https://github.com/user-attachments/assets/20421170-866c-4ca2-8c20-2692c2c01787)

## Сортировка вставками

_Сортировка вставками_ - метод сортировки массивов (в лучшем случае O(n), в худшем О($n^2$)). Алгоритм работает по следующей логике:

1. Начинаем цикл с первого индекса;
2. В качестве ключевого элемента выбираем первый элемент в неотсортированной части массива.
3. Создаём вложенный цикл `while`, где смещаем текущий выбранный элемент массива вправо на единицу от текущей позиции и позицию уменьшаем на единицу в сторону начала массива (в случае если позиция >= 0 и ключевой элемент <= текущему элементу массива).
4. После выхода из вложенного цикла `while` увеличиваем текущую позицию на единицу и туда вставляем ключевой элемент (нужно чтобы не потерять ключевой элемент, поскольку его место занял другой элемент массива).

Реализация сортировки вставками на примере языка `C++`:

```c++
template <typename T>
std::vector<T> insertion_sort(std::initializer_list<T> list) {
	std::vector<T> vec = list;
	for (int index = 1; index < vec.size(); index++) {
		int index_for_while = index;
		int key = vec[index_for_while--];
		while (index_for_while >= 0 and key <= vec[index_for_while]) {
			vec[index_for_while + 1] = vec[index_for_while];
			index_for_while--;
		}
		vec[index_for_while + 1] = key;
	}
	return vec;
}
```

![gif сортировка вставками](https://upload.wikimedia.org/wikipedia/commons/0/0f/Insertion-sort-example-300px.gif)  
[_Видео, иллюстрирующее алгоритм сортировки вставками_](https://www.youtube.com/watch?v=SIrdTFF8-4s&t=182s) ![youtube16](https://github.com/user-attachments/assets/20421170-866c-4ca2-8c20-2692c2c01787)
