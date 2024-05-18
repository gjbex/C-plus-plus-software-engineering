#include <iostream>
#include <blaze/Math.h>

using namespace blaze;

int main()
{
   // Instantiating a dynamic 3D column vector
   DynamicVector<int> x{ 4, -1, 3 };
   x[0] =  4;
   x[1] = -1;
   x[2] =  3;

   // Instantiating a dynamic 2x3 row-major matrix, preinitialized with 0. Via the function
   // call operator three values of the matrix are explicitly set to get the matrix
   //   ( 1  0  4 )
   //   ( 0 -2  0 )
   DynamicMatrix<int> A( 2UL, 3UL, 0 );
   A(0,0) =  1;
   A(0,2) =  4;
   A(1,1) = -2;

   // Performing a dense matrix/dense vector multiplication
   DynamicVector<int> y = A * x;

   // Printing the resulting vector
   std::cout << "y =\n" << y << "\n";

   // Instantiating a static column-major matrix. The matrix is directly initialized as
   //   (  3 -1 )
   //   (  0  2 )
   //   ( -1  0 )
   StaticMatrix<int,3UL,2UL,columnMajor> B{ { 3, -1 }, { 0, 2 }, { -1, 0 } };

   // Performing a dense matrix/dense matrix multiplication
   DynamicMatrix<int> C = A * B;

   // Printing the resulting matrix
   std::cout << "C =\n" << C << "\n";
}
