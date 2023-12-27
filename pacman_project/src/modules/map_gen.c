#include <stdio.h>
#include <string.h>


char result[100] = {'0'};

char * generate_filename(int lvl)
{
    const char * filename = "./maps/lvl_";
    const char * ext = ".txt";
    char lvl_name[3] = {'0'};
    itoa(lvl, lvl_name, 10);
    strcpy(result, filename);
    strcat(result, lvl_name);
    strcat(result, ext);
    return result;
}

void read_map(int lvl, int * py, int * px, char (* map)[45], int * gold_total)
{
    int i = 0, j = 0;
    
    char * filename = generate_filename(lvl);
    char c;
    FILE * lvl_map;
    lvl_map = fopen(filename, "r");
    if (lvl_map) {
        while ((c = getc(lvl_map)) != EOF) {
            if (c != '\n') {
                if ((i == *py)&&(j == *px)) {
                    map[i][j] = '@';
                    j++;
                } else if (c == '*') {
                    map[i][j] = '*';
                    *gold_total += 100;
                    j++;
                } else {
                    map[i][j] = c;
                    j++;
                }
            } else {
                map[i][j] = c;
                j = 0;
                i++;
            }
        }  
        fclose(lvl_map);
    }
}
