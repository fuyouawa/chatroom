#pragma once
#include "base/basic.h"
#include "tools/format.h"
#include <mysql_connection.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <chrono>

namespace chatroom
{
namespace detail
{
class MySql : public Singleton<MySql>
{
public:
    ~MySql();
    
    std::unique_ptr<sql::ResultSet> Query(const sql::SQLString& sql);
    int Update(const sql::SQLString& sql);

private:
    friend Singleton<MySql>;
    MySql();

    sql::Connection* conn_;
    sql::Statement* stmt_;
};
}

class MySqlUtil
{
public:
    template<typename... Args>
    static std::unique_ptr<sql::ResultSet> Query(std::string_view sql_fmt, Args&&... args) {
        auto sql = FormatString(sql_fmt, std::forward<Args>(args)...);
        return detail::MySql::instance().Query(sql);
    }

    template<typename... Args>
    static int Update(std::string_view sql_fmt, Args&&... args) {
        auto sql = FormatString(sql_fmt, std::forward<Args>(args)...);
        return detail::MySql::instance().Update(sql);
    }

    static int GetLastInsertId();

    static std::string ToString(const std::chrono::system_clock::time_point& tp);
    static std::chrono::system_clock::time_point StringToTimepoint(std::string_view str);
};
}