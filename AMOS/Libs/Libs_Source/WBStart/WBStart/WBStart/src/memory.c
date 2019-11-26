/*
 * memory.c  V2.2
 *
 * WBStart memory pool functions
 *
 * (c) 1991-1996 Stefan Becker
 */

#include "wbstart.h"

/* Local data structures */
struct Memory {
 ULONG m_Size;
 /* Real memory block follows after this */
};

/* Local data */
static void *MemoryPool;

/* Initialize memory */
BOOL InitMemory(void)
{
 return((MemoryPool = CreatePool(MEMF_PUBLIC, 4096, 4096)) != NULL);
}

/* Delete memory */
void DeleteMemory(void)
{
 DeletePool(MemoryPool);
}

#ifdef DEBUG
/* Debugging versions of memory functions. These work with Mungwall */

/* Allocate one memory block from pool */
void *AllocateMemory(ULONG size)
{
 struct Memory *m;

 /* Add size for our data structure */
 size += sizeof(struct Memory);

 /* Allocate memory, save size and move pointer to real mem. block */
 if (m = AllocMem(size, MEMF_PUBLIC)) (m++)->m_Size = size;

 kprintf("Allocated memory %08lx (%ld)\n", m, size - sizeof(struct Memory));

 /* Return pointer to memory block */
 return(m);
}

/* Free memory block */
void FreeMemory(void *p)
{
 ULONG size = (--((struct Memory *) p))->m_Size;

 kprintf("Freeing memory %08lx (%ld)\n", (struct Memory *) p + 1,
                                         size - sizeof(struct Memory));

 /* Free memory */
 FreeMem(p, size);
}

#else
/* The production code uses memory pools */

/* Allocate one memory block from pool */
void *AllocateMemory(ULONG size)
{
 struct Memory *m;

 /* Add size for our data structure */
 size += sizeof(struct Memory);

 /* Allocate memory from pool, save size and move pointer to real mem. block */
 if (m = AllocPooled(MemoryPool, size)) (m++)->m_Size = size;

 /* Return pointer to memory block */
 return(m);
}

/* Free memory block */
void FreeMemory(void *p)
{
 ULONG size = (--((struct Memory *) p))->m_Size;

 /* Return block to pool */
 FreePooled(MemoryPool, p, size);
}
#endif
