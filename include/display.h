#ifndef TERMINAL_H
struct erow{
    char a[1000];
    int len;
};
struct window{
    struct erow erows[1000];
    int row;
};
struct file_cursor{
    int row;
    int col;
};
int terminal_display();
int editor_display();
#endif