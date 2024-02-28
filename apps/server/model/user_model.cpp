#include "user_model.h"
#include "tools/mysql.h"

namespace chatroom
{
uint UserModel::Insert(const User& user)
{
    mysql::Update(
        "INSERT INTO `User`(name,password,register_time,state) VALUES('{}','{}','{}',{})",
        user.name(), user.password(), mysql::ToString(user.register_time()), user.state());

    return mysql::GetLastInsertId();
}

User UserModel::Query(uint account)
{
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

void UserModel::Update(const User& user)
{
    mysql::Update(
        "UPDATE `User` SET register_time='{}',name='{}',password='{}',state={} WHERE `account`={}",
        mysql::ToString(user.register_time()), user.name(), user.password(), user.state(), user.account());
}

void UserModel::UpdateState(uint account, UserState state)
{
    mysql::Update("UPDATE `User` SET state={} WHERE `account`={}", state, account);
}

void UserModel::Remove(std::initializer_list<uint> accounts)
{
    mysql::Update("DELETE FROM `User` WHERE `account` IN ({:`, `<>})", accounts);
}
}