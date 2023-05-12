#ifndef BOX_H
#define BOX_H

typedef void *Box;

extern Box newBox();
extern char *getBox(Box box);
extern void putBox(Box box, char *msg);

#endif
