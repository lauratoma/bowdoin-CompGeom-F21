/* 
   Some simple examples of arrays and 2d arrays of vectors.  
   Laura Toma, February 2018

 */ 

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


#include <vector>
using namespace std; 


//a structure for a point in 2D
typedef struct _point2d {
  double x, y; 
} point2d; 



int main(int argc, char** argv) {

 
  //get the arguments right
  if (argc !=2 ) {
    printf("Usage: %s n\n", argv[0]);
    exit(1);
  }
  int n = atoi(argv[1]); 
  printf("you entered n=%d\n", n);


  int i, j; 
  double sum; 



  /***************test1 *********************/
  //an array of n ints, C style 
  int *a; 

 /*  DON'T DO THIS: 

     int a[n]; 

     It's wrong and you're sure to get segfaults for larger values of
     n. YOU NEED TO ALLOCATE  dynamically using malloc() because you
     don't know n at compile time.
  */ 

  //allocate the space  dynamically
  a =(int*)malloc(n * sizeof(int)); 

  //put some data in it 
  for (i=0; i<n; i++) 
    a[i] = 1; 

  //compute something 
  sum=0; 
  for (i=0;i<n;i++)
    sum += a[i]; 

  //free the space 
  free(a); 

  printf("test1: sum=%f\n", sum); 



  /***********************test2 ****************/
  //an array of n ints, C++ style 
  int *b; 
  
  /*  DON'T DO THIS: 
      
      int b[n]; 
      
      It's wrong and you're sure to get segfaults for larger values of
      n. YOU NEED TO ALLOCATE  dynamically using new because you
      don't know n at compile time.
  */ 
    

  //allocate the space  dynamically
  b = new int[n]; 

  //put some data in it 
  for (i=0; i<n; i++) 
    b[i] = 1; 

  //compute something 
  sum=0; 
  for (i=0;i<n;i++)
    sum += b[i]; 

  //free the space 
  delete [] b; 

  printf("test2: sum=%f\n", sum); 
  


  /***********************test3 ****************/
  //a vector
  vector<int> c; 

  //put some data in it 
  for (i=0; i<n; i++) 
    c.push_back(1); 

  //compute something 
  sum=0; 
  for (i=0;i<n;i++)
    sum += c[i]; 

  printf("test3: sum=%f\n", sum); 



  /***********************test4 ****************/
  //an array of Vectors, C++ style 
  vector<int> *d; 

 /*  DON'T DO THIS: 
      
      vector<int> d[n]; 
      
      It's wrong and you're sure to get segfaults for larger values of
      n. YOU NEED TO ALLOCATE  dynamically using new because you
      don't know n at compile time.
  */ 

  //allocate the space  dynamically
  d = new vector<int> [n]; 
  //NOTE: we assume that c++ calls the constructor to create a new Vector at each d[i]
  
  //put some data in it 
  for (i=0; i<n; i++) 
    //d[i] is a Vector, so we push 1 into it 
    d[i].push_back(1); 

  //compute something 
  sum=0; 
  for (i=0;i<n;i++)
    sum += d[i][0]; 

  //free the space 
  delete [] d; 

  printf("test4: sum=%f\n", sum); 
    
  


  /***********************test5 ****************/
  //an array of Vectors of points 
  vector<point2d> *e; 

  /*  DON'T DO THIS: 
      
      vector<point2d> e[n]; 
      
      It's wrong and you're sure to get segfaults for larger values of
      n. YOU NEED TO ALLOCATE  dynamically using new because you
      don't know n at compile time.
  */ 

  //allocate the space  dynamically
  e = new vector<point2d> [n]; 
  //NOTE: we assume that c++ calls the constructor to create a new Vector at each e[i]

  //put some data in it 
  for (i=0; i<n; i++) {
    //e[i] is a Vector, so we push i into it 
    point2d p = {1,1};
    e[i].push_back(p); 
  }

  //compute something 
  sum=0; 
  for (i=0;i<n;i++) {
    // e[i] is a vector; e[i][0] is the first point in that vector
    sum += e[i][0].x;
  } 

  //free the space 
  delete [] e; 

  printf("test5: sum=%f\n", sum); 
 



  /***********************test6 ****************/
  //a 2D array of Vectors of points 
  vector<point2d> **grid; 
  
  /*  DON'T DO THIS: 

     vector<point2d> grid [n][n] 

     It's wrong and you're sure to get segfaults for larger values of
     n. YOU NEED TO ALLOCATE  dynamically using new because you
     don't know n at compile time.
  */ 

  //allocate first an array of vector*
  grid = new vector<point2d>* [n]; 
  for (i=0; i<n;i++) {
    //grid[i] is a vector*, that is, an array (of vectors); we allocate it 
    grid[i] = new vector<point2d> [n]; 
  }

  //put some data in it 
  for (i=0; i<n; i++) {
    for (j=0; j<n; j++) {
      //grid[i][j] is a Vector, so we push 1 into it 
      assert(grid[i][j].size()==0); 
      point2d p = {1.0, 1.0};
      grid[i][j].push_back(p); 
      assert(grid[i][j].size()==1); 
    }
  }
 
  //compute something 
  sum=0; 
  for (i=0; i<n; i++) {
    for (j=0; j<n; j++) {
      // grid[i] is a vector;grid[i][j][0] is the first point in that vector
      sum += grid[i][j][0].x;
    } 
  }
  //free the space 
  delete [] e;  

  printf("test6: sum=%f\n", sum); 

  printf("This is all working, check out the code!\n"); 
}
