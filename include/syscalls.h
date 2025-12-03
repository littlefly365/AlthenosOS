#ifndef SYSCALLS_H
#define SYSCALLS_H

#include <stdint.h>

// 20 syscalls
int sys_exit(int status);
int sys_write(int fd, const char *buf, uint32_t len);
int sys_read(int fd, char *buf, uint32_t len);
int sys_open(const char *path, int flags);
int sys_close(int fd);
int sys_seek(int fd, int offset, int whence);
uint32_t sys_time(void);
void sys_sleep(uint32_t ms);
int sys_getpid(void);
int sys_fork(void);
int sys_exec(const char *path);
int sys_wait(int pid);
void *sys_brk(intptr_t inc);
int sys_stat(const char *path, void *statbuf);
int sys_reboot(int cmd);
void sys_yield(void);
int sys_getchar(void);
int sys_putchar(char c);
int sys_chdir(const char *path);
char *sys_getcwd(char *buf, uint32_t size);

#endif
