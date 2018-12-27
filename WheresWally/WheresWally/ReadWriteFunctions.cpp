
// Reads .txt file representing an image of R rows and C Columns stored in filename 
// and converts it to a 1D array of doubles of size R*C
// Memory allocation is performed inside readTXT
// Read .txt file with image of size (R rows x C columns), and convert to an array of doubles

#include <iostream>
#include <fstream>

using namespace std;

double* read_text(char *fileName, int sizeR, int sizeC)
{
  double* data = new double[sizeR * sizeC];
  int i = 0;
  ifstream myfile (fileName);
  if (myfile.is_open())
  {
	 
	while (myfile.good())
    {
       if (i > sizeR * sizeC - 1) break;
		 myfile >> *(data + i);
		 // PRINTS CONVERTED DATA TO SCREEN
         //cout << *(data + i) << ' '; 
	     i++;                                                             
	}
    myfile.close();
  }

  else cout << "Unable to open file"; 
  //cout << i;

  return data;
}


// CONVERTS 1D OF ARRAY DOUBLES OF SIZE R*C TO PGM IMAGE AND STORES THE PGM IN FILENAME
// Q = 255 FOR GREYSCALE IMAGES AND 1 FOR BINARY IMAGES
void write_pgm(char *filename, double *data, int sizeR, int sizeC, int Q)
{

 int i, j;
 unsigned char *image;
 ofstream myfile;

 image = (unsigned char *) new unsigned char [sizeR * sizeC];

 // CONVERT INT VALUES TO UNSIGNED CHARS
 
 for(i = 0; i < sizeR * sizeC; i++)
	 image[i]=(unsigned char)data[i];

 myfile.open(filename, ios::out|ios::binary|ios::trunc);

 if (!myfile)
 {
   cout << "Can't open file: " << filename << endl;
   exit(1);
 }

 myfile << "P5" << endl;
 myfile << sizeC << " " << sizeR << endl;
 myfile << Q << endl;

 myfile.write(reinterpret_cast<char *>(image), (sizeR * sizeC) * sizeof(unsigned char));

 if (myfile.fail())
 {
   cout << "Can't write image " << filename << endl;
   exit(0);
 }

 myfile.close();

 delete[] image;

}