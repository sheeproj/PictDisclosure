#include <iostream>
#include "analyze.h"

void Analyze::ReadImage(std::string filename)
{
    std::cout << filename << std::endl;

    cv::Mat img = cv::imread(filename);

    std::cout << img.cols << std::endl;
    return;
}
