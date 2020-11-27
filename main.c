#include <stdio.h>
#include <stdlib.h>
#define SIZE 30

// Функция быстрой сортировки
void quickSort(int *elements, int left, int right)
{
  int pivot; // разрешающий элемент
  int lHold = left; //левая граница
  int rHold = right; // правая граница
  pivot = elements[left];
  while (left < right) // пока границы не сомкнутся
  {
    while ((elements[right] >= pivot) && (left < right)) {
        right--; // сдвигаем правую границу пока элемент [right] больше [pivot]
    }
    if (left != right) // если границы не сомкнулись
    {
      elements[left] = elements[right]; // перемещаем элемент [right] на место разрешающего
      left++; // сдвигаем левую границу вправо 
    }
    while ((elements[left] <= pivot) && (left < right))
      left++; // сдвигаем левую границу пока элемент [left] меньше [pivot]
    if (left != right) // если границы не сомкнулись
    {
      elements[right] = elements[left]; // перемещаем элемент [left] на место [right]
      right--; // сдвигаем правую границу вправо 
    }
  }
  elements[left] = pivot; // ставим разрешающий элемент на место
  pivot = left;
  left = lHold;
  right = rHold;
  if (left < pivot) // Рекурсивно вызываем сортировку для левой и правой части массива
    quickSort(elements, left, pivot - 1);
  if (right > pivot)
    quickSort(elements, pivot + 1, right);
}
int main()
{
  int a[SIZE];
  // Заполнение массива случайными числами
  for (int i = 0; i<SIZE; i++)
    a[i] = rand() % 201 - 100;
  // Вывод элементов массива до сортировки
  for (int i = 0; i<SIZE; i++)
    printf("%4d ", a[i]);
  printf("\n");
  quickSort(a, 0, SIZE - 1); // вызов функции сортировки
            // Вывод элементов массива после сортировки
  for (int i = 0; i < SIZE; i++)
    printf("%4d ", a[i]);
  printf("\n");
  getchar();
  return 0;
}