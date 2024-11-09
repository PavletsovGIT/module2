#include <stdio.h>
#include "queue2.h"

/*
void PrintQueue(queue_t* pq) {
    for (int i = 0; i < pq->size; ++i) {
        printf("Value: %d, Priority: %hhu\n", pq->packets[i].value, pq->packets[i].priority);
    }
}
*/

int main() {
    queue_t pq;
    init_queue(&pq);
    
    // Добавляем 10 элементов в очередь
    for (int i = 0; i < 10; ++i) {
        packet_t packet;
        init_packet(&packet);  // Инициализация пакета случайными значениями
        enqueue(&pq, &packet); // Добавление пакета в очередь
        printf("Добавлен элемент со значением: %5d , приоритетом: \t%5d\n", packet.value, packet.priority);
    }
    
    printf("Очередь после добавления 10 элементов:\n");
    printq(&pq, stdout); // Выводим содержимое очереди
    
   packet_t removed_packet = dequeue(&pq);
    printf("\nУдаленный элемент: Приоритет: %5d Значение %5d\n", removed_packet.priority, removed_packet.value);
    
    printf("Очередь после удаления элемента:\n");
    printq(&pq, stdout);// Вывод очереди после удаления первого элемента
    
    if (pq.size > 0) {
        packet_t top_packet = peek(&pq);  // Получаем верхний элемент очереди
        printf("\nВерхний элемент очереди: Приоритет: %5d\nЗначение %5d\n", top_packet.priority, top_packet.value);
	}
    return 0;
}
