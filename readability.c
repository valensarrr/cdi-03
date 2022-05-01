#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAX 4096

int read_file(char *text, char *filename);

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Uso: ./readability file\n");
        return 1;
    }

    char text[MAX];

    if (read_file(text, argv[1])) {
        printf("Archivo no encontrado\n");
        return 1;
    }

    int i= 0;
    int letras= 0;
    int palabras= 0;
    int oraciones= 0;

    while (text[i]){

        if (isalpha (text[i]))
        letras++;
        if (isspace (text[i]))
        palabras++;
        if (text [i] == '.' || text [i] == '!' || text [i] == '?')
        oraciones++;
    
        i++;
    }

    float s= 0;
    float l= 0;
    float grado= 0;

    s= 100 * oraciones / palabras;

    l= 100 * letras / palabras;

    grado= 0.0588 * l - 0.296 * s - 15.8;

    grado= round (grado);

//  printf("%d\n", letras);
//  printf("%d\n", palabras);
//  printf("%d\n", oraciones);
//  printf("%d\f", grado);

    if(grado < 1){

        printf("Before Grade 1");
    }
    else if (grado > 16){

        printf ("Grade 16+");
    }
    else{

        printf ("Grado %d", (int)grado);
    }

    return 0;
}

int read_file(char *text, char *filename) {

    FILE *fp;
    char c;
    char full_name[30];
    
    sprintf(full_name, "texts/%s.txt", filename);
    fp = fopen(full_name, "r");
    
    if (!fp) {
        return 1;
    } 
    while ((c = getc(fp)) != EOF) {
        *text = c;
        text++;
    }
    return 0;
}
