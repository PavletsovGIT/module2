#ifndef CONTACTS_H_
#define CONTACTS_H_

#include <stdlib.h>
#include <string.h>

#define STR_SIZE 32

//Data types

typedef struct social_network_t {
    char name[STR_SIZE];
    char link[STR_SIZE];
} social_network_t;

typedef struct work_t {
    char company[STR_SIZE];
    char post[STR_SIZE];
} work_t;

typedef struct person_t {
    int id;
    char name[STR_SIZE];
    char surname[STR_SIZE];
    char patronimic[STR_SIZE];
    char phone[STR_SIZE];
    work_t work;
    social_network_t socialNetwork;
} person_t;

typedef struct contacts_t {
    int size;
    person_t* list;
} contacts_t;

// Functions
void InitContacts(contacts_t* cnt);
void InitPerson(person_t* prs);
void InitWork(work_t* work);
void InitSocialNetwork(social_network_t* sn);

void AddPerson(contacts_t* cnt, person_t* prs);
void EditPerson(person_t* prs, person_t* edit_prs);
void DeletePerson(contacts_t* cnt, person_t* prs);

void SetName(person_t* prs, char* _name);
void SetSurname(person_t* prs, char* _surname);
void SetPatronimic(person_t* prs, char* _patronimic);
void SetPhone(person_t* prs, char* _phone);
void SetWork(person_t* prs, work_t* _work);
void SetSocialNetwork(person_t* prs, social_network_t* _sn);

void SetWorkCompany(work_t* work, char* _company);
void SetWorkPost(work_t* work, char* _post);

void SetSocNetName(social_network_t* sn, char* _name);
void SetSocNetLink(social_network_t* sn, char* _link);

person_t* GetPersonById(contacts_t* cnt, int _id);

#endif
