#include "../include/editor_core.h"
#include "../include/editor.h"
#include "../include/terminal.h"
int editor_init(){
    int err;
    err = editor_core_init();
    if (err){
        return 1;
    }
    return terminal_init();
}
int editor_done(){
        int err;
    err = editor_core_done();
    if (err){
        return 1;
    }
    return terminal_done();
}