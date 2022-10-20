#ifndef poi_functions
#define poi_functions

struct poi_t_struct {
	char *name;
	long int id;
	int threat_level;
	struct poi_t_struct *next;
};

void print_record(struct poi_t_struct*);
void print_list_of_POIs(struct poi_t_struct*);
struct poi_t_struct *search_by_name(struct poi_t_struct*, char*);
struct poi_t_struct *search_by_ID(struct poi_t_struct*, long);
void insert_record_at_index(struct poi_t_struct*, int);
struct poi_t_struct *sort_list_of_POIs(struct poi_t_struct*);
void remove_by_ID(struct poi_t_struct*, long);

//maybe remove by name?

void remove_all_records(struct poi_t_struct*);
void write_to_file(struct poi_t_struct* );

#endif