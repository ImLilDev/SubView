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

void erreur(const char*txt)
{
    ALLEGRO_DISPLAY*d;
    d=al_is_system_installed()?al_get_current_display():NULL;
    al_show_native_message_box(d,"ERREUR",txt,NULL,NULL,0);
    exit(EXIT_FAILURE);
}



void drawprimarypage(){


    time_t now = time(NULL);
    struct tm *tm_struct = localtime(&now);
    int hour = tm_struct->tm_hour;
    int minute = tm_struct->tm_min;

    char station[255] = "Nation";
    char Destination[255] = "La Défense";
    // char realtime[255] = "15:38";

    ALLEGRO_FONT * Parisine_font_small = al_load_ttf_font("../Ressources/fonts/Parisine-Bold.otf",96,0);
    ALLEGRO_FONT * Parisine_font_big = al_load_ttf_font("../Ressources/fonts/Parisine-Bold.otf",135,0);
    ALLEGRO_FONT * led_font = al_load_ttf_font("../Ressources/fonts/LED.otf",120,0);
    ALLEGRO_COLOR primary_grey = al_map_rgb(240,240,240);
    ALLEGRO_COLOR dark_grey = al_map_rgb(70,70,70);
    ALLEGRO_COLOR primary_blue = al_map_rgb(22,75,156);
    ALLEGRO_COLOR alternative_grey = al_map_rgb(188,188,188);
    ALLEGRO_BITMAP*metrologo;                // l'image

    al_flip_display(); // go editing mode
    al_clear_to_color(al_map_rgb(255,255,255)); // draw blank screen
    al_draw_filled_rectangle(50,50,1870,948,primary_grey);

    // charger une image dans le programme
    metrologo = al_load_bitmap("../Ressources/images/1.png");
    if(!metrologo)
        erreur("al_load_bitmap()");
    // puis l'afficher
    al_draw_bitmap(metrologo,120,86,0);

    al_draw_text(Parisine_font_small, al_map_rgb(22,75,156), 598,125,0, station); // station name

    al_draw_text(Parisine_font_big, al_map_rgb(22,75,156), 120,378,0, Destination); // destination name

    al_draw_filled_rectangle(1500,105,1825,258,dark_grey); // time rectangle

   al_draw_textf(led_font, al_map_rgb(253,204,75), 1510,120,0, "%d:%d", hour, minute); // time text

    al_draw_filled_rectangle(1086,386,1411,539,dark_grey); // 1st rectangle

    al_draw_filled_rectangle(1501,386,1826,539,dark_grey); // 2nd rectangle

    al_draw_filled_rectangle(1086,624,1412,777,dark_grey); // 3th rectangle

    al_draw_filled_rectangle(1501,624,1827,777,dark_grey); // 4th rectangle

    al_draw_filled_rectangle(121,341, 1827, 350, primary_blue); // blue line

    al_draw_filled_rectangle(50,813, 1256, 947, alternative_grey); // bottom left rectangle



    al_flip_display(); // end editing mode


}


int main(int argc, char *argv[])
{

    int fin=0;

    al_init();
    al_init_font_addon();
    al_init_ttf_addon();
    al_install_audio();
    al_init_acodec_addon();

    ALLEGRO_DISPLAY * display = al_create_display(1920,1080);
    ALLEGRO_DISPLAY_MODE mode;
    ALLEGRO_FONT * font = al_load_ttf_font("test.TTF",64,0);
    ALLEGRO_KEYBOARD_STATE key;        // clavier simple



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
  // al_play_sample(sample, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);

    //
    // End Audio
    //




  //  sprintf(compare, "something");

    // keyboard escape key detection
    while(!fin){

        //
        // GET REAL TIME AND DRAWING IT
        //
        time_t now = time(NULL);
        struct tm *tm_struct = localtime(&now);
        int hour = tm_struct->tm_hour;
        int minute = tm_struct->tm_min;
        int tmp;

        if(tmp != minute){

            printf("changement minute");
            drawprimarypage();
            tmp = tm_struct->tm_min;

        }



        // récupération de l'état du clavier
        al_get_keyboard_state(&key);

        // si touche [Echap] appuyée fin boucle et quitter
        if(al_key_down(&key,ALLEGRO_KEY_ESCAPE)){
            printf("esc key pressed");
            fin=1;
        };
    };


    al_destroy_display(display);
    return 0;

};
