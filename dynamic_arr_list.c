#include <stdio.h>
#include <stdlib.h>

struct list {
    int* data;
    int capacity;
    int length;
};

void list_init(struct list* lst, int capacity) {
    lst->data = malloc(sizeof(int) * capacity);
    lst->capacity = capacity;
    lst->length = 0;
}

void list_append(struct list* lst, int value) {
    if (lst->length >= lst->capacity) {
        lst->capacity *= 2;
        lst->data = realloc(lst->data, sizeof(int) * lst->capacity);
    }
    lst->data[lst->length] = value;
    lst->length++;
}

int main() {
    struct list lst;
    list_init(&lst, 10);
    list_append(&lst, 5);
    list_append(&lst, 10);
    return 0;
}
//dynamic_array for char:
#include<stdio.h>
#include<stdlib.h>
struct list
{
    char*arr;
    int len;
    int allocated;
};
void append(struct list *A,char elem){
    if(A->len==A->allocated){
        A->allocated*=2;
          char*newarr=(char*)malloc(sizeof(char)*(A->allocated));
          for(int i=0;i<A->len;i++){
            newarr[i]=A->arr[i];
          }
          free(A->arr);
          A->arr=newarr;
    }
    A->arr[A->len]=elem;
    A->len+=1;
}

int main(){
    struct list A;
    A.len=0;
    A.allocated=1;
    A.arr=(char*)malloc(sizeof(char)*A.allocated);
    append(&A,'M');
    append(&A,'A');
    append(&A,'R');
    append(&A,'W');
    append(&A,'A');
    for(int i=0;i<A.len;i++){
        printf("%c",A.arr[i]);
    }
    free(A.arr);
    return 0;
}
