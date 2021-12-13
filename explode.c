#include <stdio.h>

char ** explode(char *separador, char *string, int *explode_size){

    char *str2=NULL;
    char *straux=NULL;
    char *strinicio=NULL;
    char **result=NULL;
    int tokens=1;

    //alocate string length and \0 to str2
    str2=malloc(strlen(string)+1);
    //copy string to str2
    strcpy(str2,string);
    //reset counter, pointer to 0
    *explode_size=0;
    //str2 to pointer strinicio and straux
    straux=strinicio=str2;
    while(straux){
        //substring word and delimiter
        straux=strstr(strinicio,separador);
        if (straux){
            //word delimiter end
            *straux='\0';

            result=realloc(result,tokens*sizeof(char *));


            result[tokens-1]=malloc((strlen(strinicio)+1)*sizeof(char));
            strcpy(result[tokens-1],strinicio);
            strinicio=straux+strlen(separador);
            tokens++;
        } else { //last word
            //result=realloc(result,tokens*sizeof(char *));
            result[tokens-1]=malloc(strlen(strinicio+1)*sizeof(char));
            strcpy(result[tokens-1],strinicio);
        }
        //increment position on array
        *explode_size += 1;
    }
    return result;
}

char * implode(char *separator, char **strings, int nstrings){

    char* str = NULL;             /* Pointer to the joined strings  */
    int total_length = 0;      /* Total length of joined strings */
    int i = 0;                    /* Loop counter                   */

    /* Find total length of joined strings */
    for (i = 0; i < nstrings; i++) total_length += strlen(strings[i]);
    total_length++;     /* For joined string terminator */
    total_length += strlen(separator) * (nstrings - 1); // for seperators

    str = malloc(total_length);  /* Allocate memory for joined strings */
    str[0] = '\0';                      /* Empty string we can append to      */

    /* Append all the strings */
    for (i = 0; i < nstrings; i++) {
        strcat(str, strings[i]);
        if (i < (nstrings - 1)){
             strcat(str, separator);
        }
    }

    return str;
    free(str);




}

int main(int argc, char const *argv[])
{
char **res;
char *res_implode;
int res_size;
int i;
res = explode(",", "Ana,Carlos,Francisco,Hugo,Xavier", &res_size);
for(i=0; i<res_size; i++) {
printf("|%s|\n", *(res+i));
}
res_implode = implode("::", res, res_size);
printf("|%s|\n", res_implode);
}
