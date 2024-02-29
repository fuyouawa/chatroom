#include "mysql.h"
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include "common/tools/converter.h"
#include "common/core/config.h"

namespace chatroom {
namespace mysql {
namespace internal {
namespace {
sql::mysql::MySQL_Driver* driver;
sql::Connection* conn;
sql::Statement* stmt;
}   // namespace


MySQL::MySQL() {
    driver = sql::mysql::get_mysql_driver_instance();
    assert(driver);
    conn = driver->connect(kDbHostName, kDbUserName, kDbPassword);
    assert(conn);
    conn->setSchema(kDbCatalog);
    stmt = conn->createStatement();
    assert(stmt);
}

MySQL::~MySQL() {
    if (conn) delete conn;
    if (stmt) delete stmt;
}

std::unique_ptr<sql::ResultSet> MySQL::Query(const sql::SQLString& sql)
{
    return std::unique_ptr<sql::ResultSet>{stmt->executeQuery(sql)};
}
int MySQL::Update(const sql::SQLString& sql)
{
    return stmt->executeUpdate(sql);
}
}   // namepace internal

int64_t GetLastInsertId() {
    auto res = Query("SELECT LAST_INSERT_ID()");
    return res->next(), res->getInt64(1);
}

std::string ToString(const std::chrono::system_clock::time_point& tp) {
    return converter::ToString(tp, "%Y-%m-%d %H:%M:%S");
}

std::chrono::system_clock::time_point StringToTimepoint(std::string_view str) {
    return converter::ToTimepoint(str, "%Y-%m-%d %H:%M:%S");
}
}   // namespace sql
}   // namespace chatroom