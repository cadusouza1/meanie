#pragma once

#define MEANS_SIZE 7

typedef double (*MeanFunc)(double nums[], int len);

double arithmetic_mean(double nums[], int len);
double geometric_mean(double nums[], int len);
double harmonic_mean(double nums[], int len);
double weighted_arithmetic_mean(double nums_weight_pairs[], int len);
double median(double nums[], int len);
double variance(double nums[], int len);
double standard_deviation(double nums[], int len);
