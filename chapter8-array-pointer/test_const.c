#include <stdio.h>

int sum(const int arr[], int size)
{
    int total = 0;
    for (int i = 0; i < size; i++)
    {
        total += arr[i];
        // arr[i] = 1;
    }

    return total;
}

int main(int argc, char const *argv[])
{
    // double rates[5] = {88.99, 100.12, 59.45, 183.11, 340.5};
    // const double *pd = rates; // pd points to beginning of the array

    // double rates[5] = {88.99, 100.12, 59.45, 183.11, 340.5};
    // const double locked[4] = {0.08, 0.075, 0.0725, 0.07};
    // double * pnc = rates; // valid
    // pnc = locked; // not valid
    // pnc = &rates[3]; // valid


    double rates[5] = {88.99, 100.12, 59.45, 183.11, 340.5};
    double * const pc = &rates[1]; // pc points to beginning of the array
    // pc = rates; // not allowed to point elsewhere
    *pc = 92.99; // ok -- changes rates[0]
    return 0;   
}
