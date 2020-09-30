#include<bits/stdc++.h>

int* mergeSort(int a[], int b[], int size_a, int size_b)
{
    int i=0, j=0, k=0, *arr;
    arr = new int[size_a + size_b];

    if(size_a == 0)
    {
        return b;
    }
    else if(size_b == 0)
    {
        return a;
    }
    else
    {
        while(i < size_a || j < size_b)
        {
            if(j > size_b || a[i] <= b[j])
                *(arr + (k++)) = a[i++];
            else
                *(arr + (k++)) = b[j++];
        }

        return arr;
    }

}

int main()
{
    int arr1[]={1,3,5,7,9},
        arr2[]={2,4,4,8,10},
        *mrg, sizeArr1 = 5, sizeArr2 = 5;

    mrg = mergeSort(arr1,arr2,sizeArr1,sizeArr2);

    for(int i = 0; i < (sizeArr1 + sizeArr2); i++)
    {
        std::cout<< *(mrg + i) <<' ';
    }
    return 0;

}
