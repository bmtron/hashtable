#include <stdio.h>
#include "hashtable.h"


int main() {

    
    HashTable *hash_table = hash_table_create(HASH_TYPE_STRING, HASH_TYPE_INT);
    if (hash_table == NULL) {
        printf("hash_table null\n");
    }
    printf("Created hash table\n");
    printf("Set fn ptrs\n");
    char* name1 = malloc(sizeof(char) * 8);
    strcpy(name1, "Brendan");
    int* age1 = malloc(sizeof(int));
    *age1 = 33;
    char* name2 = malloc(sizeof(char) * 6);
    strcpy(name2, "Tyler");
    int* age2 = malloc(sizeof(int));
    *age2 = 32;
    char* name3 = malloc(sizeof(char) * 8);
    strcpy(name3, "Brendan");
    int* age3 = malloc(sizeof(int));
    *age3 = 35;
    printf("Data generated/allocated\n");
    hash_table_put(hash_table, (void*)name1, (void*)age1);
    hash_table_put(hash_table, (void*)name2, (void*)age2);
    hash_table_put(hash_table, (void*)name3, (void*)age3);

    print(hash_table);
    printf("data added to hashtable\n");
    void* age1_hashed = hash_table_get(hash_table, (void*)name1);
    printf("Age 1 retrieved: %d\n", *(int*)age1_hashed);
    int result = hash_table_remove(hash_table, (void*)name1);
    void* age1_removed = hash_table_get(hash_table, (void*)name1);
    if (age1_removed == NULL) {
        printf("removal successful\n");
    }
    return 0;
}
