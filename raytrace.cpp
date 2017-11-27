/*
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
#include "Sphere.h"
#include "getopt.h"
#include "Scene.h"
#include "Ray.h"
#include "Hit.h"
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

vector<Ray> rayFactory(const Camera& cam, const Group& g){
    vector<Ray> v;
    float width = cam._width;
    float height = cam._height;
    float pixelSize = cam._pixelSize;
    // The starting point is in camera
    glm::vec3 startPT = glm::vec3(
        cam._center.x - (width/2.0) + (pixelSize/2.0) , 
        cam._center.y + (height/2.0) - (pixelSize/2.0),
        cam._center.z
        );
    cerr << glm::to_string(startPT) << endl;
    for (float i = 0; i < cam.pixelWidth( ); i++){
        for (float j = 0; j < cam.pixelHeight( ); j++){
            glm::vec3 rayOrigin = glm::vec3(
                startPT.x + i*pixelSize,
                startPT.x + j*pixelSize,
                startPT.z
                ); 
            // this is the ray factory now
            Ray r(rayOrigin, cam._direction, int(trunc(i)), int(trunc(j)));
            //cerr << r << endl;
            //r.write(cerr);
            v.push_back(r);
        }
    }
    return v;
}


int main( int argc, char **argv ){
	string pathStr;
	gProgramName = argv[0];
	float myIntercept;

	Camera myCam;
	glm::vec3 myColor = glm::vec3(0, 0, 0); // color
	glm::vec3 myDiffuseColor = glm::vec3(0, 0, 0);
	Group myGroup;
    Hit myHits;

	parseCommandLine( argc, argv );
	argc -= optind;
	argv += optind;
	if( gTheScene->hasInputSceneFilePath( ) &&
			gTheScene->hasOutputFilePath( ) &&
			gTheScene->hasDepthFilePath( ) ){
		gTheScene->parse( myCam, myColor, myDiffuseColor, myGroup);
		cout << *gTheScene << endl;	
        myCam._pixelSize = 0.015625;
        cout << "Pixel size: " << myCam._pixelSize << endl;
        cout << "Pixel Width & Height: " << myCam.pixelWidth( ) << " " << myCam.pixelHeight( ) << endl;

        vector<Ray> myRays = rayFactory(myCam, myGroup);

        cout << "Number of rays: " << myRays.size( ) << endl;
        
        int rayCount = 0, hit = 0;
        cout << gTheScene->outputFile().c_str() <<endl;
        PNGImage myImage(gTheScene->outputFile( ).c_str( ), myCam.pixelWidth( ), myCam.pixelHeight( ));
        myImage.grayFill(0);
        for(Ray element : myRays) //check rays 
        {
 	    for(int i = 0; i < myGroup._numObjects; i++) {      
	 //cout << "Intercept: " << myGroup.myObjects[0]->intersect(element, myHits ) << endl;
		    if(myGroup.myObjects[i]->intersect(element, myHits ))
		    {
		        myImage.setPixel(element.getX( ), element.getY( ), 255, 0, 0, 255);
		        cout << "Hit!!" << endl;
		        hit++;
		    }
		}
        }
        cout <<"Ray Count: " << myRays.size( ) <<" hit count: " << hit<<endl;
        myImage.save( );

	}else{
		usage( "You specify an input scene file, an output file and a depth file." );
	}


	return( 0 );
}
