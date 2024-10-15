#include <boost/asio.hpp>
#include <iostream>

#define IPADDRESS "192.168.1.12"
#define UDP_PORT 13251

using boost::asio::ip::udp;
using boost::asio::ip::address;


void Sender(std::string msg) {
 

    boost::system::error_code err;
    boost::asio::io_service io_service;
    udp::socket socket(io_service);
    udp::endpoint remote_endpoint = udp::endpoint(address::from_string(IPADDRESS), UDP_PORT);

    socket.open(udp::v4());
    auto sent = socket.send_to(boost::asio::buffer(msg), remote_endpoint, 0, err);
    socket.close();
    //std::cout << "Sent Payload --- " << sent << "\n";
}

int main(int argc, char *argv[])
{
    std::string input = argc>1? argv[1] : "hello world";

    for(;;){
        Sender(input);
    }
}