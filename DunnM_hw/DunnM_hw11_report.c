/**************************************************************************
Homework 11

Marina Dunn
PHYS 305, Fall 2016
Created: 8 November 2016
Last Modified: 14 December 2016

Laplace's equation is a partial differential equation whose solution can be found by using the relaxation method, a numerical approximation in 2 dimensions. In this situation, we are dealing with heat conduction in solids. Laplace's equation says that the gradient of the temperature squared is equal to 0.

Here, we want to find the temperature distribution inside an insulated rectangular region with a circular cavity in the center. The temperature of the rectangular region obeys Laplace's equation.We use a fixed grid size of 20 x 20. For all points interior to the rectangular region, we assume the intial temperature to be 0 when starting each iteration, unless they are inside the circular region, in which case, the initial T is 80 degrees. In this case, we start at a particular point: r=(1.0,1.0). We are able to find the temperature at the point by distinguishing the temperatures at the surrounding points, spaced a distance 'a' away, and averaging them.

Problem 2 is essentially the same idea as problem 1 except I modified the size of the grid being used, and was able to see for a grid GxG, the solution converges as G^2, so as the grid size increased, the faster it converged to a solution. In addition to the relaxation method, the successice over-relaxation method gives the solution to the function at the n+1th iteration, which can be found by using the original function at the nth iteration with an added correction term that includes w, the over-relaxation parameter. This value falls between 1 and 2, and optimizes convergence. A value of one gives a normal Gauss-Seidel curve, but for this case, we get a value of w=1.939 at this particular point.

This numerical method of finding a solution to a partial defferential equation can also be used for the last problem, which deals with electrostatics. Here, Laplace's equation shows that in an electric field, when there is no charge present, the gradient of the electric potential squared is 0. Essentially, the only thing that is different is that we are using alternate units (volts) since we're solving for electric potential. The dimensions are the same otherwise.
