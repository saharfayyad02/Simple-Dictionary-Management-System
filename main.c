#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

void print(){
    printf("Please select an option \n");
    printf(" 1- Read File and build the dictionary \n");
    printf(" 2- Search for a specific word \n");
    printf(" 3- Search for all words that start with a character \n");
    printf(" 4- Insert new word to the dictionary \n");
    printf(" 5- Save the dictionary back to the file \n");
    printf(" 6- Exit \n");

}
typedef struct {
    int wordno;
    char word[20];
    char meaning[100];
}dec;

void split(dec v[30]){

    FILE *file = fopen("C:\\Users\\user\\CLionProjects\\untitled4\\inputWords.txt", "r");

    char buffer[300];
    char words[300][300];
    dec a;
    char *ptr;
    int n = 0;

    while (!feof(file)) {
        fgets(buffer, sizeof(buffer), file);
        char *split = strtok(buffer, "\t\n.");
        while (split != NULL) {
            strcpy(words[n], split);
            n++;
            split = strtok(NULL, "\t\n.");
        }
        fgets(buffer, sizeof(buffer), file);
    }

        char *p;
        int k = 0;
        char l[30];

        for (int i = 1; i < 300; i += 2) {
            ptr = strtok(words[i], ":");
            strcpy(l, ptr);
            char h[30];
            int a = 0;
            for (int j = 0; j < 30; j++) {
                if (l[j] != ' ') {
                    h[a] = l[j];
                    a++;
                }
            }
            printf("%s\n",h);
            strcpy(v[k].word, h);
            ptr = strtok(NULL, ":");
            strcpy(v[k].meaning, ptr);
            printf("%s %s\n", v[k].word, v[k].meaning);
            k++;
        }
    }


int main(int argc, char **argv) {

    print();
    int op;
    scanf("%d", &op);

    FILE *file = fopen("C:\\Users\\user\\CLionProjects\\untitled4\\inputWords.txt", "r");

    char buffer[300];
    char words[300][300];
    dec a;
    dec b[30];
    char *ptr;
    int i = 0;
    char *f;

        switch (op) {
            case 1 :
                printf("the data in the file is here :\n");
                while (!feof(file)) {
                    fgets(buffer, sizeof(buffer), file);
                    printf("%s", buffer);
                    fgets(buffer, sizeof(buffer), file);

                }
                break;
            case 2:
                //split(b);
                printf("enter the word you want to search on");
                char d[30];
                scanf("%s", d);
                int o = 0;
                for (int i = 0; i < 300; i++) {
                    if (strcmp(b[i].word, d) == 0 && o == 0) {
                        printf("%d.%s :%s", b[i].wordno, b[i].word, b[i].meaning);
                    }
                }
                if (o == 1) {
                    printf("the word not exixst");
                }
                break;
            case 3:
                split(b);
                char c;
                scanf("%c", &c);
                for (int v = 0; v < 300; v++) {
                    if (strncmp(b[v].word, c, 1) == 0) {
                        printf("%d %s %s ", b[v].wordno, b[v].word, b[v].meaning);
                    }
                }
                break;

            case 4:
                file = fopen("C:\\Users\\user\\CLionProjects\\untitled4\\inputWords.txt", "a");
                if (file == NULL) {
                    exit(1);
                }
                printf("enter a the number of the word \nenter the word \nenter the meaning");
                fgets(buffer, sizeof(buffer), file);
                fseek(file, 0, SEEK_END);
                scanf("%d %s %s", &a.wordno, a.word, a.meaning);
                break;

            case 5:
                file = fopen("C:\\Users\\user\\CLionProjects\\untitled4\\inputWords.txt", "a");
                if (file == NULL) {
                    exit(1);
                }
                printf("enter a the number of the word \nenter the word \nenter the meaning");
                fgets(buffer, sizeof(buffer), file);
                fseek(file, 0, SEEK_END);
                scanf("%d %s %s", &a.wordno, a.word, a.meaning);
                if (a.wordno < 150) {
                    printf("the word must have the number more than 149");
                } else {
                    fprintf(file, "\n%d. %s: %s", a.wordno, a.word, a.meaning);
                }
                break;
            case 6:
                exit(file);
                break;

            default:
                printf("you should enter numbers between 1 to 5 only");
                break;
        }


fclose(file);

    return 0;
}



