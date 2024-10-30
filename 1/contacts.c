#include "contacts.h"

void InitContacts(contacts_t* cnt) {
	cnt->size = 0;
	cnt->list = NULL;
}

void InitPerson(person_t* prs) {
	char def_str[STR_SIZE] = "_default";
	
	prs->id = -1;
	strcpy(prs->name, def_str);
	strcpy(prs->surname, def_str);
	strcpy(prs->patronimic,  def_str);
	strcpy(prs->phone,  def_str);
	InitWork(&prs->work);
	InitSocialNetwork(prs->social_network);
	
	free(def_str);
}

void InitWork(work_t* work) {
	char def_str[STR_SIZE] = "_default";

	strcpy(work->company, def_str);
	strcpy(work->post, def_str);
	
	free(def_str);
}

void InitSocialNetwork(social_network_t* sn) {
	char def_str[STR_SIZE] = "_default";

	strcpy(sn->name, def_str);
	strcpy(sn->link, def_str);
	
	free(def_str);
}

void AddPerson(contacts_t* cnt, person_t* prs) {
	cnt->list = realloc(cnt->list, (cnt->size + 1) * sizeof(person_t));
	cnt->size++;
	
	strcpy(&cnt->list[cnt->size - 1], &prs);
	cnt->list[cnt->size - 1].id = cnt->size - 1;
}

void EditPerson(person_t* prs, person_t* edit_prs) {
	strcpy(prs, edit_prs);
}

void DeletePerson(contacts_t* cnt, person_t* prs) {
	for (int i = prs->id; i < cnt->size - 1; i++) {
		cnt->list[i] = cnt->list[i + 1];
	}
	
	free(cnt->list[size - 1].id);
	free(cnt->list[size - 1].name);
	free(cnt->list[size - 1].surname);
	free(cnt->list[size - 1].patronimic);
	free(cnt->list[size - 1].phone);
	free(cnt->list[size - 1].work.company);
	free(cnt->list[size - 1].work.post);
	free(cnt->list[size - 1].work.socialNetwork.name);
	free(cnt->list[size - 1].work.socialNetwork.link);
}

void SetName(person_t* prs, char* _name) {
	strcpy(prs->name, _name);
}

void SetSurname(person_t* prs, char* _surname) {
	strcpy(prs->surname, _surname);
}

void SetPatronimic(person_t* prs, char* _patronimic) {
	strcpy(prs->patronimic, _patronimic);
}

void SetPhone(person_t* prs, char* _phone) {
	strcpy(prs->phone, _phone);
}

void SetWork(person_t* prs, work_t* _work)  {
	strcpy(prs->work, _work);
}

void SetSocialNetwork(person_t* prs, social_network_t* _sn) {
	strcpy(prs->socialNetwork, _sn);
}

void SetCompany(work_t* work, char* _company) {
	strcpy(work->company, _company);
}

void SetPost(work_t* work, char* _post) {
	strcpy(work->post, _post);
}

void SetSocNetName(social_network_t* sn, char* _name)  {
	strcpy(sn->name, _name);
}

void SetSocNetLink(social_network_t* sn, char* _link)  {
	strcpy(sn->link, _link);
}

person_t* GetPersonById(contacts_t* cnt, unsigned int _id) {
	if (_id >= cnt->size) return NULL;
	
	return &(cnt->list[_id]);
}
