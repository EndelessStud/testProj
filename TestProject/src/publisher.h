#ifndef PUBLISHER_H
#define PUBLISHER_H

#include <string>
#include <iostream>

#include <boost/beast.hpp>

#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/io_service.hpp>

#include <boost/bind.hpp> //TODO изменить на нужные

#include <boost/thread.hpp> //TODO изменить на нужные

#include <mqtt/async_client.h>//TODO изменить на нужныеt

using namespace std;

class Publisher
{
public:
    Publisher();
    void startThread();
    static string getResponse(string ip);
    bool sendToBroker(string json);
private:
    boost::asio::io_context io_context;

    const string MQTT_SERVER_ADDR = "tcp://127.0.0.1:8884";
    const string CLIENT_ID = "publisher";
    const string TOPIC = "topic1";

};


#endif // PUBLISHER_H
