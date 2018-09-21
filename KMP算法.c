#include <studio.h>


void get_next(String T, int *next)
{
    int i, j;
    i = 1;
    j = 0;
    next[1] = 0;
    /* 此处T[0]表示串T的长度 */
    while (i < T[0])                   
    {
        /* T[i]表示后缀的单个字符， */
        /* T[j]表示前缀的单个字符 */
        if (j == 0 || T[i] == T[j])    
        {
            ++i;
            ++j;
            next[i] = j;
        }
        else
            /* 若字符不相同，则j值回溯 */
            j = next[j];               
    }
}


int Index_KMP(String S, String T, int pos)
{
    /* i用于主串S当前位置下标值，若pos不为1， */
    /* 则从pos位置开始匹配 */
    int i = pos;                       
    /* j用于子串T中当前位置下标值 */
    int j = 1;                         
    /* 定义一next数组 */
    int next[255];                     
    /* 对串T作分析，得到next数组 */
    get_next(T, next);                 
    /* 若i小于S的长度且j小于T的长度时， */
    /* 循环继续 */
    while (i <= S[0] && j <= T[0]
	{
        /* 两字母相等则继续，相对于朴素算法增加了 */
        /* j=0判断 */
        if (j == 0 || S[i] == T[j])    
        {
            ++i;
            ++j;
        }
        /* 指针后退重新开始匹配 */
        else                           
        {
            /* j退回合适的位置，i值不变 */
            j = next[j];               
        }
    }
    if (j > T[0])
        return i - T[0];
    else
        return 0;
}

int main(){
	return 0;
}