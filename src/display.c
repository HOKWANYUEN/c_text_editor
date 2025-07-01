#include "../include/terminal.h"
#include "../include/display.h"
int cursor_arr[13]={9,13,53,54,65,66,67,68,70,72,27,91,128};
int display(){
    int c;
    int flag;
    while (1) {
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
        }else{
            putchar(c);
            flag=0;
        }
    }
    return 0;
}