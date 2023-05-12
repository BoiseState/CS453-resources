#ifndef DEQ_H
#define DEQ_H

// put: append onto an end, len++
// get: return from an end, len--
// ith: return by 0-base index, len unchanged
// rem: return by == comparing, len-- (iff found)

typedef void *Deq;
typedef void *Data;

extern Deq deq_new();
extern int deq_len(Deq q);

extern void deq_head_put(Deq q, Data d);
extern Data deq_head_get(Deq q);
extern Data deq_head_ith(Deq q, int i);
extern Data deq_head_rem(Deq q, Data d);

extern void deq_tail_put(Deq q, Data d);
extern Data deq_tail_get(Deq q);
extern Data deq_tail_ith(Deq q, int i);
extern Data deq_tail_rem(Deq q, Data d);

typedef char *Str;
typedef void (*DeqMapF)(Data d);
typedef Str  (*DeqStrF)(Data d);

extern void deq_map(Deq q, DeqMapF f); // foreach
extern void deq_del(Deq q, DeqMapF f); // free
extern Str  deq_str(Deq q, DeqStrF f); // toString

#endif
