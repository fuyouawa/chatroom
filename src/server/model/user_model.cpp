#include "user_model.h"
#include "utils/mysql.h"
#include "tools/logger.h"

namespace chatroom
{
std::optional<uint> UserModel::Insert(const User& user) {
    if (MySqlUtil::Update(
        "INSERT INTO User(name, password, state, register_time) VALUES({}, {}, {}, {})",
        user.name(), user.password(), user.state(), MySqlUtil::ToString(user.register_time())))
    {
        return MySqlUtil::GetLastInsertId();
    }
    else return std::nullopt;
}

std::optional<User> UserModel::Query(uint account) {
    auto res = MySqlUtil::Query("SELECT * FROM User WHERE account = {:u}", account);
    if (!res)
        return std::nullopt;

    res->next();

    try
    {
        auto name = res->getString("name");
        auto pwd = res->getString("password");
        auto register_time = res->getString("register_time");
        auto state = res->getInt("state");

        User user;
        user.set_account(account);
        user.set_name(name.asStdString());
        user.set_password(pwd.asStdString());
        user.set_register_time(MySqlUtil::TimepointCast(register_time.asStdString()));
        user.set_state(state);
        return user;
    }
    catch(const std::exception& e)
    {
        CHATROOM_LOG_ERROR("error occur in UserModel::Query({}): {}", account, e.what());
    }
    return std::nullopt;
}
}