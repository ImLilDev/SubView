//
// Created by Eliott GERMAIN on 29/12/2021.
//

#ifndef SUBVIEW_STRUCT_H
#define SUBVIEW_STRUCT_H
#include <stdio.h>
#include <stdlib.h>

typedef struct station {
    char stationName[255];
} station;

typedef struct line {
    int lineNumber;

}line;

typedef struct User {
    char userName[255];
    char userPassword[255];

}User;



#endif //SUBVIEW_STRUCT_H
