#include <iostream>
#include "analyze.h"

void Analyze::ReadImage(std::string filename)
{
    std::cout << filename << std::endl;

    image_ = cv::imread(filename);

    std::cout << image_.cols << "," << image_.rows << "," << image_.channels() << std::endl;

    return;
}
Histogram Analyze::CreateHistogram_(cv::Mat& image)
{
    Histogram hist(image);
    return hist;
}
int Analyze::CreateHistogramImage(std::string filename, const int width, const int height)
{
    cv::Mat histImage = cv::Mat::zeros(height, width, CV_8UC3);

    Histogram hist = CreateHistogram_(image_);
    
    std::vector<cv::Scalar> colors;
    if (hist.image_channels_ == 1) {
        colors = {cv::Scalar(255,255,255)};
    }
    else {
        colors = {cv::Scalar(255,0,0),cv::Scalar(0,255,0),cv::Scalar(0,0,255)};
    }
    for (int c=0; c<hist.image_channels_; c++) {

        for (int b=1; b<hist.binsize_; b++) {

            int x0 = (int)(((double)(b - 1)/(double)hist.binsize_)*(double)(width - 1));
            int y0 = (int)((1.0 - hist.buf_[c][b - 1])*(double)(height - 1));
            int x1 = (int)(((double)b/(double)hist.binsize_)*(double)(width - 1));
            int y1 = (int)((1.0 - hist.buf_[c][b])*(double)(height - 1));

            cv::line(histImage, cv::Point(x0, y0), cv::Point(x1, y1), colors[c], 2);
        }
    }
    
    cv::imwrite(filename, histImage);
    
    return 0;
}
