#include "mysql.h"
#include <mysql_driver.h>
#include "config.h"
#include "tools/converter.h"

namespace chatroom
{
namespace detail
{
static sql::mysql::MySQL_Driver* driver;

MySql::MySql() {
    driver = sql::mysql::get_mysql_driver_instance();
    assert(driver);
    conn_ = driver->connect(kDbHostName, kDbUserName, kDbPassword);
    assert(conn_);
    conn_->setSchema(kDbCatalog);
    stmt_ = conn_->createStatement();
    assert(stmt_);
}

MySql::~MySql() {
    if (conn_) delete conn_;
    if (stmt_) delete stmt_;
}

auto MySql::Query(const sql::SQLString& sql) -> std::expected<std::unique_ptr<sql::ResultSet>, sql::SQLException>
{
    try
    {
        return std::unique_ptr<sql::ResultSet>(stmt_->executeQuery(sql));
    }
    catch(const sql::SQLException& e)
    {
        return std::unexpected(e);
    }
}
auto MySql::Update(const sql::SQLString& sql) -> std::expected<int, sql::SQLException>
{
    try
    {
        return stmt_->executeUpdate(sql);
    }
    catch(const sql::SQLException& e)
    {
        return std::unexpected(std::move(e));
    }
}
}

int64_t MySqlUtil::GetLastInsertId() {
    auto exp = Query("SELECT LAST_INSERT_ID()");
    return exp.has_value() ?  exp.value()->next(), exp.value()->getInt64(1) : 0;
}

std::string MySqlUtil::ToString(const std::chrono::system_clock::time_point& tp) {
    return Converter::ToString(tp, "%Y-%m-%d %H:%M:%S");
}

std::chrono::system_clock::time_point MySqlUtil::StringToTimepoint(std::string_view str) {
    return Converter::ToTimepoint(str, "%Y-%m-%d %H:%M:%S");
}
}