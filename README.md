# Алгоритмы
* [Алгоритм Евклида](https://github.com/k0swel/algorithms/tree/algorithms?tab=readme-ov-file#алгоритм-евклида)
* [Добавление приложений в реестр автозагрузки](https://github.com/k0swel/algorithms/tree/algorithms?tab=readme-ov-file#добавление-приложений-в-реестр-автозагрузки)
## Алгоритм Евклида
Представляет собой эффективный способ нахождения Наибольшего общего делителя двух чисел.   
Реализация: [\*клик\*](https://github.com/k0swel/algorithms/tree/algorithms/algorithm_evklid)

Иллюстрация, демонстрирующая этот алгоритм:

![gcd1_ru](https://github.com/user-attachments/assets/dca2e1b0-0236-46d1-a24f-81e3eb1587e7)

Реализация алгоритма Евклида на C++. (где a - наибольшее число, b - меньшее число):

[_Рекурсивная функция_](https://github.com/k0swel/types-of-sorting/blob/algorithms/algorithm_evklid/evklid_recusive.cpp)
```cpp
int evklid(int a, int b) {
    if (b == 0) return a;
    else evklid(b, a % b);
}
```

[__Обычная функция__](https://github.com/k0swel/types-of-sorting/blob/algorithms/algorithm_evklid/evklid_usual_func.cpp)
```cpp
int evklid(int a, int b) {
    while (b != 0) {
        int temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}
```

## Добавление приложений в реестр автозагрузки
Консольное приложение со следующим функционалом:
1) Добавление записей в ключ реестра, отвечающий за автозагрузку приложений.
2) Удаление записей из ключа реестра, который отвечает за автозагрузку приложений.
   
Реализация: [\*клик\*](https://github.com/k0swel/algorithms/tree/algorithms/Добавление%20и%20удаление%20записей%20с%20реестра%20Windows)

Зависимости:
```cpp
#include <windows.h>
#include <winreg.h>
```
Поскольку в качестве начального ключа в .cpp введен ```HKEY_LOCAL_MACHINE```, то программа требует права администратора (автозагрузка применяется для всех учётных записей Windows). Если требуется включить автозагрузку для текущего пользователя, то нужно добавить запись в ключ ```HKEY_CURRENT_USER```.

Для этого нужно заменить ```HKEY_LOCAL_MACHINE``` на ```HKEY_CURRENT_USER```.
