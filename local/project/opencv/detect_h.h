#ifndef DETECT_H
#define DETECT_H

#include <boost/asio.hpp>
#include <opencv2/opencv.hpp>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <csignal>
#include <unistd.h>
#include <queue>
constexpr char SERVER_IP[] = "127.0.0.1";
constexpr unsigned short PORT_NUMBER = 9999;

static const cv::String model = "res10_300x300_ssd_iter_140000_fp16.caffemodel";
static const cv::String config = "deploy.prototxt";

class FaceDetec{
private:
    std::atomic_bool exitFlag;
    std::atomic_bool bool_confidence;
    std::queue<cv::Mat> Queue_frame;
    std::mutex mutex;
    std::condition_variable condVar;
public:
    FaceDetec()
    : bool_confidence(false), exitFlag(false){};
    void detect_face_thread();
    void send_mass_thread();
    void show_window_thread();
};


#endif