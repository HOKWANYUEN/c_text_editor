#include "../include/terminal.h"
#include "../include/display.h"
#include "../include/buffer.h"
#include <time.h>
int cursor_arr[13]={9,13,53,54,65,66,67,68,70,72,27,91,128};
int display(){
    int c;
    int flag;
    time_t start,end;
    start = clock();
    while (1) {
        end=clock();
        if (end-start>10){
            // struct buffer *a;
            // a=buffer_out;
            // for (int i=0;i<a->l;i++){
            //     putchar(a->buf[i]);
            // }
            // start=clock();
        }
        c = getinput();
        for (int i =0;i<13;i++){
            if (c==cursor_arr[i]){
                flag=1;
                break;
            }
        }
        if (c == 'q') break;
        if (flag == 1){
            cursor(c);
            flag=0;
        }else{
            putchar(c);
            // buffer_in(c);
        }
    }
    return 0;
}