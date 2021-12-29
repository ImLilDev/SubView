#include <stdio.h>

void duplicateFile(char *file, char *copy){
    FILE *fp = fopen(file , "r+");
    FILE *cp = fopen(copy, "w+");
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

}

void suppr(char *file, char *copy){

    int cpt = 0;
    FILE *fp = fopen(file , "r+");
    FILE *cp = fopen(copy, "a+");
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
}

int main() {
    duplicateFile("test.json", "formated.json");
    remove("test.json");
    rename("formated.json" , "test.json");
    suppr("test.json", "formated.json");
    return 0;
}
