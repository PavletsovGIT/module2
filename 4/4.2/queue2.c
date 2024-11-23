#include "queue2.h"

void init_packet(packet_t* packet) {
	static int seed = 2;
	srand(seed);

	packet->value = rand();
	packet->priority = rand() % MAX_PRIORITY + 1 + MIN_PRIORITY;
	
	seed++;
}

void init_item(item_t* item) {
	init_packet(&item->packet);
	item->next = 0;
	item->prev = 0;
}

void init_queue(queue_t* queue) {
	queue->size = 0;
	init_item(&queue->head);
	queue->flag = 0;
}

void packet_swap(packet_t* a, packet_t* b) {
	packet_t* tmp = (packet_t*)malloc(sizeof(packet_t));
	
	(*tmp) = (*a);
	(*a) = (*b);
	(*b) = (*tmp);
	
	free(tmp);
}

void sort(queue_t* queue) {
    for (item_t* i = queue->head.next; i != NULL; i = i->next) {
        for (item_t* j = i->next; j != NULL; j = j->next) {
            if (i->packet.priority > j->packet.priority) {
                packet_swap(&i->packet, &j->packet);
            }
        }
    }
}

void enqueue(queue_t* queue, packet_t packet) {
    item_t* newItem = (item_t*)malloc(sizeof(item_t));
    newItem->packet = packet;
    
    if (queue->head.next == NULL) {
        queue->head.next = newItem;
        newItem->prev = &queue->head;
        newItem->next = NULL;
        
        queue->size++;
        sort(queue);
        return;
    }

    item_t* last = queue->head.next;
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newItem;
    newItem->prev = last;
    newItem->next = NULL;

    queue->size++;
    sort(queue);
}

packet_t dequeue(queue_t* queue) {
    if (queue->size == 0) {
        packet_t emptyPacket;
        init_packet(&emptyPacket);
        return emptyPacket;
    }
    
    packet_t result;
    
    item_t* it = queue->head.next;
    
    it->next->prev = &queue->head;
    queue->head.next = it->next;
    
    result = it->packet;
    queue->size--;
    /*
    item_t* it = queue->head.next;
    packet_t result = it->packet;
    */
    free(it);

    return result;
}

packet_t define_priority_dequeue(queue_t* queue, unsigned char priority) {
    item_t* it = queue->head.next;

    while (it != NULL && it->packet.priority != priority) {
        it = it->next;
    }

    if (it == NULL) {
        packet_t defaultPacket;
        init_packet(&defaultPacket);
        return defaultPacket;
    }

    packet_t result = it->packet;
    queue->size--;

    // Удаляем элемент из списка
    it->prev->next = it->next;
    if (it->next != NULL) {
        it->next->prev = it->prev;
    }

    free(it);

    return result;
}

packet_t not_lower_priority_dequeue(queue_t* queue, unsigned char priority) {
    item_t* it = queue->head.next;

    while (it != NULL && it->packet.priority < priority) {
        it = it->next;
    }

    if (it == NULL) {
        packet_t defaultPacket;
        init_packet(&defaultPacket);
        return defaultPacket;
    }

    packet_t result = it->packet;
    queue->size--;

    // Удаляем элемент из списка
    it->prev->next = it->next;
    if (it->next != NULL) {
        it->next->prev = it->prev;
    }

    free(it);

    return result;
}

packet_t peek(queue_t* queue) {
    packet_t result;
    init_packet(&result);

    if (queue->size > 0) {
        item_t* last = queue->head.next;
        while (last->next != NULL) {
            last = last->next;
        }
        result = last->packet;
    }

    return result;
}

void printq(queue_t* queue, FILE* outstream) {
	
	if (queue->head.next == NULL) fprintf(outstream, "Queue is empty...\n");

	item_t* it = &queue->head;
	int i = 0;
	
	fprintf(outstream, "   No.|   Priority|   Value\n");
	
	do{
		it = it->next;
		fprintf(outstream, "%5d |%5d |%5d\n", i, it->packet.priority, it->packet.value);
		i++;
		//it = it->next;
	} while (it->next != NULL) ;
}
