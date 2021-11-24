#ifndef __DYNPROG_H__
#define __DYNPROG_H__

void SW_bottomUp(char*, char*, char**, int**, int, int);
void print_Seq_Align_X(char*, char**, int, int);
void print_Seq_Align_Y(char*, char**, int, int);

void memoized_SW(char*, char*, char**, int**, int, int);
void memoized_SW_AUX(char*, char*, char**, int**, int, int);

#endif
