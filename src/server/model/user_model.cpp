#include "user_model.h"
#include "utils/mysql.h"

namespace chatroom
{
std::optional<int> UserModel::Insert(const User& user) {
    if (MySqlUtil::Update(
        "INSERT INTO User(name, password, state, register_time) VALUES({}, {}, {}, {})",
        user.name(), user.password(), user.state(), MySqlUtil::ToString(user.register_time())))
    {
        return MySqlUtil::GetLastInsertId();
    }
    else return std::nullopt;
}

std::optional<User> UserModel::Query(int id) {
    auto res = MySqlUtil::Query("SELECT * FROM User WHERE id = {}", id);
    if (!res)
        return std::nullopt;

    User user;
    user.set_id(res->getInt("id"));
    user.set_name(res->getString("name").asStdString());
    user.set_password(res->getString("password").asStdString());
    user.set_register_time(MySqlUtil::StringToTimepoint(res->getString("register_time").asStdString()));
    user.set_state(res->getInt("state"));
    return user;
}
}