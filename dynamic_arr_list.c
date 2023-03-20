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
