#include <boost/asio.hpp>
#include <iostream>
 
#pragma warning (disable : 4996)
 
constexpr char SERVER_IP[] = "127.0.0.1";
constexpr unsigned short PORT_NUMBER = 9999;
 
int main() {
    boost::asio::io_service io_service;
    boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::address::from_string(SERVER_IP),PORT_NUMBER);
 
    boost::system::error_code connect_error;
    boost::asio::ip::tcp::socket socket(io_service);
    socket.connect(endpoint, connect_error);
 
    if (connect_error) {
        std::cout << "error No: " << connect_error.value()<< "->" << connect_error.message() << std::endl;
    }
    
    while (1) 
    {
        std::string message;
        std::cin >> message;

        boost::system::error_code ignored_error;
        socket.write_some(boost::asio::buffer(message, message.size()), ignored_error);
 
        std::cout << "Sent Message: " << message << std::endl;
 
        boost::system::error_code error;
        size_t len = socket.read_some(boost::asio::buffer(message), error);
 
        if (error) {
            if (error == boost::asio::error::eof) std::cout << "Connection cut off" << std::endl;
            else std::cout << "error No: " << error.value() << "->"<< error.message().c_str() << std::endl;
            break;
        }
        
        std::cout << "Server Message: " << message << std::endl;
    }
   

    socket.close();
    getchar();
    return 0;
}
