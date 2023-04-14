#include "../inc/common.h"

int main() {
  
  mqtt::client client(S_BROKER_ADDRESS, S_CLIENT_ID_PUB);

  mqtt::connect_options options;
  options.set_keep_alive_interval(20);
  options.set_clean_session(true);

  try {
    client.connect(options);
    mqtt::message_ptr message_ptr = mqtt::make_message(S_TOPIC, "MMMMM, le caca c'est déclicieux");
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