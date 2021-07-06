/*************************** animation.h *********************************/
/* Doug Toussaint  6/2/92 */

void set_clock_tick( float tick );
    /* sets frequency of updating.  If set to 0.0, updates as fast
	as it can. */

void wait_clock_tick();
    /* waits until next clock tick */

int animation_start( float xlow, float xhigh, float ylow, float yhigh );
    /* creates a blank window with the specified coordinate ranges */

int add_particle(float x, float y);
    /* adds a particle at the specified coordinates */
    /* return value is identifier for particle */

int delete_particle(int i);
    /* removes a particle.  "i" is the number returned by add_particle(). */

int move_particle(int i, float x , float y);
    /* moves a particle to (x,y). "i" is returned by add_particle(). */

int move_particle_leave_track(int i, float x , float y);
    /* moves a particle to (x,y). "i" is returned by add_particle(). */
    /* This one leaves a small dot to mark the track */
    /* WARNING:  subsequent nearby passages of the particle will
	obliterate track, and it isn't really working right yet */

void animate_end();
    /* kills the animation */

int add_many_particles(int n, float *x, float *y);
    /* adds n particles at the specified coordinates */
    /* return value is identifier for first particle, they are
	numbered in succession */

int move_many_particles(int number, int first, float *x , float *y);
    /* moves "number" particles to (x[i],y[i]).
	"first" is number of first particle to move,
	returned by add_particle(). */

int add_trace(int n, float *x, float *y);
    /* adds a trace connecting the given n points */
    /* return value is identifier for first point, they are
	numbered in succession */

int move_trace(int number, int first, float *x , float *y);
    /* moves trace connecting specified points
	"first" is number of first point to move,
	returned by add_trace(). */
    /* Or you can get fancy and only move a subset of a trace! */

void handle_left_button();
void handle_middle_button();
void handle_right_button();
   /* if you provide such a routine, it will be called when the
	button is pressed in the animation window.  Otherwise you
	will just get the one in the library, which does nothing
	useful. */

void add_text( float x, float y, char *text );
   /* add text at the specified coordinates.  NOT YET WORKING 1/20/95 */
