#pragma once
#include<string>

// ע���࣬�����û�ע���߼�
class Register {
public:
    // ע�����û�
    // ������username���û�������password�����룩
    // ����ֵ��ע���Ƿ�ɹ�
    static bool addUser(const std::string& username, const std::string& password);
};
