#ifndef CONSTANTS
#define CONSTANTS 

#define BIGSTEPS    /* Used to determine which version of the program is compiled. */
#define HISTOGRAM    /* Used to determine which version of the program is compiled. */
#define ASYMMETRIC  /* Used to determine which version of the program is compiled. */
#define GENERATE_RANDOM_SEED /* Used to determine which version of the program is compiled. */
#define REPROCESS_CLUSTERS /* Used to determine which vesion of the program to compile. */

#define SAVE_SCREENSHOTS /* Used to determine which version of the program to compile. */

#define USE_BOOST_RANDOM   /* Define if you want to use the Boost Random Number Generators */


int const MAX_PARTICLES = 500;
int const LATTICE_MIN = 0;
int const LATTICE_MAX = 200;
//int const STEPS = 100;
//long const ITERATIONS_PER_STEP = 10000000;
int const STEPS = 10000;
long const ITERATIONS_PER_STEP = 100000;
double const POTENTIAL_BARRIER_BEGIN = 1.5; 
double const POTENTIAL_BARRIER_END = 3.5; 
double const POTENTIAL_BARRIER_LOW = -40.0;
double const POTENTIAL_BARRIER_HIGH = 1.0;

int const MODVAL = 10000; /* Used in propagate to determine probality of making disallowed move */
int const FRAC   = 9900;  /* Fraction uses with MODVAL in propagate */


#ifdef BIGSTEPS
double const DELTA = 1.0;
#else
double const DELTA = 0.1;
#endif

double const NEIGHBOR_DISTANCE = 1.4142;
#endif
