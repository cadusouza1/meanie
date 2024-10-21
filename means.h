#pragma once

#define MEANS_SIZE 5

typedef float (*MeanFunc)(float nums[], int len);

float arithmetic_mean(float nums[], int len);
float geometric_mean(float nums[], int len);
float harmonic_mean(float nums[], int len);
float weighted_arithmetic_mean(float nums_weight_pairs[], int len);
float median(float nums[], int len);
