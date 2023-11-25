#pragma once
#include <iostream>
#include<string>
#include "User.h"
#include"Product.h"
#include"Order.h"

using namespace std;
class Administrator {
private:
	/**
	* 说明：
	* AdministratorName: 管理者名称，例如："Admin"
	* password：管理者登录密码
	* open：取值true表示管理员身份验证通过，false表示管理员身份验证失败
	*/
	string AdministratorName;
	string password;
	bool open;
public:
	//构造函数，初始化Administrator对象，初始化时open默认为关
	Administrator(string AdminiName, string paword);
	string getName();
	string getPassword();
	bool getOpen();
	void setOpen(bool o);
	//查看所有商品
	void Show_all_products(vector<Product> products);
	//搜索商品
	void search_product(vector<Product> products, string search_product);
	//下架商品
	void off_product(vector<Product>& products, string off_product_id);
	//查看所有订单
	void View_all_order(vector<Order> orders);
	//查看所有用户
	void View_all_user(vector<User> users);
	//封禁用户
	void Block_user(vector<User>& users, string id_ban);
	
	
	
};
