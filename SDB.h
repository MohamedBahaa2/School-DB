#ifndef _SDB_H_
#define _SDB_H_

#include "STD.h"

typedef struct SimpleDb {
    u32 Student_ID;
    u32 Student_year;
    u32 Course1_ID;
    u32 Course1_grade;
    u32 Course2_ID;
    u32 Course2_grade;
    u32 Course3_ID;
    u32 Course3_grade;
} student;

void initialize_database();
Bool isFull();
u8 get_used_size();
Bool addEntry();
void deletEntry(u32 id);
Bool readEntry(u32 id);
void getList(u8* count, u32* list);
Bool idExists(u32 id);

#endif
