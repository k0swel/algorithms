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
