#include <iostream>
#include "ClientOperation.h"

using namespace std;
//显示菜单
int showMenu(void) {
    int choice;
    cout << "=============================" << endl;
    cout << "========1. 密钥协商 ==========" << endl;
    cout << "========2. 密钥校验 ==========" << endl;
    cout << "========3. 密钥注销 ==========" << endl;
    cout << "========4. 密钥查看 ==========" << endl;
    cout << "========5. 退出系统 ==========" << endl;
    cout << "=============================" << endl;
    cout << "请选择： ";
    cin >> choice;
    //清空输入缓冲区
    //cin.clear();
    while ('\n' != getchar())
        /*do nothing*/;
    return choice;
}
int main1(){
    int ret = -1;
    ClientInfo info;
    memset(&info, 0, sizeof(info));
    strcpy(info.clientId, "0012");
    strcpy(info.serverId, "1212");
    strcpy(info.authCode, "3333");
    strcpy(info.serverIp, "192.168.85.130");
    info.serverPort = 10010;
    info.maxNode = 1;
    info.shmKey = 0x22;
    ClientOperation clientOperation(&info);
    while (1) {
        system("clear");
        ret = showMenu();
        if (5 == ret) {
            break;
        }
        switch (ret) {
            case 1:
                ret = clientOperation.secKeyAgree();
                break;
            case 2:
                ret = clientOperation.secKeyCheck();
                break;
            case 3:
                ret = clientOperation.secKeyRevoke();
                break;
            case 4:
                ret = clientOperation.secKeyView();
            default:
                ret = -1;
        }
        //判断对应结果
        if (0 == ret) {
            cout << "做对应的业务ok" << endl;
        } else {
            cout << "做对应的业务失败.." << endl;
        }
    }
}