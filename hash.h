#ifndef _HASH_H_
#define _HASH_H_

struct nList {
   char* name;
   struct nList *next;
};
typedef struct nList NList;
typedef struct nList *NListPtr;

unsigned Hash(const char* s);
NListPtr Lookup(const char* s);
NListPtr Insert(const char* name);

void PrintHashTable();

#endif
