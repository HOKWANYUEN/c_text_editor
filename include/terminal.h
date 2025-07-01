#ifndef TERMINAL_H
struct file_cursor{
    int row;
    int col;
};
int terminal_done();
int terminal_init();
int cursor(int a,struct file_cursor *f_cursor);
#endif