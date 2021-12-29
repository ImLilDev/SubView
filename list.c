//
// Created by Eliott GERMAIN on 29/12/2021.
//
#include "list.h"

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
