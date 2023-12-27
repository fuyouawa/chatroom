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

std::unique_ptr<sql::ResultSet> MySql::Query(const sql::SQLString& sql) {
    return std::unique_ptr<sql::ResultSet>(stmt_->executeQuery(sql));
}

int MySql::Update(const sql::SQLString& sql) {
    return stmt_->executeUpdate(sql);
}
}

int MySqlUtil::GetLastInsertId() {
    return Query("SELECT LAST_INSERT_ID()")->getInt(1);
}

std::string MySqlUtil::ToString(const std::chrono::system_clock::time_point& tp) {
    return Converter::ToString(tp, "%Y-%m-%d %H:%M:%S");
}

std::chrono::system_clock::time_point MySqlUtil::StringToTimepoint(std::string_view str) {
    return Converter::StringToTimepoint(str, "%Y-%m-%d %H:%M:%S");
}
}