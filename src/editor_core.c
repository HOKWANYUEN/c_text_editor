#include "../include/input.h"
#include "../include/editor_core.h"
int editor_core_init(){
    return input_init();
}
int editor_core_done(){
    return input_done();
}