#ifndef H_FIFO
#define H_FIFO

#define FIFO_SIZE 10
char fifo_arr[FIFO_SIZE];

void fifo_put(char);
char fifo_get();
void fifo_print();

#endif
