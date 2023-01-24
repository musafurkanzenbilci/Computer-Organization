#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
/*
 * Please fill in the following team_t struct
 */
team_t team = {
    "SINGLE", /* Team Name */

    "e2469203",             /* First student ID */
    "Musa Furkan Zenbilci", /* First student name */

    "", /* Second student ID */
    "", /* Second student name */

    "", /* Third student ID */
    ""  /* Third student Name */
};

/********************
 * CONVOLUTION KERNEL
 ********************/

/***************************************************************
 * Your different versions of the convolution functions  go here
 ***************************************************************/

char naive_conv1_descr[] = "naive_conv1: Naive 1 implementation";
void naive_conv1(int dim, pixel *src, pixel *ker, unsigned *dst)
{
    int i, j, k, l, limit, index, srcindex, kerindex, srcmid, kermid, mid;
    kermid = 0;
    limit = dim - 7;
    for (i = 0; i < limit; i++)
    {
        mid = i * dim;
        for (j = 0; j < limit; j++)
        {
            index = mid + j;
            dst[index] = 0;
            for (k = 0; k < 8; k++)
            {
                srcmid = (i + k) * dim + j;
                kermid = k * 8;
                for (l = 0; l < 8; l++)
                {
                    srcindex = srcmid + l;
                    kerindex = kermid + l;

                    dst[index] +=
                        src[srcindex].red * ker[kerindex].red + src[srcindex].green * ker[kerindex].green + src[srcindex].blue * ker[kerindex].blue;
                }
            }
        }
    }
}

char naive_conv_unroll_descr[] = "naive_conv_unrolll: Loop Unrolling";
void naive_conv_unroll(int dim, pixel *src, pixel *ker, unsigned *dst)
{
    int i, j, k, l, limit, index, srcindex, kerindex, srcmid, kermid, mid;
    pixel l0, l1, l2, l3, l4, l5, l6, l7;
    pixel k0, k1, k2, k3, k4, k5, k6, k7;
    int tempsum = 0;
    kermid = 0;
    limit = dim - 7;
    for (i = 0; i < limit; i++)
    {
        mid = i * dim;
        for (j = 0; j < limit; j++)
        {
            index = mid + j;
            dst[index] = 0;
            for (k = 0; k < 8; k++)
            {
                srcmid = (i * dim) + j + (k * dim);
                kermid = k * 8;
                k0 = ker[kermid];
                k1 = ker[kermid + 1];
                k2 = ker[kermid + 2];
                k3 = ker[kermid + 3];
                k4 = ker[kermid + 4];
                k5 = ker[kermid + 5];
                k6 = ker[kermid + 6];
                k7 = ker[kermid + 7];

                l0 = src[srcmid];
                l1 = src[srcmid + 1];
                l2 = src[srcmid + 2];
                l3 = src[srcmid + 3];
                l4 = src[srcmid + 4];
                l5 = src[srcmid + 5];
                l6 = src[srcmid + 6];
                l7 = src[srcmid + 7];

                tempsum += l0.red * k0.red + l0.green * k0.green + l0.blue * k0.blue;
                tempsum += l1.red * k1.red + l1.green * k1.green + l1.blue * k1.blue;
                tempsum += l2.red * k2.red + l2.green * k2.green + l2.blue * k2.blue;
                tempsum += l3.red * k3.red + l3.green * k3.green + l3.blue * k3.blue;
                tempsum += l4.red * k4.red + l4.green * k4.green + l4.blue * k4.blue;
                tempsum += l5.red * k5.red + l5.green * k5.green + l5.blue * k5.blue;
                tempsum += l6.red * k6.red + l6.green * k6.green + l6.blue * k6.blue;
                tempsum += l7.red * k7.red + l7.green * k7.green + l7.blue * k7.blue;

                dst[index] += tempsum;
                tempsum = 0;
                /*for (l = 0; l < 8; l += 2)
                {
                    srcindex = srcmid + l;
                    kerindex = kermid + l;

                    dst[index] +=
                        src[srcindex].red * ker[kerindex].red + src[srcindex].green * ker[kerindex].green + src[srcindex].blue * ker[kerindex].blue
                        + src[srcindex + 1].red * ker[kerindex + 1].red + src[srcindex + 1].green * ker[kerindex + 1].green + src[srcindex + 1].blue * ker[kerindex + 1].blue;
                }*/
            }
        }
    }
}

char naive_conv_unroll2_descr[] = "naive_conv_unrolll2: Loop Unrolling2";
void naive_conv_unroll2(int dim, pixel *src, pixel *ker, unsigned *dst)
{
    int i, j, k, l, limit, index, srcindex, kerindex, srcmid, srcmid0, kermid, mid;
    pixel l0, l1, l2, l3, l4, l5, l6, l7;

    pixel k0, k1, k2, k3, k4, k5, k6, k7;
    pixel k8, k9, k10, k11, k12, k13, k14, k15;
    pixel k16, k17, k18, k19, k20, k21, k22, k23;
    pixel k24, k25, k26, k27, k28, k29, k30, k31;
    pixel k32, k33, k34, k35, k36, k37, k38, k39;
    pixel k40, k41, k42, k43, k44, k45, k46, k47;
    pixel k48, k49, k50, k51, k52, k53, k54, k55;
    pixel k56, k57, k58, k59, k60, k61, k62, k63;

    k0 = ker[0];
    k1 = ker[1];
    k2 = ker[2];
    k3 = ker[3];
    k4 = ker[4];
    k5 = ker[5];
    k6 = ker[6];
    k7 = ker[7];
    k8 = ker[8];
    k9 = ker[9];
    k10 = ker[10];
    k11 = ker[11];
    k12 = ker[12];
    k13 = ker[13];
    k14 = ker[14];
    k15 = ker[15];
    k16 = ker[16];
    k17 = ker[17];
    k18 = ker[18];
    k19 = ker[19];
    k20 = ker[20];
    k21 = ker[21];
    k22 = ker[22];
    k23 = ker[23];
    k24 = ker[24];
    k25 = ker[25];
    k26 = ker[26];
    k27 = ker[27];
    k28 = ker[28];
    k29 = ker[29];
    k30 = ker[30];
    k31 = ker[31];
    k32 = ker[32];
    k33 = ker[33];
    k34 = ker[34];
    k35 = ker[35];
    k36 = ker[36];
    k37 = ker[37];
    k38 = ker[38];
    k39 = ker[39];
    k40 = ker[40];
    k41 = ker[41];
    k42 = ker[42];
    k43 = ker[43];
    k44 = ker[44];
    k45 = ker[45];
    k46 = ker[46];
    k47 = ker[47];
    k48 = ker[48];
    k49 = ker[49];
    k50 = ker[50];
    k51 = ker[51];
    k52 = ker[52];
    k53 = ker[53];
    k54 = ker[54];
    k55 = ker[55];
    k56 = ker[56];
    k57 = ker[57];
    k58 = ker[58];
    k59 = ker[59];
    k60 = ker[60];
    k61 = ker[61];
    k62 = ker[62];
    k63 = ker[63];

    int tempsum = 0;
    kermid = 0;
    limit = dim - 7;
    mid = 0;
    srcmid0 = 0;

    for (i = 0; i < limit; i++)
    {
        for (j = 0; j < limit; j++)
        {
            index = mid + j;
            dst[index] = 0;
            // srcmid = (i * dim) + j + (k * dim);
            srcmid0 = index; // 0 1 2

            // Assign L
            l0 = src[srcmid0]; // 0 .. dim-7
            l1 = src[srcmid0 + 1];
            l2 = src[srcmid0 + 2];
            l3 = src[srcmid0 + 3];
            l4 = src[srcmid0 + 4];
            l5 = src[srcmid0 + 5];
            l6 = src[srcmid0 + 6];
            l7 = src[srcmid0 + 7];
            // Do The Math

            tempsum = l0.red * k0.red + l0.green * k0.green + l0.blue * k0.blue;
            tempsum += l1.red * k1.red + l1.green * k1.green + l1.blue * k1.blue;
            tempsum += l2.red * k2.red + l2.green * k2.green + l2.blue * k2.blue;
            tempsum += l3.red * k3.red + l3.green * k3.green + l3.blue * k3.blue;
            tempsum += l4.red * k4.red + l4.green * k4.green + l4.blue * k4.blue;
            tempsum += l5.red * k5.red + l5.green * k5.green + l5.blue * k5.blue;
            tempsum += l6.red * k6.red + l6.green * k6.green + l6.blue * k6.blue;
            tempsum += l7.red * k7.red + l7.green * k7.green + l7.blue * k7.blue;

            dst[index] += tempsum;

            srcmid0 += dim; // 1

            // Assign L
            l0 = src[srcmid0];
            l1 = src[srcmid0 + 1];
            l2 = src[srcmid0 + 2];
            l3 = src[srcmid0 + 3];
            l4 = src[srcmid0 + 4];
            l5 = src[srcmid0 + 5];
            l6 = src[srcmid0 + 6];
            l7 = src[srcmid0 + 7];
            // Do The Math

            tempsum = l0.red * k8.red + l0.green * k8.green + l0.blue * k8.blue;
            tempsum += l1.red * k9.red + l1.green * k9.green + l1.blue * k9.blue;
            tempsum += l2.red * k10.red + l2.green * k10.green + l2.blue * k10.blue;
            tempsum += l3.red * k11.red + l3.green * k11.green + l3.blue * k11.blue;
            tempsum += l4.red * k12.red + l4.green * k12.green + l4.blue * k12.blue;
            tempsum += l5.red * k13.red + l5.green * k13.green + l5.blue * k13.blue;
            tempsum += l6.red * k14.red + l6.green * k14.green + l6.blue * k14.blue;
            tempsum += l7.red * k15.red + l7.green * k15.green + l7.blue * k15.blue;

            dst[index] += tempsum;

            srcmid0 += dim; // 2

            // Assign L
            l0 = src[srcmid0];
            l1 = src[srcmid0 + 1];
            l2 = src[srcmid0 + 2];
            l3 = src[srcmid0 + 3];
            l4 = src[srcmid0 + 4];
            l5 = src[srcmid0 + 5];
            l6 = src[srcmid0 + 6];
            l7 = src[srcmid0 + 7];
            // Do The Math

            tempsum = l0.red * k16.red + l0.green * k16.green + l0.blue * k16.blue;
            tempsum += l1.red * k17.red + l1.green * k17.green + l1.blue * k17.blue;
            tempsum += l2.red * k18.red + l2.green * k18.green + l2.blue * k18.blue;
            tempsum += l3.red * k19.red + l3.green * k19.green + l3.blue * k19.blue;
            tempsum += l4.red * k20.red + l4.green * k20.green + l4.blue * k20.blue;
            tempsum += l5.red * k21.red + l5.green * k21.green + l5.blue * k21.blue;
            tempsum += l6.red * k22.red + l6.green * k22.green + l6.blue * k22.blue;
            tempsum += l7.red * k23.red + l7.green * k23.green + l7.blue * k23.blue;

            dst[index] += tempsum;

            srcmid0 += dim; // 3

            // Assign L
            l0 = src[srcmid0];
            l1 = src[srcmid0 + 1];
            l2 = src[srcmid0 + 2];
            l3 = src[srcmid0 + 3];
            l4 = src[srcmid0 + 4];
            l5 = src[srcmid0 + 5];
            l6 = src[srcmid0 + 6];
            l7 = src[srcmid0 + 7];
            // Do The Math

            tempsum = l0.red * k24.red + l0.green * k24.green + l0.blue * k24.blue;
            tempsum += l1.red * k25.red + l1.green * k25.green + l1.blue * k25.blue;
            tempsum += l2.red * k26.red + l2.green * k26.green + l2.blue * k26.blue;
            tempsum += l3.red * k27.red + l3.green * k27.green + l3.blue * k27.blue;
            tempsum += l4.red * k28.red + l4.green * k28.green + l4.blue * k28.blue;
            tempsum += l5.red * k29.red + l5.green * k29.green + l5.blue * k29.blue;
            tempsum += l6.red * k30.red + l6.green * k30.green + l6.blue * k30.blue;
            tempsum += l7.red * k31.red + l7.green * k31.green + l7.blue * k31.blue;

            dst[index] += tempsum;

            srcmid0 += dim; // 4

            // Assign L
            l0 = src[srcmid0];
            l1 = src[srcmid0 + 1];
            l2 = src[srcmid0 + 2];
            l3 = src[srcmid0 + 3];
            l4 = src[srcmid0 + 4];
            l5 = src[srcmid0 + 5];
            l6 = src[srcmid0 + 6];
            l7 = src[srcmid0 + 7];
            // Do The Math

            tempsum = l0.red * k32.red + l0.green * k32.green + l0.blue * k32.blue;
            tempsum += l1.red * k33.red + l1.green * k33.green + l1.blue * k33.blue;
            tempsum += l2.red * k34.red + l2.green * k34.green + l2.blue * k34.blue;
            tempsum += l3.red * k35.red + l3.green * k35.green + l3.blue * k35.blue;
            tempsum += l4.red * k36.red + l4.green * k36.green + l4.blue * k36.blue;
            tempsum += l5.red * k37.red + l5.green * k37.green + l5.blue * k37.blue;
            tempsum += l6.red * k38.red + l6.green * k38.green + l6.blue * k38.blue;
            tempsum += l7.red * k39.red + l7.green * k39.green + l7.blue * k39.blue;

            dst[index] += tempsum;

            srcmid0 += dim; // 5

            // Assign L
            l0 = src[srcmid0];
            l1 = src[srcmid0 + 1];
            l2 = src[srcmid0 + 2];
            l3 = src[srcmid0 + 3];
            l4 = src[srcmid0 + 4];
            l5 = src[srcmid0 + 5];
            l6 = src[srcmid0 + 6];
            l7 = src[srcmid0 + 7];
            // Do The Math

            tempsum = l0.red * k40.red + l0.green * k40.green + l0.blue * k40.blue;
            tempsum += l1.red * k41.red + l1.green * k41.green + l1.blue * k41.blue;
            tempsum += l2.red * k42.red + l2.green * k42.green + l2.blue * k42.blue;
            tempsum += l3.red * k43.red + l3.green * k43.green + l3.blue * k43.blue;
            tempsum += l4.red * k44.red + l4.green * k44.green + l4.blue * k44.blue;
            tempsum += l5.red * k45.red + l5.green * k45.green + l5.blue * k45.blue;
            tempsum += l6.red * k46.red + l6.green * k46.green + l6.blue * k46.blue;
            tempsum += l7.red * k47.red + l7.green * k47.green + l7.blue * k47.blue;

            dst[index] += tempsum;

            srcmid0 += dim; // 6

            // Assign L
            l0 = src[srcmid0];
            l1 = src[srcmid0 + 1];
            l2 = src[srcmid0 + 2];
            l3 = src[srcmid0 + 3];
            l4 = src[srcmid0 + 4];
            l5 = src[srcmid0 + 5];
            l6 = src[srcmid0 + 6];
            l7 = src[srcmid0 + 7];
            // Do The Math

            tempsum = l0.red * k48.red + l0.green * k48.green + l0.blue * k48.blue;
            tempsum += l1.red * k49.red + l1.green * k49.green + l1.blue * k49.blue;
            tempsum += l2.red * k50.red + l2.green * k50.green + l2.blue * k50.blue;
            tempsum += l3.red * k51.red + l3.green * k51.green + l3.blue * k51.blue;
            tempsum += l4.red * k52.red + l4.green * k52.green + l4.blue * k52.blue;
            tempsum += l5.red * k53.red + l5.green * k53.green + l5.blue * k53.blue;
            tempsum += l6.red * k54.red + l6.green * k54.green + l6.blue * k54.blue;
            tempsum += l7.red * k55.red + l7.green * k55.green + l7.blue * k55.blue;

            dst[index] += tempsum;

            srcmid0 += dim; // 7

            // Assign L
            l0 = src[srcmid0];
            l1 = src[srcmid0 + 1];
            l2 = src[srcmid0 + 2];
            l3 = src[srcmid0 + 3];
            l4 = src[srcmid0 + 4];
            l5 = src[srcmid0 + 5];
            l6 = src[srcmid0 + 6];
            l7 = src[srcmid0 + 7];
            // Do The Math

            tempsum = l0.red * k56.red + l0.green * k56.green + l0.blue * k56.blue;
            tempsum += l1.red * k57.red + l1.green * k57.green + l1.blue * k57.blue;
            tempsum += l2.red * k58.red + l2.green * k58.green + l2.blue * k58.blue;
            tempsum += l3.red * k59.red + l3.green * k59.green + l3.blue * k59.blue;
            tempsum += l4.red * k60.red + l4.green * k60.green + l4.blue * k60.blue;
            tempsum += l5.red * k61.red + l5.green * k61.green + l5.blue * k61.blue;
            tempsum += l6.red * k62.red + l6.green * k62.green + l6.blue * k62.blue;
            tempsum += l7.red * k63.red + l7.green * k63.green + l7.blue * k63.blue;

            dst[index] += tempsum;
        }
        mid += dim;
    }
}

char naive_conv_unroll3_descr[] = "naive_conv_unrolll3: Loop Unrolling3";
void naive_conv_unroll3(int dim, pixel *src, pixel *ker, unsigned *dst)
{
    int i, j, k, l, limit, index, srcindex, kerindex, srcmid, srcmid0, kermid, mid;
    pixel l0, l1, l2, l3, l4, l5, l6, l7;

    pixel k0, k1, k2, k3, k4, k5, k6, k7;
    pixel k8, k9, k10, k11, k12, k13, k14, k15;
    pixel k16, k17, k18, k19, k20, k21, k22, k23;
    pixel k24, k25, k26, k27, k28, k29, k30, k31;
    pixel k32, k33, k34, k35, k36, k37, k38, k39;
    pixel k40, k41, k42, k43, k44, k45, k46, k47;
    pixel k48, k49, k50, k51, k52, k53, k54, k55;
    pixel k56, k57, k58, k59, k60, k61, k62, k63;

    k0 = ker[0];
    k1 = ker[1];
    k2 = ker[2];
    k3 = ker[3];
    k4 = ker[4];
    k5 = ker[5];
    k6 = ker[6];
    k7 = ker[7];
    k8 = ker[8];
    k9 = ker[9];
    k10 = ker[10];
    k11 = ker[11];
    k12 = ker[12];
    k13 = ker[13];
    k14 = ker[14];
    k15 = ker[15];
    k16 = ker[16];
    k17 = ker[17];
    k18 = ker[18];
    k19 = ker[19];
    k20 = ker[20];
    k21 = ker[21];
    k22 = ker[22];
    k23 = ker[23];
    k24 = ker[24];
    k25 = ker[25];
    k26 = ker[26];
    k27 = ker[27];
    k28 = ker[28];
    k29 = ker[29];
    k30 = ker[30];
    k31 = ker[31];
    k32 = ker[32];
    k33 = ker[33];
    k34 = ker[34];
    k35 = ker[35];
    k36 = ker[36];
    k37 = ker[37];
    k38 = ker[38];
    k39 = ker[39];
    k40 = ker[40];
    k41 = ker[41];
    k42 = ker[42];
    k43 = ker[43];
    k44 = ker[44];
    k45 = ker[45];
    k46 = ker[46];
    k47 = ker[47];
    k48 = ker[48];
    k49 = ker[49];
    k50 = ker[50];
    k51 = ker[51];
    k52 = ker[52];
    k53 = ker[53];
    k54 = ker[54];
    k55 = ker[55];
    k56 = ker[56];
    k57 = ker[57];
    k58 = ker[58];
    k59 = ker[59];
    k60 = ker[60];
    k61 = ker[61];
    k62 = ker[62];
    k63 = ker[63];

    int tempsum = 0;
    kermid = 0;
    limit = dim - 7;
    mid = 0;
    srcmid0 = 0;
    pixel *src2 = src;
    pixel *src3 = src;
    for (i = 0; i < limit; i++)
    {
        for (j = 0; j < limit; j++)
        {
            index = mid + j;
            dst[index] = 0;
            // srcmid = (i * dim) + j + (k * dim);
            // srcmid0 = index; // 0 1 2
            src = src2;

            // Assign L
            l0 = src[0]; // 0 .. dim-7
            l1 = src[1];
            l2 = src[2];
            l3 = src[3];
            l4 = src[4];
            l5 = src[5];
            l6 = src[6];
            l7 = src[7];
            // Do The Math

            tempsum = l0.red * k0.red + l0.green * k0.green + l0.blue * k0.blue;
            tempsum += l1.red * k1.red + l1.green * k1.green + l1.blue * k1.blue;
            tempsum += l2.red * k2.red + l2.green * k2.green + l2.blue * k2.blue;
            tempsum += l3.red * k3.red + l3.green * k3.green + l3.blue * k3.blue;
            tempsum += l4.red * k4.red + l4.green * k4.green + l4.blue * k4.blue;
            tempsum += l5.red * k5.red + l5.green * k5.green + l5.blue * k5.blue;
            tempsum += l6.red * k6.red + l6.green * k6.green + l6.blue * k6.blue;
            tempsum += l7.red * k7.red + l7.green * k7.green + l7.blue * k7.blue;

            dst[index] += tempsum;

            // srcmid0 += dim; // 1
            src += dim;

            // Assign L
            l0 = src[0];
            l1 = src[1];
            l2 = src[2];
            l3 = src[3];
            l4 = src[4];
            l5 = src[5];
            l6 = src[6];
            l7 = src[7];
            // Do The Math

            tempsum = l0.red * k8.red + l0.green * k8.green + l0.blue * k8.blue;
            tempsum += l1.red * k9.red + l1.green * k9.green + l1.blue * k9.blue;
            tempsum += l2.red * k10.red + l2.green * k10.green + l2.blue * k10.blue;
            tempsum += l3.red * k11.red + l3.green * k11.green + l3.blue * k11.blue;
            tempsum += l4.red * k12.red + l4.green * k12.green + l4.blue * k12.blue;
            tempsum += l5.red * k13.red + l5.green * k13.green + l5.blue * k13.blue;
            tempsum += l6.red * k14.red + l6.green * k14.green + l6.blue * k14.blue;
            tempsum += l7.red * k15.red + l7.green * k15.green + l7.blue * k15.blue;

            dst[index] += tempsum;

            // srcmid0 += dim; // 2
            src += dim;
            // Assign L
            l0 = src[0];
            l1 = src[1];
            l2 = src[2];
            l3 = src[3];
            l4 = src[4];
            l5 = src[5];
            l6 = src[6];
            l7 = src[7];
            // Do The Math

            tempsum = l0.red * k16.red + l0.green * k16.green + l0.blue * k16.blue;
            tempsum += l1.red * k17.red + l1.green * k17.green + l1.blue * k17.blue;
            tempsum += l2.red * k18.red + l2.green * k18.green + l2.blue * k18.blue;
            tempsum += l3.red * k19.red + l3.green * k19.green + l3.blue * k19.blue;
            tempsum += l4.red * k20.red + l4.green * k20.green + l4.blue * k20.blue;
            tempsum += l5.red * k21.red + l5.green * k21.green + l5.blue * k21.blue;
            tempsum += l6.red * k22.red + l6.green * k22.green + l6.blue * k22.blue;
            tempsum += l7.red * k23.red + l7.green * k23.green + l7.blue * k23.blue;

            dst[index] += tempsum;

            // srcmid0 += dim; // 3
            src += dim;
            // Assign L
            l0 = src[0];
            l1 = src[1];
            l2 = src[2];
            l3 = src[3];
            l4 = src[4];
            l5 = src[5];
            l6 = src[6];
            l7 = src[7];
            // Do The Math

            tempsum = l0.red * k24.red + l0.green * k24.green + l0.blue * k24.blue;
            tempsum += l1.red * k25.red + l1.green * k25.green + l1.blue * k25.blue;
            tempsum += l2.red * k26.red + l2.green * k26.green + l2.blue * k26.blue;
            tempsum += l3.red * k27.red + l3.green * k27.green + l3.blue * k27.blue;
            tempsum += l4.red * k28.red + l4.green * k28.green + l4.blue * k28.blue;
            tempsum += l5.red * k29.red + l5.green * k29.green + l5.blue * k29.blue;
            tempsum += l6.red * k30.red + l6.green * k30.green + l6.blue * k30.blue;
            tempsum += l7.red * k31.red + l7.green * k31.green + l7.blue * k31.blue;

            dst[index] += tempsum;

            // srcmid0 += dim; // 4
            src += dim;
            // Assign L
            l0 = src[0];
            l1 = src[1];
            l2 = src[2];
            l3 = src[3];
            l4 = src[4];
            l5 = src[5];
            l6 = src[6];
            l7 = src[7];
            // Do The Math

            tempsum = l0.red * k32.red + l0.green * k32.green + l0.blue * k32.blue;
            tempsum += l1.red * k33.red + l1.green * k33.green + l1.blue * k33.blue;
            tempsum += l2.red * k34.red + l2.green * k34.green + l2.blue * k34.blue;
            tempsum += l3.red * k35.red + l3.green * k35.green + l3.blue * k35.blue;
            tempsum += l4.red * k36.red + l4.green * k36.green + l4.blue * k36.blue;
            tempsum += l5.red * k37.red + l5.green * k37.green + l5.blue * k37.blue;
            tempsum += l6.red * k38.red + l6.green * k38.green + l6.blue * k38.blue;
            tempsum += l7.red * k39.red + l7.green * k39.green + l7.blue * k39.blue;

            dst[index] += tempsum;

            // srcmid0 += dim; // 5
            src += dim;
            // Assign L
            l0 = src[0];
            l1 = src[1];
            l2 = src[2];
            l3 = src[3];
            l4 = src[4];
            l5 = src[5];
            l6 = src[6];
            l7 = src[7];
            // Do The Math

            tempsum = l0.red * k40.red + l0.green * k40.green + l0.blue * k40.blue;
            tempsum += l1.red * k41.red + l1.green * k41.green + l1.blue * k41.blue;
            tempsum += l2.red * k42.red + l2.green * k42.green + l2.blue * k42.blue;
            tempsum += l3.red * k43.red + l3.green * k43.green + l3.blue * k43.blue;
            tempsum += l4.red * k44.red + l4.green * k44.green + l4.blue * k44.blue;
            tempsum += l5.red * k45.red + l5.green * k45.green + l5.blue * k45.blue;
            tempsum += l6.red * k46.red + l6.green * k46.green + l6.blue * k46.blue;
            tempsum += l7.red * k47.red + l7.green * k47.green + l7.blue * k47.blue;

            dst[index] += tempsum;

            // srcmid0 += dim; // 6
            src += dim;
            // Assign L
            l0 = src[0];
            l1 = src[1];
            l2 = src[2];
            l3 = src[3];
            l4 = src[4];
            l5 = src[5];
            l6 = src[6];
            l7 = src[7];
            // Do The Math

            tempsum = l0.red * k48.red + l0.green * k48.green + l0.blue * k48.blue;
            tempsum += l1.red * k49.red + l1.green * k49.green + l1.blue * k49.blue;
            tempsum += l2.red * k50.red + l2.green * k50.green + l2.blue * k50.blue;
            tempsum += l3.red * k51.red + l3.green * k51.green + l3.blue * k51.blue;
            tempsum += l4.red * k52.red + l4.green * k52.green + l4.blue * k52.blue;
            tempsum += l5.red * k53.red + l5.green * k53.green + l5.blue * k53.blue;
            tempsum += l6.red * k54.red + l6.green * k54.green + l6.blue * k54.blue;
            tempsum += l7.red * k55.red + l7.green * k55.green + l7.blue * k55.blue;

            dst[index] += tempsum;

            // srcmid0 += dim; // 7
            src += dim;
            // Assign L
            l0 = src[0];
            l1 = src[1];
            l2 = src[2];
            l3 = src[3];
            l4 = src[4];
            l5 = src[5];
            l6 = src[6];
            l7 = src[7];
            // Do The Math

            tempsum = l0.red * k56.red + l0.green * k56.green + l0.blue * k56.blue;
            tempsum += l1.red * k57.red + l1.green * k57.green + l1.blue * k57.blue;
            tempsum += l2.red * k58.red + l2.green * k58.green + l2.blue * k58.blue;
            tempsum += l3.red * k59.red + l3.green * k59.green + l3.blue * k59.blue;
            tempsum += l4.red * k60.red + l4.green * k60.green + l4.blue * k60.blue;
            tempsum += l5.red * k61.red + l5.green * k61.green + l5.blue * k61.blue;
            tempsum += l6.red * k62.red + l6.green * k62.green + l6.blue * k62.blue;
            tempsum += l7.red * k63.red + l7.green * k63.green + l7.blue * k63.blue;

            dst[index] += tempsum;

            src2 += 1;
            // src=src2;
        }
        src3 += dim;
        src2 = src3;
        mid += dim;
    }
}

/*
 * naive_conv - The naive baseline version of convolution
 */
char naive_conv_descr[] = "naive_conv: Naive baseline implementation";
void naive_conv(int dim, pixel *src, pixel *ker, unsigned *dst)
{
    int i, j, k, l;
    for (i = 0; i < dim - 8 + 1; i++)
        for (j = 0; j < dim - 8 + 1; j++)
        {
            dst[RIDX(i, j, dim)] = 0;
            for (k = 0; k < 8; k++)
                for (l = 0; l < 8; l++)
                {
                    dst[RIDX(i, j, dim)] += src[RIDX((i + k), (j + l), dim)].red * ker[RIDX(k, l, 8)].red;
                    dst[RIDX(i, j, dim)] += src[RIDX((i + k), (j + l), dim)].green * ker[RIDX(k, l, 8)].green;
                    dst[RIDX(i, j, dim)] += src[RIDX((i + k), (j + l), dim)].blue * ker[RIDX(k, l, 8)].blue;
                }
        }
}

/*
 * convolution - Your current working version of convolution
 * IMPORTANT: This is the version you will be graded on
 */
char convolution_descr[] = "Convolution: Current working version";
void convolution(int dim, pixel *src, pixel *ker, unsigned *dst)
{

    naive_conv_unroll3(dim, src, ker, dst);
}

/*********************************************************************
 * register_conv_functions - Register all of your different versions
 *     of the convolution functions  with the driver by calling the
 *     add_conv_function() for each test function. When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.
 *********************************************************************/

void register_conv_functions()
{
    add_conv_function(&naive_conv, naive_conv_descr);
    add_conv_function(&convolution, convolution_descr);
    add_conv_function(&naive_conv1, naive_conv1_descr);
    add_conv_function(&naive_conv_unroll, naive_conv_unroll_descr);
    add_conv_function(&naive_conv_unroll2, naive_conv_unroll2_descr);
    add_conv_function(&naive_conv_unroll3, naive_conv_unroll3_descr);
    /* ... Register additional test functions here */
}

/************************
 * AVERAGE POOLING KERNEL
 ************************/

/*********************************************************
 * Your different versions of the average pooling  go here
 *********************************************************/

char try_average_pooling_descr[] = "MY Average Pooling: MY  implementation";
void try_average_pooling(int dim, pixel *src, pixel *dst)
{
    int i, j, k, l;
    int index, mid, sindex;
    pixel tempdst;
    index = 0;
    pixel *src2 = src;
    pixel *src3 = src;
    for (i = 0; i < dim / 2; i++)
    {
        // index = i*(dim/2);
        for (j = 0; j < dim / 2; j++)
        {
            

            mid = index + j;
            dst[mid].red = 0;
            dst[mid].green = 0;
            dst[mid].blue = 0;

            
            sindex = 2*i*dim + 2*j;

            dst[mid].red += src[sindex].red;
            dst[mid].green += src[sindex].green;
            dst[mid].blue += src[sindex].blue;

            dst[mid].red += src[sindex +1].red;
            dst[mid].green += src[sindex +1].green;
            dst[mid].blue += src[sindex +1].blue;

            sindex += dim;

            dst[mid].red += src[sindex].red;
            dst[mid].green += src[sindex].green;
            dst[mid].blue += src[sindex].blue;

            dst[mid].red += src[sindex +1].red;
            dst[mid].green += src[sindex +1].green;
            dst[mid].blue += src[sindex +1].blue;
                
            
            dst[mid].red /= 4;
            dst[mid].green /= 4;
            dst[mid].blue /= 4;

            //dst[mid] = tempdst;
        }
        index += dim / 2;
    }
}
//RIDX(i * 2 + k, j * 2 + l, dim) = 2 i dim + 2j + k dim + l

char try_average_pooling2_descr[] = "MY Average Pooling2: MY  implementation";
void try_average_pooling2(int dim, pixel *src, pixel *dst)
{
    int i, j, k, l;
    int index, mid, sindex;
    pixel tempdst,first,second,third,fourth;
    index = 0;
    pixel *src2 = src;
    pixel *src3 = src;
    int dimo2,dimm2;
    dimo2 = dim /2;
    dimm2 = 2*dim;
    for (i = 0; i < dimo2; i++)
    {
        for (j = 0; j < dimo2; j++)
        {
            

            mid = index + j;
            dst[mid].red = 0;
            dst[mid].green = 0;
            dst[mid].blue = 0;

            src = src2;
            first = src[0];
            second = src[1];
            third = src[dim];
            fourth = src[dim+1];

            //sindex = 2*i*dim + 2*j;

            dst[mid].red += first.red;
            dst[mid].green += first.green;
            dst[mid].blue += first.blue;

            dst[mid].red += second.red;
            dst[mid].green += second.green;
            dst[mid].blue += second.blue;

            //sindex += dim;
            //src += dim;

            dst[mid].red += third.red;
            dst[mid].green += third.green;
            dst[mid].blue += third.blue;

            dst[mid].red += fourth.red;
            dst[mid].green += fourth.green;
            dst[mid].blue += fourth.blue;
                
            
            dst[mid].red /= 4;
            dst[mid].green /= 4;
            dst[mid].blue /= 4;

            //dst[mid] = tempdst;
            src2+=2;
        }
        src3 += dimm2;
        src2 = src3;

        index += dimo2;
    }
}
//RIDX(i * 2 + k, j * 2 + l, dim) = 2 i dim + 2j + k dim + l



/*
 * naive_average_pooling - The naive baseline version of average pooling
 */
char naive_average_pooling_descr[] = "Naive Average Pooling: Naive baseline implementation";
void naive_average_pooling(int dim, pixel *src, pixel *dst)
{
    int i, j, k, l;

    for (i = 0; i < dim / 2; i++)
        for (j = 0; j < dim / 2; j++)
        {
            dst[RIDX(i, j, dim / 2)].red = 0;
            dst[RIDX(i, j, dim / 2)].green = 0;
            dst[RIDX(i, j, dim / 2)].blue = 0;
            for (k = 0; k < 2; k++)
            {
                for (l = 0; l < 2; l++)
                {
                    dst[RIDX(i, j, dim / 2)].red += src[RIDX(i * 2 + k, j * 2 + l, dim)].red;
                    dst[RIDX(i, j, dim / 2)].green += src[RIDX(i * 2 + k, j * 2 + l, dim)].green;
                    dst[RIDX(i, j, dim / 2)].blue += src[RIDX(i * 2 + k, j * 2 + l, dim)].blue;
                }
            }
            dst[RIDX(i, j, dim / 2)].red /= 4;
            dst[RIDX(i, j, dim / 2)].green /= 4;
            dst[RIDX(i, j, dim / 2)].blue /= 4;
        }
}

/*
 * average_pooling - Your current working version of average_pooling
 * IMPORTANT: This is the version you will be graded on
 */
char average_pooling_descr[] = "Average Pooling: Current working version";
void average_pooling(int dim, pixel *src, pixel *dst)
{

    try_average_pooling2(dim, src, dst);
}

/******************************************************************************
 * register_average_pooling_functions - Register all of your different versions
 *     of the average pooling  with the driver by calling the
 *     add_average_pooling_function() for each test function. When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.
 ******************************************************************************/

void register_average_pooling_functions()
{
    add_average_pooling_function(&naive_average_pooling, naive_average_pooling_descr);
    add_average_pooling_function(&average_pooling, average_pooling_descr);
    add_average_pooling_function(&try_average_pooling, try_average_pooling_descr);
    add_average_pooling_function(&try_average_pooling2, try_average_pooling2_descr);
    /* ... Register additional test functions here */
}
