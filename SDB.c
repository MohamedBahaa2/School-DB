#include "STD.h"
#include "SDB.h"
#include <stdlib.h>
#include <stdio.h>

student *data_base = NULL;
u8 used_size = 0;
const u8 MAX_SIZE = 10;

void initialize_database(){
   
        data_base = (student*)calloc(MAX_SIZE, sizeof(student));

}

Bool isFull() {
    return used_size >= MAX_SIZE ? t : f;
}

u8 get_used_size() {   
    return used_size;
}

Bool addEntry() {
    
    if (isFull()) {
        printf("\nThe database is already full, consider deleting before adding to it!");
        return f;
    } else {
        student* newStudent = &data_base[used_size];
        
        printf("\nPlease enter the ID: ");
        scanf("%d", &newStudent->Student_ID);

        printf("\nPlease enter the year: ");
        scanf("%d", &newStudent->Student_year);

        printf("\nPlease enter course_1 ID: ");
        scanf("%d", &newStudent->Course1_ID);

        printf("\nPlease enter the course_1 Grade: ");
        scanf("%d", &newStudent->Course1_grade);

        printf("\nPlease enter course_2 ID: ");
        scanf("%d", &newStudent->Course2_ID);

        printf("\nPlease enter course_2 Grade: ");
        scanf("%d", &newStudent->Course2_grade);

        printf("\nPlease enter course_3 ID: ");
        scanf("%d", &newStudent->Course3_ID);

        printf("\nPlease enter the course_3 Grade: ");
        scanf("%d", &newStudent->Course3_grade);

        used_size++;
        return t;
    }
}

void deletEntry(u32 id) {
    
    Bool found = f;
    
    for (u8 i = 0; i < used_size; i++) {
        if (data_base[i].Student_ID == id) {
            found = t;
            for (u8 j = i; j < used_size - 1; j++) {
                data_base[j] = data_base[j + 1];
            }
            used_size--;
            break;
        }
    }

    if (!found) {
        printf("\nNo student with ID: %d was found!", id);
    }
}

Bool readEntry(u32 id) {
    
    for (u8 i = 0; i < used_size; i++) {
        if (data_base[i].Student_ID == id) {
            student* ptr = &data_base[i];
            printf("\nID: %d", ptr->Student_ID);
            printf("\nThe year: %d", ptr->Student_year);

            printf("\nCourse_1 ID: %d", ptr->Course1_ID);
            printf("\nCourse_1 Grade: %d", ptr->Course1_grade);

            printf("\nCourse_2 ID: %d", ptr->Course2_ID);
            printf("\nCourse_2 Grade: %d", ptr->Course2_grade);

            printf("\nCourse_3 ID: %d", ptr->Course3_ID);
            printf("\nCourse_3 Grade: %d", ptr->Course3_grade);

            return t;
        }
    }
    printf("\nNo student with ID: %d was found!", id);
    return f;
}

void getList(u8* count, u32* list) {
    
    if (*count > used_size) {
        printf("\nInsufficient IDs, try reducing the count!");
    } else {
        for (u8 i = 0; i < *count; i++) {
            list[i] = data_base[i].Student_ID;
        }
    }
}

Bool idExists(u32 id) {
    
    for (u8 i = 0; i < used_size; i++) {
        if (data_base[i].Student_ID == id) {
            return t;
        }
    }
    return f;
}
