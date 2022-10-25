#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "POI_operations.h"

int main(int argc, char **argv){
	/* One way to initialize a POI, by using a pointer */
	struct poi_t_struct *w = (struct poi_t_struct*) malloc(sizeof(struct poi_t_struct));

	/* Another way to initialize a POI, by using a struct, then getting the address of the struct and storing it as a pointer */
	struct poi_t_struct w2 = {"William Basquez", 123452, 3, NULL};
	struct poi_t_struct *ptr_w2 = &w2;

	w->name = "William Basquez";
	w->id = 12345;
	w->threat_level = 3;
	w->next = NULL;

	print_record(w);
	print_record(ptr_w2);

    char file_path[260];
	printf("Please enter the path of the file you want to read: \n");
	scanf("%s", file_path);

	//printf("Is :%s correct?\n", file_path);

	FILE * file_to_open = fopen(file_path, "r");

    char line[100];

    while(fgets(line, sizeof(line), file_to_open)){
        //print the line
        printf("%s", line);
    }

	return 0;
}
