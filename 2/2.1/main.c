#include <stdio.h>
#include "contacts.h"

void PrintContacts(contacts_t* cnt) {
	unsigned int i = 0;
	
	printf("------------ Contacts ------------\n");
	
	for ( ; i < cnt->size; i++) {
		printf("ID: %d\n", cnt->list[i].id);
		printf("Name: %s\n", cnt->list[i].name);
		printf("Surname: %s\n", cnt->list[i].surname);
		printf("Patrominic: %s\n", cnt->list[i].patronimic);
		printf("Phone: %s\n", cnt->list[i].phone);
		printf("Work:\n");
		printf("\tCompany: %s\n", cnt->list[i].work.company);
		printf("\tPost: %s\n", cnt->list[i].work.post);
		printf("SocialNetwork:\n");
		printf("\tName: %s\n", cnt->list[i].socialNetwork.name);
		printf("\tLink: %s\n\n", cnt->list[i].socialNetwork.link);
	}
	
	printf("-------------- End ---------------\n");
}

int main() {

	contacts_t contacts;
	InitContacts(&contacts);
	
	person_t person;
	InitPerson(&person+4);
	
	AddPerson(&contacts, &person);
	printf("1. After add first person\n\n");
	PrintContacts(&contacts);
	
	person_t* ptr_prs = GetPersonById(&contacts, 1);
	
	person_t edit_prs;
	InitPerson(&edit_prs);
	
	EditPerson(&edit_prs, &ptr_prs);
	
	SetName(&edit_prs, "John");
	SetSurname(&edit_prs, "Silver");
	
	EditPerson(&ptr_prs, &edit_prs);
	printf("\n2. After edit person\n\n");
	PrintContacts(&contacts);
	
	SetName(&person, "e-bashiox");
	SetSocNetName(&person.socialNetwork, "tg");
	SetSocNetLink(&person.socialNetwork, "@ebashiox");
	
	AddPerson(&contacts, &person);
	printf("\n3. After add second person\n\n");
	PrintContacts(&contacts);
	
	DeletePerson(&contacts, &ptr_prs);
	printf("\n4. After delete first person\n\n");
	PrintContacts(&contacts);
	
		
	return 0;
}
