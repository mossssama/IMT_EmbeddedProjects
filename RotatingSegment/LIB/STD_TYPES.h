#ifndef _STD_TYPES_H
#define _STD_TYPES_H

/*
 * Signed Data Types
 */
typedef unsigned char           u8;
typedef unsigned short int      u16;
typedef unsigned long int       u32;

/*	Unsigned Data Types		*/
typedef signed char             s8;
typedef signed short int        s16;
typedef signed long int         s32;

/*	Floating point Types	*/
typedef float                   f32;
typedef double                  f64;

/*	Address NULL			*/
#define ADDRESS_NULL ( (void *) 0x00)

#endif /* _STD_TYPES_H */
