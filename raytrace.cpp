/* Your Name Here
 * somebody at something dot TLD
 * CS 484
 * September 2008
 *
 * $Id: raytrace.cpp 1961 2010-02-24 08:46:53Z mshafae $
 *
 */

/*
#include <iostream>
#include <string>
#include "getopt.h"
#include "Scene.h"
#include <vector>
 int count = 0;//global counter

using namespace std;

Scene *gTheScene;
string gProgramName;

void usage( string message = "" ){
	cerr << message << endl;
	cerr << gProgramName << " -i <inputfile> -o <outputfile> -d <depthfile>" << endl;
	cerr << "          -or-" << endl;
	cerr << gProgramName << " --input <inputfile> --output <outputfile> --depth <depthfile>" << endl;
	
}

std::ostream& operator <<( std::ostream &out, const Pixel &p ){
  p.write( out );
  return( out );
}

void parseCommandLine( int argc, char **argv ){
	int ch;
	string inputFile( "" ), outputFile( "" ), depthFile( "" );
  int resolution;
	static struct option longopts[] = {
    { "input", required_argument, NULL, 'i' },
    { "output", required_argument, NULL, 'o' },
    { "depth", required_argument, NULL, 'd' },
    { "resolution", required_argument, NULL, 'r' },
    { "verbose", required_argument, NULL, 'v' },
    { "help", required_argument, NULL, 'h' },
    { NULL, 0, NULL, 0 }
	};

	while( (ch = getopt_long(argc, argv, "i:o:d:r:vh", longopts, NULL)) != -1 ){
		switch( ch ){
			case 'i':
				// input file
				inputFile = string(optarg);
				break;
			case 'o':
				// image output file
				outputFile = string(optarg);
				break;
			case 'd':
				// depth output file
				depthFile = string( optarg );
				break;
			case 'r':
        resolution = atoi(optarg);
        break;
      case 'v':
        // set your flag here.
        break;
      case 'h':
        usage( );
        break;
			default:
				// do nothing
				break;
		}
	}
	gTheScene = new Scene( inputFile, outputFile, depthFile );
}

struct Points{          //data-structure to create list of points
	float pts[3];
	};
	
//Start of raytrace code we are trying to implement
float pixelSize = 5;

void jig( float cameraWidth, float cameraHeight, float pixelSize, float offset[3] ){  //pixel size = 5 unless you find it some where
           
	   float totalWidth, totalHeight;
	   Points* pt = new Points[100];
		
 	   if (pixelSize > cameraHeight)
               totalHeight = 1;
           else if(pixelSize == cameraHeight)
                totalHeight = cameraHeight;
           else 
                totalHeight = cameraHeight/pixelSize;

           
           if (pixelSize > cameraWidth)
               totalWidth = 1;
           else if(pixelSize == cameraWidth)
                totalWidth = cameraWidth;
           else 
               totalWidth = cameraWidth/pixelSize;
               
        for ( int i = 0; i < totalHeight; i++ )
        {
			for ( int j  = 0; j < totalWidth; j++)
			{
				pt[count].pts[0] = i + offset[0];
				pt[count].pts[1] = j + offset[1];
				pt[count].pts[2] = 0 + offset[2];
				//count++;
			}
		}
	
}



void rayfactory(Points p1[], Points p2[]){
	  //change to 

	  float* arrRay = new float; //generate list of rays
	       for (int i = 0; i < count; i++){
	           //for (int j = 0; j < sizeof(arrV2[i][j]); j++)
	               arrRay[i]= {p2[i].pts[3] - p1[i].pts[3]};//arrV1[i][j] - arrV2[i][j]; //head - tail
	       }

}



//End of implementation 

int main( int argc, char **argv ){
	string pathStr;
	gProgramName = argv[0];

	
	parseCommandLine( argc, argv );
	argc -= optind;
	argv += optind;
	if( gTheScene->hasInputSceneFilePath( ) &&
			gTheScene->hasOutputFilePath( ) &&
			gTheScene->hasDepthFilePath( ) ){
		gTheScene->parse( );	
		cout << *gTheScene << endl;	
	}else{
		usage( "You specify an input scene file, an output file and a depth file." );
	}


	return( 0 );
}



*/



#include <iostream>
#include <string>
#include "Group.h"
#include "getopt.h"
#include "Scene.h"
#include "Ray.h"
#include "glm/gtx/string_cast.hpp"

using namespace std;

Scene *gTheScene;
string gProgramName;

void usage( string message = "" ){
	cerr << message << endl;
	cerr << gProgramName << " -i <inputfile> -o <outputfile> -d <depthfile>" << endl;
	cerr << "          -or-" << endl;
	cerr << gProgramName << " --input <inputfile> --output <outputfile> --depth <depthfile>" << endl;
	
}

std::ostream& operator <<( std::ostream &out, const Pixel &p ){
  p.write( out );
  return( out );
}

void parseCommandLine( int argc, char **argv ){
	int ch;
	string inputFile( "" ), outputFile( "" ), depthFile( "" );
  int resolution;
	static struct option longopts[] = {
    { "input", required_argument, NULL, 'i' },
    { "output", required_argument, NULL, 'o' },
    { "depth", required_argument, NULL, 'd' },
    { "resolution", required_argument, NULL, 'r' },
    { "verbose", required_argument, NULL, 'v' },
    { "help", required_argument, NULL, 'h' },
    { NULL, 0, NULL, 0 }
	};

	while( (ch = getopt_long(argc, argv, "i:o:d:r:vh", longopts, NULL)) != -1 ){
		switch( ch ){
			case 'i':
				// input file
				inputFile = string(optarg);
				break;
			case 'o':
				// image output file
				outputFile = string(optarg);
				break;
			case 'd':
				// depth output file
				depthFile = string( optarg );
				break;
			case 'r':
        resolution = atoi(optarg);
        break;
      case 'v':
        // set your flag here.
        break;
      case 'h':
        usage( );
        break;
			default:
				// do nothing
				break;
		}
	}
	gTheScene = new Scene( inputFile, outputFile, depthFile );
}
//make jig2 with vector - norm(direction) then use this in rayfactory
vector<Ray> jig(float camWidth, float camHeight, float pixelSize, glm::vec3 camCenter, glm::vec3 camDirection, float &totalWidth, float &totalHeight)//(float camera.width, float camera.height, float pixelSize, vec3 camera.center)
{
    //float totalWidth, totalHeight;

 	if (pixelSize > camHeight)
        totalHeight = 1;
    else if(pixelSize == camHeight)
        totalHeight = camHeight;
    else 
        totalHeight = camHeight/pixelSize;

           
    if (pixelSize > camWidth)
        totalWidth = 1;
    else if(pixelSize == camWidth)
        totalWidth = camWidth;
    else 
        totalWidth = camWidth/pixelSize;
    
    vector<Ray> myRays;
    glm::vec3 rayOrigin;//vector<glm::vec3> myJig; //not glm:: vector????
    //Starting Point
    if((int)totalHeight % 2 == 0 || (int)totalWidth % 2 == 0) //compute center for even height& width
    {
    	glm::vec3 startPT = glm::vec3( camCenter.x - (totalWidth/2) + (pixelSize/2) , 
        camCenter.y + (totalHeight/2) - (pixelSize/2),
        camCenter.z);

    	for (int i = 0; i < totalWidth; i++){
        	for (int j = 0; j < totalHeight; j++)
        	{
            	rayOrigin = glm::vec3(startPT.x + i*pixelSize , startPT.x + j*pixelSize , camCenter.z); 
				myRays.push_back(Ray(rayOrigin, camDirection, rayOrigin.x, rayOrigin.y));//this is the ray factory now
       		}
    	}
    }else
    {
    	glm::vec3 startPT = glm::vec3( camCenter.x, 
        camCenter.y + (totalHeight/2) - (pixelSize/2),
        camCenter.z);

    	for (float j = startPT.y; j > -totalHeight/2 ; j = j - pixelSize){
    		
    		rayOrigin = glm::vec3(startPT.x , j , camCenter.z); 
			myRays.push_back(Ray(rayOrigin, camDirection, rayOrigin.x, rayOrigin.y));
        	
        	for (float i = pixelSize/2; i < totalWidth/2 ; i++)
        	{

            	rayOrigin = glm::vec3(startPT.x + i , j, camCenter.z); 
				myRays.push_back(Ray(rayOrigin, camDirection, rayOrigin.x, rayOrigin.y));//this is the ray factory now

				rayOrigin = glm::vec3(startPT.x - i , j, camCenter.z); 
				myRays.push_back(Ray(rayOrigin, camDirection, rayOrigin.x, rayOrigin.y));//this is the ray factory now
       		}
    	}

    }
    return myRays;
}







/*
Ray rayFactory(vector<glm::vec3> jiggy, glm::vec3 camDirection)
{
    vector<glm::vec3> myRays;
    
    for(glm::vec3 element : jiggy) 
    {
      //myRays.push_back(glm::vec3(normalize(camDirection) - element));  //element - normalize(camDirection) this is completely wrong
    	 // ( intersect())
		//if(newVal < DepthfileVal)
			//set depthfile
			//set color - picture file
      
    }

    return myRays;
}
*/

int main( int argc, char **argv ){
	string pathStr;
	gProgramName = argv[0];
	float myIntercept;

	Camera myCam;
	glm::vec3 myColor = glm::vec3(0, 0, 0); // color
	glm::vec3 myDiffuseColor = glm::vec3(0, 0, 0);
	Group myGroup;
	
    float totalHeight = 0, totalWidth = 0; //size of pixel frame image

	parseCommandLine( argc, argv );
	argc -= optind;
	argv += optind;
	if( gTheScene->hasInputSceneFilePath( ) &&
			gTheScene->hasOutputFilePath( ) &&
			gTheScene->hasDepthFilePath( ) ){
		gTheScene->parse( myCam, myColor, myDiffuseColor, myGroup);//pass constructors by reference	
		cout << *gTheScene << endl;	
		//raytrace();
		//vector<glm::vec3> myRays = rayFactory(jig(myCam._width, myCam._height, 1, myCam._center),myCam._direction);
        vector<Ray> myRays = jig(myCam._width, myCam._height, myGroup._radius, myCam._center, myCam._direction, totalWidth, totalHeight);
        int rayCount = 0, hit = 0;
        PNGImage myImage(gTheScene->outputFile( ).c_str( ), totalWidth, totalHeight); //check this
        for(Ray element : myRays) //check rays 
        {
            glm::vec3 myEle = element.returnPoint();
            cout << glm::to_string(myEle) << endl; //Ray object must refence private var inside to print
            cout << "Intercept: " << myGroup.intercept(myEle, myCam._direction, myGroup._center, myGroup._radius, myIntercept) <<endl;
            cout << "Image Pixel Orgins" << endl;
            cout << element.returnX() << " "<<element.returnY() << endl;
            //myImage.colorPixel(rayCount, rayCount, glm::vec3(0,0,1));//myImage.colorPixel(element.returnX(), element.returnY(), glm::vec3(1,1,1));//must use intercept and pixel color
            if(myGroup.intercept(myEle, myCam._direction, myGroup._center, myGroup._radius , myIntercept))
            {
                //myImage.pixels[rayCount++] = Pixel(0,0,0);
                //myImage.setPixel(i, j, 255, 0, 0, 255);
                myImage.setPixel(element.returnX() + 0.5 * totalWidth, element.returnY() + 0.5 * totalHeight,255,0,0,255);
                cout << "image coord: " << element.returnX() * 0.5 * totalWidth << " " << 0.5 * totalHeight << endl;
                hit++;
            }
            rayCount++;
        }
        cout <<"Ray Count: " <<rayCount <<" hit count: " << hit<<endl;
        myImage.save( );

	}else{
		usage( "You specify an input scene file, an output file and a depth file." );
	}


	return( 0 );
}
