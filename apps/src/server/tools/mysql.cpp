#include "tools/sql_engine.h"
#include <mysql_driver.h>
#include "public/tools/converter.h"
#include "public/core/config.h"

namespace chatroom
{
namespace detail
{
static sql::mysql::MySQL_Driver* driver;

MySQL::MySQL() {
    driver = sql::mysql::get_mysql_driver_instance();
    assert(driver);
    conn_ = driver->connect(kDbHostName, kDbUserName, kDbPassword);
    assert(conn_);
    conn_->setSchema(kDbCatalog);
    stmt_ = conn_->createStatement();
    assert(stmt_);
}

MySQL::~MySQL() {
    if (conn_) delete conn_;
    if (stmt_) delete stmt_;
}

auto MySQL::Query(const sql::SQLString& sql) -> std::expected<std::unique_ptr<sql::ResultSet>, sql::SQLException>
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
auto MySQL::Update(const sql::SQLString& sql) -> std::expected<int, sql::SQLException>
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

int64_t SQLEngine::GetLastInsertId() {
    auto exp = Query("SELECT LAST_INSERT_ID()");
    return exp.has_value() ?  exp.value()->next(), exp.value()->getInt64(1) : 0;
}

std::string SQLEngine::ToString(const std::chrono::system_clock::time_point& tp) {
    return Converter::ToString(tp, "%Y-%m-%d %H:%M:%S");
}

std::chrono::system_clock::time_point SQLEngine::StringToTimepoint(std::string_view str) {
    return Converter::ToTimepoint(str, "%Y-%m-%d %H:%M:%S");
}
}