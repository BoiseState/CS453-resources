
#include <stdio.h>
#include "simple-malloc.h"

static Header *morecore(unsigned);
static Header base; /* empty list to get started */
static Header *freep = NULL; /* start of free list */

/** 
 * simple_malloc: General purpose storage allocator that uses the next-fit heuristic.
 */
void *simple_malloc(unsigned nbytes)
{
	Header *p, *prevp;
	unsigned nunits;
	
	nunits = (nbytes+sizeof(Header)-1)/sizeof(Header) + 1;
	if ((prevp = freep) == NULL) {  /* no free list yet */
		/* this becomes a marker node with size 0 */
		base.s.ptr = freep = prevp = &base;
		base.s.size = 0;
	}

	for (p = prevp->s.ptr; ; prevp = p, p = p->s.ptr) {
		if (p->s.size >= nunits) {  /* big enough */
			if (p->s.size == nunits)   /* exactly */
				prevp->s.ptr = p->s.ptr;
			else {   /* allocate tail end */
				p->s.size -= nunits;
				p += p->s.size;
				p->s.size = nunits;
			}
			freep = prevp; /* next-fit */
			return (void *) (p+1);
		}
		if (p == freep)  /* wrapped around free list */
			if ((p = morecore(nunits)) == NULL)
				return NULL;  /* none left */
	}
}

#define NALLOC 1024 /* minimum #units to request */

/**
 * morecore: ask system for more memory.
 */
static Header *morecore(unsigned nu)
{
	void *cp;
	Header *up;

	if (nu < NALLOC) 
		nu = NALLOC;
	cp = sbrk(nu * sizeof(Header));
	if (cp == (void *) -1) /* no memory left */
		return NULL;
	up = (Header *) cp;
	up->s.size = nu;
	simple_free((void *)(up+1));
	return freep;
}


/**
 * put block ap in the free list 
 */
void simple_free(void *ap)
{
	Header *bp, *p;

	bp = (Header *) ap - 1; /* point to block header */
	for (p = freep;!(bp > p && bp < p->s.ptr); p = p->s.ptr)
		if (p >= p->s.ptr && (bp > p || bp < p->s.ptr))
			break; /* freed block at start or end of arena */
	
	if (bp + bp->s.size == p->s.ptr) { /* join to upper neighbor */
		bp->s.size += p->s.ptr->s.size;
		bp->s.ptr = p->s.ptr->s.ptr;
	} else 
		bp->s.ptr = p->s.ptr;
	
	if (p + p->s.size == bp) { /* join to lower neighbor */
		p->s.size += bp->s.size;
		p->s.ptr = bp->s.ptr;
	} else
		p->s.ptr = bp;
	freep = p;
}


/**
 * print out the free list for demonstration purposes 
 */
void print_free_list()
{
	Header *next;
	int i;

	if (!freep) {
		printf("free list is empty\n");
		return;
	}
	i=0; 
	printf("\n");
	next = freep;
	do {
		printf("node %d:  address = %p size = %u bytes\n", i, next, next->s.size * (unsigned) sizeof(Header)); 
    	next = next->s.ptr;;
		i++;
	} while (next != freep); 
	printf("\n");
}

/* vim: set ts=4: */
