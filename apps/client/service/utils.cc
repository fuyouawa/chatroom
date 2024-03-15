#include "tools/console.h"
#include "service/utils.h"

namespace chatroom {
void TipBack() {
    console::Print("(按下任意键回退上一级)\n");
    console::InputKey();
}
void TipRetry() {
    console::Print("(按下任意键重新操作)\n");
    console::InputKey();
}
void TipContinue() {
    console::Print("(按下任意键继续)\n");
    console::InputKey();
}
}