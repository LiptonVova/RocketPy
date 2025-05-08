//g++ macro.cpp GPT.cpp -Wall -o2 -o test1 `root-config --cflags --glibs` -std=c++0x -pthread
#include "lmesh.hpp"

using namespace std;

vector< int> sensorindex1;


#define SMALL_NUM   0.00000001 // anything that avoids division overflow

//convert variabes to string
template <typename T> string tostr(const T& t) { 
   ostringstream os; 
   os<<t; 
   return os.str();
}


vector< float> View (3);
vector< float> View2 (3);
vector< float> Axis (3);
string projfile;

//quarternion functions
quaternion mult(quaternion A, quaternion B);
quaternion conjugate(quaternion quat);
quaternion normalizeq(quaternion quat);
void Rotate(float Angle, float x, float y, float z);
float length(quaternion quat);

//vector/math operations functions
tvec cross(tvec v1, tvec v2);
float dot(tvec v1, tvec v2);
tvec addvec(tvec v1, tvec v2);
tvec subvec(tvec v1, tvec v2);
tvec refvec(tvec v1, tvec v2, float sub);
tvec vecaddnum(tvec v1, float f1, float f2, float f3);
float get_dist(tvec v1, tvec v2);


void getcad(striset & imesh, string cadfile);
bool file_exists(string& name);





//****************************************************************************************************//
//*************************************start of main functions****************************************//
//****************************************************************************************************//


//----------------------------load geometry-------------------------------------------------------//
void load_mesh(striset & imesh, string cadfile)
{
 bool run = true;
 
 float k = 1;
 while(run)
  {string temp;
  cout << " Looking...\n";
  temp.append("/home/jerin/rocketSIM/cpress/cadd/");
  temp.append(cadfile);
  temp.append(tostr(k));
  temp.append(".ast");
  cout << "Attempting to open: " <<  temp << "\n";
	  if(file_exists(temp))
	  {
	  getcad(imesh, temp);
	  //cout << "\n" << imesh.size();
	  }
	  else
	  {
	  run = false;
	  cout << " ...failed\n";
	  }
	  ++k;
}

}



//-----------------------------------------------CAD Loader------------------------------------------------//


void getcad(striset & imesh, string cadfile)
{  
cout << "loading cadd file: " << cadfile;
const char * path;

char norm;

        //enter .txt and .wfi files to be used
	string wfifile= cadfile;
	path = wfifile.c_str();

stri tri1;
//find vertex

std::cout << "\nRegular .ast Import: ";
	
		FILE * file = fopen(path, "r");
		if( file == NULL ){
			printf("File not found with path given\n");
			getchar();
			return;
		}

		int ind = 0;
		int ggg = 0;

		while( 1 ){
			
			char lineHeader[500];
			// read the first word of the line
			int res = fscanf(file, "%s", lineHeader);
			if (res == EOF)
				break; // EOF = End Of File. Quit the loop.

			/*if (ggg == 70)
				break;
				++ggg;*/

			//cout << lineHeader << "\n";
			if ( strcmp( lineHeader, "vertex" ) == 0 ){
				tvec vertex;
				int matches = fscanf(file, " %f %f %f \n", &vertex.i, &vertex.j, &vertex.k );
			
				if (matches != 3){
					printf("File can't be read by our simple parser :-( problem with vertices\n");
					return;
				}
			
				++ind;
				//printf("   vertex: %f %f %f\n", vertex.i, vertex.j, vertex.k);
				if(ind == 1)
				{
				tri1.vert1 = vertex;
				}
				
				if(ind == 2)
				{
				tri1.vert2 = vertex;
				}
				
				if(ind == 3)
				{
				tri1.vert3 = vertex;
				imesh.mesh.push_back(tri1);
				ind = 0;
				}
				
				
			}
		
			if ( strcmp( lineHeader, "normal" ) == 0 ){
				tvec normal;
				int matches = fscanf(file, "%f %f %f \n", &normal.i, &normal.j, &normal.k );
				if (matches != 3){
					printf("File can't be read by our simple parser :-( problem with normals\n");
					return;
				}
				//printf("   normal: %f %f %f\n", normal.i, normal.j, normal.k);
				if(ind == 0)
				{
				tri1.facet = normal;
				}
				
			
			}

		}
      




cout << "  size:" << imesh.mesh.size() << "\nFinshed \n\n";		
}	





//-----------------------------------------Triangle Detection-----------------------------------------// 
/*


int triangledetect(vector< vector<float> > T, vector< vector<float> > P, vector<float> & I, vector<float> & R,  vector<float> & nnn, vector<float> & ddir, float & theta)
{   vector< float>  uuu, vvv;              // triangle vectors
    vector<float> ww0, ww;           // ray vectors
    float     rrr, aaa, bbb;  
    vector<float> V0(3);
    vector<float> V1(3);
    vector<float> V2(3);
    vector<float> null(3); 
    float    uu1, uv1, vv1, wu1, wv1, D1;
float sss, ttt;

    I.at(0) = 0;
    I.at(1) = 0;
    I.at(2) = 0;
    
    R.at(0) = 0;
    R.at(1) = 0;
    R.at(2) = 0;
    
    null.at(0) = 0;
    null.at(1) = 0;
    null.at(2) = 0;	
    
    vector<float> P0(3);
    vector<float> P1(3);
    V0 = T.at(0);
    V1 = T.at(1);
    V2 = T.at(2); 

    P0 = P.at(0);
    P1 = P.at(1);
       
 //start of detect 
    // get triangle edge vectors and plane normal
    uuu = subvec(V1, V0);
    vvv = subvec(V2, V0);
    nnn = cross(uuu,vvv);            // cross product nnn is plane normal
    
    
    if (nnn == null)             // triangle is degenerate
        return -1;                  // do not deal with this case

    ddir = subvec(P1,P0);              // ray direction vector
    ww0 = subvec(P0 , V0);
    aaa = -dot(nnn,ww0);
    bbb = dot(nnn,ddir);  
    
    if (fabs(bbb) < SMALL_NUM) {     // ray is  parallel to triangle plane
        if (aaa == 0)  
                       // ray lies in triangle plane
            return 2;
        else return 0;              // ray disjoint from plane
    }

    // get intersect point of ray with triangle plane
    rrr = aaa / bbb;
    if (rrr < 0.0)                    // ray goes away from triangle
        return 0;                   // => no intersect
    // for a segment, also test if (r > 1.0) => no intersect

    I.at(0) = P0.at(0) + rrr * ddir.at(0);            // intersect point of ray and plane
    I.at(1) = P0.at(1) + rrr * ddir.at(1);
    I.at(2) = P0.at(2) + rrr * ddir.at(2);
    
    
    // is I inside T?
    
    uu1 = dot(uuu,uuu);
    uv1 = dot(uuu,vvv);
    vv1 = dot(vvv,vvv);
    ww = subvec(I , V0);
    wu1 = dot(ww,uuu);
    wv1 = dot(ww,vvv);
    D1 = uv1 * uv1 - uu1 * vv1;

    // get and test parametric coords
    
    sss = (uv1 * wv1 - vv1 * wu1) / D1;
    if (sss < 0.0000000 || sss > 1.0000000)         // I is outside T
        return 0;
    ttt = (uv1 * wu1 - uu1 * wv1) / D1;
    if (ttt < 0.0000000 || (sss + ttt) > 1.0000000)  // I is outside T
        return 0;

    float sub = (2*dot(ddir, nnn))/dot(nnn,nnn);
    
	R = refvec(ddir, nnn, sub);
	
	//angle between reflected and normal vector
	
	theta = 360*(acos( dot(nnn,R)/(sqrt(dot(nnn,nnn))*sqrt(dot(R,R))))/(2*3.14159265359));
	if(theta > 90)
	theta = 180-theta;


    return 1;                       // I is in T
    
   
}


*/

//-------------------------------------Transmission Calculator--------------------------------------//
/*
vector<float> trans(vector<float> v1, vector<float> v2, vector<float> v3, float n1, float n2, vector<float> ddir, vector<float> & I)//v1 normal 
{ vector<float> vcross(3);
vector<float> vecP;
vecP = normalize(ddir);
v1 = normalize(v1);
//printf("\nvecP here: %f %f %f", vecP.at(0), vecP.at(1), vecP.at(2)); 
//printf("\nv1 here: %f %f %f", v1.at(0), v1.at(1), v1.at(2));  
vector<float> vectemp (3);
vector<float> vectemp1 (3);
vector<float> vectemp2 (3);
vector<float> vectempN (3);
float hhh11 = dot(cross(v1, vecP),cross(v1,vecP));
//printf( "\nhhh11 here: %f", hhh11);
float hhh22;

       vectempN.at(0) = -v1.at(0);
       vectempN.at(1) = -v1.at(1);
       vectempN.at(2) = -v1.at(2);

       vectemp = cross(v1, cross(vectempN,vecP));
        //printf("\nvectemp here: %f %f %f", vectemp.at(0), vectemp.at(1), vectemp.at(2));
       vectemp1.at(0) = (n1/n2)*vectemp.at(0);
       vectemp1.at(1) = (n1/n2)*vectemp.at(1);
       vectemp1.at(2) = (n1/n2)*vectemp.at(2);
       //printf("\nvectemp1 here: %f %f %f", vectemp1.at(0), vectemp1.at(1), vectemp1.at(2));
       //printf("\nsqr: %f",(pow((n1/n2),2)*hhh11)); 
       hhh22 = sqrt(1-(pow((n1/n2),2)*hhh11));
       //printf( "\nhhh22 here: %f", hhh22);
       vectemp2.at(0) = hhh22*v1.at(0);
       vectemp2.at(1) = hhh22*v1.at(1);
       vectemp2.at(2) = hhh22*v1.at(2);
       //printf("\nvectemp2 here: %f %f %f", vectemp2.at(0), vectemp2.at(1), vectemp2.at(2));
       vcross = subvec(vectemp1,vectemp2);
       vcross.at(0) = 15* vcross.at(0);
       vcross.at(1) = 15* vcross.at(1);
       vcross.at(2) = 15* vcross.at(2);
       vcross = addvec(vcross, I);
       
     
return vcross;
}

*/


//---------------------------------------------Quartionion Rotations----------------------------------------//

float length(quaternion quat)
{
  return sqrt(quat.x * quat.x + quat.y * quat.y +
              quat.z * quat.z + quat.w * quat.w);
}

quaternion normalizeq(quaternion quat)
{
  float L = length(quat);

  quat.x /= L;
  quat.y /= L;
  quat.z /= L;
  quat.w /= L;

  return quat;
}

quaternion conjugate(quaternion quat)
{
  quat.x = -quat.x;
  quat.y = -quat.y;
  quat.z = -quat.z;
  return quat;
}

quaternion mult(quaternion A, quaternion B)
{
  quaternion C;

  C.x = A.w*B.x + A.x*B.w + A.y*B.z - A.z*B.y;
  C.y = A.w*B.y - A.x*B.z + A.y*B.w + A.z*B.x;
  C.z = A.w*B.z + A.x*B.y - A.y*B.x + A.z*B.w;
  C.w = A.w*B.w - A.x*B.x - A.y*B.y - A.z*B.z;
  return C;
}


void Rotate(float Angle, float x, float y, float z)
{
  quaternion temp, quat_view, result;

  temp.x = x * sin(Angle/2);
  temp.y = y * sin(Angle/2);
  temp.z = z * sin(Angle/2);
  temp.w = cos(Angle/2);

  quat_view.x = View.at(0);
  quat_view.y = View.at(1);
  quat_view.z = View.at(2);
  quat_view.w = 0;

  result = mult(mult(temp, quat_view), conjugate(temp));

  View.at(0) = result.x;
  View.at(1) = result.y;
  View.at(2) = result.z;
}



bool file_exists(string& name)
{
  struct stat buffer;   
  return (stat (name.c_str(), &buffer) == 0); 
}


//----------------------------------------------Math Operations---------------------------------------//

tvec cross(tvec v1, tvec v2)
{tvec vcross;
	vcross.i = (v2.j*v1.k)-(v2.k*v1.j);
	vcross.j = (v2.k*v1.i)-(v2.i*v1.k);
	vcross.k = (v2.i*v1.j)-(v2.j*v1.i);
return vcross;
}

float dot(tvec v1, tvec v2)
{
        float dotp;
	dotp = v1.i*v2.i +v1.j*v2.j +v1.k*v2.k;
	
return dotp;
}

tvec addvec(tvec v1, tvec v2)
{tvec vcross;
	vcross.i = v1.i + v2.i;
	vcross.j = v1.j + v2.j;
	vcross.k = v1.k + v2.k;
return vcross;
}

tvec subvec(tvec v1, tvec v2)
{tvec vcross;
	vcross.i = v1.i - v2.i;
	vcross.j = v1.j - v2.j;
	vcross.k = v1.k - v2.k;
return vcross;
}

tvec vecaddnum(tvec v1, float f1, float f2, float f3)
{ tvec vcross;
	vcross.i = v1.i + f1;
	vcross.j = v1.j + f2;
	vcross.k = v1.k + f3;
return vcross;
}

  
tvec refvec(tvec v1, tvec v2, float sub)
{tvec vcross;
	vcross.i = v1.i - sub*v2.i;
	vcross.j = v1.j - sub*v2.j;
	vcross.k = v1.k - sub*v2.k;
return vcross;
}

void cyltocart(float & r, float & theta, float & z) //cylindrical to cartesian
{float x, y;
x = r*cos(theta);
y = r*sin(theta);
r = x;
theta = y;

}

tvec normalize(tvec v1)//v1 normal 
{ tvec vcross;
float hhh33 = sqrt(pow(v1.i,2)+ pow(v1.j,2) + pow(v1.k,2));
vcross.i = v1.i/hhh33;
vcross.j = v1.j/hhh33;
vcross.k = v1.k/hhh33;

return vcross;
}

float get_dist(tvec v1, tvec v2)
{
float dist1 = 0;
dist1 = sqrt( pow((v1.i-v2.i),2) + pow((v1.j-v2.j),2) + pow((v1.k-v2.k),2)); 
return dist1;
}


float get_tri_area(tvec v1, tvec v2, tvec v3)
{
//Herons formula
int n = 3;
float area = 0;
float aa = get_dist(v1, v2);
float bb = get_dist(v2, v3);
float cc = get_dist(v3, v1);

float p = (aa+bb+cc)/2;
area = sqrt(p*(p-aa)*(p-bb)*(p-cc));
return area;   
}












//----------------------------print or view---------------------------------//
void print_triangle(stri temp, int i)
{
printf("triangle %d :\nvert1 %f %f %f\nvert2 %f %f %f\nvert3 %f %f %f\nnorm1 %f %f %f\naproj: %f\narea: %f\n\n", i+1, temp.vert1.i, temp.vert1.j, temp.vert1.k, temp.vert2.i, temp.vert2.j, temp.vert2.k, temp.vert3.i, temp.vert3.j, temp.vert3.k, temp.facet.i, temp.facet.j, temp.facet.k, temp.aproj, temp.area);
}

