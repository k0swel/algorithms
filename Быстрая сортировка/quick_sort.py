
# Реализация quick sort на Python.
#   Partition работает по следующему принципу:
#     элементы до i(включая) являются меньше или равен pivot, а элементы после i (не включая) являются больше pivot

def quick_sort(massiv: list, low = 0, high = None):
    if high is None:
        high = len(massiv) - 1
    if low < high:
        pi = partition(massiv, low, high)
        quick_sort(massiv, 0, pi-1)
        quick_sort(massiv, pi+1, high)


def partition(massiv: list, low: int = 0, high: int = None):
    i: int = low
    for j in range(low, high):
        if massiv[j] <= massiv[high]:
            massiv[i], massiv[j] = massiv[j], massiv[i]
            i+=1
    massiv[i], massiv[high] = massiv[high], massiv[i]
    return i
