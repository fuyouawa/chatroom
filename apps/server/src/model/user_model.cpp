#include "user_model.h"
#include "tools/logger.h"
#include "tools/sql_engine.h"

namespace chatroom
{
auto UserModel::Insert(const User& user) -> std::expected<uint, sql::SQLException>
{
    try
    {
        auto exp = SQLEngine::Update(
            "INSERT INTO `User`(name,password,register_time,state) VALUES('{}','{}','{}',{})",
            user.name(), user.password(), SQLEngine::ToString(user.register_time()), user.state());

        if (exp.has_value())
            return SQLEngine::GetLastInsertId();
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
    auto exp = SQLEngine::Query("SELECT * FROM User WHERE account = {}", account);
    if (!exp.has_value())
        return std::unexpected(exp.error());
    auto res = std::move(exp.value());
    
    try
    {
        res->next();
        auto name = res->getString("name");
        auto pwd = res->getString("password");
        auto register_time = res->getString("register_time");
        auto state = static_cast<UserState>(res->getInt("state"));
        User user;
        user.set_account(account);
        user.set_name(name.asStdString());
        user.set_password(pwd.asStdString());
        user.set_register_time(SQLEngine::StringToTimepoint(register_time.asStdString()));
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
    auto exp = SQLEngine::Update(
        "UPDATE `User` SET register_time='{}',name='{}',password='{}',state={} WHERE `account`={}",
        SQLEngine::ToString(user.register_time()), user.name(), user.password(), user.state(), user.account());
    if (exp.has_value())
        return std::nullopt;
    else
        return std::move(exp.error());
}

auto UserModel::UpdateState(uint account, UserState state) -> std::optional<sql::SQLException>
{
    auto exp = SQLEngine::Update("UPDATE `User` SET state={} WHERE `account`={}", state, account);
    if (exp.has_value())
        return std::nullopt;
    else
        return std::move(exp.error());
}

auto UserModel::Remove(std::initializer_list<uint> accounts) -> std::optional<sql::SQLException>
{
    auto exp = SQLEngine::Update("DELETE FROM `User` WHERE `account` IN ({:`, `<>})", accounts);
    if (exp.has_value())
        return std::nullopt;
    else
        return std::move(exp.error());
}
}