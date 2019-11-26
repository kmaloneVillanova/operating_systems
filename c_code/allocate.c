#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    //we can declare a string like this:
    //char name[] = "kathleen";
    //or like this:
    //char name[100]; - later we can add up to 100 characters to name
    //if we know the size of the sting we can declare like this
    //or even if we have an approximation
    //memory space for these char arrays are set and allocated at compile time
    //memory remains throughout the life of the program whether we use it or not

    //or we can use dynamic memory and allocate memory at run-time
    //memory space for these pointers is unknown at compilation time
    //space will not be allocated until we initialize it at run-time
    //must be initialized before we use it

    char* first_name;
    char* middle_name;
    char* last_name;
    char* full_name;

    printf("What is your first name?\n");

    //note we don't have to put & here because first_name is an array AND a pointer
    first_name = malloc(100*sizeof(char));
    scanf("%s", first_name);

    printf("What is your middle name?\n");
    middle_name = malloc(100*sizeof(char));
    scanf("%s", middle_name);

    printf("What is your last name?\n");
    last_name = malloc(100 * sizeof(char));
    scanf("%s", last_name);

    //now we can declare the size of full name as the strlen of first name
    //middle name and last name
    //we need the size so we can allocate space for it
    int len = strlen(first_name) + strlen(middle_name) + strlen(last_name) +3;
    printf("allocate %i character memory spaces for full_name\n", len);
    //+3 is to hold the white space between names and for the terminating character
    //'0'
    //use malloc to dynamically allocate space in memory for the full name
    full_name = malloc(len*sizeof(*first_name));
    //or can declare like this:
    //full_name = malloc(len * sizeof(char));

    strcat(full_name, first_name);
    strcat(full_name, " ");
    strcat(full_name, middle_name);
    strcat(full_name, " ");
    strcat(full_name, last_name);

    printf("Full Name is = %s,  Address = %p\n", full_name, full_name);
    printf("String length is: %li\n", strlen(full_name));

    //never use realloc with memory that has not been dynamically allocated
    char* id = malloc(5*sizeof(char));
    strcpy(id," 1234");

    //what if we need more memory for the full name?
    //we can use realloc to reallocate memory for us
    //realloc will deallocate memory for full_name first using free
    char* full_name_id = realloc(full_name, strlen(full_name + strlen(id)));
    strcat(full_name_id,id);

    printf("Full Name is = %s,  Address = %p\n", full_name_id, full_name_id);
    printf("String length is: %li\n", strlen(full_name_id));
    

   //must use free to deallocate the memory we used
    free(full_name_id);
   return(0);
}
    