//
// Created by Eliott GERMAIN on 29/12/2021.
//

#ifndef SUBVIEW_LIST_H
#define SUBVIEW_LIST_H
#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include <stdbool.h>


///----------------------  WIP PART ---------------------///
/*
    This part of the code in not used in the program yet.
    Coming features :

    - change stations
    - display all the stations on a line
    - selection of a line and a station
    - sign in and login options
    - keep in a favorite section lines and stations you use the most

    Coming soon...
 */


///---------------------- STRUCT ----------------------///

typedef struct node {       // elements of the struct will be the different stations
    station _station;
    struct node * nextNode;

}node;

typedef struct list {       // list of stations
    node *first;
}list;

///-------------------- PROTOTYPES --------------------///

list *listInitialisation();
int listLength(list *);
void startInsertion(list *, station);
void listDisplay(list *);
bool isEmpty(list *);

///--------------------- FUNCTIONS --------------------///

list *listInitialisation(){
    list *_list = malloc(sizeof(*_list));
    node *_node = malloc(sizeof(*_node));

    if (_list == NULL || _node == NULL ){
        EXIT_FAILURE;
    }

    //_node->_station;
    _node->nextNode = NULL;
    _list->first = _node;

    return _list;
}

/// ----------------------------------------------------- ///

bool isEmpty(list *_list){
    if(_list->first == NULL)
        return true;
    return false;
}

/// ----------------------------------------------------- ///

int listLength(list *_list){
    int size = 0;
    if(!isEmpty(_list)){
        while(_list->first != NULL){
            ++size;
            _list->first = _list->first->nextNode;
        }
    }
    return size;
}

/// ----------------------------------------------------- ///


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

/// ----------------------------------------------------- ///

void listDisplay(list * _list){
    if(isEmpty(_list)){
        printf("nothing to display, th e list is empty");
        return;
    }

    node * current = _list->first;

    while(current != NULL){
        printf("%s\n" , current->_station.stationName);
        current = current->nextNode;
    }
}

#endif //SUBVIEW_LIST_H
