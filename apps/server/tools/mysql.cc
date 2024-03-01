#include "tools/mysql.h"
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
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
}   // namespace sql
}   // namespace chatroom