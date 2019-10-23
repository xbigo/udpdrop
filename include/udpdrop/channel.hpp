#include <udpdrop/config.hpp>
#include <cstdint>
#include <string>
#include <vector>
#include <list>
#include <unordered_map>
#include <chrono>

namespace udpdrop {

    enum class channel_id_t : uint64_t {};

    using connection_id = std::uint64_t;    

    struct channel {

    };

    struct address{};
    using time_point = std::chrono::system_clock::time_point;
    using duration = std::chrono::system_clock::duration;

    struct endpoint {
        address addr;
        time_point last_receive_time, last_send_time;
    };

    struct remote_point{
        std::vector<endpoint> endpoints;

        void shrink_to(size_t capacity, duration d) ;    // remove aging remote
    };

    struct server_point {
        endpoint listen_port;
        std::unordered_map<connection_id, remote_point> remotes;

    };
}