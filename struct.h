//
// Created by Eliott GERMAIN on 29/12/2021.
//

#ifndef SUBVIEW_STRUCT_H
#define SUBVIEW_STRUCT_H
#include <stdio.h>
#include <stdlib.h>

///----------------- STRUCT -------------------///

typedef struct station {
    char stationName[255];
    int timeNextTrain1;
    int timeNextTrain2;
    int timeNextTrain3;
    int timeNextTrain4;
    int metroNumber;
    const char * destination;
    char direction[2];
} station;

typedef struct line {       /// WIP
    int lineNumber;

}line;

typedef struct User {       /// WIP
    char userName[255];
    char userPassword[255];

}User;

#endif //SUBVIEW_STRUCT_H
