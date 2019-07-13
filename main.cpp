#define _CRT_SECURE_NO_WARNINGS
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
//主函数
int main() {
    int ret = -1;
    //读取配置文件获取密钥协商客户端配置信息
    ClientInfo info;
    memset(&info, 0, sizeof info);
    strcpy(info.clientId, "0001");
    strcpy(info.serverId, "1111");
    strcpy(info.authCode, "1111");
    strcpy(info.serverIp, "192.168.85.130");
    info.serverPort = 10086;
    info.maxNode = 1;
    info.shmKey = 0x11;
    //创建密钥协商客户端对象
    ClientOperation clientOperation(&info);
    while (1) {
        //清屏
        system("clear");
        //显示菜单
        ret = showMenu();
        if (5 == ret) {
            break;
        }
        switch (ret) {
                //密钥协商
            case 1:
                cout << "密钥协商" << endl;
                ret = clientOperation.secKeyAgree();
                break;
                //密钥校验
            case 2:
                cout << "密钥校验" << endl;
                ret = clientOperation.secKeyCheck();
                break;
                //密钥注销
            case 3:
                cout << "密钥注销" << endl;
                ret = clientOperation.secKeyRevoke();
                break;
                //密钥查看
            case 4:
                cout << "密钥查看" << endl;
                ret = clientOperation.secKeyView();
                break;
                //非法选择
            default:
                cout << "非法选择" << endl;
                ret = -1;
        }
        //判断对应结果
        if (0 == ret) {
            cout << "做对应的业务ok" << endl;
        } else {
            cout << "做对应的业务失败.." << endl;
        }
        //按下任意键继续
        cout << "按下任意键继续" << endl;
        getchar();
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}