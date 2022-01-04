//
// Created by Eliott GERMAIN on 29/12/2021.
//

#ifndef SUBVIEW_LIST_H
#define SUBVIEW_LIST_H
#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

typedef enum{
   false,
   true
}bool;

typedef struct node {       // elements of the struct will be the different stations
    station _station;
    struct node * nextNode;

}node;

typedef struct list {       // list of stations
    node *first;
}list;

 /// prototypes

list *listInitialisation();
int listLength(list *_list );
void startInsertion(list *_list, station _inputStation);
void listDisplay(list *_list);
bool isEmpty(list *_list);


#endif //SUBVIEW_LIST_H
