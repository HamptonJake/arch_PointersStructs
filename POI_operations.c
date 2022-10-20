#include <stdio.h>
#include <stdlib.h>
#include "POI_operations.h"

void print_list_of_POIs(struct poi_t_struct *head){
    /* Print the linked list content (ID, Name, and threat level) */
}

struct poi_t_struct *search_by_name(struct poi_t_struct *head, char *name){
    /* Search a person of interest */
}

struct poi_t_struct *search_by_ID(struct poi_t_struct *head, long id){
    /* Search a person of interest */
}

void insert_record_at_index(struct poi_t_struct *head, int index){
    /* Insert a new person into the list at a particular location index (index 0 being the first record) */
}

struct poi_t_struct *sort_list_of_POIs(struct poi_t_struct *head){
/* Sort the list by thread level (can be ascending or descending order) */
}

void remove_by_ID(struct poi_t_struct *head, long id){
/* Remove a record containing a specific ID */
}

//maybe remove by name?

void remove_all_records(struct poi_t_struct *head){
/* Remove all records with a certain threat level */
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