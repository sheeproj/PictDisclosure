#include <iostream>
#include "analyze.h"

void Analyze::ReadImage(std::string filename)
{
    std::cout << filename << std::endl;

    image_ = cv::imread(filename);

    std::cout << image_.cols << "," << image_.rows << "," << image_.channels() << std::endl;

    return;
}
int Analyze::CreateHistogramImage(std::string filename)
{
    cv::Mat histImage = cv::Mat::zeros(300, 400, CV_8UC3);

    cv::imwrite(filename, histImage);
    
    return 0;
}
