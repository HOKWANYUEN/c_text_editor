#include "../include/terminal.h"
#include "../include/display.h"
#include "../include/buffer.h"
#include "../include/file_io.h"
#include <time.h>
#include <stdio.h>
#include<sys/types.h>
#include<sys/ioctl.h>
#include<unistd.h>
int cursor_arr[13]={9,13,53,54,65,66,67,68,70,72,27,91,127};
struct  window window;
struct file_cursor f_cursor;
int editor_display(){
    int c;
    int flag;
    read_file(&window);
    read_display(window);
    f_cursor.row=window.row;
    f_cursor.col=window.erows[window.row-1].len;
    while(1){
        read_file(&window);
        read_display(window);
        c = getinput();
        for (int i =0;i<13;i++){
            if (c==cursor_arr[i]){
                flag=1;
                break;
            }
        }
        if (c == 3) break;
        if (flag == 1){
            cursor(c,&f_cursor);
            flag=0;
        }else{
            write_file(c,&window,f_cursor);
            f_cursor.col++;
        }
    }
    system("clear");
	return 0;
}
int read_display(){
    printf("\033c");
    for (int i=0;i<window.row;i++){
        printf(window.erows[i].a);
    }
    printf("\n");
	struct winsize size;
    ioctl(STDIN_FILENO,TIOCGWINSZ,&size);
    for (int i=0;i<size.ws_row-window.row-1;i++){
        printf("~\n");
    }
    printf("test.txt line:%d",f_cursor.row+1);
    printf("\033[%d;%dH",f_cursor.row,f_cursor.col);
}