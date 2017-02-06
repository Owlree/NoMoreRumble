#include <iostream>

#include <Windows.h>
#include <xinput.h>

#pragma comment(lib, "XInput.lib")

int main() {

    int cnt = 0;

    DWORD dwResult;
    for (DWORD i = 0; i < XUSER_MAX_COUNT; i++) {
        XINPUT_STATE state;
        ZeroMemory(&state, sizeof(XINPUT_STATE));
        dwResult = XInputGetState(i, &state);

        if (dwResult == ERROR_SUCCESS) {
            XINPUT_VIBRATION vibration;
            ZeroMemory(&vibration, sizeof(XINPUT_VIBRATION));
            vibration.wLeftMotorSpeed = 0;
            vibration.wRightMotorSpeed = 0;
            XInputSetState(i, &vibration);
            cnt += 1;
        }
    }

    std::cout << std::endl;

    if (cnt > 0) {
        std::cout << "Turned off rumble on " << cnt << " controller";
        if (cnt != 1) { std::cout << "s"; }
        std::cout << ".";
    } else {
        std::cout << "Didn't find any connected controllers.";
    }

    std::cout << std::endl;

    return 0;
}
