/***********************************************************************
Homework 10 Report

Marina Dunn
PHYS 305, Fall 2016
Created: 27 October 2016
Last Modified: 14 December 2016

Purpose: to understand the logistic map, which estimates the population growth model based on parameters X_n (where 0<= X_n <=1), the nth population, based on r, the growth parameter (where 0<= r >=1).

The logistic map is a useful way to predict the population for future n generations based on the parameter r, although it can be applied to other growth concepts as well. It is understanable why the value of X_n has been scaled to the range 0 to 1, where at 1, the population will have reached its limit, but the parametr r is somewhat harder to interpret, as shown by problem 1.

For any value of r greater than 0.75, the system begins oscillating with a period of 2, and as it continues to increase, the period increases by a factor of 2 and becomes more and more chaotic. The equilibrium of the system has become more unstable. When testing the code, the value of r=0.74 was the only time the parameter was in between 0.5 and 0.75, so the system neared equilibrium. At r=0.88 for example, the period was approximately 8, and by the time r=0.910, the system had reached total chaos. The values of r we were asked to test evidently were the parameters at which bifurcation, or the splitting into 2 branches on the graph, occurred.

For Problem 3, the Lorentzian "Butterfly Effect" refers to the idea of deterministic chaos/sensitive dependence on initial condition, where a slight change in two similar systems will cause them to become drastically different very quickly, similar to the effect of unintentionally stepping on a butterfly and changing a series of outcomes, causing a natural disaster somewhere else. This is evidenced by starting with a value of r=0.91, and two very close initial populations, 0.500000 and 0.500001, but the sequences quickly diverge.
