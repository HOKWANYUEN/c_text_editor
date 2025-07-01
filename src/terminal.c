#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include "../include/terminal.h"
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
    term.c_lflag &= ~(ICANON | ECHO| BRKINT | INPCK | ISTRIP |ISIG |IXON);
    term.c_cc[VMIN]=1;
    term.c_cc[VTIME]=100;
    err=tcsetattr(STDIN_FILENO, TCSANOW, &term);
    if (err){
        return err;
    }
    return err;
}


int disableRawMode() {
    int err;
    err=tcsetattr(STDIN_FILENO, TCSANOW, &old);
    if(err){
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
int cursor(int a){
    switch (a)
    {
        case 9:   printf("\t");break;
        case 13:  printf("\n");break;
        case 53:  printf("PAGUP");break;
        case 54:  printf("PAGDOWN");break;
        case 65:  printf("\033[A"); break;
        case 66:  printf("\033[B"); break;
        case 67:  printf("\033[C"); break;
        case 68:  printf("\033[D"); break;
        case 70:  printf("\033[10C");break;
        case 72:  printf("\033[G");break;
        case 27: break;
        case 91: break;
        case 128: printf("BACK");break;
        default:
        break;
    }
    return 0;
}
int getinput(){
    return getchar();
}