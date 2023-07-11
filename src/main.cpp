#include <iostream>
#include <time.h>

const int ARRAY_SIZE = 10;
const int MAX_NUM = 99;

void InitArray(int *array);
void InsertionSort(int *array);

int main()
{
    int array[ARRAY_SIZE];

    InitArray(array);
    InsertionSort(array);

    return 0;
}

void PrintArray(int array[])
{
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        std::cout << array[i] << ", ";
    }

    std::cout << std::endl;
}

void InitArray(int *array)
{
    srand((unsigned int)time(NULL));

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        array[i] = rand() % MAX_NUM + 1;
    }

    std::cout << "初期値" << std::endl;
    PrintArray(array);
}

void Swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void InsertionSort(int *array)
{
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        int j = i;

        while (j > 0 && array[j] < array[j - 1])
        {
            Swap(&array[j], &array[j - 1]);
            j--;
        }

        std::cout << i + 1 << "回目のソート" << std::endl;
        PrintArray(array);
    }
}