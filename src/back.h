#ifndef BACK_H__
#define BACK_H__
#pragma once

#ifdef WITH_COLOR
# define BACK_COLOR "\x1b[36;1m"
# define BACK_COLOR_RESET "\x1b[0m"
# define BACK_COLOR_ERR "\x1b[31;1m"
#else
# define BACK_COLOR
# define BACK_COLOR_RESET
# define BACK_COLOR_ERR
#endif

#define BACK_ERR(msg) fprintf(stderr, BACK_COLOR "[BACK] " BACK_COLOR_RESET     \
    BACK_COLOR_ERR "error" BACK_COLOR_RESET ": " msg "\n")
#define BACK_LOG(msg) printf(BACK_COLOR "[BACK] " BACK_COLOR_RESET msg "\n")
#define BACK_ERRF(fmt, ...) fprintf(stderr,                                     \
    BACK_COLOR "[BACK] " BACK_COLOR_RESET                                       \
    BACK_COLOR_ERR "error" BACK_COLOR_RESET ": " fmt "\n",                      \
    __VA_ARGS__)
#define BACK_LOGF(fmt, ...) printf(BACK_COLOR "[BACK] " BACK_COLOR_RESET        \
    fmt "\n", __VA_ARGS__)

#ifdef UNUSED
# error "UNUSED is already defined."
#endif
#if (__GNUC__ > 2) || (__GNUC__ == 2 && __GNUC_MINOR__ > 4)
# define UNUSED __attribute__((__unused__))
#else
# define UNUSED
#endif

int back_bone(int, char**);
int back_up(int, char**);
int back_list(int, char**);
int back_pack(int, char**);
int back_wash(int, char**);
int back_spin(int, char**);
int back_track(int, char**);

#ifdef WITH_TIMER
long long back_clock(void);
double back_clock_secs(long long);
#endif

#endif
