#ifndef __BODY_HTTP_H__
#define __BODY_HTTP_H__

#include "header.h"
#include "pair.h"
typedef struct Body Body;

// We need header's information to select how do we parse the body
Body *body_parser(const Header *restrict header, char *restrict buffer);

void *body_get(const Body *restrict b, const char *restrict key);
void body_delete(Body *b);
void body_delete_const(const Body *b);

#define body_delete(b) \
    _Generic((b), const Body * : body_delete_const, Body * : body_delete)(b)

#ifdef DEBUG
void Body_print(const Body *b);
#endif

#endif
