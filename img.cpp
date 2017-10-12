#include <iostream>
#include "Image.h"

using namespace std;

int main( void ){
  Image test(20,20);

  for (int i = 0; i < 20; i++)
    for (int j = 0; j < 20; j++)
      test(i,j) = Pixel(200,100,100);

  test.write("test.ppm");
  return(0);
}
