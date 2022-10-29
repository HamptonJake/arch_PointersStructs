#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "POI_operations.h"
#define MAX_LINES 100
#define MAX_LEN 1000


int main(int argc, char **argv){
	/* One way to initialize a POI, by using a pointer */
	struct poi_t_struct *w = (struct poi_t_struct*) malloc(sizeof(struct poi_t_struct));

	/* Another way to initialize a POI, by using a struct, then getting the address of the struct and storing it as a pointer */
	struct poi_t_struct w2 = {"William Basquez", 123452, 3, NULL};
	struct poi_t_struct *ptr_w2 = &w2;

	w->name = "William Basquez";
	w->id = 12345;
	w->threat_level = 3;
	//w->next = w2; Not Doable
	w->next = ptr_w2;

	//print_record(w);
	//print_record(ptr_w2);

	//print_list(ptr_w2);




    //Credit to Portfolio Courses for creating array from file contents
    char file_path[260];
	printf("Please enter the path of the file you want to read: \n");
	scanf("%s", file_path);

    char data[MAX_LINES][MAX_LEN];

	FILE * file_to_open = fopen(file_path, "r");

    if(file_to_open == NULL){
        printf("Error opening file\n");
        return 1;
    }

    int lineCounter = 0;

    while(!feof(file_to_open) && !ferror(file_to_open)){
        if (fgets(data[lineCounter], MAX_LEN, file_to_open) != NULL){
            lineCounter++;
        }
    }
    fclose(file_to_open);


    int i;

    struct poi_t_struct *p = NULL;
    struct poi_t_struct *added = NULL;
    struct poi_t_struct *personB = NULL;
    struct poi_t_struct **pptr = &p;



    //Assuming that there are 3 criteria per struct, read the file 3 lines at a time
    //Assistance from Bluefever Software on YT for building the linked list
    for(i = 0; i < lineCounter; i+=3){
        if(p == NULL){
            p = (struct poi_t_struct*) malloc(sizeof(struct poi_t_struct));
            p->id = atoi(data[i]);
            data[i+1][strlen(data[i+1])-1] = '\0'; // Credits to Portfolio Courses for removing new line character
            p->name = data[i+1];
            p->threat_level = atoi(data[i+2]);
            p->next = NULL;

            if(p != NULL){
                added = p;
            }
        }else{
            personB = (struct poi_t_struct*) malloc(sizeof(struct poi_t_struct));
            added->next = personB;
            personB->id = atoi(data[i]);
            data[i+1][strlen(data[i+1])-1] = '\0';
            personB->name = data[i+1];
            personB->threat_level = atoi(data[i+2]);
            personB->next = NULL;
            added = personB;
        }

    }


    int userquit = 0;
    int rem_threat;
    int user_id;

    while(userquit != 8){

        printf("Please enter the operation you'd like to perform:\n");
        switch(get_user_option()){
            fflush(stdin);
            case 1:
                print_list(p);
                break;
            case 2:
                print_record(search_by_name(p));
                break;
            case 3:
                fflush(stdin);
                printf("Enter the POI ID:\n");
                scanf("%d", &user_id);
                fflush(stdin);
                print_record(search_by_ID(p, user_id));
                break;
            case 4:
                break;
            case 5:
                fflush(stdin);
                printf("Enter the threat level you wish to remove:\n");
                scanf("%d", &rem_threat);
                fflush(stdin);
                remove_all_records(pptr, p, rem_threat);
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                userquit = 8;
                break;
            default:
                printf("That is not a valid option\n");
        }
    }





    struct poi_t_struct w3 = {"Jake", 777777, 7, NULL};
	struct poi_t_struct *ptr_w3 = &w3;

    //insert_to_first(pptr, ptr_w3);
    remove_all_records(pptr, p, 5);

    //print_list(p);








	return 0;
}
