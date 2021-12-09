#include <iostream>
#include <vector>

void swap(int a, int b){
    int temp;
    temp = a;
    a = b;
    b = a;
}

void Merge(int* arr, int left, int right, int middle ){
    if (left >= right || middle < left || middle > right) return;
/*    if (right == left + 1 && arr[left] > arr[right]){
        swap(arr[left], arr[right]);
        return;
    }*/
    int tempSize = right - left + 1;
    int* temp = new int [tempSize];

    for (int i = left, j = 0, k = middle + 1; j < tempSize  ; ++j) {
        if (i > middle ) temp[j] = arr[k++];
        else if (k > right) temp[j] = arr[i++];
        else if (arr[i] < arr[k]) temp[j] = arr[i++];
        else temp[j] = arr[k++];
    }
    for (int i = left, j = 0; i <= right ; ++i, ++j) {
        arr[i] = temp[j];
    }
    delete[] temp;
    return;
}

void MergeSort(int* arr, int left, int right ){
    if (left >= right) return;
    int middle = left + (right - left ) / 2;
    MergeSort(arr, left, middle);
    MergeSort(arr, middle+1, right);
    Merge(arr,left,right,middle);
}



int main()
{
    int size = 10;
    int* array = new int [size];
    for (int i = size ; i > -1; --i) {
        array[i] = size-i;
    }
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << std::endl;
    }
    std::cout << std::endl;
    MergeSort(array,0,size-1);

    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << std::endl;
    }

}
