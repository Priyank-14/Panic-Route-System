#include "risk.h"

/*
    Function: calculateRiskCost

    Purpose:
    --------
    Combines distance and danger into one value

    Why?
    ----
    Helps prioritize safer routes over shorter ones
*/
int calculateRiskCost(int distance, int danger, int weight) {

    return distance + (danger * weight);
}