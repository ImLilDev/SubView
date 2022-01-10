#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <time.h>
#include <string.h>
#include <json-c/json.h>
#include "struct.h"
#include "files.h"
#include "display.h"
#include "list.h"

int main(int argc, char *argv[])
{

    ///------------------        INITIALIZATION      ---------------------///

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

   ///-------------------- checking for allegro errors ------------------///

    if (!al_init()){
        fprintf(stderr, "failed to initialize allegro!\n");
        return -1;
    }

    if(!al_init_primitives_addon())
        Error("al_init_primitives_addon()");

    //necessary to load and save bitmap
    if(!al_init_image_addon())
        Error("al_init_image_addon()");

    if (!al_install_audio())
        Error("al_install_audio()");

    // to use keyboard
    if(!al_install_keyboard())
        Error("al_install_keyboard()");

    // mouse check
    if(!al_install_mouse())
        Error("al_install_mouse()");

    // End checking


    firstStartup();
    drawPrimaryPage();

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


    ///-------------------- RUNNING APP LOOP -----------------------///

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
            drawScheldures();
            al_flip_display();
            tmp = tm_struct->tm_min;
            tmp2 = tm_struct->tm_sec;
        }


        if(tmp != minute){
            printf("changement minute");
            al_flip_display();
            drawTime();
            al_flip_display();
            tmp = tm_struct->tm_min;
            tmp2 = tm_struct->tm_sec;
        }


        ///  get keyboard state

        al_get_keyboard_state(&key);

        // si touche [Echap] appuyée fin boucle et quitter
        if(al_key_down(&key,ALLEGRO_KEY_ESCAPE)){
            printf("esc key pressed");
            fin=1;
        };

        al_get_mouse_state(&mouse);

        if(88 < mouse.x && mouse.x < 1063 && 386<mouse.y && mouse.y <599 && mouse.buttons &1 ){ // clic on direction text
            al_rest(0.1);
            changeDirection(&station1);
        }

        if(120 < mouse.x && mouse.x < 509 && 86<mouse.y && mouse.y <277 && mouse.buttons &1 ){ // clic on metro logo
            printf("clic on metro logo");
            al_rest(0.1);
            changeMetro();
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
