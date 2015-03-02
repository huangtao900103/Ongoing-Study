/* 2015-03-02T11:36+08:00 */
#ifndef COMMON_H_
#define COMMON_H_

#include <stdlib.h>

/* PAUSE */
#ifdef _MSC_VER
# ifdef NDEBUG
#  define PAUSE() (__noop)
# else
#  define PAUSE() system("pause")
# endif
#else
# define PAUSE() ((void)0)
#endif

#define FREE(ptr) do { free(ptr); ptr = NULL; } while (0)

#endif /* COMMON_H_ */