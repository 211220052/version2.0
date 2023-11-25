#pragma once
#include <iostream>
#include<string>
#include"Product.h"
#include "Order.h"

using namespace std;
class User {
	/**
	* 说明：
	* ID:ID
	* Name: 名称
	* Phone:电话
	* Address:地址
	* Password：登录密码
	* Open：取值true表示身份验证通过，false表示身份验证失败
	* Account：账户余额
	* Identity:身份
	*/
	string ID;
	string Name;
	string Phone;
	string Address;
	string Password;
	bool Open;
	float Account;
	
public:
	
	User( string name, string phone, string address, string paword);
	User(string id, string name, string phone, string address, string password, bool open, float account);

	string getID();
	string getName();
	string getPhone();
	string getAddress();
	string getPassword();
	float getAccount();
	void setAccount(bool sell_or_buy, int num, float price);
	bool getOpen();
	void setOpen(bool o);
	void show_information();
	void setID(string id);



	void setName(string name);
	void setPhone(string phone);	
	void setAddress(string address);	
	void setPassword(string password);	
	void setAccount(string account);
	void setOpen(string open);



	bool Register_user(vector<User>& users, User user);

	//卖家
	void Release_products(vector<Product>& Products, Product& product, User user);
	//查看发布商品
	void View_released_products(vector<Product> Products, string seller);
	//修改商品信息
	void Modify_information(vector<Product>& Products, string iD_product, string ID_user,int number, float price, string description);
	//下架商品
	void off_product(vector<Product>& Products, string iD_product, string ID_user);
	//查看历史订单
	void View_historical_order_seller(vector<Order> Orders, string id_seller);
	



	//买家
	//查看商品列表
	void Show_all_products(vector<Product> products);
	//搜索商品
	void search_product(vector<Product> products, string search_product);
	//购买商品
	bool Buy_product(string id_buyer, User buyer, vector<User>& users, vector<Product>& products, string toBuy_product, int number);

	
	//查看历史订单
	void View_historical_order_buyer(vector<Order> Orders,string id_buyer);
	
	//查看商品详细信息
	void View_details(vector<Product> products, string view_ID);
	//返回用户主界面
	
	//PIM
	void view_PIMinformation(User user);
	bool Modify_PIMinformation(vector<User>& users, string id, int number, string name, string phone, string address);
	bool Modify_PIMaccount(vector<User>& users, string id, float account);




};

	





