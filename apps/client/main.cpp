#include <imgui_ex/imgui_ex_win32.h>


void ImGuiInit() {
    ImGuiIO& io = ImGui::GetIO();
    ImGui::StyleColorsLight();
}
void ImGuiUpdate() {
    static ImGuiEx::Window message_window("Message##Window", false, false);
    static ImGuiEx::Text message_text("");
    static ImGuiEx::Window control_window("Control##Window", true);
    static ImGuiEx::Window capture_window("Capture##Window", true);
    static ImGuiEx::Window data_window("Data##Window", true);
    static ImGuiEx::Window filter_window("Filter##Window", true);

    message_window.Begin();

    message_window.InitEvent([]() {
        message_window.SetDocking(false);
        message_window.SetTop(true);
        message_window.SetCollapse(false);
        message_window.SetAlwaysAutoResize(true);
        });

    message_window.CreateEvent([]() {
        control_window.Disable();
        control_window.AddFlags(ImGuiWindowFlags_NoInputs);
        });

    message_window.CloseEvent([]() {
        control_window.Enable();
        control_window.UnaddFlags(ImGuiWindowFlags_NoInputs);
        });

    message_window.CreateUpdate([]() {
        message_text.Begin();
        message_text.End();
        static ImGuiEx::Button ok("Ok##Button");
        ok.Begin();
        ok.ClickEvent([]() {
            message_window.Close();
            });
        ok.End();
        });
    message_window.End();



    capture_window.Begin();
    capture_window.InitEvent([]() {
        data_window.SetCollapse(false);
        });

    capture_window.CreateUpdate([]() {
        ImGui::Text("Capture List");
        static ImGuiEx::ListBox<> capture_list("##Capture List");
        capture_list.Begin();
        capture_list.InsertUpdate([](std::string& ele) {
            return ele;
            });
        capture_list.End();

        });

    capture_window.End();



    data_window.Begin();
    data_window.InitEvent([]() {
        data_window.SetCollapse(false);
        });

    data_window.CreateUpdate([]() {
        ImGui::Text("Info");

        static ImGuiEx::InputTextMultiline mult_text("Info##InputTextMultiline");
        mult_text.InitEvent([]() {
            mult_text.SetReadOnly(true);
            });
        mult_text.Begin(); mult_text.End();
        });

    data_window.End();
}
void ImGuiExit() {

}