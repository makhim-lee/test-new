#include <boost/asio.hpp>
#include <iostream>
 
#include <opencv2/opencv.hpp>
#include <thread>

#pragma warning (disable : 4996)
 
constexpr char SERVER_IP[] = "127.0.0.1";
constexpr unsigned short PORT_NUMBER = 9999;

static const cv::String model = "res10_300x300_ssd_iter_140000_fp16.caffemodel";
static const cv::String config = "deploy.prototxt";

void test_test() {
//TCPIP set
	boost::asio::io_service io_service;
    boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::address::from_string(SERVER_IP),PORT_NUMBER);
 
    boost::system::error_code connect_error;
    boost::asio::ip::tcp::socket socket(io_service);
    socket.connect(endpoint, connect_error);
 
    if (connect_error) {
        std::cout << "error No: " << connect_error.value()<< "->" << connect_error.message() << std::endl;
    }
//dnn_face set
	cv::VideoCapture capture(-1, cv::CAP_V4L2);
	if(!capture.isOpened()) return;
	cv::dnn::Net net = cv::dnn::readNet(model, config);
	if(net.empty()) return;
	
	cv::Mat frame;
	cv::namedWindow("frame");
    
    while (1) 
    {
		capture>>frame;
		cv::Mat blob = cv::dnn::blobFromImage(frame, 1, cv::Size(300,300),cv::Scalar(104,177,123));
		net.setInput(blob);//input
		cv::Mat result = net.forward(); 
		cv::Mat detect(result.size[2], result.size[3], CV_32FC1, result.ptr<float>());

		for (int i = 0; i < detect.rows; ++i) {
			float CONFIDENCE = detect.at<float>(i,2); // column 2
			if(CONFIDENCE<0.7)break;
			int x1 = cvRound(detect.at<float>(i, 3)* frame.cols);
			int y1 = cvRound(detect.at<float>(i, 4)* frame.rows);
			int x2 = cvRound(detect.at<float>(i, 5)* frame.cols);
			int y2 = cvRound(detect.at<float>(i, 6)* frame.rows);

			cv::rectangle(frame, cv::Rect(cv::Point(x1,y1),\
						cv::Point(x2,y2)), cv::Scalar(0,255,0));
			
			cv::String label = cv::format("Face : %5.3f", CONFIDENCE);
			cv::putText(frame, label, cv::Point(x1,y1-1), \
					cv::FONT_HERSHEY_COMPLEX, 0.8, cv::Scalar(0,255,0));
			if (CONFIDENCE > 0.98){
				std::string message = "myface";
       			boost::system::error_code ignored_error;
        		socket.write_some(boost::asio::buffer(message, message.size()), ignored_error);
        		std::cout << "Sent Message: " << message << std::endl;
			}
		}
		cv::imshow("frame", frame);
		if(cv::waitKey(1) == 27) break; 
    }
	cv::destroyAllWindows();
    socket.close();
    getchar();
}
