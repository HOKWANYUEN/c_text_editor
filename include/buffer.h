#ifndef TERMINAL_H
int buffer_in(int c);
struct buffer buffer_out();
struct buffer{
    int buf[1024];
    int l;
};
#endif