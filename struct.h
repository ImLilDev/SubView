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
    char direction[2];
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

    if(strcmp(destinationTrain, "La Defense (Grande Arche)") == 0){
        destinationTrain = "La Defense";
    }

    if (strcmp(destinationTrain, "Chateau de Vincennes") == 0){
        destinationTrain = "Ch. Vincennes";
    }

    if(strcmp(destinationTrain, "Pont de Levallois-Becon") == 0){
        destinationTrain = "Pt. Levallois-B";
    }

    if(strcmp(destinationTrain, "Villejuif-Louis Aragon") == 0){
        destinationTrain = "Villejuif-Louis";
    }

    if(strcmp(destinationTrain, "La Courneuve-8-Mai-1945") == 0){
        destinationTrain = "La Courneuve";
    }
    if(strcmp(destinationTrain, "Porte Dauphine (Marechal de Lattre de Tassigny)") == 0){
        destinationTrain = "Prt-Dauphine";
    }
    if(strcmp(destinationTrain, "Mairie de Montrouge") == 0){
        destinationTrain = "Montrouge";
    }
    if(strcmp(destinationTrain, "Porte de Clignancourt") == 0){
        destinationTrain = "Clignancourt";
    }
    if(strcmp(destinationTrain, "Bobigny-Pablo-Picasso") == 0){
        destinationTrain = "Bobigny-Pablo";
    }
    if(strcmp(destinationTrain, "Charles de Gaulle-Etoile") == 0){
        destinationTrain = "CDG-Etoile";
    }
    if(strcmp(destinationTrain, "Creteil-Pointe du Lac") == 0){
        destinationTrain = "Creteil-Lac";
    }
    if(strcmp(destinationTrain, "Mairie de Montreuil") == 0){
        destinationTrain = "Montreuil";
    }
    if(strcmp(destinationTrain, "Boulogne Pont de Saint-Cloud") == 0){
        destinationTrain = "Boulogne";
    }
    if(strcmp(destinationTrain, "Gare d'Austerlitz") == 0){
        destinationTrain = "G. d'Austerlitz";
    }
    if(strcmp(destinationTrain, "Mairie des Lilas") == 0){
        destinationTrain = "M. des Lilas";
    }
    if(strcmp(destinationTrain, "Boulogne Pont de Saint-Cloud") == 0){
        destinationTrain = "Boulogne";
    }
    if(strcmp(destinationTrain, "Front Populaire") == 0){
        destinationTrain = "F. Populaire";
    }
    if(strcmp(destinationTrain, "Chatillon Montrouge") == 0){
        destinationTrain = "Montrouge";
    }
    if(strcmp(destinationTrain, "Asnieres-Gennevilliers Les Courtilles") == 0){
        destinationTrain = "Gennevilliers";
    }
    if(strcmp(destinationTrain, "Gallieni (Parc de Bagnolet)") == 0){
        destinationTrain = "Gallieni (Parc)";
    }


    return destinationTrain;
}
void changeStationName(char newName[255]){
    FILE * configFile = fopen("../config.txt", "r+");
    char data[255];
    char key[255];
    if(configFile == NULL){
        printf("File not open");
    }else
    {
        while(fscanf(configFile,"%s %s",key, data) != EOF){

            if(strcmp( key, "station" ) == 0){
                fseek(configFile,-(int)strlen(data),SEEK_CUR);
                fputs(newName, configFile);
                fputs("~~~~~~~~~~~~~~~~~",configFile);
            }
        }
    }
    fclose(configFile);
}

void readConfigFile(station * _station){


    FILE * configFile = fopen("../config.txt", "r");
    char data[255];
    char key[255];
    if(configFile == NULL){
        printf("File not open");
    }else
    {
        while(fscanf(configFile,"%s %s",key, data) != EOF){

            if(strcmp( key, "station" ) == 0){
                strcpy(_station->stationName , data);
                printf("station name from file : %s\n" ,_station->stationName);
            }
            if(strcmp(key, "Direction")==0){
                strcpy( _station->direction, data);
            }
            if(strcmp(key, "Line")==0){
                _station->metroNumber = atoi(data);
            }
        }
        printf("station name from file after while() : %s\n" , _station->stationName );
        printf("end of file\n");
    }
    fclose(configFile);
}

station creatStation(){

    CURL *curl;
    FILE *fp;
    CURLcode res;
    station _station;


    readConfigFile(&_station);



    char url[255];
    sprintf(url, "https://api-ratp.pierre-grimaud.fr/v4/schedules/metros/%d/%s/%s", _station.metroNumber, _station.stationName, _station.direction);

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

void drawnextStationName(){

    ALLEGRO_FONT * Parisine_font_medium = al_load_ttf_font("../Ressources/fonts/Parisine-Bold.otf",96,0);
    ALLEGRO_COLOR primary_grey = al_map_rgb(240,240,240);


    FILE *configFile = fopen("../config.txt", "r");
    int data= 0;
    int number = 0 ;
    char key[255];
    struct json_object *nameStation;
    if (configFile == NULL) {
        printf("File not open");
    } else {
        while (fscanf(configFile, "%s %d", key, &data) != EOF) {

            if (strcmp(key, "Line") == 0){
                number = data;
            }

        }

    }

    CURL *curl;
    FILE *fp;
    CURLcode res;
    char name[255];
    char Displayname[255];
    char url[255];
    sprintf(url, "https://api-ratp.pierre-grimaud.fr/v4/stations/metros/%d", number);

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
    FILE *fp2;

    char buffer[1024];
    struct json_object *parsed_json;
    struct json_object *slug;

    fp2 = fopen("result.json","r");
    fread(buffer, 1024, 1, fp);
    fclose(fp2);

    parsed_json = json_tokener_parse(buffer);

    json_object_object_get_ex(parsed_json, "slug", &slug);
    json_object_object_get_ex(parsed_json, "name", &nameStation);
    printf("NAME   :   %s\n", json_object_get_string(nameStation));
    printf("SLUG   :   %s\n", json_object_get_string(slug));
    strcpy(name, json_object_get_string(slug));
    strcpy(Displayname, json_object_get_string(nameStation));

    changeStationName(name);
    printf("new name : %s\n" , name);
    printf("ChangeStationName  à  été  appelée \n");

    if(strcmp(Displayname, "Chateau de Vincennes") == 0){
        strcpy(Displayname, "Ch. de Vincennes");
    }
    if(strcmp(Displayname, "Gallieni (Parc de Bagnolet)") == 0){
        strcpy(Displayname, "Gallieni (Parc)");
    }
    if(strcmp(Displayname, "Porte de Clignancourt") == 0){
        strcpy(Displayname, "Pt. de Clignancourt");
    }
    if(strcmp(Displayname, "Bobigny-Pablo-Picasso") == 0){
        strcpy(Displayname, "Bobigny-Picasso");
    }
    if(strcmp(Displayname, "La Courneuve-8-Mai-1945") == 0){
        strcpy(Displayname, "La Courneuve");
    }
    if(strcmp(Displayname, "Boulogne Pont de Saint-Cloud") == 0){
        strcpy(Displayname, "Boulogne");
    }
    if(strcmp(Displayname, "Chatillon Montrouge") == 0){
        strcpy(Displayname, "Montrouge");
    }
    if(strcmp(Displayname, "Mairie de Saint-Ouen") == 0){
        strcpy(Displayname, "M. de Saint-Ouen");
    }

    al_draw_filled_rectangle(582,102, 1482, 266, primary_grey); // blue line
    al_draw_text(Parisine_font_medium, al_map_rgb(22,75,156), 598, 125, 0, Displayname);





}





int determineLine() {

    FILE *configFile = fopen("../config.txt", "r");
    int data = 0;
    char key[255];
    if (configFile == NULL) {
        printf("File not open");
    } else {
        while (fscanf(configFile, "%s %d", key, &data) != EOF) {

            if (strcmp(key, "Line") == 0) {

                return data;

            }

        }
    }
    return 0;
}





int recupDest(char * _file);

#endif //SUBVIEW_STRUCT_H
