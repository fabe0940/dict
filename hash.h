#ifndef _HASH_H_
#define _HASH_H_

struct nList {
   char *name;
   char *defn;
   struct nList *next;
};
typedef struct nList NList;
typedef struct nList *NListPtr;

unsigned Hash(char *s);
NListPtr Lookup(char *s);
NListPtr Insert(char *name, char *defn);

void PrintHashTable();

#endif
