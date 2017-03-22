//
//
//  Colloidal Dynamics Monte Carlo Stepper
//
//  Andrew J. Pounds, Ph.D.
//  Department of Chemistry 
//  Mercer University
//  Spring 2013
//
//  Based on Meyer, et. al.  J. Phys. Chem B 110 (2006) 6040.
//

#include "sysincludes.h" 
#include "namespaces.h"
#include "constants.h"

#include "structs.h"
#include "prototypes.h" 

// Be sure to invlude these item from globals.h in a global scope so they
// can then be initialized.
//
int nParticles;
int lattice_min;
int lattice_max;
string fileheader, filename, command, prefix;

int start_time, elapsed_time;

vector<Particle> colloids;
Particle colloid;

BoostRandomContext boostRandom;

long iter, step;
bool firstStep;
int windowsize;

int main(int argc, char** argv) {

    double referenceEnergy;
    double testEnergy;

    
    nParticles = MAX_PARTICLES;
    lattice_min = LATTICE_MIN;
    lattice_max = LATTICE_MAX;


    fstream myfile;
    fileheader = "data-";

#ifdef GENERATE_RANDOM_SEED
    boostRandom.setSeed(std::time(0));
#endif

    // Fill vector array //
    
    for (int i=0;i<nParticles;i++) 
       colloids.push_back(colloid);

    // Now place particles at random positions in lattice //
    
//    setInitialPositions( colloids, boostRandom, lattice_min, lattice_max );
    setInitialPositions( colloids, lattice_min, lattice_max );
 

    // Calculate reference potentials for everyone

    calculateAllReferencePotentials( colloids ); 
    
#ifdef DEBUG
    // print out prior to starting monte carlo run //
    //
    for (int i=0; i<colloids.size(); i++){
        cout << colloids.at(i).get_x() << " " <<
                colloids.at(i).get_y() << " " <<
                colloids.at(i).get_ref_potential() << endl;
        } 
#endif

     // Now start Monte-Carlo Simulation
     //

    // Set initial value of loop counters here; they will be updated in idleFunction

    step = 0; // Outer loop counter
    iter = 0; // Inner loop counter
    firstStep = true;

    // Now that all of the global variables have been initialized, we can initialize
    // the graphics.

    windowsize=800;    
    glutInit(&argc, argv);
    start_time = glutGet(GLUT_ELAPSED_TIME);    
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB  );
    glutInitWindowSize (windowsize, windowsize); 
    glutCreateWindow("Colloidal Dyamics");
    init();
/*
    glClearColor(0.0,0.0,0.0,0.0);
    glLoadIdentity();
    glClear (GL_COLOR_BUFFER_BIT);
*/
    glutDisplayFunc(countClusters);
    glutReshapeFunc(reshape);
    glutIdleFunc(propagate);
    glutMainLoop();
    
} 
