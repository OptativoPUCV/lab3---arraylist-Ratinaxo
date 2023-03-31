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
  if (i >= list->size) return;
  if (list->size == list->capacity){
    list->data = (void**)realloc(list->data, (2 * list->capacity) * sizeof(void*));
    if(list->data == NULL) return;
    list->capacity *= 2;
  }
  for (int j = list->size - 1; j >=i; j--)
    list->data[j+1] = list->data[j];
  list->data[i] = data;
  list->size++;
}

void* pop(ArrayList * list, int i){
  int aux = i;
  if (i < 0)
    aux = abs(i)-1;
  if (i >= list->size || i < 0)return NULL;
  
  void *dato = list->data[aux];
  for (int j = aux; j < list->size - 1; j++)
    list->data[j] = list->data[j+1];
  list->size = list->size - 1;
  return dato;
}

void* get(ArrayList * list, int i){
  //if (i >= list->size || i < -list->size)return NULL;
  if (i < 0)
    i = list->size + i;
  return list->data[i];
}

int get_size(ArrayList * list){
    return list->size;
}

//remove elements
void clean(ArrayList * list){
    
}
