#ifndef __DLLENTER_H
#define __DLLENTER_H

typedef unsigned long OperKeys;
#define NOT_ASSIGNED_OPER ((OperKeys)(unsigned)-1)

struct OpFrame
{
  int Abort_Flag; 
  OperKeys OpKey;
  struct OpFrame* Prev;
  struct OpFrame* ME;  // validity check
};

// TLS data at index is head of list of OpFrame 
//extern DWORD TgbIndex; // RCV added, our only non-constant global.

int Add_Oper(struct OpFrame* Op);
int Remove_Oper(struct OpFrame* Op);
int Set_Oper_Abort(OperKeys key);

struct OpFrame* Get_Current_Oper(void);

extern int Init_Process(void);
extern int Clear_Oper(struct OpFrame* Op);

#endif
 
