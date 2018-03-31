#include <opencv2/opencv.hpp>

class Histogram
{
 public:
    
};
class Analyze
{
 private:
    cv::Mat image_;
 public:
    Analyze() {
    };
    void ReadImage(std::string filename);
    int CreateHistogramImage(std::string filename);
};
