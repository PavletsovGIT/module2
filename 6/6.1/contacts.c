#include "contacts.h"
#include <stdio.h>
#include <string.h>

void InitContacts(contacts_t* cnt) {
    cnt->size = 0;
    cnt->head = NULL;
}

void InitItem(item_t* item) {
    InitPerson(item->p);
    item->next = NULL;
    item->prev = NULL;
}

void InitPerson(person_t* prs) {
    char def_str[STR_SIZE] = "_default";

    prs->id = 0;
    strncpy(prs->name, def_str, STR_SIZE);
    strncpy(prs->surname, def_str, STR_SIZE);
    strncpy(prs->patronimic, def_str, STR_SIZE);
    strncpy(prs->phone, def_str, STR_SIZE);
    InitWork(&prs->work);
    InitSocialNetwork(&prs->socialNetwork);
}

void InitWork(work_t* work) {
    char def_str[STR_SIZE] = "_default";

    strncpy(work->company, def_str, STR_SIZE);
    strncpy(work->post, def_str, STR_SIZE);
}

void InitSocialNetwork(social_network_t* sn) {
    char def_str[STR_SIZE] = "_default";

    strncpy(sn->name, def_str, STR_SIZE);
    strncpy(sn->link, def_str, STR_SIZE);
}

item_t* Begin(contacts_t* cnt) {
    return cnt->head;
}

item_t* End(contacts_t cnt) {
    if (cnt.head == NULL) return NULL;

    item_t* it = cnt.head;

    while (it->next != NULL) {
        it = it->next;
    }

    return it;
}

void Swap(item_t* it1, item_t* it2) {
    person_t* temp = it1->p;
    it1->p = it2->p;
    it2->p = temp;
}

void Sort(contacts_t* cnt) {
    if (cnt->size <= 1) return;

    for (item_t *i = cnt->head; i != NULL; i = i->next) {
        for (item_t *j = i->next; j != NULL; j = j->next) {
            if (strcmp(i->p->surname, j->p->surname) > 0) {
                Swap(i, j);
            }
        }
    }
}

void AddPerson(contacts_t* cnt, person_t* prs) {
    item_t* newItem = (item_t*)malloc(sizeof(item_t));
    if (!newItem) {
        printf("Ошибка выделения памяти\n");
        return;
    }

    newItem->p = prs;
    newItem->next = NULL;

    if (cnt->head == NULL) {
        cnt->head = newItem;
        newItem->prev = NULL;
    } else {
        item_t* last = End(*cnt);
        last->next = newItem;
        newItem->prev = last;
    }
	//newItem->p->id = 2;
    cnt->size++;

    Sort(cnt);
}

void EditPerson(person_t* prs, person_t* edit_prs) {
    memcpy(prs, edit_prs, sizeof(person_t));
}

void DeletePerson(contacts_t* cnt, person_t* prs) {
    if (cnt->head == NULL) return;

    item_t* it = cnt->head;

    while (it && it->p != prs) {
        it = it->next;
    }

    if (it) {
        item_t* nextItem = it->next;
        item_t* prevItem = it->prev;

        if (prevItem)
            prevItem->next = nextItem;
        else
            cnt->head = nextItem;

        if (nextItem)
            nextItem->prev = prevItem;

        free(it);
        cnt->size--;
    }
}

void SetName(person_t* prs, const char* _name) {
    strncpy(prs->name, _name, STR_SIZE - 1); // Оставляем место для завершающего нуля
    prs->name[STR_SIZE - 1] = '\0';          // Убеждаемся, что строка завершается нулевым символом
}

void SetSurname(person_t* prs, const char* _surname) {
    strncpy(prs->surname, _surname, STR_SIZE - 1);
    prs->surname[STR_SIZE - 1] = '\0';
}

void SetPatronimic(person_t* prs, const char* _patronimic) {
    strncpy(prs->patronimic, _patronimic, STR_SIZE - 1);
    prs->patronimic[STR_SIZE - 1] = '\0';
}

void SetPhone(person_t* prs, const char* _phone) {
    strncpy(prs->phone, _phone, STR_SIZE - 1);
    prs->phone[STR_SIZE - 1] = '\0';
}

void SetWork(person_t* prs, work_t* _work) {
    SetWorkCompany(&prs->work, _work->company);
    SetWorkPost(&prs->work, _work->post);
}

void SetSocialNetwork(person_t* prs, social_network_t* _sn) {
    SetSocNetName(&prs->socialNetwork, _sn->name);
    SetSocNetLink(&prs->socialNetwork, _sn->link);
}

void SetWorkCompany(work_t* work, const char* _company) {
    strncpy(work->company, _company, STR_SIZE - 1);
    work->company[STR_SIZE - 1] = '\0';
}

void SetWorkPost(work_t* work, const char* _post) {
	strncpy(work->post, _post, STR_SIZE);
}

void SetSocNetName(social_network_t* sn, const char* _name)  {
	strncpy(sn->name, _name, STR_SIZE);
}

void SetSocNetLink(social_network_t* sn, const char* _link)  {
	strncpy(sn->link, _link, STR_SIZE);
}

person_t* GetPersonById(contacts_t* cnt, int _id) {
	if (_id > cnt->size) return NULL;
	
	item_t* it = cnt->head;
	
	while (it->p->id != _id || it->next != NULL) {
		it = it->next;
	}
	
	return it->p;
}
