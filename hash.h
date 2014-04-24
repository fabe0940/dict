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

int BucketSize(int index);

void Print(NListPtr node);
void PrintHashTable(void);
void PrintBucketSize(void);
void PrintBucketMinMax(void);

#endif
