#include "../include/terminal.h"
#include "../include/display.h"
#include "../include/buffer.h"
#include <time.h>
#include <stdio.h>
#include<sys/types.h>
#include<sys/ioctl.h>
#include<unistd.h>
int cursor_arr[13]={9,13,53,54,65,66,67,68,70,72,27,91,127};
struct  window window;
int terminal_display(){
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
int editor_display(){
    printf("\033c");
    FILE* p = fopen("test.txt", "a+");
	if (p)
	{
        while (fgets(window.erows[window.row].a,sizeof(window.erows[window.row].a),p) != NULL)
        {
            int len;
            len=printf("%s",window.erows[window.row].a);
            window.erows[window.row].len=len;
            window.row++;
        }
        printf("\n");
	}
	else
	{
		printf("文件打开失败！\n");
        return -1;
	}
	struct winsize size;
    ioctl(STDIN_FILENO,TIOCGWINSZ,&size);
    for (int i=0;i<size.ws_row-window.row-1;i++){
        printf("~\n");
    }
    printf("test.txt line:%d",window.row);
    printf("\033[999A\033[999D");
    printf("\033[%dB",window.row-1);
    if (window.erows[window.row-1].len>0){
        printf("\033[%dC",window.erows[window.row-1].len);
    }
    int c;
    int flag;
    while(1){
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
            if (c==127){

            }
            flag=0;
        }else{
            putchar(c);
            fputc(c,p);
        }
    }
    fclose(p);
	p = NULL;
    system("clear");
	return 0;
}