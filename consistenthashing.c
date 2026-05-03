#include <stdio.h>

#define RINGSIZE 64

unsigned int hash_create(const char *str) {
    unsigned int hash = 5381;
    int c;

    while( (c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash;
}

int ring_position(const char* key, int ring_size) {
    return hash_create(key) %ring_size;
}

int map_location(int key_pos, int *nodes, int sz) {
    for(int i = 0; i < sz; i++) {
        if(key_pos > nodes[i]) {
            continue;
        } else return nodes[i];
    }
    return nodes[0];
}
int main() {
    int nodes[] = { 13, 34, 45, 59};
    int sz = sizeof(nodes)/sizeof(nodes[0]);
    //printf("%u\n", hash_create("apple")%RINGSIZE);
    const char *key_value = "give me a good numebr";
    
    int hashed_val = ring_position(key_value, RINGSIZE);
    printf("location on ring: %d\n", ring_position(key_value, RINGSIZE));
    
    int mapped_location = map_location(hashed_val, nodes, sz);
    printf("key %s maps to pos %d\n", key_value, mapped_location);
    
    return 0;
}