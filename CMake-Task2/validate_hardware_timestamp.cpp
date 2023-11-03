
//#ifdef CHECK_LICENSE
#include "validate_hardware_timestamp.h"

#include <iostream>

using tcp = net::ip::tcp;

rakurai::connector::validate_hardware_timestamp::validate_hardware_timestamp(const std::string &host,
                                                                             const std::string &target,
                                                                             const std::string &logger_name,
                                                                             const std::string &port)
   : resolver(ioc)
   , stream(ioc)
   , req(http::verb::get, target, 11)
//   , _rakurai_logger(spdlog::get(logger_name))
{
   req.set(http::field::host, host);
   req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

   auto const results = resolver.resolve(host, port);
   stream.connect(results);
}

std::string rakurai::connector::validate_hardware_timestamp::do_request()
{
   http::write(stream, req);
   http::read(stream, buffer, res);
   return beast::buffers_to_string(res.body().data());
}

bool rakurai::connector::validate_hardware_timestamp::is_system_time_correct()
{
   world_clock_time = 12111; //get_unixtime();
   current_system_time =
      std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
   if (std::abs(world_clock_time - current_system_time) <= 18000)
   {
     // LOG_TRACE(_rakurai_logger, "The time difference is less than 5 hours.");
      return true;
   }
   else
   {
    //  LOG_ERROR(_rakurai_logger, "The time difference is greater than 5 hours.");
      return false;
   }
}

std::string rakurai::connector::validate_hardware_timestamp::get_unixtime()
{
   std::string         json_response = do_request();
return json_response;
}
//#endif
