#ifndef RISK_H
#define RISK_H

/*
==========================================================
                RISK MODULE
==========================================================

This module defines how "safety" is calculated.

Formula:
    Cost = Distance + (Danger × Weight)

==========================================================
*/

int calculateRiskCost(int distance, int danger, int weight);

#endif