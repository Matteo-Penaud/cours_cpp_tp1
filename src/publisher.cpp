#include "../inc/common.h"

const string S_MESSAGE_CONTENT("Mattéo, depuis c++");

int main() {
  
  mqtt::client client(S_BROKER_ADDRESS, S_CLIENT_ID_PUB);

  mqtt::connect_options options;
  options.set_keep_alive_interval(20);
  options.set_clean_session(true);

  try {
    client.connect(options);
    cout << "Sending the message : " << S_MESSAGE_CONTENT << endl;
    mqtt::message_ptr message_ptr = mqtt::make_message(S_TOPIC, S_MESSAGE_CONTENT);
    message_ptr->set_qos(0);
    client.publish(message_ptr);
    client.disconnect();
  }
  catch (const mqtt::exception& except) {
    cerr << except.what() << endl;
    return 1;
  }

  return 0;
}