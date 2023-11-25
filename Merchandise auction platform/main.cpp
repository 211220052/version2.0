#include <iostream>
#include<string>
#include<vector>
#include <stdlib.h>
#include <ctime>
#include <cstdio>
#include<fstream>
#include"Administrator.h"
#include"file_io.h"
#include"menu.h"
using namespace std;
//商品
string productID;
string productName;
float productPrice;
string uptime;
string sellerID;
int number;
bool state;
string  description;
//用户
string ID;
string name;
string phone;
string address;
string password;
bool open;
float account;
string identity;

void read_users_file(vector<User>& users);
void read_products_file(vector<Product>& products);
void read_orders_file(vector<Order>& orders);
void write_users_file(vector<User> users);
void write_products_file(vector<Product> products);
void write_orders_file(vector<Order> orders);


int main()
{
    vector<Product> Products; vector<User> Users; vector<Order> Orders;
     read_users_file(Users);
     read_products_file(Products);
     read_orders_file(Orders);
    string admin = "admin";
    password = "123456";
    Administrator administrator(admin, password);
    while (true)//1.管理员登录   2.用户注册   3.用户登录   4.退出程序
    {
        main_menu();
        cout << "请输入操作："; string serial; cin >> serial;      
        switch (serial[0])
        {           
//----------------------------------------------                   管理员登录                       ---------------------------------------------- 
        case '1': {//case1          
while (true) { //管理员登录          
 cout << "请输入管理员姓名：";  cin >> admin;                               
 while (true){//正确输入姓名               //姓名正确输入密码                .
            if (admin == administrator.getName())
            {
             cout << "请输入密码：";   cin >> password;  //密码正确进入管理员操作                                  
            if (password == administrator.getPassword())
            {//管理员操作
            administrator.setOpen(1); cout << "管理员登录成功！" << endl<<endl; 
            while (true)
            {//输入管理员操作
            admin_menu();
            cout <<endl<< "请输入管理员操作：" ; string serial_admin; cin >> serial_admin;
            //1.查看所有商品  2.搜索商品  3.下架商品  4.查看所有订单  5.查看所有用户  6.封禁用户  7.注销" 
            switch (serial_admin[0])
            {//switch (serial_admin)
            case '1': {
            product_menu();                            
            administrator.Show_all_products( Products);                                                             
            continue;
                      }                               
            case '2': {
            cout << endl << "请输入要搜索的商品的名称:";
            cin >> productName;
            administrator.search_product(Products, productName);
            continue;
                      }
            case '3': {
            cout << "请输入要下架的商品的ID:"; 
            cin >> productID;
            administrator.off_product(Products, productID);
            continue;
                      }
            case '4': {
            order_menu();
            administrator.View_all_order(Orders);
            continue;
                       }
            case '5': {
            view_alluser_menu();
            administrator.View_all_user(Users);
            continue;
                       }
            case '6': {
                                
            cout << "请输入要封禁的用户ID：";
            cin>>ID;
            administrator.Block_user(Users,ID);
            break;
                      }
            case '7': {                       
            goto main_break;
            break;
                       }
            default:{                            
            cout << "没有此操作！"<<endl;
            continue;
            }

            }//switch (serial_admin)
            }//输入管理员操作
            

            }//管理员操作
            else { cout << "密码输入错误！"; }
                 
            }
            else { cout << "管理员姓名错误!"; break; }
                                
             }//正确输入姓名              
             }//管理员登录
             }//case1       
//----------------------------------------------                    用户注册                        ---------------------------------------------- 
        case '2': {//case '2'         
        cout << "请输入要注册用户的姓名:"; cin >> name ;
        cout << "请输入要注册用户的电话："; cin >> phone;
        cout << "请输入要注册用户的地址："; cin >> address ;
        cout << "请输入要注册用户的密码："; cin >> password ;                       
        User user( name, phone, address, password);                
        user.Register_user(Users, user); 
        cout << endl << endl; main_menu();
        continue;
            }//case '2'        
//----------------------------------------------                    用户登录                        ----------------------------------------------  
        case '3': {//case3           
while (true){//用户登录               
cout << "请输入用户名：";  cin >> name;   bool flag = 0;   unsigned i;                                                                          
for ( i = 0; i < Users.size(); i++)
{
if (name == Users[i].getName()&& Users[i].getOpen()){    flag = 1;
while (true) {
    cout << "请输入密码：";  cin >> password;//密码正确进入用户操作   
    if (password == Users[i].getPassword())
    {//if password == Password
    cout << "用户登录成功！" << endl;
    user_menu();
    cout << endl;
    while (true) {//选择身份
            cout << "请选择身份："; string serial_select; cin >> serial_select;                     
            switch (serial_select[0]){
            
            case'1'://我是买家
            {//买家
                while (true) {
                    buyer_menu(); cout << "请选择操作："; string serial_buyer; cin >> serial_buyer;
                    //1.查看商品列表  2.购买商品   3.搜索商品  4.查看历史订单  5.查看商品详细信息  6.返回用户主界面"
                    switch (serial_buyer[0])
                    {
                    case '1': {
                        product_menu();
                        Users[i].Show_all_products(Products);
                        continue;
                    }
                    case '2': {                   
                        cout << "请输入要购买商品的ID:";  cin >> productID; 
                        cout<< "请输入要购买商品的个数:"; cin>> number;
                        state=Users[i].Buy_product(Users[i].getID(), Users[i],Users, Products, productID, number);
                        if (state)
                        {
                            for (unsigned i_ = 0; i_ < Products.size(); i_++)
                            {
                                if (Products[i_].getProductName() == productName)
                                {
                                    productID = Products[i_].getID_product();
                                    productPrice = Products[i_].getPrice();
                                    sellerID = Products[i_].getID_seller();
                                    Order order(productID, productPrice, number, sellerID, Users[i].getID());
                                    order.SettradeTime(order);
                                    order.SetID_and_Addorder(Orders, order);
                                }
                            }
                            
                        }                 
                        continue;
                    }                                     
                    case '3': {
                        cout << "请输入要搜索的商品:"; cin >> productName;
                        Users[i].search_product(Products, productName);
                        continue;
                    }
                    case '4': {
                    order_menu();
                    Users[i].View_historical_order_buyer(Orders,Users[i].getID());
                    continue;
                    }//case4
                    case '5': {
                        cout << "请输入您想要查看的商品ID：";  cin >> productID;
                        Users[i].View_details(Products, productID);
                        continue;
                    }             
                    case '6': { user_menu(); break; }
                    default: { 
                        cout << "没有此操作！"; 
                        continue; 
                    }   
                    }      
                    break;
                }
            }//买家
            continue;//返回用户主界面
            case'2'://我是卖家
            {// 卖家
                while (true) {
                    seller_menu();
                    //1.发布商品  2.查看发布商品  3.修改商品信息  4.下架商品  5.查看历史订单  6.返回用户主界面"
                    cout << "请选择操作："; string serial_seller; cin >> serial_seller;
                    switch (serial_seller[0])
                    {
                    case '1': {
                        cout << "请输入商品名称："; cin >> productName;
                        cout << "请输入商品价格："; cin >> productPrice;
                        cout << "请输入商品数量："; cin >> number;
                        cout << "请输入商品描述："; cin >> description;
                        Product product(productName, productPrice, number, description);                     
                        if (/*product.if_repeated(Products, productName) == false &&*/ number >= 1)                           
                                Users[i].Release_products(Products, product, Users[i]);                          
                        else { cout << "上架失败，请检查商品名是否重复，上架数量是否正确，价格是否正确"<<endl; }  
                        continue;
                    }
                    case '2': {  
                        product_menu();
                        Users[i].View_released_products(Products, Users[i].getID());
                        continue;
                    }
                    case '3': {
                        cout << "请输入被修改商品的ID："; cin >> productID;  cout << "请输入要修改的信息（1.价格 2.描述）："; cin >> number; cout << "请输入要修改后信息：";
                    switch (number) { case 1:cin >> productPrice; break; case 2:cin >> description; break; }
                        Users[i].Modify_information(Products,productID, Users[i].getID(),number,productPrice,description);                 
                        continue;
                    }
                    case '4': {
                        cout << "请输入被下架商品的ID："; cin >> productID;
                        Users[i].off_product(Products, productID, Users[i].getID());
                        continue;
                    }
                    case '5': {
                    order_menu();
                    Users[i].View_historical_order_seller(Orders, Users[i].getID());
                    continue;
                    }
                    case '6': { user_menu(); break; }
                    default: { cout << "没有此操作！"; continue; }  
                    }   
                    break;       
                }               
            }// 卖家
            continue;//返回用户主界面
            case'3'://个人信息管理
            {
                while (true) {
                    PIM_menu();
                    //1.查看信息  2.修改信息  3.充值  4.返回用户主界面
                    cout << "请选择操作："; string serial_PIM; cin >> serial_PIM;
                    switch (serial_PIM[0])
                    {
                    case '1': {
                        Users[i].view_PIMinformation(Users[i]);
                        continue;
                    }
                    case '2': {                      
                    cout << "请输入要修改的信息（1.用户名 2.联系方式 3.地址）："; cin >> number; cout << "请输入要修改后信息：";
                    switch (number) { case 1:cin >> name; break; case 2:cin >> phone; break; case 3:cin >> address; break; }
                    Users[i].Modify_PIMinformation( Users,Users[i].getID(),number, name,phone,address);
                    continue;
                    }
                    case '3': {
                    cout << "请输入充值金额："; cin >> account;                   
                    Users[i].Modify_PIMaccount(Users,Users[i].getID(),account);
                    continue;
                    }                  
                    case '4': { user_menu(); break; }
                    default: { cout << "没有此操作！"; continue; }    }    break;  }

            }
            continue;//返回用户主界面
            case'4'://注销登录
            {
                goto main_break;
            }
            default: { cout << "没有此操作！"; continue; }   
                                       }                      }//请选择身份

               
    }//if password == Password
    else  cout << "密码输入错误！" << endl; }     }  //if name == Users[i].getName()                                         
}     
if(flag==0) { cout << "无此用户名或用户已被管理员禁用!" << endl; continue; }      }//用户登录                      
                  }//case3                              
//----------------------------------------------                    退出程序                        ---------------------------------------------- 
        case '4': {
            write_users_file(Users);
            write_products_file(Products);
            write_orders_file(Orders);
            cout << "程序退出成功!  ........";
            return 0;
            }  
//----------------------------------------------                    重新输入                        ---------------------------------------------- 
        default:  { cout << "请输入正确操作！" << endl;}
        }
        main_break: ;       
    }   // 1.管理员登录   2.用户注册   3.用户登录   4.退出程序     

}


