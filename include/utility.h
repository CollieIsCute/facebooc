#ifndef __UTILITY_H__
#define __UTILITY_H__
#include <stddef.h>
#include <stdlib.h>

/* "typeof" is a GNU extension.
 * Reference: https://gcc.gnu.org/onlinedocs/gcc/Typeof.html
 */
#if defined(__GNUC__)
#define __LIST_HAVE_TYPEOF 1
#endif

/**
 * container_of() - Calculate address of object that contains address ptr
 * @ptr: pointer to member variable
 * @type: type of the structure containing ptr
 * @member: name of the member variable in struct @type
 *
 * Return: @type pointer of object containing ptr
 */
#ifndef container_of
#ifdef __LIST_HAVE_TYPEOF
#define container_of(ptr, type, member)                          \
	__extension__({                                              \
		const __typeof__(((type*)0)->member)* __pmember = (ptr); \
		(type*)((char*)__pmember - offsetof(type, member));      \
	})
#else
#define container_of(ptr, type, member) ((type*)((char*)(ptr)-offsetof(type, member)))
#endif
#endif

#define likely(x) __builtin_expect(!!(x), 1)
#define unlikely(x) __builtin_expect(!!(x), 0)

// Using __typeof__ extension by GCC
// ! Be careful, the type of value might not be deduced as you expect
#define CONST_INIT(x, value) *(__typeof__(value)*)(&x) = value

int string_hash(const char* s);
int obj_hash(const void* data, size_t size);
// trigger the address sanitizer
void mem_canary_alert(const char* msg);

#endif