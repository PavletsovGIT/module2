#include <stdio.h>
#include <stdlib.h>

#include "contacts.h"

void print_person(person_t* prs) {
    printf("ID: %d\n", prs->id);
    printf("Имя: %s\n", prs->name);
    printf("Фамилия: %s\n", prs->surname);
    printf("Отчество: %s\n", prs->patronimic);
    printf("Телефон: %s\n", prs->phone);
    printf("Компания: %s\n", prs->work.company);
    printf("Должность: %s\n", prs->work.post);
    printf("Социальная сеть: %s (%s)\n", prs->socialNetwork.name, prs->socialNetwork.link);
    puts("");
}

void print_contacts(contacts_t* contacts) {
	item_t* current_item = Begin(&(*contacts));
    if (!current_item) {
        puts("Контакты пусты.");
    } else {
        while (current_item) {
            print_person(current_item->p);
            current_item = current_item->next;
        }
    }
}

void test_contacts() {
    contacts_t my_contacts;
    InitContacts(&my_contacts);

    person_t person1 = { .id = 1 };
    SetName(&person1, "Иван");
    SetSurname(&person1, "Иванов");
    SetPatronimic(&person1, "Иванович");
    SetPhone(&person1, "+7 123 456 7890");
    work_t work1 = {"ООО 'Ромашка'", "Менеджер"};
    SetWork(&person1, &work1);
    social_network_t sn1 = {"VK", "vk.com/ivanov"};
    SetSocialNetwork(&person1, &sn1);

    AddPerson(&my_contacts, &person1);

    person_t person2 = { .id = 2 };
    SetName(&person2, "Петр");
    SetSurname(&person2, "Петров");
    SetPatronimic(&person2, "Петрович");
    SetPhone(&person2, "+7 987 654 3210");
    work_t work2 = {"ЗАО 'Василек'", "Программист"};
    SetWork(&person2, &work2);
    social_network_t sn2 = {"Instagram", "instagram.com/petrov"};
    SetSocialNetwork(&person2, &sn2);

    AddPerson(&my_contacts, &person2);

    printf("\nСписок контактов:\n");
    print_contacts(&my_contacts);

    // Найти контакт по ID
    int search_id = 2;
    person_t* found_person = GetPersonById(&my_contacts, search_id);
    if (found_person) {
        printf("\nКонтакт с ID=%d найден:\n", search_id);
        print_person(found_person);
    } else {
        printf("Контакт с таким ID не найден.\n");
    }

    // Удаление контакта
    DeletePerson(&my_contacts, found_person);

	printf("\nСписок контактов:\n");
    print_contacts(&my_contacts);
    
    person_t edit_prs = person1;
    
    SetSurname(&edit_prs, "Программистов");
    EditPerson(&person1, &edit_prs);
    
    printf("\nСписок контактов:\n");
    print_contacts(&my_contacts);
}

int main() {
    test_contacts();
    return 0;
}
