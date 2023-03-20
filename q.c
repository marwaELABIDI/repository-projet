queue.c
#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int len;
    int mal;
    int start_index;
    int empty;
    int *arr;
}queue;

void *push(queue *my_arr, int elem)
{
    if (my_arr->len >= my_arr->mal)
    {
        int new_mal = my_arr->mal * 2;
        int *new_arr =(int *) malloc(new_mal * sizeof(int));
        for (int i = 0; i < my_arr->len; i++)
        {
            new_arr[(new_mal - 1) - i] = my_arr->arr[(my_arr->mal - 1) - i];
        }
        free(my_arr->arr);
        my_arr->mal = new_mal;
        my_arr->arr = new_arr;
    }
    my_arr->len++;
    my_arr->start_index = my_arr->mal - my_arr->len;
    my_arr->arr[my_arr->start_index] = elem;
}

void *pop(queue *my_arr)
{
    if (my_arr->len != 0)
    {
        my_arr->len--;
        if (my_arr->mal - my_arr->len >= my_arr->empty)
        {
            my_arr->empty *= 2;
            int new_mal = my_arr->len;
            int *new_arr = (int *) malloc(new_mal * sizeof(int));
            for (int i = 0; i < my_arr->len; i++)
            {
                new_arr[i] = my_arr->arr[my_arr->start_index + i];
            }
            free(my_arr->arr);
            my_arr->mal = new_mal;
            my_arr->arr = new_arr;
            my_arr->start_index = my_arr->mal - my_arr->len;
        }
    }
}

int peak(queue *my_arr)
{
    int elem = my_arr->arr[my_arr->start_index];
    return elem;
}

int main()
{

    queue array = { 7, 8, array.mal - array.len, 1, (int *) malloc(array.mal * sizeof(int))};

    for (int i = 0; i<array.len; i++)
    {
        array.arr[array.start_index + i] = i;
    }
    
    push(&array, 5);
    for (int i = 0; i<array.len; i++)
    {
        printf("%d\n", array.arr[array.start_index + i]);
    }
    printf("Stop\n\n");

    pop(&array);
    for (int i = 0; i<array.len; i++)
    {
        printf("%d\n", array.arr[array.start_index + i]);
    }
    printf("Stop\n\n");


    push(&array, 254);
    for (int i = 0; i<array.len; i++)
    {
        printf("%d\n", array.arr[array.start_index + i]);
    }
    printf("Stop\n\n");
    return 0;
}

queue_char.c
#include <stdio.h>
#include <stdlib.h>
struct queue
{
    char *arr;
    int len;
    int space;
}
queue;
void push(struct queue* vect,char k){
    if (vect->space == 0){
            vect->arr = (char*)malloc((2)*sizeof(char));
            vect->space += 2;
            vect->len++;
        }
    if (vect->space != vect->len){
        vect->arr[vect->len-1] = k;
        vect->arr[vect->len] = '\0';
        vect->len++;
    }
    else {
        char* arr;
        arr = (char*) malloc((vect->space*2) * sizeof(char));
        for (int i = 0; i < vect->len-1; i++){
            arr[i] = vect->arr[i];
        }
        arr[vect->len-1] = k;
        arr[vect->len] = '\0';
        vect->len++;
        free(vect->arr);
        vect->space = vect->space*2;
        vect->arr = arr;
    }
}
void pop (struct queue* vect){
    char* arr;
    arr = (char*) malloc((vect->space) * sizeof(char));
    for (int i = 0; i < vect->len-1; i++){
        arr[i] = vect->arr[i+1];
    }
    vect->len--;
    free(vect->arr);
    vect->arr = arr;
}
char peak(struct queue *vect){
    return vect->arr[0];
}
