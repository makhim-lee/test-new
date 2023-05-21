#include"detect_h.h"

void FaceDetec::detect_face_thread() {
    cv::VideoCapture capture(-1, cv::CAP_V4L2);
    capture.set(cv::CAP_PROP_FPS, 30);
    if(!capture.isOpened()) return;
    cv::dnn::Net net = cv::dnn::readNet(model, config);
    if(net.empty()) return;
	
    cv::Mat frame, blob, result;
    float CONFIDENCE;
    bool local_bool_confidence = false;
    cv::String label; 
    
    while (!exitFlag.load()) 
    {
        capture>>frame;
        blob = cv::dnn::blobFromImage(frame, 1, cv::Size(300,300),cv::Scalar(104,177,123));
        net.setInput(blob);
        result = net.forward();
        cv::Mat detect(result.size[2], result.size[3], CV_32FC1, result.ptr<float>());
        
        CONFIDENCE = detect.at<float>(0,2);
        if(CONFIDENCE < 0.7){
            local_bool_confidence = false;
        }else{
            local_bool_confidence = true;
            
            int x1 = cvRound(detect.at<float>(0, 3)* frame.cols);
            int y1 = cvRound(detect.at<float>(0, 4)* frame.rows);
            int x2 = cvRound(detect.at<float>(0, 5)* frame.cols);
            int y2 = cvRound(detect.at<float>(0, 6)* frame.rows);
            cv::rectangle(frame, cv::Rect(cv::Point(x1,y1), cv::Point(x2,y2)), cv::Scalar(0,255,0));
            label = cv::format("Face : %5.3f", CONFIDENCE);
            cv::putText(frame, label, cv::Point(x1,y1-1), cv::FONT_HERSHEY_COMPLEX, 0.8, cv::Scalar(0,255,0));
        
            //std::unique_lock<std::mutex> lock(mutex);
            Queue_frame.push(frame.clone()); 
            //lock.unlock(); 
        }

        if(bool_confidence != local_bool_confidence){
            bool_confidence = !bool_confidence;
            condVar.notify_all();
        }
    }
}

void FaceDetec::send_mass_thread(){
    boost::asio::io_service io_service;
    boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::address::from_string(SERVER_IP),PORT_NUMBER);
    boost::system::error_code connect_error;
    boost::asio::ip::tcp::socket socket(io_service);
    socket.connect(endpoint, connect_error);
    
    if (connect_error) {
        std::cout << "error No: " << connect_error.value()<< "->" << connect_error.message() << std::endl;
        return;
    }
	bool flag = true;
    while(!exitFlag.load()){
        std::unique_lock<std::mutex> lock(mutex);
		condVar.wait(lock, []{ return true; });

        if(bool_confidence  && flag) {
            std::cout << "Detected " << std::endl;
            flag = false;
            std::string message = "myface";
            boost::system::error_code ignored_error;
            socket.write_some(boost::asio::buffer(message, message.size()), ignored_error);
            std::cout << "Sent Message: " << message << std::endl;
            sleep(3);
        } else if(!bool_confidence && !flag){
            std::cout <<"not Detected"<<std::endl;
            flag = true;
        }
    }
    socket.close();
}

void FaceDetec::show_window_thread(){
	cv::Mat standby = cv::imread("standby.png");
	bool changeWindow = false;
	cv::namedWindow("frame");
    cv::imshow("frame", standby);
    while (!exitFlag.load()) {
        if(cv::waitKey(1) == 27) break; 
        //std::unique_lock<std::mutex> lock(mutex);
		if(bool_confidence) {
			cv::imshow("frame", Queue_frame.front());
			Queue_frame.pop();
            //lock.unlock();
			changeWindow = false;
		}else if(!(bool_confidence || changeWindow)) {
			cv::imshow("frame", standby);
			changeWindow = true;
		}
    }
    cv::destroyAllWindows();
    exitFlag = true;
}
