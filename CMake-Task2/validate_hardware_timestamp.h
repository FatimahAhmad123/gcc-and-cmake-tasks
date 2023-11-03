#ifndef VALIDATE_HARDWARE_TIMESTAMP
#define VALIDATE_HARDWARE_TIMESTAMP

//#ifdef CHECK_LICENSE

//#include "rakurai_logger.h"

#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
//#include <rapidjson/document.h>
#include <string>

namespace beast = boost::beast;
namespace http  = beast::http;
namespace net   = boost::asio;
using tcp       = net::ip::tcp;

namespace rakurai {
namespace connector {
   class validate_hardware_timestamp
   {
    public:
      validate_hardware_timestamp(const std::string &host, const std::string &target, const std::string &logger_name,
                                  const std::string &port = "80");
      std::string do_request();
      bool        is_system_time_correct();
     std::string      get_unixtime();

    private:
      net::io_context                    ioc;
      tcp::resolver                      resolver;
      beast::tcp_stream                  stream;
      http::request<http::string_body>   req;
  //    std::shared_ptr<spdlog::logger>    _rakurai_logger;
      beast::flat_buffer                 buffer;
      http::response<http::dynamic_body> res;
      double                             world_clock_time;
      double                             current_system_time;
      std::string                        curl_command;
   };
}  // namespace connector
}  // namespace rakurai

//#endif
#endif
