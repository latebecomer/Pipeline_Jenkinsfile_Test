/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _BUR_1650440530_1_
#define _BUR_1650440530_1_

#include <bur/plctypes.h>

/* Datatypes and datatypes of function blocks */
typedef struct myOutputType
{	float out_Real;
	signed short out_Int[3];
	plcbit out_Bool;
} myOutputType;

typedef struct myInputType
{	float in_Real;
	signed short in_Int[3];
	plcbit New_Member;
} myInputType;






__asm__(".section \".plc\"");

/* Used IEC files */
__asm__(".ascii \"iecfile \\\"Logical/Global.typ\\\" scope \\\"global\\\"\\n\"");

/* Exported library functions and function blocks */

__asm__(".previous");


#endif /* _BUR_1650440530_1_ */

