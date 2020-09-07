#ifndef MY_SORTING_H
#define MY_SORTING_H

#include "mylist.h"
#include <string>

using namespace std;

template <class T>
void mySort(T &array){
    int l = size(array);
    int pom, j;
    for(int i=1; i<l; i++){
        pom = array[i];
        j = i-1;
        while(j>=0 && array[j]>pom){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = pom;
    }
}

template <size_t w, size_t l>
void mySort(char(&array)[w][l]){
    char s1[l], s2[l];
    for(int i=0; i<w; i++){
        for(int j=0; j<w-1; j++){
            strcpy(s2, array[j+1]);
            strcpy(s1, array[j]);
            for(int k=0; k<l; k++){
                s2[k] = toupper(s2[k]);
                s1[k] = toupper(s1[k]);
            }
            if(strcmp(s1,s2)>0){
                strcpy(s1, array[j]);
                strcpy(array[j], array[j+1]);
                strcpy(array[j+1], s1);
            }
        }
    }
}

#endif // MY_SORTING_H