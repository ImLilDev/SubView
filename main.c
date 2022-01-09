#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <stdio.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <stdbool.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <time.h>
#include <curl/curl.h>
#include <curl/easy.h>
#include <string.h>
#include <json-c/json.h>
#include "struct.h"


void erreur(const char*txt)
{
    ALLEGRO_DISPLAY*d;
    d=al_is_system_installed()?al_get_current_display():NULL;
    al_show_native_message_box(d,"ERREUR",txt,NULL,NULL,0);
    exit(EXIT_FAILURE);
}

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
void drawmNextMetroLogo(int number){
    ALLEGRO_COLOR primary_grey = al_map_rgb(240,240,240);
    ALLEGRO_BITMAP*metrologo; // l'image
    // charger une image dans le programme

    char path[255];
    sprintf(path, "../Ressources/images/%d.png", number);

    metrologo = al_load_bitmap(path);
    if(!metrologo)
        erreur("al_load_bitmap()");
    // puis l'afficher
    al_draw_filled_rectangle(60,59,548,320,primary_grey);

    al_draw_bitmap(metrologo,120,86,0);

}


void drawmetrologo(station *_station1){

    ALLEGRO_BITMAP*metrologo; // l'image
    // charger une image dans le programme

    char path[255];
    sprintf(path, "../Ressources/images/%d.png", _station1->metroNumber);

    metrologo = al_load_bitmap(path);
    if(!metrologo)
        erreur("al_load_bitmap()");
    // puis l'afficher
    al_draw_bitmap(metrologo,120,86,0);

}

void drawscheldures(){

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

void drawtime(){


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

void drawprimarypage(){


    time_t now = time(NULL);
    struct tm *tm_struct = localtime(&now);
    int hour = tm_struct->tm_hour;
    int minute = tm_struct->tm_min;
    char realtime[255];

    sprintf(realtime, "%d:%d", hour, minute);

    char station[255] = "Nation️";

    // char realtime[255] = "15:38";

    ALLEGRO_FONT * Parisine_font_small = al_load_ttf_font("../Ressources/fonts/Parisine-Bold.otf",64,0);
    ALLEGRO_FONT * Parisine_font_medium = al_load_ttf_font("../Ressources/fonts/Parisine-Bold.otf",96,0);

    ALLEGRO_FONT * led_font = al_load_ttf_font("../Ressources/fonts/LED.otf",120,0);
    ALLEGRO_COLOR primary_grey = al_map_rgb(240,240,240);
    ALLEGRO_COLOR dark_grey = al_map_rgb(70,70,70);
    ALLEGRO_COLOR primary_blue = al_map_rgb(22,75,156);
    ALLEGRO_COLOR alternative_grey = al_map_rgb(188,188,188);
    ALLEGRO_BITMAP*heart;
    ALLEGRO_BITMAP*iledefrance;
    ALLEGRO_BITMAP*RATP;

    al_flip_display(); // go editing mode
    al_clear_to_color(al_map_rgb(255,255,255)); // draw blank screen
    al_draw_filled_rectangle(50,50,1870,948,primary_grey);

    al_draw_text(Parisine_font_medium, al_map_rgb(22,75,156), 598,125,0, station); // station name


    drawtime();
    

    al_draw_filled_rectangle(121,341, 1827, 350, primary_blue); // blue line

    al_draw_filled_rectangle(50,813, 1256, 947, alternative_grey); // bottom left rectangle

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

    drawscheldures();

    al_flip_display(); // end editing mode
}

void changedirection(station *_station) {

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
    drawscheldures();
    al_flip_display();
}


void changemetro(){

    FILE *configFile = fopen("../config.txt", "r+");
    int data= 0;
    char key[255];
    char name[255];
    struct json_object *nameStation;
    ALLEGRO_FONT * Parisine_font_medium = al_load_ttf_font("../Ressources/fonts/Parisine-Bold.otf",96,0);
    if (configFile == NULL) {
        printf("File not open");
    } else {
        while (fscanf(configFile, "%s %d", key, &data) != EOF) {

            if (strcmp(key, "Line") == 0){
                if(data == 14){
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

        CURL *curl;
        FILE *fp;
        CURLcode res;
        char url[255];
        sprintf(url, "https://api-ratp.pierre-grimaud.fr/v4/stations/metros/%d", data);

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
        strcpy(name, json_object_get_string(slug));



    }

    fclose(configFile);
    changeStationName(name);
    printf("new name : %s\n" , name);
    printf("ChangeStationName  à  été  appelée \n");
    al_flip_display();
    drawscheldures();
    drawmNextMetroLogo(data);
    al_flip_display();
}




int main(int argc, char *argv[])
{

    int fin=0;
    al_init();
    al_init_font_addon();
    al_init_ttf_addon();
    al_install_audio();
    al_init_acodec_addon();
    //al_set_new_display_flags(ALLEGRO_WINDOWED | ALLEGRO_RESIZABLE);
    ALLEGRO_DISPLAY * display = al_create_display(1920,1080);
    ALLEGRO_DISPLAY_MODE mode;
    ALLEGRO_FONT * font = al_load_ttf_font("test.TTF",64,0);
    ALLEGRO_KEYBOARD_STATE key;        // keyboard info
    ALLEGRO_MOUSE_STATE mouse;      // mouse info
    station station1;
    readConfigFile(&station1);
   //      al_rest(10.0);
   //     al_destroy_display(display);





   // checking for allegro errors :

    if (!al_init()){
        fprintf(stderr, "failed to initialize allegro!\n");
        return -1;
    }

    if(!al_init_primitives_addon())
        erreur("al_init_primitives_addon()");

    //nécessaire pour load et save bitmap
    if(!al_init_image_addon())
        erreur("al_init_image_addon()");

    if (!al_install_audio())
        erreur("al_install_audio()");

    // pour utiliser le clavier
    if(!al_install_keyboard())
        erreur("al_install_keyboard()");

    // mouse check
    if(!al_install_mouse())
        erreur("al_install_mouse()");

    // End checking


    drawprimarypage();

    //
    // Audio
    //

    ALLEGRO_SAMPLE *sample = al_load_sample("../Ressources/audio/Annonce.ogg"); //convert to ogg file your link
    al_reserve_samples(1);
    if (!sample){
        printf("Audio clip sample not loaded!\n");
        return -1;
    }
 //  al_play_sample(sample, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);

    //
    // End Audio
    //

al_flip_display();
    drawmetrologo(&station1);
    al_flip_display();


  //  sprintf(compare, "something");

    // keyboard escape key detection
    while(!fin){

        //
        // GET REAL TIME AND REDRAWING IT
        //
        time_t now = time(NULL);
        struct tm *tm_struct = localtime(&now);
        int hour = tm_struct->tm_hour;
        int minute = tm_struct->tm_min;
        int sec = tm_struct->tm_sec;
        int tmp;
        int tmp2;



        if(sec >= tmp2+5){
            printf("plus de 5 second sont passé");
            al_flip_display();
            drawscheldures();
            al_flip_display();
            tmp = tm_struct->tm_min;
            tmp2 = tm_struct->tm_sec;
        }


        if(tmp != minute){
            printf("changement minute");
            al_flip_display();
            drawtime();
            al_flip_display();
            tmp = tm_struct->tm_min;
            tmp2 = tm_struct->tm_sec;
        }



        // récupération de l'état du clavier
        al_get_keyboard_state(&key);

        // si touche [Echap] appuyée fin boucle et quitter
        if(al_key_down(&key,ALLEGRO_KEY_ESCAPE)){
            printf("esc key pressed");
            fin=1;
        };

        al_get_mouse_state(&mouse);

        if(88 < mouse.x && mouse.x < 1063 && 386<mouse.y && mouse.y <599 && mouse.buttons &1 ){ // clic on direction text
            changedirection(&station1);
        }

        if(120 < mouse.x && mouse.x < 509 && 86<mouse.y && mouse.y <277 && mouse.buttons &1 ){ // clic on metro logo
            printf("clic on metro logo");
            al_rest(1.0);
            changemetro();
        }

        if(20 < mouse.x && mouse.x < 129 && 957<mouse.y && mouse.y <1066 && mouse.buttons &1 ){ // clic on add rectangle ?
            printf("add button pressed");
            fin=1;
        }

        if(893 < mouse.x && mouse.x < 1002 && 957<mouse.y && mouse.y <1066 && mouse.buttons &1 ){ // clic on list rectangle ?
            printf("list button pressed");
            fin=1;
        }

        if(1777 < mouse.x && mouse.x < 1886 && 957<mouse.y && mouse.y <1066 && mouse.buttons &1 ){ // clic on fav rectangle ?
            printf("fav button pressed");
            fin=1;
        }

    };


    al_destroy_display(display);
    return 0;

};
