#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct data_struct{
    char brand_name[20]; // Marca.
    int releasing_year; // Anul producerii.
    char gas_type[10]; // Combustibil.
    char body_type[10]; // Caroserie.
    int engine_capacity; // Capacitatea motorului.
    char color[10];
} data_struct;

// This structure will be used for lists and stacks.
typedef struct list{
    struct data_struct data;
    struct list *next;
} list;

// Queue elements will contain list nodes, because structure is the same.
typedef struct queue {
    list *head;
    list *tail;
} queue;

// Global declaration for making compact functions.
// Stack ‘*root’ is declared as 'list', because 'list' and 'stack'-s structure is the same.
list *head; // it will be ‘struct_type - 1’
queue *q; // it will be ‘struct_type - 2’
list *root; // it will be ‘struct_type - 3’, -> more details in menu1() function.

// ------- Create node -------- //
struct list* new_node(list *element);
// ---------------------------- //

// ------ Queue functions ------ //
struct queue* initialize_queue();
int en_queue(list *element);
// ----------------------------- //

// ------ List functions ------- //
void create_list(int n);
// ----------------------------- //

// ------ Stack functions ------ //
int isEmpty();
void push(list *element);
struct data_struct pop();
struct data_struct peek();
// ----------------------------- //

// ------ File functions ------- //
void get_file_format(char *directory, int len, char *format);
int file_size(char *directory, int file_type);
void data_to_txtFile(char *directory, int struct_type);
void data_to_binFile(char *directory, int struct_type);
void data_from_txtFile(int n, char *directory, int struct_type);
void data_from_binFile(int n, char *directory, int struct_type);
int check_existance(char *directory, int file_type);
// ---------------------------- //

// ------- Main functions ------ //
void scan(list *element, int count);
void print(list *element, int count);
void swap(list *a, list *b);
void readStruct(int n, int struct_type);
void printStruct(int struct_type);
int addToStruct(int struct_type);
void displayElement(int carNum, int struct_type);
void changeElement(int struct_type);
void searchElement(int struct_type);
void sortStruct(int struct_type);
int removeElement(int n, int struct_type);
void swapTwoElements(int struct_type);
void deleteStruct(int struct_type);
void lastElementAddress(int struct_type);
int numberOfElements(int struct_type);
// ----------------------------- //

int menu2(int struct_type, int file_type);
void menu1();

#endif
