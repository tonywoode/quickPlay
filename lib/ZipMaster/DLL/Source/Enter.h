#ifndef __ENTER_H
#define __ENTER_H

#include "Common.h"
 
int Set_Oper_Abort(OperKeys key); 
void Set_Oper(Frames *Op, int typ);

//struct OpFrame* Get_Current_Oper(void);

extern int Init_Process(void);
extern void Cleanup_Process(void);
extern int Clear_Oper(struct OpFrame* Op); 
extern int Clear_Oper1(struct OpFrame* Op);
                    
extern int UCount;  
extern int ZCount;
extern unsigned int FCount;

#endif
 
