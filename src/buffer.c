#include "../include/buffer.h"
struct buffer buffer;
int buffer_in(int c){
    buffer.buf[buffer.l]=c;
    buffer.l++;
    return 0;
}
struct buffer buffer_out(){
    struct buffer a;
    a=buffer;
    buffer.l=0;
    return a;
}