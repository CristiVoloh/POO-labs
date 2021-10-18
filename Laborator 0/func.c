#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "header.h"

// ------- Create node -------- //
struct list* new_node(list *element){
    list *temp = (list*)malloc(sizeof(list));
    temp->data = element->data;
    temp->next = NULL;
    return temp;
}
// ---------------------------- //

// ------ Queue functions ------ //
struct queue* initialize_queue(){
    q = (queue*)malloc(sizeof(queue));
    q->head = NULL;
    q->tail = NULL;
    return q;
}
int en_queue(list *element){
    list *temp = new_node(element);
    if(q->tail == NULL){
        q->head = q->tail = temp;
        return 1;
    }
    q->tail->next = temp;
    q->tail = temp;
}
// ----------------------------- //

// ------ List functions ------- //
void create_list(int n){
    list *c, *p;
    for(int i = 0; i < n; i++){
        c = (list*)malloc(sizeof(list));
            if(i == 0){
                head = c;
                p = c;
            }
            else{
                p->next = c;
                p = c;
            }
    }
    p->next = NULL;
}
// ----------------------------- //

// ------ Stack functions ------ //
int isEmpty(){
    return !root;
}
void push(list *element){
    // Using list - structure for pushing into the stack.
    list *to_push = new_node(element);
    to_push->next = root;
    root = to_push;
}
struct data_struct pop(){
    if(isEmpty(root))
        printf("\nThe root is empty!");
    else{
        list *temp = root;
        data_struct popped;
        root = root->next;
        popped = temp->data;
        free(temp);
        return popped;
    }
}
struct data_struct peek(){
    if (isEmpty(root))
        printf("\nEmpty stack");
    else
        return root->data;
}
// ----------------------------- //

// ------ File functions ------- //
void get_file_format(char *directory, int len, char *format){
    for(int i = 3; i >= 0; i--){
        *(format+3-i) = *(directory+len-i);
    }
}
int file_size(char *directory, int file_type){
    FILE *file;
    if(file_type == 1)
        file = fopen(directory, "r");
    else if(file_type == 2)
        file = fopen(directory, "rb");

    if(file){
        if(file_type == 1){
            int ch = 0, lines = 0;
            while ((ch = fgetc(file)) != EOF){
                if (ch == '\n')
                    lines++;
            }
            fclose(file);
            return lines;
        }
        else if(file_type == 2){
            int n;
            fseek(file, 0, SEEK_END);
            int file_size = ftell(file);
                if(file_size < sizeof(list))
                    return 0;
            n = (file_size / sizeof(list));
            fseek(file, 0, SEEK_SET);

            fclose(file);
            return n;
        }
    }
    else{
        printf("\nError while opening the file!");
        return 0;
    }
}
void data_to_txtFile(char *directory, int struct_type){
    FILE *file;

    list *current;

    if(struct_type == 1)
        current = head;
    else if(struct_type == 2)
        current = q->head;
    else if(struct_type == 3)
        current = root;

    file = fopen(directory, "w");

    if(file){
        int i = 0;
        while(current != NULL){
            fprintf(file, " %d", i+1);
            fprintf(file, " %s", current->data.brand_name);
            fprintf(file, " %d", current->data.releasing_year);
            fprintf(file, " %s", current->data.gas_type);
            fprintf(file, " %s", current->data.body_type);
            fprintf(file, " %d", current->data.engine_capacity);
            fprintf(file, " %s\n", current->data.color);
            current = current->next;
            i++;
        }
        printf("\n| Elements successfuly saved!");
    }
    else{
        printf("\n Error while entering data into the file!");
    }
    fclose(file);
}
void data_to_binFile(char *directory, int struct_type){
    FILE *file;
    list *current;

    if(struct_type == 1)
        current = head;
    else if(struct_type == 2)
        current = q->head;
    else if(struct_type == 3)
        current = root;

    file = fopen(directory, "wb");

    if(file){
        while(current != NULL){
            fwrite(current, 1, sizeof(list), file);
            current = current->next;
        }
        if(file != NULL)
            printf("\nList was successfuly introduced in the file.");
    }
    else
        printf("\nError while creating / openin the file!");
    fclose(file);
}
void data_from_txtFile(int n, char *directory, int struct_type){
    FILE *file;

    list *current;

    if(struct_type == 1)
        current = head;
    else if(struct_type == 2 || struct_type == 3)
        current = (list*)malloc(sizeof(list));

    file = fopen(directory, "r");
    int temp;

    if(file){
        for(int i = 0; i < n; i++){
            fscanf(file, " %d", &temp);
            fscanf(file, " %s", current->data.brand_name);
            fflush(stdin);
            fscanf(file, " %d", &current->data.releasing_year);
            fscanf(file, " %s", current->data.gas_type);
            fflush(stdin);
            fscanf(file, " %s", current->data.body_type);
            fflush(stdin);
            fscanf(file, " %d", &current->data.engine_capacity);
            fscanf(file, " %s\n", current->data.color);
            fflush(stdin);

            if(struct_type == 1)
                current = current->next;
            else if(struct_type == 2)
                en_queue(current);
            else if(struct_type == 3)
                push(current);
        }
        printf("\n| Elements successfuly saved!");
    }
    else{
        printf("\n Error while entering data into the file!");
    }
    fclose(file);
}
void data_from_binFile(int n, char *directory, int struct_type){
    FILE *file;
    list *current;
    
    if(struct_type == 1)
        current = head;
    else if(struct_type == 2 || struct_type == 3)
        current = (list*)malloc(sizeof(list));

    file = fopen(directory, "rb");

    if(file){
        for(int i = 0; i < n; i++){
            fread(current, 1, sizeof(list), file);

            if(struct_type == 1)
                current = current->next;
            else if(struct_type == 2)
                en_queue(current);
            else if(struct_type == 3)
                push(current);
        }
    }
    else
        printf("\nError while creating / openin the file!");

    fclose(file);

}
int check_existance(char *directory, int file_type){
    FILE *file;

    if(file_type == 1)
        file = fopen(directory, "w");
    if(file_type == 2)
        file = fopen(directory, "wb");
    if(file){
        printf("\n| File successfuly created!");
        fclose(file);
        return 1;
    }
    else 
        return 0;
}
// ---------------------------- //

// ------- Main functions ------ //
void scan(list *element, int count){
    printf("\n------- Car %d --------", count);
        printf("\n[%d] Enter brand: ", count);
            scanf("%s", element->data.brand_name);
            fflush(stdin);
        printf("[%d] Enter releasing year: ", count);
            scanf("%d", &element->data.releasing_year);
        printf("[%d] Enter gas type: ", count);
            scanf("%s", element->data.gas_type);
            fflush(stdin);
        printf("[%d] Enter body type: ", count);
            scanf("%s", element->data.body_type);
            fflush(stdin);
        printf("[%d] Enter engine capacity: ", count);
            scanf("%d", &element->data.engine_capacity);
        printf("[%d] Enter color: ", count);
            scanf("%s", element->data.color);
            fflush(stdin);
}
void print(list *element, int count){
    printf("\n [Car %d] Brand: %s", count, element->data.brand_name);
    printf(" | Releasing year: %d", element->data.releasing_year);
    printf(" | Gas type: %s", element->data.gas_type);
    printf(" | Body type: %s", element->data.body_type);
    printf(" | Engine capacity: %d", element->data.engine_capacity);
    printf(" | Color: %s", element->data.color);
}
void swap(list *a, list *b){
    list temp;
    temp.data = a->data;
    a->data = b->data;
    b->data = temp.data;
}
void readStruct(int n, int struct_type){
    list *current;
    
    if(struct_type == 1)
        current = head;
    else if(struct_type == 2 || struct_type == 3)
        current = (list*)malloc(sizeof(list));

    int count = 1;
    for(int i = 0; i < n; i++){
        scan(current, count);
            if(struct_type == 1)
                current = current->next;
            else if(struct_type == 2)
                en_queue(current);
            else if(struct_type == 3)
                push(current);
        count++;
    }
     if(struct_type == 2 || struct_type == 3)
         free(current);

    printf("\nData has been successfuly got!");
        
}
void printStruct(int struct_type){
    list *current;
    
    if(struct_type == 1)
        current = head;
    else if(struct_type == 2)
        current = q->head;
    else if(struct_type == 3)
        current = root;

    int count = 1;
    while(current != NULL){
        print(current, count);
        current = current->next;
        count++;
    }
}
int addToStruct(int struct_type){
    list *temp = (list*)malloc(sizeof(list));
        scan(temp, 1);
    if(struct_type == 1){
        temp->next = head;
        head = temp;
    }
    else if(struct_type == 2)
        en_queue(temp);
    else if(struct_type == 3)
        push(temp);
        
    printf("\nCar successfuly added!");
    return 1;
}
void displayElement(int carNum, int struct_type){
    list *current;
    
    if(struct_type == 1)
        current = head;
    else if(struct_type == 2)
        current = q->head;
    else if(struct_type == 3)
        current = root;

    int num = 1;
    while(current != NULL){
        if(num == carNum){
            print(current, num);
        }
        current = current->next;
        num++;
    }
}
void changeElement(int struct_type){
    list *current;
    
    if(struct_type == 1)
        current = head;
    else if(struct_type == 2)
        current = q->head;
    else if(struct_type == 3)
        current = root;

    int carNum = 1, num;
    printf("\nEnter the number of the car you want to change: ");
        scanf("%d", &num);

    while(current != NULL){
        if(carNum == num){
            printf("[%d] Enter brand: ", carNum);
                scanf("%s", current->data.brand_name);
                fflush(stdin);
            printf("[%d] Enter releasing year: ", carNum);
                scanf("%d", &current->data.releasing_year);
            printf("[%d] Enter gas type: ", carNum);
                scanf("%s", current->data.gas_type);
                fflush(stdin);
            printf("[%d] Enter body type: ", carNum);
                scanf("%s", current->data.body_type);
                fflush(stdin);
            printf("[%d] Enter engine capacity: ", carNum);
                scanf("%d", &current->data.engine_capacity);
            printf("[%d] Enter color: ", carNum);
                scanf("%s", current->data.color);
                fflush(stdin);
        }
        current = current->next;
        carNum++;
    }
}
void searchElement(int struct_type){
    list *current;
    
    if(struct_type == 1)
        current = head;
    else if(struct_type == 2)
        current = q->head;
    else if(struct_type == 3)
        current = root;

    int choice, search_int, carNum = 1; 
    char search_char[20];
    printf("\nSearch cars by: \n[1] Brand\n[2] Year\n[3] Gas type\n[4] Body\n[5] Engine capacity\n[6] Color\n");
    printf("\nEnter value: ");
        scanf("%d", &choice);
    switch(choice){
        case 1:
            printf("\nEnter brand: ");
                scanf("%s", &search_char);
            system("cls");
            printf("\n----------------------------------------------------------------------\n");
            printf("\t\t\tCars founded by brand name - %s\t", search_char);
            printf("\n----------------------------------------------------------------------\n");
            while(current != NULL){
                if(strcmp(current->data.brand_name, search_char) == 0){
                    displayElement(carNum, struct_type);
                }
                carNum++;
                current = current->next;
            }
        break;

        case 2:
            printf("\nEnter year: ");
                scanf("%d", &search_int);
            system("cls");
            printf("\n----------------------------------------------------------------------\n");
            printf("\t\t\tCars founded by year - %d\t", search_int);
            printf("\n----------------------------------------------------------------------\n");
            while(current != NULL){
                if(current->data.releasing_year == search_int){
                    displayElement(carNum, struct_type);
                }
                carNum++;
                current = current->next;
            }
        break;

        case 3:
            printf("\nEnter gas type: ");
                scanf("%s", &search_char);
            system("cls");
            printf("\n----------------------------------------------------------------------\n");
            printf("\t\t\tCars founded by gas type - %s\t", search_char);
            printf("\n----------------------------------------------------------------------\n");
            while(current != NULL){
                if(strcmp(current->data.gas_type, search_char) == 0){
                    displayElement(carNum, struct_type);
                }
                carNum++;
                current = current->next;
            }
        break;

        case 4:
            printf("\nEnter body type: ");
                scanf("%s", &search_char);
            system("cls");
            printf("\n----------------------------------------------------------------------\n");
            printf("\t\t\tCars founded by body type - %s\t", search_char);
            printf("\n----------------------------------------------------------------------\n");
            while(current != NULL){
                if(strcmp(current->data.body_type, search_char) == 0){
                    displayElement(carNum, struct_type);
                }
                carNum++;
                current = current->next;
            }
        break;

        case 5:
            printf("\nEnter engine capacity: ");
                scanf("%d", &search_int);
            system("cls");
            printf("\n----------------------------------------------------------------------\n");
            printf("\t\t\tCars founded engine capacity - %d\t", search_int);
            printf("\n----------------------------------------------------------------------\n");
            while(current != NULL){
                if(current->data.engine_capacity == search_int){
                    displayElement(carNum, struct_type);
                }
                carNum++;
                current = current->next;
            }
        break;

        case 6:
            printf("\nEnter color: ");
                scanf("%s", &search_char);
            system("cls");
            printf("\n----------------------------------------------------------------------\n");
            printf("\t\t\tCars founded by color - %s\t", search_char);
            printf("\n----------------------------------------------------------------------\n");
            while(current != NULL){
                if(strcmp(current->data.color, search_char) == 0){
                    displayElement(carNum, struct_type);
                }
                carNum++;
                current = current->next;
            }
        break;
    }
}
void sortStruct(int struct_type){
    list *current, *next, temp;
    int choice;
    bool sorted = true;
    printf("\nSearch cars by: \n[1] Brand\n[2] Year\n[3] Gas type\n[4] Body\n[5] Engine capacity\n[6] Color");
    printf("\n\nEnter value: ");
        scanf("%d", &choice);
    
    if(struct_type == 1)
            current = head;
    else if(struct_type == 2)
        current = q->head;
    else if(struct_type == 3)
        current = root;

    do{
        sorted = true;
        if(struct_type == 1)
            current = head;
        else if(struct_type == 2)
            current = q->head;
        else if(struct_type == 3)
            current = root;

        while(current->next != NULL){
            next = current->next;
                switch(choice){
                    case 1:
                        if(strcmp(current->data.brand_name, next->data.brand_name) > 0){
                            swap(current, next);
                            sorted = false;
                        }
                    break;
                    case 2:
                        if(current->data.releasing_year > next->data.releasing_year){
                            swap(current, next);
                            sorted = false;
                        }
                    break;
                    case 3:
                        if(strcmp(current->data.gas_type, next->data.gas_type) > 0){
                            swap(current, next);
                            sorted = false;
                        }
                    break;
                    case 4:
                        if(strcmp(current->data.body_type, next->data.body_type) > 0){
                            swap(current, next);
                            sorted = false;
                        }
                    break;
                    case 5:
                        if(current->data.engine_capacity > next->data.engine_capacity){
                            swap(current, next);
                            sorted = false;
                        }
                    break;
                    case 6:
                        if(strcmp(current->data.color, next->data.color) > 0){
                            swap(current, next);
                            sorted = false;
                        }
                    break;
                }
            current = current->next;
        }
    }while(!sorted);

    printf("\nCars successfuly sorted!");
}
int removeElement(int n, int struct_type){
    int choice, count = 1;
    list *current, *to_delete;

    printf("\nEnter the number of the car to remove [1-%d]: ", n);
        scanf("%d", &choice);
    if(choice > n || choice < 1)
        return 0;

    if(choice == 1){
        if(struct_type == 1){
            to_delete = head;
            head = head->next;
        }
        else if(struct_type == 2){
            to_delete = q->head;
            q->head = q->head->next;
        }
        else if(struct_type == 3)
            to_delete = root;
            root = root->next;

        free(to_delete);
        printf("\nCar successfuly removed!");
        return 1;
    }

    if(struct_type == 1)
        current = head;
    else if(struct_type == 2)
        current = q->head;
    else if(struct_type == 3)
        current = root;

    while(current != NULL){
        if(count == choice-1){
            to_delete = current->next;
            current->next = current->next->next;
            free(to_delete);
        }
        count++;
        current = current->next;
    }
    printf("\nCar successfuly removed!");
    return 1;

}
void swapTwoElements(int struct_type){
    list *current, *temp1, *temp2;

    if(struct_type == 1)
        current = head, temp1 = head, temp2 = head;
    else if(struct_type == 2)
        current = q->head, temp1 = q->head, temp2 = q->head;
    else if(struct_type == 3)
        current = root, temp1 = root, temp2 = root;

    int element1, element2, count = 1;

    printf("\nEnter element 1: ");
        scanf("%d", &element1);
    printf("\nEnter element 2: ");
        scanf("%d", &element2);

    while(current != NULL){
        if(element1 == count)
            temp1 = current;
        else if(element2 == count)
            temp2 = current;
        current = current->next;
        count++;
    }
    swap(temp1, temp2);
    printf("\nElements successfuly swaped!");
}
void deleteStruct(int struct_type){
    list *current, *next = NULL;;

    if(struct_type == 1)
        current = head;
    else if(struct_type == 2)
        current = q->head;
    else if(struct_type == 3)
        current = root;

    if(current != NULL){
        while(current != NULL){
            next = current->next;
            free(current);
            current = next;
        }

        if(struct_type == 1){
            head = NULL;
            free(head);
        }    
        else if(struct_type == 2){
            q->head = NULL;
            free(head);
        }  
        else if(struct_type == 3){
            root = NULL;
            free(root);
        } 
    } else
        printf("\n| There is no any element.");
}
void lastElementAddress(int struct_type){
    list *current;

    if(struct_type == 1)
        current = head;
    else if(struct_type == 2)
        current = q->head;
    else if(struct_type == 3)
        current = root;

    while(current->next != NULL){
        current = current->next;
    }
    printf("\n%p", current);
}
int numberOfElements(int struct_type){
    list *current;

    if(struct_type == 1)
        current = head;
    else if(struct_type == 2)
        current = q->head;
    else if(struct_type == 3)
        current = root;

    int count = 0;
    while(current != NULL){
        count++;
        current = current->next;
    }
    printf("\n| %d elements.", count);
    return count;
}
// ----------------------------- //

int menu2(int struct_type, int file_type){
    int exit = 0, n = 0, choice = 0, data = 0, go_to_menu = 0;
    char directory[100], name[20], format[3];
    do {
        system("cls");
        printf("\n|                 Made by Cristi Voloh                       |");
        printf("\n|------------------------------------------------------------|");
        printf("\n|                 CARS DATABASE - MENU                       |");
        printf("\n|------------------------------------------------------------|");
        printf("\n| [1] Start working with an existing file.                   |");
        printf("\n| [2] Create a new database.                                 |");
        printf("\n| [3] Display the elements.                                  |");
        printf("\n| [4] Add a new car.                                         |");
        printf("\n| [5] Display an element.                                    |");
        printf("\n| [6] Change an element.                                     |");
        printf("\n| [7] Search for an element.                                 |");
        printf("\n| [8] Sort elements.                                         |");
        printf("\n| [9] Remove an element.                                     |");
        printf("\n| [10] Swap two elements.                                    |");
        printf("\n| [11] Delete all elements.                                  |");
        printf("\n| [12] Get last element address.                             |");
        printf("\n| [13] Number of elements.                                   |");
        printf("\n| [14] Save the elements into the file.                      |");
        printf("\n| [15] Back to main menu.                                    |");
        printf("\n| [0] Exit.                                                  |");
        printf("\n-------------------------------------------------------------|");
        printf("\nChoose the option: ");
            scanf("%d", &choice);
        switch(choice){
            case 1:
            // D:/Salvate 15.08.19/Cristi/Programare/C/database_test.txt
                system("cls");
                printf("\n|----------------------------------------------------------------------|");
                printf("\n|                  Enter the directory of the file.                    |");
                printf("\n|----------------------------------------------------------------------|");
                printf("\n| For example -> D:/Salvate 15.08.19/Cristi/Programare/C/test.txt      |");
                printf("\n| Enter a value: ");
                    fflush(stdin); 
                    fgets(directory, 100, stdin);
                    directory[strlen(directory)-1] = '\0';

                get_file_format(directory, strlen(directory), format);

                    if(file_type == 1 && (format[0] != 't' && format[1] != 'x' && format[2] != 't')){
                        printf("|\n| Error! Choose a file with right format (TXT)");
                        break;
                    } 
                    else if(file_type == 2 && (format[0] != 'b' && format[1] != 'i' && format[2] != 'n')){
                        printf("|\n| Error! Choose a file with right format (BIN)");
                        break;
                    }
                    
                n = file_size(directory, file_type);
                if(n < 1){
                    printf("\nError! There isn't any data!");
                    break;
                }
                
                if(struct_type == 1)
                    create_list(n);
                else if(struct_type == 2)
                    q = initialize_queue();
                else if(struct_type == 3)
                    root = NULL;
                else
                    break;

                if(file_type == 1)
                    data_from_txtFile(n, directory, struct_type);
                else if(file_type == 2)
                    data_from_binFile(n, directory, struct_type);
                else
                    break;

                data = 1;
                system("cls");
                printf("\n[%d] File data successfuly loaded!", n);
            break;

            case 2:
                system("cls");
                printf("\n|--------------------------------------------------------------------|");
                printf("\n|                        Create a new database.                      |");
                printf("\n|--------------------------------------------------------------------|");
                printf("\n| Enter the directory of the file (without name).                    |");
                printf("\n| For example -> D:/Programare/C/                                    |\n| Enter value: ");
                    fflush(stdin); 
                    fgets(directory, 100, stdin);
                    directory[strlen(directory)-1] = '\0';
                        if(strlen(directory) < 3){
                            printf("Error! Invalid directory!");
                            break;
                        }

                printf("| Enter database name (without format): ");
                    fflush(stdin); 
                    fgets(name, 20, stdin);
                    name[strlen(name)-1] = '\0';
                        if(strlen(name) < 1){
                            printf("Error! Invalid name!");
                            break;
                        }
                strcat(directory, name);

                if(file_type == 1)
                    strcat(directory, ".txt");
                if(file_type == 2)
                    strcat(directory, ".bin");

                printf("|\n| Directory is: %s", directory);

                int check = check_existance(directory, file_type);
                    if(check == 0){
                        printf("Error while creating the file!");
                        break;
                    }

                printf("\n|\n| Enter amount of cars: ");
                    scanf("%d", &n);
                        if(n < 1){
                            printf("\nError! There isn't any data!");
                            break;
                        }
                        
                system("cls");
                if(struct_type == 1)
                    create_list(n);
                else if(struct_type == 2)
                    q = initialize_queue();
                else if(struct_type == 3)
                    root = NULL;
                else 
                    break;
                
                readStruct(n, struct_type);
                data = 1;           
            break;

            case 3:
                system("cls");
                printf("\n|---------------------------------------------------------------------");
                printf("\n|             Displaying the elements of the database.                ");
                printf("\n|---------------------------------------------------------------------");
                if(data < 1) 
                    printf("\nError! There isn't any data!");
                else{
                    printStruct(struct_type);
                } 
            break;

            case 4:
                system("cls");
                printf("\n|--------------------------------------------------------------------|");
                printf("\n|          Adding a new car at the beginning of the list.            |");
                printf("\n|--------------------------------------------------------------------|");
                if(data < 1) 
                    printf("\nError! There isn't any data!");
                else{
                    int add = addToStruct(struct_type);
                        if(add == 1)
                            n++;
                } 
            break;

            case 5:
                system("cls");
                printf("\n|--------------------------------------------------------------------|");
                printf("\n|                      Display an element.                           |");
                printf("\n|--------------------------------------------------------------------|");
                if(data < 1) 
                    printf("\nError! There isn't any data!");
                else{
                    int carNum;
                    printf("\nEnter the number of the element [1-%d]: ", n);
                        scanf("%d", &carNum);
                            if(carNum < 1 || carNum > n)
                                printf("\nInvalid number!");

                    displayElement(carNum, struct_type);
                } 
            break;

            case 6:
                system("cls");
                printf("\n|--------------------------------------------------------------------|");
                printf("\n|                      Changing an element.                          |");
                printf("\n|--------------------------------------------------------------------|");
                if(data < 1) 
                    printf("\nError! There isn't any data!");
                else{
                    changeElement(struct_type);
                } 
            break;

            case 7:
                system("cls");
                printf("\n|--------------------------------------------------------------------|");
                printf("\n|                     Search for an element.                         |");
                printf("\n|--------------------------------------------------------------------|");
                if(data < 1) 
                    printf("\nError! There isn't any data!");
                else{
                    searchElement(struct_type);
                } 
            break;

            case 8:
                system("cls");
                printf("\n|--------------------------------------------------------------------|");
                printf("\n|                     Sorting all the elements.                      |");
                printf("\n|--------------------------------------------------------------------|");
                if(data < 1) 
                    printf("\nError! There isn't any data!");
                else{
                   sortStruct(struct_type);
                } 
            break;

            case 9:
                system("cls");
                printf("\n|--------------------------------------------------------------------|");
                printf("\n|                      Removing an element.                          |");
                printf("\n|--------------------------------------------------------------------|");
                if(data < 1) 
                    printf("\nError! There isn't any data!");
                else{
                    int remove = removeElement(n, struct_type);
                    if(remove != 0)
                        n--;
                } 
            break;

            case 10:
                system("cls");
                printf("\n|--------------------------------------------------------------------|");
                printf("\n|                         Swap two elements.                         |");
                printf("\n|--------------------------------------------------------------------|");
                if(data < 1) 
                    printf("\nError! There isn't any data!");
                else{
                    swapTwoElements(struct_type);
                } 
            break;

            case 11:
                system("cls");
                printf("\n|--------------------------------------------------------------------|");
                printf("\n|                   Delete all the elements.                         |");
                printf("\n|--------------------------------------------------------------------|");
                if(data < 1) 
                    printf("\nError! There isn't any data!");
                else{
                    deleteStruct(struct_type);
			     data = 0;
                    printf("\n| All elemets are successfuly deleted.");
                } 
            break;

            case 12:
                system("cls");
                printf("\n|--------------------------------------------------------------------|");
                printf("\n|                      Last element address.                         |");
                printf("\n|--------------------------------------------------------------------|");
                if(data < 1) 
                    printf("\nError! There isn't any data!");
                else{
                    printf("\n| ");
                    lastElementAddress(struct_type);
                } 
            break;

            case 13:
                system("cls");
                printf("\n|--------------------------------------------------------------------|");
                printf("\n|                           Elements number.                         |");
                printf("\n|--------------------------------------------------------------------|");
                if(data < 1) 
                    printf("\nError! There isn't any data!");
                else{
                    numberOfElements(struct_type);
                } 
            break;

            case 14:
                system("cls");
                printf("\n|--------------------------------------------------------------------|");
                printf("\n|             Saving the elements into the file.                     |");
                printf("\n|--------------------------------------------------------------------|");
                if(data < 1) 
                    printf("\nError! There isn't any data!");
                else{
                    if(file_type == 1)
                        data_to_txtFile(directory, struct_type);
                    if(file_type == 2)
                        data_to_binFile(directory, struct_type);
                } 
            break;

            case 15:
                choice = 0;
                exit = 1;
                deleteStruct(struct_type);
            break;

            case 0:
                choice = 0;
                exit = 0;
                deleteStruct(struct_type);
            break;
        }

        if(choice != 0){
            printf("\n\nGo to menu? - [Enter anything]: ");
                scanf("%d", &go_to_menu);
            if(go_to_menu != 0)
                system("cls");
        }

    } while(choice != 0);

    return exit;
}
void menu1(){
    int struct_type, file_type, exit;
        do{
            system("cls");
            printf("\n|------------------------------------------------------------|");
            printf("\n|       Choose the type of the data structure                |");
            printf("\n|------------------------------------------------------------|");
            printf("\n| [1] List.                                                  |");
            printf("\n| [2] Queue.                                                 |");
            printf("\n| [3] Stack.                                                 |");
            printf("\n| [0] Exit.                                                  |");
            printf("\n|------------------------------------------------------------|");
            et1:printf("\nChoose the option: ");
                scanf("%d", &struct_type);

            if(struct_type == 1 || struct_type == 2 || struct_type == 3){
                system("cls");
                printf("\n|------------------------------------------------------------|");
                printf("\n|               Choose the type of the file                  |");
                printf("\n|------------------------------------------------------------|");
                printf("\n| [1] TXT.                                                   |");
                printf("\n| [2] BIN.                                                   |");
                printf("\n| [0] Back.                                                  |");
                printf("\n|------------------------------------------------------------|");
                printf("\nChoose the option: ");
                    scanf("%d", &file_type);

                if(file_type == 1 || file_type == 2)
                    exit = menu2(struct_type, file_type);
                else
                    system("cls");
            }   
            else if(struct_type == 0){
                printf("\nGood bye!");
                exit = 0;
            }
            else{
                printf("\nEnter a correct value.");
                goto et1;
            }
        } while(exit != 0);
}
