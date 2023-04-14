#include <iostream>
#include <mqtt/client.h>

using namespace std;

const string S_BROKER_ADDRESS("tcp://broker.emqx.io:1883");
const string S_CLIENT_ID_SUB("matteo_penaud_sub");
const string S_CLIENT_ID_PUB("matteo_penaud_pub");

const string S_TOPIC("/ynov/bordeaux/");