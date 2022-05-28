// Copyright 2020 Lee Choon Siong. All rights reserved.
// Use of this source code is governed by a MIT-style
// license that can be found in the LICENSE file.

#ifndef Helper_h
#define Helper_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <pwd.h>
#include "PCBFile.h"

#define MIN_YEAR_RANGE 1970
#define MAX_YEAR_RANGE 2100
#define MIN_PCB 0
#define MAX_PCB 1000000

extern int set_homedir(void);
extern void print_usage_and_exit(void);

extern bool validYear(int);
extern bool validMonth(int);
extern bool validPCB(const char *);

extern char *left_padding(int, const char *, const char *);
extern char *right_padding(int, const char *, const char *);

#endif /* Helper_h */
