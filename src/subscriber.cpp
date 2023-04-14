#include "../inc/common.h"

class MqttCallback : public virtual mqtt::callback
{
public :
    virtual void connection_lost(const std::string& s_cause)
    {
        cerr << "Connection lost : " << s_cause << "Exiting ..." << endl;
    }

    virtual void message_arrived(mqtt::const_message_ptr message_ptr)
    {
        if(message_ptr->get_qos() == 0)
        {
            if(message_ptr->get_topic() == S_TOPIC)
            {
                cout << "New message arrived : " << message_ptr->to_string() << endl;
            }
        }
    }

    virtual void delivery_complete(mqtt::delivery_token_ptr token_ptr)
    {
        cout << "Delivery  complete for token : " << token_ptr->get_message_id() << endl;
    }
};

int main()
{
    std::cout << "Starting app..." << std::endl;

    mqtt::client client(S_BROKER_ADDRESS, S_CLIENT_ID_SUB);

    mqtt::connect_options options;
    options.set_keep_alive_interval(20);
    options.set_clean_session(true);

    MqttCallback mqtt_callback;
    client.set_callback(mqtt_callback);

    try {
        client.connect(options);
        client.subscribe(S_TOPIC, 0);

        while (true) {}

        client.disconnect();
    }
    catch (const mqtt::exception& except) {
        cerr << except.what() << endl;
        return 1;
    }

    return 0;
}