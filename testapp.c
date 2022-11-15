#include "mm.h"
#include "uapi_mm.h"

#include <stdio.h>

typedef struct emp_ {
    char name[32];
    uint32_t emp_id;
} emp_t;

typedef struct student_ {
    char name[32];
    uint32_t rollno;
    uint32_t marks_phys;
    uint32_t marks_chem;
    uint32_t marks_maths;
    struct student_ *next;
} student_t;

int main(int argc, char **argv) {
    mm_init();

    MM_REG_STRUCT(emp_t);
    MM_REG_STRUCT(student_t);

    vm_page_family_t *vm_page_family = lookup_page_family_by_name("emp_t");
    if (!vm_page_family) {
        perror("There is no `emp_t` struct available.\n");
        return 1;
    }

    fprintf(stdout, "%s[%u]\n", vm_page_family->struct_name,
            vm_page_family->struct_size);

    return 0;
}
