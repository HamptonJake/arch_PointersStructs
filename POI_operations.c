#include <stdio.h>
#include <stdlib.h>
#include "POI_operations.h"

void print_list_of_POIs(struct poi_t_struct *head){
    /* Print the linked list content (ID, Name, and threat level) */
    struct poi_t_struct *temp = head;
	while (temp != NULL){
		print_record(temp);
		temp = temp->next;
	}

}

int compare_names(char* a, char* b){
    while(*a != '\0'){
            //printf("Comparing: %c to %c\n", *a, *b);
        if(*a != *b){
            return 1;
        }
        a++;
        b++;
    }
    return 0;
}


int get_user_option(){
    int user_option;
    printf("1: Print linked list\n2: Search POI by name (Case sensitive)\n3: Search POI by ID\n4: Remove single record by ID\n5: Remove all records from certatin threat level\n6: Insert at index\n7: Write to file\n8: Quit\n");
    scanf("%d", &user_option);
    return user_option;
}

struct poi_t_struct *search_by_name(struct poi_t_struct *head){
    fflush(stdin); //Credits to GeeksforGeeks for clearing stdin
    struct poi_t_struct *temp = head;
    char user_name[100];
    printf("Enter the name: \n");
    scanf("%[^\n]%*c", user_name); //Credits to Portfolio Courses for accepting spaces in stdin
    fflush(stdin);
    printf("You entered %s\n", user_name);

    while(temp != NULL){
        if(compare_names(temp->name, user_name) == 0){
            printf("**Found**\n");
            return temp;
        }
        temp = temp->next;
    }

    printf("Name not found, returned head\n");
    return head;

}

struct poi_t_struct *search_by_ID(struct poi_t_struct *head, long user_id){

    struct poi_t_struct *temp = head;
    while(temp != NULL){
        //printf("Comparing %d with %d\n", temp->id, user_id);
        if(temp->id == user_id){
            printf("**Found**\n");
            return temp;
        }
        temp = temp->next;
    }
    printf("ID not found, returned head\n");
    return head;
}

void insert_record_at_index(struct poi_t_struct *head, int index){

    /* Insert a new person into the list at a particular location index (index 0 being the first record) */
}

struct poi_t_struct *sort_list_of_POIs(struct poi_t_struct *head){

/* Sort the list by thread level (can be ascending or descending order) */
}

void remove_by_ID(struct poi_t_struct **headptr, struct poi_t_struct *head, long id){
/* Remove a record containing a specific ID */


}

//maybe remove by name?

void remove_all_records(struct poi_t_struct **headptr, struct poi_t_struct *head, int TL){
    struct poi_t_struct *temp = head;
    if(temp->next == NULL && temp->threat_level == TL){
        temp = NULL;
    }
    int iteration = 0;
	while (temp->next != NULL){
        if(temp->next == NULL && temp->threat_level == TL){
            temp = NULL;
        }

		if (temp->threat_level == TL && iteration == 0){
		    *headptr = temp->next;

		}

		if(temp->next->threat_level == TL && temp->next->next != NULL){
                temp->next = temp->next->next;
		}

		if(temp->next->threat_level == TL && temp->next->next == NULL){
            temp->next = NULL;
		}

        if(temp->next != NULL){
            temp = temp->next;
        }

		iteration ++;
	}

}

void write_to_file(struct poi_t_struct *head){
/* Write content of the linked list into an output file (a .txt file) */
}

void print_record(struct poi_t_struct *p)
{
	if(p != NULL){
		printf("Name: %s\n", p->name);
   		printf("Threat: #%d\n",p->threat_level);
   		printf("ID: #%ld\n\n",p->id);
   	}
}

void print_list (struct poi_t_struct *p){
	struct poi_t_struct *temp = p;

	while (temp != NULL){
		print_record(temp);
		temp = temp->next;
	}
}

void insert_to_first(struct poi_t_struct **head, struct poi_t_struct *p){
	p->next = *head;
	*head = p;
}
