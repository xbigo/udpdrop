# UdpDrop design

---

## Concepts

- Address
    Either IPv4 or IPv6 address.

- Port
    UDP port

- Endpoint
    Pair of address and port

- Channel
    A pair of UDP source and destination endpoints, indicate a virtual UDP communication pair. A Channel has a channel id.

- Slave
    A service instance of UDP communication. A slave can be identified by slave id. A slave can hold many channels, and channel id is unique in a slave scope. A pair of slave id and channel id can identify a unique channel in glob scope.

- Session
    A logic communication link, it consists of multiple channels, and those channels can be hold by multiple slaves.

- Master
    Manage slaves and sessions.

## Protocol

1. Package
    |order|offset|name|type|description|
    |:-----|:-----|:---|:----------|:----------|
    |1|0|sid|u2|Session id|
    |2|2|Reserved|u2|default is 1. if both field 1 & 2 are 0, means connect|
    |3|4|payload|raw|Encrypted data, to the end of current package. For connecting, encrypt via pre-shared key|

2. Connect Request payload

    The payload should be encrypted by preshared server key.
    |order|offset|name|type|description|
    |:-----|:-----|:---|:----------|:----------|
    |1|0|uname|tiny_array|User name|
    |2|len(uname) + 1|s_uname|tiny_array|Encrypted user name, with user key|
    |3|off_end(2)|ticket|u8|random ticket|

3. Connect Response ayload

    Field sid and Reserved must be 0 for connect response. The payload, except ticket should be encrypted by user key.
    |order|offset|name|type|description|
    |:-----|:-----|:---|:----------|:----------|
    |1|0|ticket|u8|random ticket, sent by previous connect request|
    |2|8|sid|u2|New session id, not 0|
    |3|endof(4)|skey|u32|Session Key for AES 256|
    |4|10|cend|tiny_array|List of control endpoints|
    |5|endof(3)|dend|tiny_array|List of data endpoints|
