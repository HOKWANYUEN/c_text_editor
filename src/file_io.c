#include <stdio.h>
#include<sys/types.h>
#include<sys/ioctl.h>
#include "../include/buffer.h"
#include "../include/terminal.h"
FILE* f;
// int file_io_init(){
//     p=fopen("./test.txt","r+t");
//     if (p==NULL){
//         perror("打开文件时发生错误");
//         return -1;
//     }
//     return 0;
// }
int read_file(struct window *window) {
    FILE* p = fopen("test.txt", "a+");
	if (p)
	{
		for(int i=0;i<window->row;i++){
			struct erow erow;
			window->erows[i]= erow;
		}
		window->row=0;
        while (fgets(window->erows[window->row].a,sizeof(window->erows[window->row].a),p) != NULL)
        {
            int len;
            len=printf("%s",window->erows[window->row].a);
            window->erows[window->row].len=len;
            window->row++;
        }
        printf("\n");
	}else
	{
		printf("文件打开失败！\n");
        return -1;
	}
	fclose(p);
}
int write_file(int c,struct window *window,struct file_cursor f_cursor){
	FILE* p = fopen("test.txt", "w+");
	if (p)
	{	
		for (int i=0;i<window->erows[f_cursor.row-1].len-f_cursor.col;i++){
			window->erows[f_cursor.row-1].a[window->erows[f_cursor.row-1].len-i]=window->erows[f_cursor.row-1].a[window->erows[f_cursor.row-1].len-i-1];
		}
		window->erows[f_cursor.row-1].a[f_cursor.col]=c;

		for(int i=0;i<window->row;i++){
			fputs(window->erows[i].a,p);
		}
	}else
	{
		printf("文件打开失败！\n");
        return -1;
	}
	fclose(p);
}