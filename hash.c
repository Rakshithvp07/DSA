#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct EmployeeRecord {
    int key;    
};

struct HashTableEntry {
    int key;
    int address;
};

void initializeHashTable(struct HashTableEntry HT[], int m) {
    for (int i = 0; i < m; i++) {
        HT[i].key = -1;
        HT[i].address = -1;
    }
}

int hashFunction(int key, int m) {
    return key % m;
}
void insert(struct HashTableEntry HT[], int m, int key, int address) {
    int hashIndex = hashFunction(key, m);
    while (HT[hashIndex].key != -1) {
        hashIndex = (hashIndex + 1) % m;
    }
    HT[hashIndex].key = key;
    HT[hashIndex].address = address;
}
void displayHashTable(struct HashTableEntry HT[], int m) {
    printf("\nHash Table:\n");
    printf("Index\tKey\tAddress\n");
    for (int i = 0; i < m; i++) {
        printf("%d\t%d\t%d\n", i, HT[i].key, HT[i].address);
    }
}

int main() {
    struct EmployeeRecord employeeRecords[MAX];
    struct HashTableEntry hashTable[MAX];
    int n, m;

    printf("Enter the number of employee records: ");
    scanf("%d", &n);
    printf("Enter the number of memory locations in the hash table: ");
    scanf("%d", &m);

    printf("Enter %d employee keys:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &employeeRecords[i].key);
    }

    initializeHashTable(hashTable, m);

    for (int i = 0; i < n; i++) {
        int address = hashFunction(employeeRecords[i].key, m);
        insert(hashTable, m, employeeRecords[i].key, address);
    }

    // Display the hash table
    displayHashTable(hashTable, m);

    return 0;
}
