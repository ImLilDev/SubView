//
// Created by Eliott GERMAIN on 10/01/2022.
//
#ifndef SUBVIEW_DISPLAY_H
#define SUBVIEW_DISPLAY_H

///---------------- PROTOTYPES ---------------///

void Error(const char*);

void drawTrainTime(int , float, float, float, float, float, float);

void drawNextMetroLogo(int);

//void drawmetrologo(station *);

void drawScheldures();

void drawTime();

void firstStartup();

void drawPrimaryPage();

void changeDirection(station *);

void changeMetro();

///----------------- FUNCTIONS ----------------///

void Error(const char*txt)
{
    ALLEGRO_DISPLAY*d;
    d=al_is_system_installed()?al_get_current_display():NULL;
    al_show_native_message_box(d,"ERROR : ",txt,NULL,NULL,0);
    exit(EXIT_FAILURE);
}

///--------------------------------------------///

void drawTrainTime(int time, float x1, float y1, float x2, float y2, float x, float y){ // to avoid code repetition


    ALLEGRO_FONT * led_font = al_load_ttf_font("../Ressources/fonts/LED.otf",120,0);
    ALLEGRO_COLOR dark_grey = al_map_rgb(70,70,70);
    if(time > 9){
        x = x - 30;
    } else if(time >= 20){
        x = x - 10;
    }

    al_draw_filled_rectangle(x1,y1,x2,y2,dark_grey); // 1st rectangle
    al_draw_textf(led_font, al_map_rgb(253,204,75), x , y ,0,"%d",  time); // time for next metro
}

///--------------------------------------------///

void drawNextMetroLogo(int number){

    ALLEGRO_COLOR primary_grey = al_map_rgb(240,240,240);
    ALLEGRO_COLOR color1 = al_map_rgb(255,190,0);
    ALLEGRO_COLOR color2 = al_map_rgb(0,108,184);
    ALLEGRO_COLOR color3 = al_map_rgb(155,152,59);
    ALLEGRO_COLOR color4 = al_map_rgb(187,75,156);
    ALLEGRO_COLOR color5 = al_map_rgb(242,142,66);
    ALLEGRO_COLOR color6 = al_map_rgb(119,198,150);
    ALLEGRO_COLOR color7 = al_map_rgb(245,159,179);
    ALLEGRO_COLOR color8 = al_map_rgb(206,173,210);
    ALLEGRO_COLOR color9 = al_map_rgb(213,201,36);
    ALLEGRO_COLOR color10 = al_map_rgb(227,179,42);
    ALLEGRO_COLOR color11 = al_map_rgb(141,94,42);
    ALLEGRO_COLOR color12 = al_map_rgb(23,129,79);
    ALLEGRO_COLOR color13 = al_map_rgb(137,211,222);
    ALLEGRO_COLOR color14 = al_map_rgb(102,36,131);




    ALLEGRO_BITMAP*metrologo; // l'image
    // charger une image dans le programme

    char path[255];
    sprintf(path, "../Ressources/images/%d.png", number);

    metrologo = al_load_bitmap(path);
    if(!metrologo)
        Error("al_load_bitmap()");
    // puis l'afficher
    al_draw_filled_rectangle(60,59,548,320,primary_grey);

    al_draw_bitmap(metrologo,120,86,0);


    switch(number){

        case 1:
            al_draw_filled_rectangle(50,813, 1256, 947, color1); // bottom left rectangle
            break;
        case 2:
            al_draw_filled_rectangle(50,813, 1256, 947, color2); // bottom left rectangle
            break;
        case 3:
            al_draw_filled_rectangle(50,813, 1256, 947, color3); // bottom left rectangle
            break;
        case 4:
            al_draw_filled_rectangle(50,813, 1256, 947, color4); // bottom left rectangle
            break;
        case 5:
            al_draw_filled_rectangle(50,813, 1256, 947, color5); // bottom left rectangle
            break;
        case 6:
            al_draw_filled_rectangle(50,813, 1256, 947, color6); // bottom left rectangle
            break;
        case 7:
            al_draw_filled_rectangle(50,813, 1256, 947, color7); // bottom left rectangle
            break;
        case 8:
            al_draw_filled_rectangle(50,813, 1256, 947, color8); // bottom left rectangle
            break;
        case 9:
            al_draw_filled_rectangle(50,813, 1256, 947, color9); // bottom left rectangle
            break;
        case 10:
            al_draw_filled_rectangle(50,813, 1256, 947, color10); // bottom left rectangle
            break;
        case 11:
            al_draw_filled_rectangle(50,813, 1256, 947, color11); // bottom left rectangle
            break;
        case 12:
            al_draw_filled_rectangle(50,813, 1256, 947, color12); // bottom left rectangle
            break;
        case 13:
            al_draw_filled_rectangle(50,813, 1256, 947, color13); // bottom left rectangle
            break;
        case 14:
            al_draw_filled_rectangle(50,813, 1256, 947, color14); // bottom left rectangle
            break;
    }

}

///--------------------------------------------///

void drawmetrologo(station *_station1){

    ALLEGRO_BITMAP*metrologo; // l'image
    // charger une image dans le programme

    char path[255];
    sprintf(path, "../Ressources/images/%d.png", _station1->metroNumber);

    metrologo = al_load_bitmap(path);
    if(!metrologo)
        Error("al_load_bitmap()");
    // puis l'afficher
    al_draw_bitmap(metrologo,120,86,0);

}

///--------------------------------------------///

void drawScheldures(){

    station  _station = creatStation();

    ///                   console test                 ///

    printf("%s %d\n","time1 : ", _station.timeNextTrain1);
    printf("%s %d\n","time2 : ", _station.timeNextTrain2);
    printf("%s %d\n","time3 : ", _station.timeNextTrain3);
    printf("%s %d\n","time4 : ", _station.timeNextTrain4);
    printf("%s %s\n", "station Name : ", _station.stationName);
    printf("%s %d\n", "Line  : ", _station.metroNumber);
    printf("%s %s\n", "Direction : ", _station.direction);

    ///                     display                    ///
    ALLEGRO_FONT * Parisine_font_small = al_load_ttf_font("../Ressources/fonts/Parisine-Bold.otf",64,0);
    ALLEGRO_FONT * Parisine_font_big = al_load_ttf_font("../Ressources/fonts/Parisine-Bold.otf",135,0);
    ALLEGRO_COLOR primary_grey = al_map_rgb(240,240,240);
    drawTrainTime(_station.timeNextTrain1,1086, 386, 1411,539,1150,405);
    drawTrainTime(_station.timeNextTrain2,1501,386, 1826,539, 1565, 405);
    drawTrainTime(_station.timeNextTrain3,1086,624, 1412,777,1150,635);
    drawTrainTime(_station.timeNextTrain4,1501,624, 1826,777,1565,635);
    al_draw_text(Parisine_font_small, al_map_rgb(255,255,255), 1263,439,0, "min"); // min text
    al_draw_text(Parisine_font_small, al_map_rgb(255,255,255), 1676,439,0, "min"); // min text
    al_draw_text(Parisine_font_small, al_map_rgb(255,255,255), 1263,666,0, "min"); // min text
    al_draw_text(Parisine_font_small, al_map_rgb(255,255,255), 1676,666,0, "min"); // min text
    al_draw_filled_rectangle(88,386, 1063, 599, primary_grey); // overdraw on text
    al_draw_text(Parisine_font_big, al_map_rgb(22,75,156), 120,378,0, _station.destination); // destination name
}

///--------------------------------------------///

void drawTime(){


    time_t now = time(NULL);
    struct tm *tm_struct = localtime(&now);
    int hour = tm_struct->tm_hour;
    int minute = tm_struct->tm_min;

    ALLEGRO_FONT * led_font = al_load_ttf_font("../Ressources/fonts/LED.otf",110,0);
    ALLEGRO_COLOR dark_grey = al_map_rgb(70,70,70);

    al_draw_filled_rectangle(1500,105,1825,258,dark_grey); // time rectangle

    if(minute <= 9){
        al_draw_textf(led_font, al_map_rgb(253,204,75), 1515,125,0, "%d:0%d", hour, minute); // time text case of only 1 digit
    }  else al_draw_textf(led_font, al_map_rgb(253,204,75), 1515,125,0, "%d:%d", hour, minute); // time text


}

///--------------------------------------------///

void firstStartup() {

    ALLEGRO_COLOR color1 = al_map_rgb(255,190,0);

    FILE *configFile = fopen("../config.txt", "r+");
    char data[255];
    int fin=0;
    char FirstStartup[255];
    if (configFile == NULL) {
        printf("File not open");
    } else {
        while (fscanf(configFile, "%s %s", FirstStartup, data) != EOF) {

            if (strcmp(FirstStartup, "FirstStartup") == 0){
                if(strcmp(data , "0")==0){

                    al_flip_display();
                    ALLEGRO_BITMAP*overlay;
                    ALLEGRO_KEYBOARD_STATE key;        // keyboard info

                    al_clear_to_color(al_map_rgb(255,255,255)); // draw blank screen

                    overlay = al_load_bitmap("../Ressources/images/overlay.png");
                    if(!overlay)
                        Error("al_load_bitmap()");
                    al_draw_bitmap(overlay,0,0,0);

                    al_flip_display();


                    while(!fin) {

                        // recuperation of keyboard state
                        al_get_keyboard_state(&key);

                        // if [Escape] pressed, end of the loop and quit the program
                        if (al_key_down(&key, ALLEGRO_KEY_SPACE)) {
                            fseek(configFile, -1, SEEK_CUR);
                            fputc('1', configFile);
                            fin = 1;
                        };

                    }

                }

            }

        }
    }
}

///--------------------------------------------///

void drawPrimaryPage(){


    time_t now = time(NULL);
    struct tm *tm_struct = localtime(&now);
    int hour = tm_struct->tm_hour;
    int minute = tm_struct->tm_min;
    char realtime[255];

    sprintf(realtime, "%d:%d", hour, minute);

    //  char station[255] = "Nation️";

    // char realtime[255] = "15:38";

    ALLEGRO_FONT * Parisine_font_small = al_load_ttf_font("../Ressources/fonts/Parisine-Bold.otf",64,0);
    ALLEGRO_FONT * Parisine_font_medium = al_load_ttf_font("../Ressources/fonts/Parisine-Bold.otf",96,0);

    ALLEGRO_FONT * led_font = al_load_ttf_font("../Ressources/fonts/LED.otf",120,0);
    ALLEGRO_COLOR primary_grey = al_map_rgb(240,240,240);
    ALLEGRO_COLOR dark_grey = al_map_rgb(70,70,70);
    ALLEGRO_COLOR primary_blue = al_map_rgb(22,75,156);
    ALLEGRO_BITMAP*heart;
    ALLEGRO_BITMAP*iledefrance;
    ALLEGRO_BITMAP*RATP;

    al_flip_display(); // go editing mode



    al_clear_to_color(al_map_rgb(255,255,255)); // draw blank screen

    al_draw_filled_rectangle(50,50,1870,948,primary_grey);

//    al_draw_text(Parisine_font_medium, al_map_rgb(22,75,156), 598,125,0, station); // station name


    drawTime();


    al_draw_filled_rectangle(121,341, 1827, 350, primary_blue); // blue line

    al_draw_filled_rounded_rectangle(20,957, 129, 1066, 30, 30, primary_grey); // add rectangle
    al_draw_filled_rounded_rectangle(35,1007, 114, 1016, 2, 2, primary_blue); // line1
    al_draw_filled_rounded_rectangle(70,972, 79, 1051, 2, 2,  primary_blue); // line2


    al_draw_filled_rounded_rectangle(893,957, 1002, 1066, 30, 30, primary_grey); // list rectangle
    al_draw_filled_rounded_rectangle(908,979, 987, 988, 2, 2, primary_blue); // line1
    al_draw_filled_rounded_rectangle(908,1007, 987, 1016, 2, 2,  primary_blue); // line2
    al_draw_filled_rounded_rectangle(908,1035, 987, 1044, 2, 2,  primary_blue); // line3


    al_draw_filled_rounded_rectangle(1777,957, 1886, 1066, 30, 30, primary_grey); // favourite rectangle
    heart = al_load_bitmap("../Ressources/images/heart.png"); // heart image
    al_draw_bitmap(heart,1777,957,0);


    iledefrance = al_load_bitmap("../Ressources/images/iledefrance.png"); // logo ile de france
    al_draw_bitmap(iledefrance,1283,849,0);

    RATP = al_load_bitmap("../Ressources/images/RATP.png"); // logo RATP
    al_draw_bitmap(RATP,1727,820,0);

    drawScheldures();
    drawnextStationName();
    drawNextMetroLogo(determineLine());

    al_flip_display(); // end editing mode

}

///--------------------------------------------///

void changeDirection(station * _station) {

    FILE *configFile = fopen("../config.txt", "r+");
    char data[255];
    char key[255];
    if (configFile == NULL) {
        printf("File not open");
    } else {
        while (fscanf(configFile, "%s %s", key, data) != EOF) {

            if (strcmp(key, "Direction") == 0){
                if(strcmp(data , "A")==0){
                    fseek(configFile,-1,SEEK_CUR);
                    fputc('R',configFile);
                }
                else{
                    fseek(configFile,-1,SEEK_CUR);
                    fputc('A',configFile);
                }

            }

        }
    }
    al_flip_display();
    drawScheldures();
    al_flip_display();
}

///--------------------------------------------///

void changeMetro(){

    FILE *configFile = fopen("../config.txt", "r+");
    int data= 0;
    char key[255];
    struct json_object *nameStation;
    if (configFile == NULL) {
        printf("File not open");
    } else {
        while (fscanf(configFile, "%s %d", key, &data) != EOF) {

            if (strcmp(key, "Line") == 0){
                if(data == 13){ // usually 14
                    fseek(configFile,-2,SEEK_CUR);
                    data = 1;
                    fprintf(configFile,"%d ",data);
                }
                else if(data == 9){
                    fseek(configFile,-1,SEEK_CUR);
                    data = 10;
                    fprintf(configFile,"%d", data);
                }
                else if(data >= 10){
                    fseek(configFile,-2,SEEK_CUR);
                    data++;
                    fprintf(configFile,"%d", data);
                }
                else{
                    fseek(configFile,-1,SEEK_CUR);
                    data++;
                    fprintf(configFile,"%d", data);
                }

            }

        }

    }

    fclose(configFile);

    al_flip_display();

    drawnextStationName();
    drawNextMetroLogo(data);
    drawScheldures();


    al_flip_display();
}

#endif //SUBVIEW_DISPLAY_H
