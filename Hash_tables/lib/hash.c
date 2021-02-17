#include "hash.h"

int hash_code(int key)
{
    return key % HASH_SIZE;
}
/*
struct DataItem *hash_search(struct DataItem **self, int key)
{
    int hashIndex = hash_code(key);

    while(self[hashIndex] != NULL) {
        if(self[hashIndex]->key == key)
            return self[hashIndex];

        hashIndex++;

        hashIndex %= HASH_SIZE;
    }

    return NULL;
}
*/
void hashtb_insert(struct DataItem **self, int key, int data)
{
    struct DataItem *item = (struct DataItem *) malloc(sizeof(struct DataItem));
    item->data = data;
    item->key = key;

    int hashIndex = hash_code(key);

    while(self[hashIndex] != NULL && self[hashIndex]->key != -1) {
        hashIndex++;
        hashIndex %= HASH_SIZE;
    }
    
    self[hashIndex] = item;
}


void hashtb_display(struct DataItem **self) 
{
   int i = 0;
	
   for(i = 0; i<HASH_SIZE; i++) {
	
      if(self[i] != NULL)
         printf(" (%d,%d)", self[i]->key, self[i]->data);
      else
         printf(" ~~ ");
   }
	
   printf("\n");
}