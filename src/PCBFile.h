// Copyright 2020 Lee Choon Siong. All rights reserved.
// Use of this source code is governed by a MIT-style
// license that can be found in the LICENSE file.

#ifndef PCBFile_h
#define PCBFile_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <assert.h>
#include <setjmp.h>
#include "Helper.h"
#include "PCBData.h"

extern char *data_line1;
extern char *data_line2;

extern void read_data_file(void);
extern void generate_data(const char *year, const char *month, const char *total_mtd_amount, const char *mtd_amount);
extern void write_data_file(const char *line1, const char *line2);

#endif /* PCBFile_h */
