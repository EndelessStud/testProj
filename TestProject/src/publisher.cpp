#include "publisher.h"

namespace http = boost::beast::http;

Publisher::Publisher() {}

void Publisher::startThread()
{

}

string Publisher::getResponse(string ip) {
  boost::asio::io_context io;
  boost::asio::ip::tcp::resolver resolver(io);
  boost::asio::ip::tcp::socket socket(io);
  const string API  = "ip-api.com";
  const string API_ARG = "/json/";
  boost::asio::connect(socket, resolver.resolve(API, "80"));
  string arguments = API_ARG + ip;
  http::request<http::string_body> req(http::verb::get, arguments, 11);

  req.set(http::field::host, API);
  req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

  http::write(socket,req);

  string response;
  {
    boost::beast::flat_buffer buffer;
    http::response<http::dynamic_body> res;
    http::read(socket,buffer,res);
    response = boost::beast::buffers_to_string(res.body().data());
  }

  socket.shutdown(boost::asio::ip::tcp::socket::shutdown_both);
 ;
  return response;
}

bool Publisher::sendToBroker(string json)
{
    boost::asio::io_service io_service;
    mqtt::async_client client(MQTT_SERVER_ADDR,CLIENT_ID);
    mqtt::connect_options options;
    options.set_keep_alive_interval(20);
    options.set_clean_session(true);

    try{
        client.connect(options)->wait();
        std::cout<< "Connected to broker" << std::endl;

        mqtt::message_ptr publisherMessage = mqtt::make_message(TOPIC,json);
        client.publish(publisherMessage);
        std::cout << "Message send to " << TOPIC << std::endl;

        client.disconnect()->wait();
        std::cout << "Disconnected from broker" << std::endl;
        return true;
    } catch(const mqtt::exception& exc) {
        std::cerr << "Error: " << exc.what() << std::endl;
        return false;
    }
}
