#pragma once
#include <cppconn/resultset.h>
#include <chrono>
#include "common/core/singleton.h"
#include "common/tools/format.h"

namespace chatroom {
namespace mysql {
namespace detail {
class MySQL : public Singleton<MySQL>
{
public:
    ~MySQL();
    
    std::unique_ptr<sql::ResultSet> Query(const sql::SQLString& sql);
    int Update(const sql::SQLString& sql);

private:
    friend Singleton<MySQL>;
    MySQL();
};
}

template<typename... Args>
auto Query(std::string_view sql_fmt, Args&&... args) {
    auto sql = FormatString(sql_fmt, std::forward<Args>(args)...);
    return detail::MySQL::instance().Query(sql);
}

template<typename... Args>
auto Update(std::string_view sql_fmt, Args&&... args) {
    auto sql = FormatString(sql_fmt, std::forward<Args>(args)...);
    return detail::MySQL::instance().Update(sql);
}

int64_t GetLastInsertId();

std::string ToString(const std::chrono::system_clock::time_point& tp);
std::chrono::system_clock::time_point StringToTimepoint(std::string_view str);
}
}