#include <vector>
#include <opencv2/opencv.hpp>

class Histogram
{
 private:
 public:
    int image_channels_ = 0;
    int binsize_ = 0;
    std::vector<std::vector<double>> buf_;

    Histogram(cv::Mat& image) {

        binsize_ = 256;
        image_channels_ = image.channels();

        buf_ = std::vector<std::vector<double>>(image_channels_);
        for (int c=0; c<image_channels_; c++) {
            buf_[c] = std::vector<double>(binsize_, 0);
        }

        unsigned char* data = image.data;
        for (int y=0; y<image.rows; y++) {
            for (int x=0; x<image.cols; x++) {
                for (int c=0; c<image_channels_; c++) {

                    int index = image.step*y + image.elemSize()*x + c;
                    
                    buf_[c][data[index]] += 1.0;
                }
            }
        }
        
        // normalize by max value
        double max = -1.0;
        for (int c=0; c<image_channels_; c++) {
            for (int b=0; b<binsize_; b++) {
                max = std::max(max, buf_[c][b]);
            }
        }
        std::cout << "hist max : " << max << std::endl;
        for (int c=0; c<image_channels_; c++) {
            for (int b=0; b<binsize_; b++) {
                buf_[c][b] = buf_[c][b]/max;
            }
        }
    };
};
class Analyze
{
 private:
    cv::Mat image_;
    Histogram CreateHistogram_(cv::Mat& image);
 public:
    Analyze() {
    };
    void ReadImage(std::string filename);
    int CreateHistogramImage(std::string filename, const int width, const int height);
};
