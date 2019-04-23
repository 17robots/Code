#include "DisjSets.h"


/**
 * Construct the disjoint sets object.
 * numElements is the initial number of disjoint sets.
 */
DisjSets::DisjSets( int numElements ) : s( numElements, -1 )
{
}

/**
 * Union two disjoint sets.
 * For simplicity, we assume root1 and root2 are distinct
 * and represent set names.
 * root1 is the root of set 1.
 * root2 is the root of set 2.
 * Be careful, this could cause a problem.
 */
void DisjSets::unionSets( int root1, int root2 )
{
    if( s[ root2 ] < s[ root1 ] )  // root2 is deeper
        s[ root1 ] = root2;        // Make root2 new root
    else
    {
        if( s[ root1 ] == s[ root2 ] )
            --s[ root1 ];          // Update height if same
        s[ root2 ] = root1;        // Make root1 new root
    }
}



/**
 * TO DO: YOU will write code for this function.
 * You need to perform a find with path compression
 * per exercise 8.16 in the book.  This will be a 
 * recursive function.
 * 
 * Return the set containing x.  
 * That is, you will need to return the root;
 * be careful!
 */
int DisjSets::find( int x )
{
   
}

/* TO DO: Write this code.  
 * Return true if the two neighbors are in the same set.
*/
bool DisjSets::isConnected(int n1, int n2)
{
 
}
