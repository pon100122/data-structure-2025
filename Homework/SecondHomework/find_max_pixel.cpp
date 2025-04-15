#include <opencv2/opencv.hpp>
#include <cstdio>

int main() {

    cv::Mat img = cv::imread("Lenna.png", cv::IMREAD_GRAYSCALE);
    if (img.empty()) {

        return -1;
    }

    int maxVal = 0;


    for (int row = 0; row < img.rows; row++) {
        for (int col = 0; col < img.cols; col++) {
            uchar pixel = img.at<uchar>(row, col);
            if (pixel > maxVal) {
                maxVal = pixel;
            }
        }
    }

    printf("최대 화소 밝기: %d\n", maxVal);


    cv::imshow("lenna window", img);
    cv::waitKey(0);
    return 0;
}
