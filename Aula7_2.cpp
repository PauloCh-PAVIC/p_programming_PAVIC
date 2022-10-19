#include <iostream>
#include <fstream>

//Load Images
#define STB_IMAGE_IMPLEMENTATION
// Write Images
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "include/stb_image.h"
//#include "stb/stb_image_resize.h"
#include "include/stb_image_write.h"

using namespace std;



struct Pixel
{
    unsigned char red, green, blue;
};

// Convert Image to Gray at CPU
void ConvertImageToGrayCpu(unsigned char* imageRGBA, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {

            /*  Color to Grayscale Equation
             Ylinear = 0.2126RLinear + 0.7152GLiners +0.0722BLiners */
            Pixel* ptrPixel = (Pixel*)&imageRGBA[y * width * 3 + 3 * x];
            unsigned char pixelValue = (unsigned char)(ptrPixel->red * 0.2126f + ptrPixel->green * 0.7152f + ptrPixel->blue * 0.0722f);

            //float pixelValue = ptrPixel->red * 0.2126f + ptrPixel->green * 0.7152f + ptrPixel-> blue * 0.0722f;
            //unsigned char pixelValue = pixelValue;
            ptrPixel->red = pixelValue;
            ptrPixel->green = pixelValue;
            ptrPixel->blue = pixelValue;
            //ptrPixel->alpha = 255;

        }
    }

}


int main()
{
    int width, height, channels;
    // Loading jpeg files
    unsigned char* img = stbi_load("images/apple.jpg", &width, &height, &channels, 3);



    // Converting color to grayscale
   /*
    Color to Grayscale Equation
    Ylinear = 0.2126RLinear + 0.7152GLiners +0.0722BLiners
    */


    // Pixel Strucure
    /* Define Pixel Struct */
    // An output image with N components has the following components interleaved
    // in this order in each pixel:
    //     N=#comp     components
    //       4           red, green, blue, alpha

    /* Pixel Level!!
      Color to Grayscale Equation
      Ylinear = 0.2126RLinear + 0.7152GLiners +0.0722BLiners
                 */


                 // Check If image was loads correct!!
    if (img == 0) {
        cout << "Error loading image file" << endl;
        return -1;
    }


    // Image info display
    cout << "Loading image\n";
    cout << "\twidth = " << width << "\n";
    cout << "\theight = " << height << "\n";
    cout << "\tchannels = " << channels << "\n";



    //Convert Image to Gray at CPU
    //void ConvertImageToGrayCpu(unsigned char* imageRGBA, int width, int height)
    ConvertImageToGrayCpu(img, width, height);
    cout << "Done" << endl;



    // Writing jpeg files
    stbi_write_jpg("images/apple-Gray.jpg", width, height, channels, img, 100);

    stbi_image_free(img);
    return 0;
}