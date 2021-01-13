#include "htab.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>




void print_pl(struct pair *sent)
{
  printf(" - ");
  while(sent->next != NULL)
    {
      sent = sent->next;
      printf("(%s,%s) => ",sent->key,(char*)sent->value);
    }
  printf("\n");
}

void print_ht(struct htab *ht)
{
  printf("////////////////////////\n");
  printf("capqcity : %i\n",ht->capacity);
  printf("size : %i\n",ht->size);
  for(size_t i = 0; i < ht->capacity; i++)
    {
      print_pl(ht->data + i);
    }
}



int main()
{
  printf("%u\n", hash("France"));

  struct htab *ht = htab_new();

  struct pair *p = htab_get(ht,"France");
  if(p == NULL) printf("get 1 succeded\n");

  htab_insert(ht,"France","Paris");
  print_ht(ht);

htab_insert(ht,"Spain","Madrid");
  print_ht(ht);

  htab_insert(ht,"Jamaica","Kingston");
  print_ht(ht);

  htab_insert(ht,"Cuba","Kingston");
  htab_insert(ht,"Iraq","Kingston");
  htab_insert(ht,"Turkey","Kingston");
  print_ht(ht);


  htab_remove(ht,"Spain");
  print_ht(ht);

  htab_remove(ht,"Jamaica");
  print_ht(ht);
  
  htab_free(ht);

 
  
  return 0;
}
