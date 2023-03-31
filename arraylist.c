#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "arraylist.h"

//normal array
typedef struct ArrayList {
    void **data;
    int capacity;
    int size;
} ArrayList;

ArrayList *createList(void) {
  ArrayList *list = (ArrayList*) malloc(sizeof(ArrayList));
  if (list == NULL) return NULL;

  list->data = (void**) malloc(sizeof(void*));
  if (list->data == NULL){
    free(list);
    return NULL;
  }
  list->capacity = 2;
  list->size = 0;
  return list;
}

void append(ArrayList * list, void * data){
  if (list->size == list->capacity){
    list->data = (void**)realloc(list->data, (list->capacity * (sizeof(void*))));
    
    if (list->data == NULL)return;
    list->capacity *= 2;
  }
  
  list->data[list->size] = data;
  list->size++;
}


void push(ArrayList * list, void * data, int i){
  if (list->size == list->capacity){
    list->data = (void**)realloc(list->data, (2 * list->capacity) * sizeof(void*));
      if (list->data == NULL) return;
    list->capacity *= 2;
  }
  void *aux = data;
  list->data[list->size] = aux;
  list->size++;
}

void* pop(ArrayList * list, int i){
    return NULL;
}

void* get(ArrayList * list, int i){
    return NULL;
}

int get_size(ArrayList * list){
    return list->size;
}

//remove elements
void clean(ArrayList * list){
    
}
