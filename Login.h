#pragma once
#include<string>

// ��¼�࣬�����û���¼�߼�
class Login {
public:
    // ��֤�û���¼
    // ������username���û�������password�����룩
    // ����ֵ����¼�Ƿ�ɹ�
    static bool authenticate(const std::string& username, const std::string& password);
};