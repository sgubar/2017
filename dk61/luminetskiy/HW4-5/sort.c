#include "sort.h"
#include <stdbool.h>
#include "circling.h"

void swap (circle *a, circle *s)
{
    circle tmp = *a;
    *a = *s;
    *s = tmp;
}
void bubble(circle array[], int size)
{
    int pointer = false;
    do {
        pointer = 0;
        for (int i = 0; i < size-1; i++) {
            if (array[i+1].square < array[i].square) {
                swap(&array[i], &array[i + 1]);
                pointer = true;
            }
        }
    }while(!pointer);

}
void shell(circle array[],int size)
{
    for (int step = size/2; step > 0; step /= 2){
        for (int i = step; i < size; ++i) {
            for (int j = i-step; j >= 0 && array[j].square > array[j+step].square; j -=step)
                swap(&array[j],&array[j+step]);
        }
    }
}
int linear(circle* array,int size, double d)
{
    for (int i = 0; i < size; i++){
        if(array[i].square == d){
            return i+1;
        }
    }
    return  -1; //in case if array (arr) doesn't have value of k
}
