#include "subscriber.h"

bool Subscriber::tryConnect()
{
    try{
        mqtt::connect_options options;
        options.set_keep_alive_interval(20);

        options.set_clean_session(true);
        client.connect(options)->wait();
        client.subscribe("#",1)->wait();
        inConnection = true;
        return true;
    }catch(mqtt::exception& e) {
        cerr << "Error " << e.what() << endl;
        inConnection = false;
        return false;
    }
}

void Subscriber::on_failure(const mqtt::token &token)
{
     std::cerr << "Failture " << std::endl;
     inConnection = false;
}

void Subscriber::on_success(const mqtt::token &token)
{
    std::cout << "Sended" << std::endl;
}

void Subscriber::connected(const string &cause)
{
    std::cout << "Connected" << std::endl;
    inConnection = true;
}

void Subscriber::connection_lost(const string &cause)
{
    std::cerr << "Connection lost" << std::endl;
    inConnection = false;
}

void Subscriber::message_arrived(mqtt::const_message_ptr msg)
{
     try {
    if (db.connected){
      db.insertCountry(Parser::getCountry(msg->get_payload_str()));
    }
    else
       cerr << "Database status is not connected" << endl;
  } catch (std::exception &e) {
    cerr << e.what() << endl;
  }
}

