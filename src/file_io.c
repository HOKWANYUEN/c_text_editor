#include <stdio.h>
#include<sys/types.h>
#include<sys/ioctl.h>

FILE* f;
// int file_io_init(){
//     p=fopen("./test.txt","r+t");
//     if (p==NULL){
//         perror("打开文件时发生错误");
//         return -1;
//     }
//     return 0;
// }
int file_read() {
    f=fopen("/mnt/c/Users/HEKUN/Desktop/temp/text_editor/test.txt","r+t");
    if (f==NULL){
        perror("打开文件时发生错误");
        return -1;
    }
	if (f)
	{
        char str[60];
        if( fgets (str, 60, f)!=NULL ) {
            /* 向标准输出 stdout 写入内容 */
            puts(str);
        }
		fclose(f);
		f = NULL;
	}
	else
	{
		printf("文件打开失败！\n");
	}
	system("pause");
	return 0;
}
