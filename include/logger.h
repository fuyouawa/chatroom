#include <iostream>
#include <vector>
#include <format>
#include <boost/system/error_code.hpp>

namespace chatroom
{
class Logger
{
public:
    enum Level {
        kInfo,
        kDebug,
        kWarning,
        kError,
        kFatal
    };

    static void set_ostream(Level lv, std::ostream& outer);

    Logger(Level lv, std::string_view description);
    Logger(Level lv, std::string_view description, std::string_view filename, std::string_view func_name, size_t line);
    Logger(Level lv, std::string_view description, const boost::system::error_code& ec);
    Logger(Level lv, std::string_view description, const std::exception& ex);

    void Print();


private:
    static inline std::vector<std::tuple<std::string_view, std::ostream*>> out_manager_ = {
        {"Info", &std::cout},
        {"Debug", &std::clog},
        {"Warning", &std::cout},
        {"Error", &std::cerr},
        {"Fatal", &std::cerr}
    };

    std::string message_;
    Level lv_;
};


}