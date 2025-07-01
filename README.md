```mermaid
graph
A[main] -->B[editor]
B -->C[editor_core]
B-->F[buffer]
B-->G[file_io]
G-->D
F--> D[display]
C-->E[terminal]
D-->E
```
建立一个文件缓冲区、一个光标。
当键盘被按下的时候写入文件并对页面进行刷新。