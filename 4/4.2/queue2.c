#include "queue2.h"

void init_packet(packet_t* packet) {
	static int seed = 2;
	srand(seed);

	packet->value = rand();
	packet->priority = rand() % MAX_PRIORITY + 1 + MIN_PRIORITY;
	
	seed++;
}

void init_item(item_t* item) {
	item->packet = NULL;
	item->next = 0;
	item->prev = 0;
}

void init_queue(queue_t* queue) {
	queue->size = 0;
	init_item(&queue->head);
	queue->flag = 0;
}

void swap(packet_t* a, packet_t* b) {
	packet_t* tmp = (packet_t*)malloc(sizeof(packet_t));
	
	(*tmp) = (*a);
	(*a) = (*b);
	(*b) = (*tmp);
	
	free(tmp);
}

void sort(queue_t* queue) {
	int f;
	item_t* jt = queue->head.next;;
	item_t* it = jt->next;
	
	while (jt->next != NULL) {
		f = 0;
		while (it->next != NULL) {
			if (it->packet->priority > it->next->packet->priority) {
				swap(it->packet, it->next->packet);
			}
			f = 1;
			it = it->next;
		}
		if (f == 0) break;
		jt = jt->next;
	}
}

void enqueue(queue_t* queue, packet_t* packet) {
	item_t* newItem = (item_t*)malloc(sizeof(item_t));
	
	if (queue->head.next == NULL) {
		queue->head.next = newItem;
		newItem->prev = &queue->head;
		queue->size++;
		sort(queue);
		return;
	}
	
	newItem->packet = packet;
	queue->head.next->prev = newItem;
	newItem->next = queue->head.next->next;
	newItem->prev = &queue->head;
	
	queue->head.next = newItem;
	queue->size++;
	sort(queue);
}

packet_t dequeue(queue_t* queue) {
	item_t* it = queue->head.next;
	packet_t result;
	
	init_packet(&result);
	
	if (queue->size == 0) return result;
	
	while (it->next != NULL) {
		it = it->next;
	}
	queue->size--;
	
	result = *(it->packet);
	free(it);
	
	return result;
}

packet_t define_priority_dequeue(queue_t* queue, unsigned char priority) {
	item_t* it = queue->head.next;
	packet_t result;
	
	init_packet(&result);
	
	if (queue->size == 0) return result;
	
	while (it->packet->priority != priority || it->next != NULL) {
		it = it->next;
	}
	
	if (it->packet->priority != priority &&  it->next == NULL) {
		result = *(it->packet);
		return result;
	}
	
	queue->size--;
	result = *(it->packet);
	free(it);
	
	return result;
}

packet_t not_lower_priority_dequeue(queue_t* queue, unsigned char priority) {
	item_t* it = queue->head.next;
	packet_t result;
	
	init_packet(&result);
	
	if (queue->size == 0) return result;
	
	while (it->packet->priority >= priority || it->next != NULL) {
		it = it->next;
	}
	
	if (it->packet->priority >= priority &&  it->next == NULL) {
		result = *(it->packet);
		return result;
	}
	
	queue->size--;
	result = *(it->packet);
	free(it);
	
	return result;
}

packet_t peek(queue_t* queue) {
	item_t* it = queue->head.next;
	packet_t result;
	
	init_packet(&result);
	
	if (queue->size == 0) return result;
	
	while (it->next != NULL) {
		it = it->next;
	}
	
	result = *(it->packet);
	
	return result;
}

void printq(queue_t* queue, FILE* outstream) {
	item_t* it = queue->head.next;
	int i = 0;
	
	fprintf(outstream, "\tNo. | \tPriority | \tValue\n");
	while (it->next != NULL) {
		fprintf(outstream, "%5d | \t%5d | \t%5d\n", i, it->packet->priority, it->packet->value);
		i++;
		it = it->next;
	}
}
