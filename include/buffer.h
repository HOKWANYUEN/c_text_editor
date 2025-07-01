#ifndef TERMINAL_H
int buffer_in(int c);
struct buffer buffer_out();
struct erow{
    char a[1000];
    int len;
};
struct window{
    struct erow erows[1000];
    int row;
};
#endif