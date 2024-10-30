#include "contacts.h"

void InitContacts(contacts_t* cnt) {
	cnt->size = 0;
	cnt->list = NULL;
}

void InitPerson(person_t* prs) {
	char def_str[STR_SIZE] = "_default";
	
	prs->id = 0;
	strncpy(prs->name, def_str, STR_SIZE);
	strncpy(prs->surname, def_str, STR_SIZE);
	strncpy(prs->patronimic,  def_str, STR_SIZE);
	strncpy(prs->phone,  def_str, STR_SIZE);
	InitWork(&prs->work);
	InitSocialNetwork(&prs->socialNetwork);
	
	//free(def_str);
}

void InitWork(work_t* work) {
	char def_str[STR_SIZE] = "_default";

	strncpy(work->company, def_str, STR_SIZE);
	strncpy(work->post, def_str, STR_SIZE);
	
	//free(def_str);
}

void InitSocialNetwork(social_network_t* sn) {
	char def_str[STR_SIZE] = "_default";

	strncpy(sn->name, def_str, STR_SIZE);
	strncpy(sn->link, def_str, STR_SIZE);
	
	//free(def_str);
}

void AddPerson(contacts_t* cnt, person_t* prs) {
	cnt->list = realloc(cnt->list, (cnt->size + 1) * sizeof(person_t));
	cnt->size++;
	
	memcpy(&cnt->list[cnt->size - 1], &prs, sizeof(person_t));
	cnt->list[cnt->size - 1].id = cnt->size;
}

void EditPerson(person_t* prs, person_t* edit_prs) {
	memcpy(prs, edit_prs, sizeof(person_t));
}

void DeletePerson(contacts_t* cnt, person_t* prs) {
	for (int i = prs->id; i < cnt->size - 1; i++) {
		cnt->list[i] = cnt->list[i + 1];
		cnt->list[i].id = i;
	}
	
	cnt->size--;
	
	/*
	//free(cnt->list[cnt->size - 1].id);
	free(cnt->list[cnt->size - 1].name);
	free(cnt->list[cnt->size - 1].surname);
	free(cnt->list[cnt->size - 1].patronimic);
	free(cnt->list[cnt->size - 1].phone);
	free(cnt->list[cnt->size - 1].work.company);
	free(cnt->list[cnt->size - 1].work.post);
	free(cnt->list[cnt->size - 1].socialNetwork.name);
	free(cnt->list[cnt->size - 1].socialNetwork.link);
	*/
}

void SetName(person_t* prs, char* _name) {
	strncpy(prs->name, _name, strlen(_name));
}

void SetSurname(person_t* prs, char* _surname) {
	strncpy(prs->surname, _surname, strlen(_surname));
}

void SetPatronimic(person_t* prs, char* _patronimic) {
	strncpy(prs->patronimic, _patronimic, strlen(_patronimic));
}

void SetPhone(person_t* prs, char* _phone) {
	strncpy(prs->phone, _phone, strlen(_phone));
}

void SetWork(person_t* prs, work_t* _work)  {
	SetWorkCompany(&prs->work, _work->company);
	SetWorkPost(&prs->work, _work->post);
}

void SetSocialNetwork(person_t* prs, social_network_t* _sn) {
	SetSocNetName(&prs->socialNetwork, _sn->name);
	SetSocNetLink(&prs->socialNetwork, _sn->link);
}

void SetWorkCompany(work_t* work, char* _company) {
	strncpy(work->company, _company, STR_SIZE);
}

void SetWorkPost(work_t* work, char* _post) {
	strncpy(work->post, _post, STR_SIZE);
}

void SetSocNetName(social_network_t* sn, char* _name)  {
	strncpy(sn->name, _name, STR_SIZE);
}

void SetSocNetLink(social_network_t* sn, char* _link)  {
	strncpy(sn->link, _link, STR_SIZE);
}

person_t* GetPersonById(contacts_t* cnt, int _id) {
	if (_id >= cnt->size) return NULL;
	
	return &(cnt->list[_id]);
}
