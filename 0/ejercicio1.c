#define YES 1
#define NO 0
#line 3000

#ifdef TRUE
#undef TRUE
#endif

#define TRUE 1

#if (TRUE)
#define FALSE 0
#else
#define FALSE 1
#endif

#define SQUARE_AREA(a) ((a) * (a))
