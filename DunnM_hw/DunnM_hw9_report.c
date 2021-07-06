/*************************************************************************
Homework 9

Marina Dunn
PHYS 305, Fall 2016
Created: 18 October 2016
Last Modified: 14 December 2016

Using the fundamental concepts of last week, that for an elliptical orbit, in order to obey Kepler's 2nd Law, conservation of angular momentum must apply, we can now expand that to show that bound orbits have a 1/r potential in order to also be closed. This is because the ratio of the object sweeping out an orbit segment at a distance r1 in time t1 at an angle has a relationship to when it sweeps out another segment at a different r2 and t2, but at the same angle. This is because the impulses, or change in momentum, for each segment, must be equal but opposite.

Therefore, once the object returns to its starting position, it must have the same initial velocity, a unique characteristic of 1/r-potential orbits. There are 3 time intervals to consider: t>t_kick, t=t_kick, t<t_kick, each with energy and momentum conditions.

For the tangential kick, I modified v[0] to be 0, and v[1] to be 1.1*v_init*2*PI since it receives an impuls v_mag = (0, 1.1*v_init), and for the radial kick, I modified v[0] to be 0.1*v*2*PI, and v[1] to be v_init, both receiveing 10% impulses. An object traveling in a regular orbit is essentially traveling with a velocity that is a vector addition of its radial and tangential velocity components. For a singular outward radial impulse, the orbit is shifted slightly to one direction. If it had constant outward, it would continue to be shifted every time yet maintain a circular shape. A singular tangential impulse causes the orbit to widen, but continue to stay circular afterwards. However, if there was constant tangential thrust, the object would spiral outwards away from it's original orbit.
