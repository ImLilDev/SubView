//
// Created by Eliott GERMAIN on 29/12/2021.
//
#ifndef SUBVIEW_STRUCT_H
#define SUBVIEW_STRUCT_H
#include <stdio.h>
#include <stdlib.h>
#include <json-c/json.h>

typedef struct station {
    char stationName[255];
    int timeNextTrain1;
    int timeNextTrain2;
    int timeNextTrain3;
    int timeNextTrain4;
    int metroNumber;
    const char * destination;
    char direction[1];
} station;

typedef struct line {
    int lineNumber;

}line;

typedef struct User {
    char userName[255];
    char userPassword[255];

}User;


void formatFile(char *file){
    FILE *fp = fopen(file , "r+");
    FILE *cp = fopen("tmp.json", "w+");
    int cond = 0;
    while(feof(fp) == 0)
    {
        while(cond != 1){
            if(fgetc(fp) == '['){
                cond = 1;
            }
        }
        fputc(fgetc(fp),cp);
    }
    fclose(fp);
    fclose(cp);

    FILE * fp1 = fopen(file , "w+");
    FILE * cp1 = fopen("tmp.json", "r");
    while(feof(cp1) == 0)
    {
        fputc(fgetc(cp1),fp1);
    }

    fclose(fp1);
    fclose(cp1);
}

void suppr(char *file){

    int cpt = 0;
    FILE *fp = fopen(file , "r");
    FILE *cp = fopen("tmp.json", "w+");
    int cond = 0;
    while(feof(fp) == 0)
    {
        while(cond != 1 || cpt != 2){
            if(fgetc(fp) == ','){
                cpt++;
                cond = 1;
            }
        }
        fputc(fgetc(fp),cp);
    }
    fclose(fp);
    fclose(cp);

    FILE * fp1 = fopen(file , "w+");
    FILE * cp1 = fopen("tmp.json", "r");
    while(feof(cp1) == 0)
    {
        fputc(fgetc(cp1),fp1);
    }

    fclose(fp1);
    fclose(cp1);
}

int recupTime(FILE* fp){

    FILE *fp2;
    int time = 0;
    char buffer[1024];
    struct json_object *parsed_json;
    struct json_object *message;
    fp2 = fopen("result.json","r");
    fread(buffer, 1024, 1, fp);
    fclose(fp2);

    parsed_json = json_tokener_parse(buffer);

    json_object_object_get_ex(parsed_json, "message", &message);
    printf("Message: %d\n", json_object_get_int(message));
    time = json_object_get_int(message);
    return time;
}

/*char * getStationName(FILE* fp){

    FILE *fp2;
    char * stationName;
    char buffer[1024];
    struct json_object *parsed_json;
    struct json_object *call;
    fp2 = fopen("result.json","r");
    fread(buffer, 1024, 1, fp);
    fclose(fp2);

    parsed_json = json_tokener_parse(buffer);

    json_object_object_get_ex(parsed_json, "call", &call);
    printf("%s\n", json_object_get_string(call));
    stationName = json_object_get_string(call);

    return stationName;
}*/

const char * getDestination(FILE* fp){

    const char * destinationTrain;
    FILE *fp2;
    char buffer[1024];
    struct json_object *parsed_json;
    struct json_object *destination;
    fp2 = fopen("result.json","r");
    fread(buffer, 1024, 1, fp);
    fclose(fp2);
    parsed_json = json_tokener_parse(buffer);
    json_object_object_get_ex(parsed_json, "destination", &destination);
    printf("%s\n", json_object_get_string(destination));
    destinationTrain = json_object_get_string(destination);
    if (strcmp(destinationTrain, "Chateau de Vincennes") <= 0){
        destinationTrain = "Ch. Vincennes";
        return destinationTrain;
    }
    if(strcmp(destinationTrain, "La Defense (Grande arche)") <= 0){
        destinationTrain = "La Defense";
        return destinationTrain;
    }

    if(strcmp(destinationTrain, "Pont de Levallois-Becon") <= 0){
        destinationTrain = "Pt. Levallois-B";
        return destinationTrain;
    }

    return destinationTrain;
}

station creatStation(){

    CURL *curl;
    FILE *fp;
    CURLcode res;
    char *url = "https://api-ratp.pierre-grimaud.fr/v4/schedules/metros/1/berault/R";
    char outfilename[FILENAME_MAX] = "result.json";
    curl = curl_easy_init();
    if(curl) {
        fp = fopen(outfilename,"wb");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);
        /* always cleanup */
        curl_easy_cleanup(curl);
        fclose(fp);
    }


    formatFile("result.json");
    station _station;
    _station.destination = getDestination(fp);
    _station.timeNextTrain1 = recupTime(fp);
    suppr("result.json");
    _station.timeNextTrain2 = recupTime(fp);
    suppr("result.json");
    _station.timeNextTrain3 = recupTime(fp);
    suppr("result.json");
    _station.timeNextTrain4 = recupTime(fp);
    suppr("result.json");
    //_station.stationName = getStationName(fp);
    return _station;
}





int recupDest(char * _file);

#endif //SUBVIEW_STRUCT_H
