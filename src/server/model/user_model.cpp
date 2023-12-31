#include "user_model.h"
#include "utils/mysql.h"
#include "tools/logger.h"

namespace chatroom
{
auto UserModel::Insert(const User& user) -> std::expected<uint, sql::SQLException>
{
    try
    {
        auto exp = MySqlUtil::Update(
            "INSERT INTO `User`(name,password,register_time,state) VALUES('{}','{}','{}',{})",
            user.name(), user.password(), MySqlUtil::ToString(user.register_time()), user.state());

        if (exp.has_value())
            return MySqlUtil::GetLastInsertId();
        else
            return std::unexpected(std::move(exp.error()));
    }
    catch(const std::exception& e)
    {
        return std::unexpected(sql::SQLException{e.what()});
    }
}

auto UserModel::Query(uint account) -> std::expected<User, sql::SQLException>
{
    auto exp = MySqlUtil::Query("SELECT * FROM User WHERE account = {:u}", account);
    if (!exp.has_value())
        return std::unexpected(exp.error());
    auto res = std::move(exp.value());
    
    try
    {
        res->next();
        auto name = res->getString("name");
        auto pwd = res->getString("password");
        auto register_time = res->getString("register_time");
        auto state = res->getInt("state");

        User user;
        user.set_account(account);
        user.set_name(name.asStdString());
        user.set_password(pwd.asStdString());
        user.set_register_time(MySqlUtil::StringToTimepoint(register_time.asStdString()));
        user.set_state(state);
        return user;
    }
    catch(const std::exception& e)
    {
        return std::unexpected(sql::SQLException{e.what()});
    }
}

auto UserModel::Update(const User& user) -> std::optional<sql::SQLException>
{
    auto exp = MySqlUtil::Update(
        "UPDATE `User` SET register_time='{}',name='{}',password='{}',state={} WHERE `account`={}",
        MySqlUtil::ToString(user.register_time()), user.name(), user.password(), user.state(), user.account());
    if (exp.has_value())
        return std::nullopt;
    else
        return std::move(exp.error());
}

auto UserModel::Remove(std::initializer_list<uint> accounts) -> std::optional<sql::SQLException>
{
    auto exp = MySqlUtil::Update("DELETE FROM `User` WHERE `account` IN ({:`, `<>})", accounts);
    if (exp.has_value())
        return std::nullopt;
    else
        return std::move(exp.error());
}
}