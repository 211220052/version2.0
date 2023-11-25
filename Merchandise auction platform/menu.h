#pragma once
#include <iostream>
#include<string>
#include<iomanip>
using namespace std;
void main_menu()
{
    cout << std::right << setw(50) << "---商品购物平台---"<<endl;
    string b1 = "------------------------------------------------------------------------------------------------------";
    cout << b1 << endl;
    cout << std::left << setw(25)<<"1.管理员登录"
         << std::left << setw(25) <<"2.用户注册"
         << std::left << setw(25) <<"3.用户登录"
         << std::left << setw(25) <<"4.退出程序"
         << endl;
    cout << b1 << endl << endl;
}
void product_menu()
{
    cout << std::right << setw(50) << "---商品列表---" << endl;
    string b1 = "------------------------------------------------------------------------------------------------------";
    cout << b1 << endl;
    // "     1.商品ID     2.商品名称     3.商品价格     4.上架时间     5.卖家ID     6.数量     7.商品状态 " 
    cout << std::left << setw(16) << "1.商品ID"
         << std::left << setw(16) << "2.商品名称"
         << std::left << setw(16) << "3.商品价格"
         << std::left << setw(16) << "4.上架时间"
         << std::left << setw(16) << "5.卖家ID"
         << std::left << setw(16) << "6.数量"
         << std::left << setw(16) << "7.商品状态"
         << endl << endl;
}

void admin_menu()
{
    string b1 = "------------------------------------------------------------------------------------------------------";
    cout << b1 << endl;
    //"     1.查看所有商品  2.搜索商品  3.下架商品  4.查看所有订单  5.查看所有用户  6.封禁用户  7.注销" 
    cout << std::left << setw(11) << "1.查看所有商品"
         << std::left << setw(11) << "2.搜索商品"
         << std::left << setw(11) << "3.下架商品"
         << std::left << setw(11) << "4.查看所有订单"
         << std::left << setw(11) << "5.查看所有用户"
         << std::left << setw(11) << "6.封禁用户"
         << std::left << setw(11) << "7.注销"
         << endl;

    cout << b1 << endl << endl;
}



void view_alluser_menu()
{
    string b1 = "------------------------------------------------------------------------------------------------------------------";
    cout << b1 << endl;
    //cout << "用户ID" << "   " << "用户名" << "   " << "联系方式" << "   " << "地址" << "   " << "余额" << "   " << "用户状态" << "   "<<endl<<endl;
    cout << std::left << setw(20) << "1.用户ID"
         << std::left << setw(20) << "2.用户名"
         << std::left << setw(20) << "3.联系方式"
         << std::left << setw(20) << "4.地址"
         << std::left << setw(20) << "5.余额"
         << std::left << setw(20) << "6.用户状态"
         << endl << endl;
}
void user_menu()
{
    string b1 = "------------------------------------------------------------------------------------------------------";
    cout << b1 << endl;
    //cout << "     1.我是买家  2.我是卖家  3.个人信息管理  4.注销登录" << endl;
    cout << std::left << setw(25) << "1.我是买家"
         << std::left << setw(25) << "2.我是卖家"
         << std::left << setw(25) << "3.个人信息管理"
         << std::left << setw(25) << "4.注销登录"
         << endl;
    cout << b1 << endl << endl;
}
void buyer_menu()
{
    string b1 = "------------------------------------------------------------------------------------------------------";
    cout << b1 << endl;
    //cout << "  1.查看商品列表  2.购买商品  3.搜索商品  4.查看历史订单  5.查看商品详细信息  6.返回用户主界面" << endl;
    cout << std::left << setw(11) << "1.查看商品列表"
         << std::left << setw(11) << "2.购买商品"
         << std::left << setw(11) << "3.搜索商品"
         << std::left << setw(11) << "4.查看历史订单"
         << std::left << setw(11) << "5.查看商品详细信息"
         << std::left << setw(11) << "6.返回用户主界面"
         << endl;
    cout << b1 << endl << endl;
}
void seller_menu()
{
    string b1 = "------------------------------------------------------------------------------------------------------";
    cout << b1 << endl;
    //cout << "     1.发布商品  2.查看发布商品  3.修改商品信息  4.下架商品  5.查看历史订单  6.返回用户主界面" << endl;
    cout << std::left << setw(12) << "1.发布商品"
         << std::left << setw(12) << "2.查看发布商品"
         << std::left << setw(12) << "3.修改商品信息"
         << std::left << setw(12) << "4.下架商品"
         << std::left << setw(12) << "5.查看历史订单"
         << std::left << setw(12) << "6.返回用户主界面"
         << endl;
    cout << b1 << endl << endl;
}
void PIM_menu()
{
    string b1 = "------------------------------------------------------------------------------------------------------";
    cout << b1 << endl;
    //cout << "        1.查看信息  2.修改信息  3.充值  4.返回用户主界面" << endl;
    cout << std::left << setw(25) << "1.查看信息"
         << std::left << setw(25) << "2.修改信息"
         << std::left << setw(25) << "3.充值"
         << std::left << setw(25) << "4.返回用户主界面"
         << endl;
    cout << b1 << endl << endl;
}

void order_menu()
{
    string b1 = "------------------------------------------------------------------------------------------------------";
    cout << b1 << endl;
    //cout << "        1.订单ID  2.商品ID  3.交易单价  4.数量   5.交易时间  6.卖家ID   7.买家ID " << endl;
    cout << std::left << setw(16) << "1.订单ID"
         << std::left << setw(16) << "2.商品ID"
         << std::left << setw(16) << "3.交易单价"
         << std::left << setw(16) << "4.数量"
         << std::left << setw(16) << "5.交易时间"
         << std::left << setw(16) << "6.卖家ID"
         << std::left << setw(16) << "7.买家ID"
         << endl;
    cout << b1 << endl << endl;
}

