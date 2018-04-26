#ifndef _SUPTABLE_H
#define _SUPTABLE_H

#include <hash.h>

enum type_data
  {
    FILE_DATA,
    SWAP_FILE, 
    ZERO_PAGE,
    
  };


struct sup_page_entry
{
    struct hash_elem page_elem;
    void *addr;
    int usls;
    enum type_data type;
		uint32_t read_bytes;
		uint32_t zero_bytes;

};


struct lock sup_lock;
unsigned page_hash (const struct hash_elem *, void *aux );

bool page_less (const struct hash_elem *, const struct hash_elem *,void *aux );

bool init_sup_table (void);

struct sup_page_entry *sup_lookup (const void *,struct hash);

void save_sup_page (struct sup_page_entry *,void *,uint32_t , uint32_t, int );

#endif
