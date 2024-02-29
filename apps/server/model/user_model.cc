#include "user_model.h"
#include "tools/mysql.h"

namespace chatroom {
namespace model {
int InsertUser(const User& user) {
    auto res = mysql::Update(
        "INSERT INTO `User`(name,password,register_time,state) VALUES('{}','{}','{}',{})",
        user.name(), user.password(), mysql::ToString(user.register_time()), user.state());
    assert(res);
    return mysql::GetLastInsertId();
}

User QueryUser(int account) {
    auto res = mysql::Query("SELECT * FROM User WHERE account = {}", account);
    res->next();
    const auto name = res->getString("name");
    const auto pwd = res->getString("password");
    const auto register_time = res->getString("register_time");
    const auto state = static_cast<UserState>(res->getInt("state"));
    User user;
    user.set_account(account);
    user.set_name(name.asStdString());
    user.set_password(pwd.asStdString());
    user.set_register_time(mysql::StringToTimepoint(register_time.asStdString()));
    user.set_state(state);
    return user;
}

void UpdateUser(const User& user) {
    auto res = mysql::Update(
        "UPDATE `User` SET register_time='{}',name='{}',password='{}',state={} WHERE `account`={}",
        mysql::ToString(user.register_time()), user.name(), user.password(), user.state(), user.account());
    assert(res);
}

void UpdateUserState(int account, UserState state) {
    auto res = mysql::Update("UPDATE `User` SET state={} WHERE `account`={}", state, account);
    assert(res);
}

void RemoveUser(std::initializer_list<int> accounts) {
    auto res = mysql::Update("DELETE FROM `User` WHERE `account` IN ({:`, `<>})", accounts);
    assert(res);
}
}   // namespace model
}   // namespace chatroom