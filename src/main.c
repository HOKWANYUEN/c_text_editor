#include <stdio.h>
#include "../include/editor.h"
#include "../include/display.h"
int main(){
    int err;
    err=editor_init();
    if (err==1){
        printf("\nerror!");
        return 0;
    }
    display();
    editor_done();
    return 0;
}