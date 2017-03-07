//
// Created by maksi on 3/1/2017.
//

#ifndef LABWORK2_WRITE_H
#define LABWORK2_WRITE_H

#endif //LABWORK2_WRITE_H

void makefile(FILE *tabl);

void closefile(FILE *d_f_save);

void make_heder_file(FILE *d_f_save);

void Write_time(FILE *d_f_save, int x, int time);

void make_futter_file(FILE *d_f_save);

void Write_in_file(FILE *d_f_save, int x, int dsize, int *d_array);