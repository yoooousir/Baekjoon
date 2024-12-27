#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TABLE_SIZE 100003

typedef struct Node {
    char url[21];
    char pw[21];
    struct Node* next;
} Node;

Node* hash_table[TABLE_SIZE];


unsigned int hash(const char* str) {
    unsigned int hash = 0;
    while (*str) {
        hash = (hash * 31) + (*str++);
    }
    return hash % TABLE_SIZE;
}


void insert(const char* url, const char* pw) {
    unsigned int idx = hash(url);
    Node* new_node = (Node*)malloc(sizeof(Node));
    strcpy(new_node->url, url);
    strcpy(new_node->pw, pw);
    new_node->next = hash_table[idx];
    hash_table[idx] = new_node;
}


char* find_pw(const char* url) {
    unsigned int idx = hash(url);
    Node* current = hash_table[idx];
    while (current) {
        if (strcmp(current->url, url) == 0) {
            return current->pw;
        }
        current = current->next;
    }
    return NULL; 
}


void free_table() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* current = hash_table[i];
        while (current) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    char url[21], pw[21];
    for (int i = 0; i < n; i++) {
        scanf("%s %s", url, pw);
        insert(url, pw);
    }

    char find[21];
    for (int i = 0; i < m; i++) {
        scanf("%s", find);
        printf("%s\n", find_pw(find));
    }

    free_table();
    return 0;
}
