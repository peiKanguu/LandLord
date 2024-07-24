#include "SettingGUI.h"
#include "AccountGUI.h"

int bgmVolume = 50; // 背景音乐音量
int sfxVolume = 50; // 游戏音效音量

// 加载音量设置
void loadVolumeSettings() {
    std::wifstream inFile(L"volume_settings.txt");
    if (inFile) {
        inFile >> bgmVolume >> sfxVolume;
    }
}

// 保存音量设置
void applyVolumeSettings() {
    std::wstring command = L"setaudio bgm volume to " + std::to_wstring(bgmVolume * 10);
    mciSendString(command.c_str(), nullptr, 0, nullptr);

    // std::wstring sfxCommand = L"setaudio sfx volume to " + std::to_wstring(sfxVolume * 10);
    // mciSendString(sfxCommand.c_str(), nullptr, 0, nullptr);
}

void returnToMainMenu() {
    // 在这里实现返回主菜单的逻辑
    MessageBox(GetHWnd(), L"返回主菜单", L"提示", MB_OK);
}

void showMainMenu(std::function<void()> onSettingsButtonClick, std::function<void()> onAccountButtonClick) {
    cleardevice();
    setbkcolor(WHITE);
    cleardevice();

    settextcolor(BLACK);
    settextstyle(30, 0, _T("Arial"));
    outtextxy(540, 300, _T("主菜单"));

    // 绘制设置按钮
    setfillcolor(LIGHTGRAY);
    solidrectangle(540, 400, 740, 450);
    settextstyle(20, 0, _T("Arial"));
    settextcolor(BLACK);
    outtextxy(580, 415, _T("设置"));

    // 绘制账户按钮
    solidrectangle(540, 460, 740, 510);
    outtextxy(580, 475, _T("账户"));

    // 检查按钮点击
    while (true) {
        if (MouseHit()) {
            ExMessage msg = getmessage(EM_MOUSE);
            if (msg.message == WM_LBUTTONDOWN) {
                int mouseX = msg.x;
                int mouseY = msg.y;
                if (mouseX >= 540 && mouseX <= 740 && mouseY >= 400 && mouseY <= 450) {
                    onSettingsButtonClick();
                    break;
                }
                if (mouseX >= 540 && mouseX <= 740 && mouseY >= 460 && mouseY <= 510) {
                    onAccountButtonClick();
                    break;
                }
            }
        }
    }
}

int main() {
    // 加载音量设置
    loadVolumeSettings();

    // 初始化图形界面
    initgraph(1280, 720); // 创建一个 1280x720 的窗口
    SetWindowText(GetHWnd(), L"主菜单测试");

    // 自动播放背景音乐
    std::wstring bgmFilePath = L"C:\\CODE\\LandLords\\Landlords\\background.mp3";
    std::wstring command = L"open \"" + bgmFilePath + L"\" type mpegvideo alias bgm";
    mciSendString(command.c_str(), nullptr, 0, nullptr);
    mciSendString(L"play bgm repeat", nullptr, 0, nullptr);

    // 应用加载的音量设置
    applyVolumeSettings();

    auto mainMenu = [&]() {
        showMainMenu([&]() {
            // 创建 SettingGUI 对象
            SettingGUI settingGUI(returnToMainMenu);

            // 显示设置界面
            settingGUI.show();

            // 处理设置界面的用户输入
            ExMessage msg;
            while (true) {
                if (peekmessage(&msg, EM_MOUSE)) {
                    switch (msg.message) {
                    case WM_LBUTTONDOWN:
                        settingGUI.handleMouseClick(msg.x, msg.y);
                        break;
                    case WM_MOUSEMOVE:
                        settingGUI.handleMouseMove(msg.x, msg.y);
                        break;
                    case WM_LBUTTONUP:
                        settingGUI.handleMouseRelease(msg.x, msg.y);
                        break;
                    }
                }
            }
            }, [&]() {
                // 创建 AccountGUI 对象
                AccountGUI accountGUI(returnToMainMenu);

                // 显示账户界面
                accountGUI.show();

                // 处理账户界面的用户输入
                ExMessage msg;
                while (true) {
                    if (peekmessage(&msg, EM_MOUSE)) {
                        switch (msg.message) {
                        case WM_LBUTTONDOWN:
                            accountGUI.handleMouseClick(msg.x, msg.y);
                            break;
                        }
                    }
                }
                });
        };

    while (true) {
        mainMenu();
    }

    // 关闭图形界面
    closegraph();
    return 0;
}
