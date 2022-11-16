#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <armadillo>
using namespace cv;

template <class T, size_t N>
std::vector<float> asFloat(T (&input)[N]) {
    return std::vector<float> {input, input+N};
}

int main(int argc, char** argv)
{
    int Io=240, alpha=1;
    float beta=0.15;
    if (argc != 2) {
        printf("usage: DisplayImage.out <Image_Path>\n");
        return -1;
    }
    Mat image;
    image = imread(argv[1], 1);
    if (!image.data) {
        printf("No image data \n");
        return -1;
    }
    float HERef[3][2] = {{0.5626, 0.2159}, {0.7201, 0.8012}, {0.4062, 0.5581}};
    float maxCRef[2] = {1.9705, 1.0308};
    int h = image.size().height;
    int w = image.size().width;
    int c = image.channels();

    Mat image_ = image.reshape(1,3);   
    std::cout<<"Size "<<image_.size()<<std::endl;
    std::cout<<"Image = "<<image.at< int >(0,0)<<std::endl;
    // auto res = asFloat(image_);

    //     # calculate optical density
    // OD = -np.log((img.astype(np.float)+1)/Io)  

    namedWindow("Display Image", WINDOW_AUTOSIZE);
    imshow("Display Image", image);
    waitKey(0);
    return 0;
}