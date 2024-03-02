#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H



#include <iostream>
#include <string>

#include <boost/asio.hpp>//TODO изменить на нужные
#include <boost/bind.hpp>//TODO изменить на нужные
#include <boost/thread.hpp>//TODO изменить на нужные
#include <mqtt/async_client.h>//TODO изменить на нужные

#include <parser.h>
#include <database.h>

using namespace std;

const string MQTT_SERVER_ADDR = "tcp://127.0.0.1:8884";
const string CLIENT_ID = "subscriber";
const string TOPIC = "topic1";

class Subscriber:public virtual mqtt::callback, public virtual mqtt::iaction_listener
{
public:
    Subscriber(): client(MQTT_SERVER_ADDR,CLIENT_ID){
        client.set_callback(*this);
    }
    bool tryConnect();
    void on_failure(const mqtt::token &token) override;
    void on_success(const mqtt::token &token) override;
    void connected(const std::string &cause) override;
    void connection_lost(const std::string &cause) override;
    void message_arrived(mqtt::const_message_ptr msg) override;

    bool inConnection = 1;

private:
     mqtt::async_client client;
     Database db;
};

#endif // SUBSCRIBER_H
