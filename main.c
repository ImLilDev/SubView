#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <stdio.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <stdbool.h>



int main(int argc, char *argv[])
{

    al_init();
    //ALLEGRO_BITMAP* img = al_load_bitmap("doge.jpeg");
    al_init_font_addon();
    al_init_ttf_addon();

    ALLEGRO_DISPLAY * display = al_create_display(1920,1080);
    ALLEGRO_FONT * font = al_load_ttf_font("test.TTF",64,0);


        al_clear_to_color(al_map_rgb(255,255,255));
        al_draw_text(font, al_map_rgb(0,0,0), 0,0,0, "HEllo World");
        //al_draw_bitmap(img, 100, 100, 0);
        al_flip_display();
        al_rest(10.0);
        al_destroy_display(display);
    return 0;
}
