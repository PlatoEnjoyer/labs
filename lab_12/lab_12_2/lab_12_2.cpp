#include <iostream>


void quickSort(int arr[], int left, int right)
{
    if (left > right)
    {
        return;
    }
    
    int p = arr[(left + right)/2];
    int i = left;
    int j = right;

    while (i <= j)
    {
        while (arr[i] < p)
        {
            i++;
        }

        while (arr[j] > p)
        {
            j--;
        }

        if (i <= j)
        {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }
    quickSort(arr, left, j);
    quickSort(arr, i, right);
}


int main()
{
    int arr[7] = {7, -12, 4, 18 , 22, 777, -1};

    quickSort(arr, 0, 6);

    for (int i = 0; i < 7; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}