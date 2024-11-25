#ifndef QUEUE2_H_
#define QUEUE2_H_

#include<stdio.h>
#include<stdlib.h>

#define MAX_PRIORITY 255
#define MIN_PRIORITY 0

/*
int summ(int arg1 , int arg2) {
	for (int i = 0; i <= arg2 - arg1; i++) {
		arg1 += i;
	}
	
	return arg1;
}

const int MAX_SIZE = summ(MIN_PRIORITY, MAX_PRIORITY);
*/

typedef struct packet_t {
	unsigned char value; // Значение
	unsigned char priority; // Приоритет пакета
} packet_t;

typedef struct item_t {
	packet_t packet;
	
	// Pointers
	struct item_t* next;
	struct item_t* prev;
} item_t;

typedef struct queue_t {
	size_t size;
	item_t head;
	unsigned char flag; // Если flag == 0 => создаётся новая очередь, если flag != 0 => очередь заполнена и вставлять новые элементы можно только в конец и только по правилам формирования новой очереди
} queue_t;

void init_packet(packet_t* packet);
void init_item(item_t* item);
void init_queue(queue_t* queue);

void packet_swap(packet_t* a, packet_t* b);
void sort(queue_t* queue);

void enqueue(queue_t* queue, packet_t packet);
packet_t dequeue(queue_t* queue);
packet_t define_priority_dequeue(queue_t* queue, unsigned char priority);
packet_t not_lower_priority_dequeue(queue_t* queue, unsigned char priority); 
packet_t peek(queue_t* queue);

void printq(queue_t* queue, FILE* outstream);

#endif // QUEUE2_H_
