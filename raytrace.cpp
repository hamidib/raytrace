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
//make jig2 with vector - norm(direction) then use this in rayfactory
vector<Ray> jig(float pixelSize, Camera myCam, Group myGroup, float &totalWidth, float &totalHeight)//float camWidth, float camHeight, float pixelSize, glm::vec3 camCenter, glm::vec3 camDirection, float &totalWidth, float &totalHeight)//(float camera.width, float camera.height, float pixelSize, vec3 camera.center)
{
    //float totalWidth, totalHeight;

 	if (pixelSize > myCam._height)
        totalHeight = 1;
    else if(pixelSize == myCam._height)
        totalHeight = myCam._height;
    else 
        totalHeight = myCam._height/pixelSize;

           
    if (pixelSize > myCam._width)
        totalWidth = 1;
    else if(pixelSize == myCam._width)
        totalWidth = myCam._width;
    else 
        totalWidth = myCam._width/pixelSize;
    
    vector<Ray> myRays;
    glm::vec3 rayOrigin;//vector<glm::vec3> myJig; //not glm:: vector????
    //Starting Point
    //if((int)totalHeight % 2 == 0 || (int)totalWidth % 2 == 0) //compute center for even height& width
    //{
    	glm::vec3 startPT = glm::vec3( myCam._center.x - (totalWidth/2) + (pixelSize/2) , 
        myCam._center.y + (totalHeight/2) - (pixelSize/2),
        myCam._center.z);
        int pixPos = 0;
    	for (int i = 0; i < totalWidth; i++){
        	for (int j = 0; j < totalHeight; j++)
        	{
            	rayOrigin = glm::vec3(startPT.x + i*pixelSize , startPT.x + j*pixelSize , myCam._center.z); 

				myRays.push_back(Ray(rayOrigin, myCam._direction, pixPos/totalWidth, pixPos%(int)totalWidth));//this is the ray factory now
                pixPos++;
       		}
    	}
        /*
    }else //off by 1 pixel - doesnt matter in a bigger picture
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
                //l-> l/w, l%w
                //#
				myRays.push_back(Ray(rayOrigin, camDirection, rayOrigin.x, rayOrigin.y));//this is the ray factory now

				rayOrigin = glm::vec3(startPT.x - i , j, camCenter.z); 
				myRays.push_back(Ray(rayOrigin, camDirection, rayOrigin.x, rayOrigin.y));//this is the ray factory now
       		}
    	}

    } */
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
    Hit myHits;
    //Sphere mySphere(myGroup._radius, myGroup._center);
	
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
        vector<Ray> myRays = jig(1, myCam, myGroup, totalWidth, totalHeight);
        int rayCount = 0, hit = 0;
        cout << gTheScene->outputFile().c_str() <<endl;
        PNGImage myImage(gTheScene->outputFile( ).c_str( ), totalWidth, totalHeight); //check this
        for(Ray element : myRays) //check rays 
        {
            glm::vec3 myEle = element.getPoint();
            cout << glm::to_string(myEle) << endl; //Ray object must refence private var inside to print
            cout << "Intercept: " << myGroup.myObjects[0]->intersect(element, myHits ) << endl;//<< myGroup._o3d._s.intercept(element.getPoint(), myCam._direction, myGroup._o3d._s._center, myGroup._o3d._s._radius, myIntercept) <<endl;
            cout << "Image Pixel Orgins" << endl;
            cout << element.getX() << " "<<element.getY() << endl;
            //myImage.colorPixel(rayCount, rayCount, glm::vec3(0,0,1));//myImage.colorPixel(element.returnX(), element.returnY(), glm::vec3(1,1,1));//must use intercept and pixel color
            if(myGroup.myObjects[0]->intersect(element, myHits ))//myGroup._o3d._s.intercept(element.getPoint(), myCam._direction, myGroup._o3d._s._center, myGroup._o3d._s._radius , myIntercept))
            {
                //myImage.pixels[rayCount++] = Pixel(0,0,0);
                //myImage.setPixel(i, j, 255, 0, 0, 255);
                if((int)totalHeight % 2 == 0 || (int)totalWidth % 2 == 0) 
                {
                    myImage.setPixel(element.getX(),element.getY(),255,0,0,255);
                    cout << "X "<< element.getX() << "Y " << element.getY() << endl;
                }else
                {
                    //myImage.setPixel(static_cast<float>(element.returnPoint().x + 0.5 * totalWidth +0.5), static_cast<float>(element.returnPoint().y + 0.5 * totalHeight) ,255,0,0,255);
                    //cout << "img coord: "<< element.returnPoint().x + 0.5 * totalWidth +0.5 << " " << element.returnPoint().y + 0.5 * totalHeight ;
                }
            
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
