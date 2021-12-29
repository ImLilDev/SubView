//
// Created by Eliott GERMAIN on 29/12/2021.
//

#ifndef SUBVIEW_LIST_H
#define SUBVIEW_LIST_H
#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

typedef struct node {       // elements of the struct will be different stations
    station _station;
    struct node * nextNode;

}node;

typedef struct list {       // list of stations
    node *first;
}list;

list *listInitialisation(){
    list *_list = malloc(sizeof(*_list));
    node *_node = malloc(sizeof(*_node));

    if (_list == NULL || _node == NULL ){
        EXIT_FAILURE;
    }

    _node->_station;            // trouver le bon truc a initialiser, pour l'instant ????
    _node->nextNode = NULL;
    _list->first = _node;

    return _list;
}

void startInsertion(list *_list, station _inputStation){
    // new station creation //
    node *newStation = malloc(sizeof(*newStation));
    if(_list == NULL || newStation == NULL){
        EXIT_FAILURE;
    }
    newStation->_station = _inputStation;

    // new station insertion //
    newStation->nextNode = _list->first;
    _list->first = newStation;

}

void listDisplay(list *_list){
    if(_list == NULL){
        EXIT_FAILURE;
    }

    node * current = _list->first;

    while(current != NULL){
        printf("%s\n" , current->_station.stationName);
        current = current->nextNode;
    }
}

#endif //SUBVIEW_LIST_H
