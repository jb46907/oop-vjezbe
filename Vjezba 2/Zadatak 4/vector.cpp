#include "vector.hpp"

void MyVector::vector_new()
{
    //alokacija niza
    if (capacity == 0) {
        capacity = 1;
        arr = new int[capacity + 1];//doda +1 zbog ^z
    }
    else {

        capacity *= 2;
        int* novi = new int[capacity];

        for (int i = 0; i < capacity; i++) {
            novi[i] = arr[i];
        }

        arr = new int[capacity + 1];

        for (int i = 0; i < capacity; i++) {
            arr[i] = novi[i];
        }
        delete[] novi;
    }

}
void MyVector::vector_delete()
{
    delete[] arr;
}
void MyVector::vector_push_back(int n)
{
    if (size == capacity) {
        arr[size] = n;
        size++;
        vector_new();
    }
    else {
        arr[size] = n;
        size++;
    }
}
void MyVector::vector_pop_back()
{

    arr[size] = 0;
    if (arr[0] > 0) {
        size--;
    }
    //size--;
}
int& MyVector::vector_front()
{
    //if (arr[0] == 0) {
    //    return arL;
    //}
    return arr[0];
}
int& MyVector::vector_back()
{
    if (size <= 2) {
        return arr[size - 1];
    }
    return arr[size - 2];
}
int MyVector::vector_size()
{
    return size;
}


void MyVector::print_vector()
{
    for (int i = 0; i < vector_size(); ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}