#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
    List * new = (List *)malloc(sizeof(List));
    assert(new != NULL);
    new->head = NULL;
    new->tail = NULL;
    new->current = NULL;
     return new;
}

void * firstList(List * list) {
  if (list == NULL){
    return NULL;
  }
  if (list->head == NULL){
    return NULL;
  }
  list->current = list->head;
  return list->head->data;
}

void * nextList(List * list) {
  if (list == NULL){
    return NULL;
  }
  if (list->current == NULL){
    return NULL;
  }
  if (list->current->next == NULL){
    return NULL;
  }
  list->current = list->current->next;
  return list->current->data;
}

void * lastList(List * list) {
  if (list == NULL){
    return NULL;
  }
  if (list->tail == NULL){
    return NULL;
  }
  list->current = list->tail;
  return list->tail->data;
}

void * prevList(List * list) {
  if (list == NULL){
    return NULL;
  }
  if (list->current == NULL){
    return NULL;
  }
  if (list->current->prev == NULL){
    return NULL;
  }
  list->current = list->current->prev;
  return list->current->data;
}

void pushFront(List * list, void * data) {
  if (list == NULL){
    return;
  }
  Node * new = createNode(data);
  if (list->head == NULL){
    list->head = new;
    list->tail = new;
  }
  else{
    new->next = list->head;
    list->head->prev = new;
    list->head = new;
  }
}


void pushBack(List * list, void * data) {
  if (list == NULL){
    return;
  }
  Node * new = createNode(data);
  if (list->tail == NULL){
    list->head = new;
    list->tail = new;
  }
  else{
    new->prev = list->tail;
    list->tail->next = new;
    list->tail = new;
  }
}
  

void pushCurrent(List * list, void * data) {
  if (list == NULL){
    return;
  }
  if (list->current == NULL){
    return;
  }
  Node * new = createNode(data);
  new->next = list->current->next;
  new->prev = list->current;
  list->current->next = new;
  if (new->next != NULL){
    new->next->prev = new;
  }
  else{
    list->tail = new;
  }
}



void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}