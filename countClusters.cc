
#include "sysincludes.h"
#include "namespaces.h"
#include "structs.h"
#include "constants.h"
#include "globals.h"
#include "prototypes.h"

#ifndef COUNT_CLUSTERS
#define COUNT_CLUSTERS

void countClusters ( ){

    vector<Cluster> clusters;
    Cluster cluster; 
    Cluster singles;    // Added to ease visualization
    vector<int> histogram;

    bool ADDED_CLUSTER;
    bool ADDED_LEAF;

/* A cluster is any group whose members are connected by a distance less than
 * POTENTIAL_BARRIER_BEGIN
 */


    int i = 0;
    do {

       ADDED_CLUSTER = false;
       ADDED_LEAF = false;

       if ( notAssociated(clusters, i) ) {
          if ( canMakeAssociation(colloids, clusters, i) ) {
              assignAssociation(colloids, clusters, i);
              ADDED_LEAF = true;
              i = -1;
              }
              
          else {
             for (int j=0; j<colloids.size(); j++) {
               if (!ADDED_CLUSTER && (i != j) && (( notAssociated(clusters, j) &&
                  (distance(colloids.at(i).get_x(), colloids.at(i).get_y(),
                            colloids.at(j).get_x(), colloids.at(j).get_y())  
                            < NEIGHBOR_DISTANCE )) )) {
             
                     cluster.particles.push_back(i);
                     cluster.particles.push_back(j);
                     clusters.push_back(cluster);
                     cluster.particles.clear();
                     ADDED_CLUSTER = true;
                     i = -1;
                }
             }
          }
       }
       i++;
    } while ( i < colloids.size() );

#ifdef DEBUG
    int particlesInClusters =0;
    for (int i=0; i<clusters.size(); i++ ) particlesInClusters += clusters.at(i).particles.size();
    cout << "=====    There are now " << clusters.size() << " holding " << particlesInClusters << " particles." << endl;
#endif
    

#ifdef REPROCESS_CLUSTERS
/* Now that the clusters have all been formed, we need to run back through them and make sure that if any 
 * particles in two separate clusters are close enough that the clusters can become one large cluster.
 *
 * Should first form a list of the clusters -- because we can easily resize the delete nodes in
 * a list.
 */

    list<Cluster> tempList;
    Cluster tempCluster;

      
    // Now test to see if stuff is in the list
    list<Cluster>::iterator iter;
    list<Cluster>::iterator check;
    bool foundMatch;

     
//    for ( iter=tempList.begin(); iter != tempList.end(); iter++ ){
//       cout << (*iter).get_number_of_particles() << "  from list " << endl;
//    } 

    // So try the following...  

    foundMatch = true;
    while (foundMatch) {
        int node1 = 0;
        for ( int i=0; i<clusters.size(); i++ ) {
            tempCluster = clusters.at(i);
            tempList.push_back(tempCluster);
        }
        foundMatch = false;
        for ( iter=tempList.begin(); iter != tempList.end(); iter++ ){
            node1++;
            int node2 = 0;
            for ( check=tempList.begin(); check != tempList.end(); check++ ){
                node2++;
                if ( check != iter ) {
                    for (int j=0; j<(*iter).get_number_of_particles(); j++ ) {
                        for (int k=0; k<(*check).get_number_of_particles(); k++ ) {
                            // cout <<
                            // (*iter).particles.at(j) << " " << (*check).particles.at(k) << endl;
                            if ( distance(colloids.at((*iter).particles.at(j)).get_x(), 
                                        colloids.at((*iter).particles.at(j)).get_y(),
                                        colloids.at((*check).particles.at(k)).get_x(),
                                        colloids.at((*check).particles.at(k)).get_y()) < NEIGHBOR_DISTANCE ) {
#ifdef DEBUG
                                cout << " F O U N D    A   M A T C H   B E T W E E N   C L U S T E R S " << endl;
                                cout << "    tempList has " << tempList.size() << " clusters" << endl;
#endif
                                // Set the boolean to true so we will not exit the while loop
                                foundMatch = true;
                                // Now need to copy the particles from the cluster with the higher
                                // index to the cluster with the lower index.
#ifdef DEBUG
                                cout << "      copying " << (*check).get_number_of_particles();
                                cout << " particles from cluster " << node2 << " to " << node1 << endl;
#endif
                                for (int l=0; l<(*check).get_number_of_particles(); l++){
                                    (*iter).particles.push_back((*check).particles.at(l));
                                }
                                // Now delete that node from the list
#ifdef DEBUG
                                cout << "      deleting node for cluster " << node2 << endl;
#endif
                                tempList.erase(check);
#ifdef DEBUG
                                cout << "    tempList now has " << tempList.size() << " clusters" << endl;
                                cout << "    cluster " << node1 << " now has " <<  (*iter).particles.size()
                                     << " particles" << endl;
#endif
                                break;
                            }
                            if ( foundMatch) break;
                        }
                        if (foundMatch) break;
                    }
                    if (foundMatch) break;
                }
                if (foundMatch) break;
            }
            if (foundMatch) break;
        }
        if (foundMatch) {
            // Need to clear the vector
            clusters.clear();
            // And copy elements from list back into vector
            for ( iter=tempList.begin(); iter != tempList.end(); iter++ ){ 
                clusters.push_back(*iter);
            }
        }
        // Now clear the list
        tempList.clear();       
    }
              

#endif /* REPROCESS_CLUSTERS */


/* Put the singles not associated with a cluster in their own vector. */ 

   for ( i=0; i<colloids.size(); i++ ) {
            if (notAssociated(clusters, i ) ) { 
                singles.particles.push_back(i);
            }
       }


  
 
#ifdef DEBUG
    cout << "Found " << clusters.size() << " clusters." << endl; 

    for (int j=0; j<clusters.size(); j++ ) {
        cout << "Cluster " << j << ":";
        double avgX =0.0;
        double avgY =0.0;
        for (int k=0; k<clusters.at(j).particles.size(); k++) {
            cout << clusters.at(j).particles.at(k) << " ";
            avgX = avgX + colloids.at(clusters.at(j).particles.at(k)).get_x();
            avgY = avgY + colloids.at(clusters.at(j).particles.at(k)).get_y();
            }
        avgX = avgX / clusters.at(j).particles.size();
        avgY = avgY / clusters.at(j).particles.size();

        cout << avgX << " " << avgY << endl;
    }
    cout << "There are " << singles.particles.size() << " unassociated particles." << endl; 

/*    for (int j=0; j<singles.particles.size(); j++ ) {
            cout << singles.particles.at(j) << " ";
            }
        cout << endl;
*/
#endif


#ifdef HISTOGRAM 
    /* Determine maximum cluster size and the number of particles associated with all clusters. */

    int total_in_clusters = 0;
    int maxSize = 0;
    for (int i=0; i<clusters.size(); i++) {
       maxSize = max(maxSize, clusters.at(i).get_number_of_particles()); 
       total_in_clusters += clusters.at(i).get_number_of_particles();
       }

    /* Add the number of single colloids to first element of histogram */
    histogram.push_back(colloids.size()-total_in_clusters);
        
    
    // Now build a vector that is the histogram of cluster sizes. //
    for (int i=0; i<maxSize-1; i++) {
      int temp = 0;
      for (int j=0; j<clusters.size(); j++) {
        if ( (i+2) == clusters.at(j).get_number_of_particles() ) {
           temp++;
        }
      }
      histogram.push_back(temp);
    }

   
    // The following loop counts the actual number of particles by adding up the sum
    // of the clusters multiplied by the number of particles in each cluster.
    int sum = 0; 
    for (int i=0; i<histogram.size(); i++) {
       sum += (i+1)*histogram.at(i); 
       cout  << " " << histogram.at(i)*(i+1); // added the *(i+1) to print out the actual particles and not the number of clusters
       }

#ifdef DEBUG
    cout << "  Total number of particles is " << sum;
#endif
    cout << endl;  
#endif


// Now that everything is counted, lets put them on the display

   int px, py;
   double center;

   glClearColor(0.0,0.0,0.0,0.0);
   glLoadIdentity();
   glClear (GL_COLOR_BUFFER_BIT);

   glColor3f(1.0, 1.0, 1.0);
   glEnable(GL_TEXTURE_2D);
   glBindTexture(GL_TEXTURE_2D,metalTexture);
   
   // Do individual particles first

   glPolygonMode(GL_FRONT, GL_FILL);
   int numberOfSingleParticles = singles.get_number_of_particles();
   for (int i=0; i<numberOfSingleParticles; i++ ){
      double centerx = colloids.at(singles.particles.at(i)).get_x()/LATTICE_MAX * 800.0; 
      double centery = colloids.at(singles.particles.at(i)).get_y()/LATTICE_MAX * 800.0; 
      //printf("Should be drawing now\n");
      double r = sqrt(1.0 / M_PI );
      
      glBegin(GL_POLYGON);
        for (int j=0; j<36; j++){
          double angle = 2.0 * M_PI * j / 36.0;
          //printf("  x = %8.4f ", centerx+cos(angle)*3.0);
          //printf("  y = %8.4f\n ", centery+sin(angle)*3.0);
          // Do texture coordinate first
          glTexCoord2d(cos(angle)*0.5+0.5,sin(angle)*0.5+0.5);
          glVertex2d(centerx+cos(angle)*10*r, centery+sin(angle)*10*r);
        }
      glEnd();
   }

   // Now do the clusters
   
   glColor3f(1.0, 1.0, 1.0);
    for (int i=0; i<clusters.size(); i++ ) {
        double avgX =0.0;
        double avgY =0.0;
        for (int k=0; k<clusters.at(i).particles.size(); k++) {
            avgX = avgX + colloids.at(clusters.at(i).particles.at(k)).get_x();
            avgY = avgY + colloids.at(clusters.at(i).particles.at(k)).get_y();
            }
        double centerx = (avgX / clusters.at(i).particles.size())/LATTICE_MAX * 800.0;
        double centery = (avgY / clusters.at(i).particles.size())/LATTICE_MAX * 800.0;

      double r = sqrt(clusters.at(i).particles.size() / M_PI );
      glBegin(GL_POLYGON);
        for (int j=0; j<36; j++){
          double angle = 2.0 * M_PI * j / 36.0;
          glTexCoord2d(cos(angle)*0.5+0.5,sin(angle)*0.5+0.5);
          glVertex2d(centerx+cos(angle)*10*r, centery+sin(angle)*10*r);
        }
      glEnd();
    }

    glDisable(GL_TEXTURE_2D);
   // And now compute the elapsed time and put it on the screen
   elapsed_time = glutGet(GLUT_ELAPSED_TIME) - start_time;
   int hours = elapsed_time / 3600000;
   int remainder = elapsed_time % 3600000;
   int min = remainder / 60000;
   remainder = remainder % 60000;
   int sec = remainder / 1000;
   int msec = remainder % 1000;

   void *font = GLUT_BITMAP_HELVETICA_18;
   char cbuf[9];
   if ((min < 10 ) && (sec < 10)) {
     sprintf(cbuf, "%3d:0%1d:0%1d", hours, min, sec);
   }
   else if (min < 10 )  {
     sprintf(cbuf, "%3d:0%1d:%2d", hours, min, sec);
   }
   else if (sec < 10) {
     sprintf(cbuf, "%3d:%2d:0%1d", hours, min, sec);
   }
   else  {
     sprintf(cbuf, "%3d:%2d:%2d", hours, min, sec);
   }
//   printf("In countClusters %s\n", cbuf);
   glColor3f(1.0,1.0,1.0);
   renderBitmapString(20,650,font,cbuf);
   

   glutSwapBuffers();

#ifdef SAVE_SCREENSHOTS
   screenShot(step);   
#endif 

}


      


#endif
