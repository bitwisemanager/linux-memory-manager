#include <memory.h>
#include <stdio.h>
#include <sys/mman.h> /* for using mmap */
#include <unistd.h>   /* for get pagesize */

static size_t SYSTEM_PAGE_SIZE = 0;

void mm_init() {
    SYSTEM_PAGE_SIZE = getpagesize();

    printf("pagesize: %lu\n", SYSTEM_PAGE_SIZE);
}

/* Function to request VM page from kernel */
static void *mm_get_new_vm_page_from_kernel(int units) {
    char *vm_page =
        mmap(0, units * SYSTEM_PAGE_SIZE, PROT_READ | PROT_WRITE | PROT_EXEC,
             MAP_ANON | MAP_PRIVATE, 0, 0);

    if (vm_page == MAP_FAILED) {
        printf("Error: VM Page allocation failled\n");
        return NULL;
    }
    memset(vm_page, 0, units * SYSTEM_PAGE_SIZE);

    return (void *)vm_page;
}

/* Function to return a page to kernel */
static void mm_return_vm_page_to_kernel(void *vm_page, int units) {
    if (munmap(vm_page, units * SYSTEM_PAGE_SIZE)) {
        printf("Error: Could not munmap VM page to kernel");
    }
}

int main(int argc, char **argv) {
    mm_init();
    printf("VM Page size = %lu\n", SYSTEM_PAGE_SIZE);

    void *addr1 = mm_get_new_vm_page_from_kernel(1);
    void *addr2 = mm_get_new_vm_page_from_kernel(1);

    printf("page 1 =  %p, page 2 = %p\n", addr1, addr2);

    return 0;
}
