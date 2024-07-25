#include "SettingGUI.h"
#include "AccountGUI.h"

int bgmVolume = 50; // ������������
int sfxVolume = 50; // ��Ϸ��Ч����

// ������������
void loadVolumeSettings() {
    std::wifstream inFile(L"volume_settings.txt");
    if (inFile) {
        inFile >> bgmVolume >> sfxVolume;
    }
}

// ������������
void applyVolumeSettings() {
    std::wstring command = L"setaudio bgm volume to " + std::to_wstring(bgmVolume * 10);
    mciSendString(command.c_str(), nullptr, 0, nullptr);

    // std::wstring sfxCommand = L"setaudio sfx volume to " + std::to_wstring(sfxVolume * 10);
    // mciSendString(sfxCommand.c_str(), nullptr, 0, nullptr);
}

void returnToMainMenu() {
    // ������ʵ�ַ������˵����߼�
    MessageBox(GetHWnd(), L"�������˵�", L"��ʾ", MB_OK);
}

void showMainMenu(std::function<void()> onSettingsButtonClick, std::function<void()> onAccountButtonClick) {
    cleardevice();
    setbkcolor(WHITE);
    cleardevice();

    settextcolor(BLACK);
    settextstyle(30, 0, _T("Arial"));
    outtextxy(540, 300, _T("���˵�"));

    // �������ð�ť
    setfillcolor(LIGHTGRAY);
    solidrectangle(540, 400, 740, 450);
    settextstyle(20, 0, _T("Arial"));
    settextcolor(BLACK);
    outtextxy(580, 415, _T("����"));

    // �����˻���ť
    solidrectangle(540, 460, 740, 510);
    outtextxy(580, 475, _T("�˻�"));

    // ��鰴ť���
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
    // ������������
    loadVolumeSettings();

    // ��ʼ��ͼ�ν���
    initgraph(1280, 720); // ����һ�� 1280x720 �Ĵ���
    SetWindowText(GetHWnd(), L"���˵�����");

    // �Զ����ű�������
    std::wstring bgmFilePath = L"C:\\CODE\\LandLords\\Landlords\\background.mp3";
    std::wstring command = L"open \"" + bgmFilePath + L"\" type mpegvideo alias bgm";
    mciSendString(command.c_str(), nullptr, 0, nullptr);
    mciSendString(L"play bgm repeat", nullptr, 0, nullptr);

    // Ӧ�ü��ص���������
    applyVolumeSettings();

    auto mainMenu = [&]() {
        showMainMenu([&]() {
            // ���� SettingGUI ����
            SettingGUI settingGUI(returnToMainMenu);

            // ��ʾ���ý���
            settingGUI.show();

            // �������ý�����û�����
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
                // ���� AccountGUI ����
                AccountGUI accountGUI(returnToMainMenu);

                // ��ʾ�˻�����
                accountGUI.show();

                // �����˻�������û�����
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

    // �ر�ͼ�ν���
    closegraph();
    return 0;
}
