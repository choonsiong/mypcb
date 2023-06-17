// Copyright 2020 Lee Choon Siong. All rights reserved.
// Use of this source code is governed by a MIT-style
// license that can be found in the LICENSE file.

#include "../include/Helper.h"

int set_homedir(void) {
    struct passwd *pw = getpwuid(getuid());
    assert(pw != NULL);
    
    return (chdir(pw->pw_dir));
}

void print_usage_and_exit(void) {
    fprintf(stderr, "Usage: my_pcb YEAR MONTH PCB_AMOUNT\n");
    fprintf(stderr, "\n\tYEAR         from %d to %d\n", MIN_YEAR_RANGE, MAX_YEAR_RANGE);
    fprintf(stderr, "\tMONTH        from 1 to 12\n");
    fprintf(stderr, "\tPCB_AMOUNT   from 0 (0.00) to %d (%d.00)\n", MAX_PCB, MAX_PCB/100);
    fprintf(stderr, "\n\te.g.\n\t PCB for 2018 Jan is $1234.56, so enter:\n\t my_pcb 2018 01 123456\n");
    
    exit(1);
}

bool valid_year(int year) {
    if (year >= MIN_YEAR_RANGE && year <= MAX_YEAR_RANGE) {
        return true;
    }
    
    return false;
}

bool valid_month(int month) {
    if (month >= 1 && month <= 12) {
        return true;
    }
    
    return false;
}

bool valid_pcb(const char *value) {
    char *temp = (char *)calloc(1, sizeof(strlen(value))+ 1);
    temp = (char *)value;

    // Numbers only
    while (*temp != '\0') {
        if (!isdigit(*temp)) {
            return false;
        }
        
        temp++;
    }
    
    int number = atoi(value);
    
    // Make sure valid within acceptable range
    if (number < MIN_PCB || number > MAX_PCB) {
        return false;
    }
    
    return true;
}

char *left_padding(int count, const char *ch, const char *value) {
    char *str = (char *)calloc(1, sizeof(strlen(value)) + count);
    *str = *((char *)ch); // assign first padding character
    
    // start with i = 1 because of above assignment
    for (int i = 1; i < count; ++i) {
        strcat(str, ch);
    }
    
    strcat(str, value);
    
    return str;
}

char *right_padding(int total_size, const char *ch, const char *value) {
    // Allocate enough space for the string plus padding character and NUL
    char *str = (char *)calloc(1, total_size + 1);
    
    // Number of padding character required
    size_t count = total_size - strlen(value);
    
    strlcpy(str, value, total_size - count + 1); // + 1 for NUL    
    
    for (size_t i = 0; i < count; ++i) {
        strcat(str, ch);
    }
    
    return str;
}
