#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include "../include/terminal.h"
#include<sys/types.h>
#include<sys/ioctl.h>


struct termios old;
int enableRawMode() {
    struct termios term;
    int err;
    err=tcgetattr(STDIN_FILENO, &term);
    if (err){
        return err;
    }
    struct termios old;
    err=tcgetattr(STDIN_FILENO, &old);
    if (err){
        return err;
    }
    term.c_lflag |= ~(ICANON | ECHO| BRKINT | INPCK | ISTRIP |ISIG |IXON);
    term.c_cc[VMIN]=1;
    term.c_cc[VTIME]=0;
    err=tcsetattr(STDIN_FILENO, TCSANOW, &term);
    if (err){
        return err;
    }
    return err;
}


int disableRawMode() {
    struct termios term;
    int err;
    err=tcgetattr(STDIN_FILENO, &term);
    if (err){
        return err;
    }
    struct termios old;
    err=tcgetattr(STDIN_FILENO, &old);
    if (err){
        return err;
    }
    term.c_lflag |= ~(ICANON | ECHO| BRKINT | INPCK | ISTRIP |ISIG |IXON);
    err=tcsetattr(STDIN_FILENO, TCSANOW, &term);
    if (err){
        return err;
    }
    return err;
}
int terminal_init(){
    return enableRawMode();
    
}
int terminal_done(){
    return disableRawMode();
}
int cursor(int a,struct file_cursor *f_cursor){
    struct winsize size;
    switch (a)
    {
        case 9:   printf("\t");break;
        case 13:  printf("\n");break;
        case 53:
            ioctl(STDIN_FILENO,TIOCGWINSZ,&size);
            printf("\033[%dD\033[%dB",size.ws_col,size.ws_row);
            f_cursor->col+=size.ws_col;
            if (f_cursor->row<0){
                f_cursor->row=0;
            }
            f_cursor->row-=size.ws_col;
            break;
        case 54:   
            ioctl(STDIN_FILENO,TIOCGWINSZ,&size);
            printf("\033[%dD\033[%dB",size.ws_col,size.ws_row);
            f_cursor->col+=size.ws_col;
            f_cursor->row+=size.ws_col;
            break;
        case 65:  printf("\033[A"); f_cursor->row--;break;
        case 66:  printf("\033[B"); f_cursor->row++;break;
        case 67:  printf("\033[C"); f_cursor->col++;break;
        case 68:  printf("\033[D"); f_cursor->col--;break;
        case 70:
            ioctl(STDIN_FILENO,TIOCGWINSZ,&size);
            printf("\033[%dC",size.ws_col-size.ws_xpixel);
            f_cursor->col=size.ws_col-size.ws_xpixel;
            break;
        case 72:  printf("\033[G");f_cursor->col=0;break;
        case 27: break;
        case 91: break;
        case 127: printf("\033[D"); break;
        default:
        break;
    }
    return 0;
}
int getinput(){
    return getchar();
}