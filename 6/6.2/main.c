#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

#include "contacts.h"

#define LIBRARY_PATH "/home/pavletsov21/eltex/module2/6/6.2/libcontacts.so"

// Прототипы функций из динамической библиотеки
typedef void (*init_contacts_ptr)(contacts_t*);
typedef void (*add_person_ptr)(contacts_t*, person_t*);
typedef void (*print_contacts_ptr)(contacts_t*);
typedef void (*delete_person_ptr)(contacts_t*, person_t*);
typedef void (*set_surname_ptr)(person_t*, const char*);
typedef void (*edit_person_ptr)(person_t*, person_t*);
typedef person_t* (*get_person_by_id_ptr)(contacts_t*, int);

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

int main() {
    // Загрузка динамической библиотеки
    void* handle = dlopen(LIBRARY_PATH, RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "Не удалось загрузить библиотеку: %s\n", dlerror());
        exit(EXIT_FAILURE);
    }
    
    // Получаем указатель на функцию InitContacts
    init_contacts_ptr init_contacts = (init_contacts_ptr)dlsym(handle, "InitContacts");
    if (!init_contacts) {
        fprintf(stderr, "Не удалось получить адрес функции InitContacts: %s\n", dlerror());
        dlclose(handle);
        exit(EXIT_FAILURE);
    }

    // Получаем указатель на функцию AddPerson
    add_person_ptr add_person = (add_person_ptr)dlsym(handle, "AddPerson");
    if (!add_person) {
        fprintf(stderr, "Не удалось получить адрес функции AddPerson: %s\n", dlerror());
        dlclose(handle);
        exit(EXIT_FAILURE);
    }

    // Получаем указатель на функцию PrintContacts
    print_contacts_ptr print_contacts = (print_contacts_ptr)dlsym(handle, "PrintContacts");
    if (!print_contacts) {
        fprintf(stderr, "Не удалось получить адрес функции PrintContacts: %s\n", dlerror());
        dlclose(handle);
        exit(EXIT_FAILURE);
    }

    // Получаем указатель на функцию DeletePerson
    delete_person_ptr delete_person = (delete_person_ptr)dlsym(handle, "DeletePerson");
    if (!delete_person) {
        fprintf(stderr, "Не удалось получить адрес функции DeletePerson: %s\n", dlerror());
        dlclose(handle);
        exit(EXIT_FAILURE);
    }

    // Получаем указатель на функцию SetSurname
    set_surname_ptr set_surname = (set_surname_ptr)dlsym(handle, "SetSurname");
    if (!set_surname) {
        fprintf(stderr, "Не удалось получить адрес функции SetSurname: %s\n", dlerror());
        dlclose(handle);
        exit(EXIT_FAILURE);
    }

    // Получаем указатель на функцию EditPerson
    edit_person_ptr edit_person = (edit_person_ptr)dlsym(handle, "EditPerson");
    if (!edit_person) {
        fprintf(stderr, "Не удалось получить адрес функции EditPerson: %s\n", dlerror());
        dlclose(handle);
        exit(EXIT_FAILURE);
    }

    // Получаем указатель на функцию GetPersonById
    get_person_by_id_ptr get_person_by_id = (get_person_by_id_ptr)dlsym(handle, "GetPersonById");
    if (!get_person_by_id) {
        fprintf(stderr, "Не удалось получить адрес функции GetPersonById: %s\n", dlerror());
        dlclose(handle);
        exit(EXIT_FAILURE);
    }

    // Пример использования функций из динамической библиотеки
    contacts_t my_contacts;
    init_contacts(&my_contacts);

    person_t person1 = { .id = 1 };
    SetName(&person1, "Иван");
    SetSurname(&person1, "Иванов");
    SetPatronimic(&person1, "Иванович");
    SetPhone(&person1, "+7 123 456 7890");
    work_t work1 = {"ООО 'Ромашка'", "Менеджер"};
    SetWork(&person1, &work1);
    social_network_t sn1 = {"VK", "vk.com/ivanov"};
    SetSocialNetwork(&person1, &sn1);

    add_person(&my_contacts, &person1);

    person_t person2 = { .id = 2 };
    SetName(&person2, "Петр");
    SetSurname(&person2, "Петров");
    SetPatronimic(&person2, "Петрович");
    SetPhone(&person2, "+7 987 654 3210");
    work_t work2 = {"ЗАО 'Василек'", "Программист"};
    SetWork(&person2, &work2);
    social_network_t sn2 = {"Instagram", "instagram.com/petrov"};
    SetSocialNetwork(&person2, &sn2);

    add_person(&my_contacts, &person2);

    printf("\nСписок контактов:\n");
    print_contacts(&my_contacts);

    // Найти контакт по ID
    int search_id = 2;
    person_t* found_person = get_person_by_id(&my_contacts, search_id);
    if (found_person) {
        printf("\nКонтакт с ID=%d найден:\n", search_id);
        print_person(found_person);
    } else {
        printf("Контакт с таким ID не найден.\n");
    }

    // Удаление контакта
    delete_person(&my_contacts, found_person);

    printf("\nСписок контактов:\n");
    print_contacts(&my_contacts);

    person_t edit_prs = person1;

    set_surname(&edit_prs, "Программистов");
    edit_person(&person1, &edit_prs);

    printf("\nСписок контактов:\n");
    print_contacts(&my_contacts);

    // Освобождаем ресурсы
    dlclose(handle);

    return 0;
}
