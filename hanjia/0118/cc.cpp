/*  Problem: d733 "11329 - Curious Fleas" from 11329 - Curious Fleas              */
/*  Language: C                                                                   */
/*  Result: AC(1.2s, 31.2MB) judge by this@ZeroJudge                              */
/*  Author: morris1028 at 2011-09-10 14:12:03                                     */
/**********************************************************************************/


#include<stdio.h>
#include<stdlib.h>
#define HAND 876543
struct {
    int state, next;
    char Ans;
}NODE[1760900];
int size = 1, HASH[HAND+1];
int Queue[1760896], Qt = -1;
char Min(char x, char y) {
    return x < y ? x : y;
}
void FreeAll() {
    int i;
    for(i = 0, size = 1; i <= HAND; i++)
        HASH[i] = 0;
}
char insHASH(int state, char Ans) {
    static int m, pre, now;
    m = state%HAND;
    pre = 0, now = HASH[m];
    while(now) {
        if(NODE[now].state == state) {
            NODE[now].Ans = Min(NODE[now].Ans, Ans);
            return 1;
        } else if(NODE[now].state < state) {
            pre = now, now = NODE[now].next;
        }
        else    break;
    }
    NODE[size].Ans = Ans, NODE[size].state = state;
    NODE[size].next = now;
    if(pre)    NODE[pre].next = size;
    else    HASH[m] = size;
    size++;
    return 0;
}
char findHASH(int state) {
    static int m, pre, now;
    m = state%HAND;
    pre = 0, now = HASH[m];
    while(now) {
        if(NODE[now].state == state) {
            return NODE[now].Ans;
        } else if(NODE[now].state < state) {
            pre = now, now = NODE[now].next;
        }
        else    break;
    }
    return -1;
}
void Front_turn(int state, int step) {
    static int change_state, t1, t2, dice;
    t1 = state&63;
    dice = t1&12;/*001100*/
    dice |= ((t1&32) != 0) | (((t1&16) != 0)<<1) | (((t1&2) != 0)<<5) | (((t1&1) != 0)<<4);
    t1 = (state>>6)&15, t2 = t1;
    if(t1 >= 12 && t1 <= 15)    return;
    t1 += 4;
    change_state = dice | ((state>>10)<<10) | (t1<<6);
    if((state&1) != 0 && (state&(1<<(t2+10))) == 0)
        change_state = (change_state | (1<<(t2+10))) - (1<<4);
    else if((state&1) == 0 && (state&(1<<(t2+10))) != 0)
        change_state = (change_state - (1<<(t2+10))) | (1<<4);
    if(insHASH(change_state, step) == 0)
        Queue[++Qt] = change_state;
}
void Back_turn(int state, int step) {
    static int change_state, t1, t2, dice;
    t1 = state&63;
    dice = t1&12;/*001100*/
    dice |= (((t1&32) != 0)<<1) | ((t1&16) != 0) | (((t1&2) != 0)<<4) | (((t1&1) != 0)<<5);
    t1 = (state>>6)&15, t2 = t1;
    if(t1 >= 0 && t1 <= 3)    return;
    t1 -= 4;
    change_state = dice | ((state>>10)<<10) | (t1<<6);
    if((state&1) != 0 && (state&(1<<(t2+10))) == 0)
        change_state = (change_state | (1<<(t2+10))) - (1<<5);
    else if((state&1) == 0 && (state&(1<<(t2+10))) != 0)
        change_state = (change_state - (1<<(t2+10))) | (1<<5);
    if(insHASH(change_state, step) == 0)
        Queue[++Qt] = change_state;
}
void Right_turn(int state, int step) {
    static int change_state = 0, t1, t2, dice;
    t1 = state&63;
    dice = t1&48;/*110000*/
    dice |= (((t1&8) != 0)<<1) | (((t1&4) != 0)) | (((t1&2) != 0)<<2) | (((t1&1) != 0)<<3);
    t1 = (state>>6)&15, t2 = t1;
    if(t1 == 3 || t1 == 7 || t1 == 11 || t1 == 15)    return;
    t1 += 1;
    change_state = dice | ((state>>10)<<10) | (t1<<6);
    if((state&1) != 0 && (state&(1<<(t2+10))) == 0)
        change_state = (change_state | (1<<(t2+10))) - (1<<3);
    else if((state&1) == 0 && (state&(1<<(t2+10))) != 0)
        change_state = (change_state - (1<<(t2+10))) | (1<<3);
    if(insHASH(change_state, step) == 0)
        Queue[++Qt] = change_state;
}
void Left_turn(int state, int step) {
    static int change_state = 0, t1, t2, dice;
    t1 = state&63;
    dice = t1&48;/*110000*/
    dice |= (((t1&8) != 0)) | (((t1&4) != 0)<<1) | (((t1&2) != 0)<<3) | (((t1&1) != 0)<<2);
    t1 = (state>>6)&15, t2 = t1;
    if(t1 == 0 || t1 == 4 || t1 == 8 || t1 == 12)    return;
    t1 -= 1;
    change_state = dice | ((state>>10)<<10) | (t1<<6);
    if((state&1) != 0 && (state&(1<<(t2+10))) == 0)
        change_state = (change_state | (1<<(t2+10))) - (1<<2);
    else if((state&1) == 0 && (state&(1<<(t2+10))) != 0)
        change_state = (change_state - (1<<(t2+10))) | (1<<2);
    if(insHASH(change_state, step) == 0)
        Queue[++Qt] = change_state;
}
void process() {
    FreeAll();
    int i, j, now, step, k;
    for(i = 0; i <= 15; i++)
        for(j = 0; j <= 63; j++) {
            k = (i<<6) | j;
            insHASH(k, 0);
            Queue[++Qt] = k;
        }
    for(i = 0; i <= Qt; i++) {
        now = Queue[i], step = findHASH(now)+1;
        Front_turn(now, step);
        Back_turn(now, step);
        Right_turn(now, step);
        Left_turn(now, step);
    }
}
main() {
    process();
    int t;
    char s[5];
    scanf("%d", &t);
    while(t--) {
        int i, j, state = 0;
        for(i = 0; i < 4; i++) {
            scanf("%s", s);
            for(j = 0; j < 4; j++) {
                if(s[j] == 'X')
                    state |= (1<<(i*4+j+10));
                if(s[j] == 'D')
                    state += (1<<6)*(i*4+j);
            }
        }
        if(findHASH(state) == -1)
            puts("impossible");
        else
            printf("%d\n", findHASH(state));
    }
    return 0;
}