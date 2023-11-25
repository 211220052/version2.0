#pragma once
#include <iostream>
#include<string>
#include<vector>
#include<time.h> 
#include <stdio.h>
#include<iomanip>
using namespace std;
class Product {
private:
	/**
	* 说明：
	* ID_product:商品ID
	* ProductName: 商品名称
	* Price：商品价格
	* upTime:上架时间
	* ID_seller: 卖家ID
	* ID_buyer:买家ID
	* Number:数量
	* State:状态
	*/
	string ID_product;
	string ProductName;
    float Price;
	string upTime;
	string ID_seller;
	int Number;
	bool State;
	string  Description;
public:

	void setID_product(string id_product);
	void setProductName(string id_product);
	void setPrice(string price);
	void setupTime(string uptime);
	void setID_seller(string id_seller);
	void setNumber(string number);
	void setState(string state);
	//void setDescription(string description);

	//构造函数，初始化Product对象，初始化时open默认为关

	Product(string productName, float price,  int number, string  description);
	//析构函数
	string getID_product();
	void setID_product(Product& product, vector<Product> products);

	string getProductName();
	
	float getPrice();
	void setPrice(float price);

	string getupTime();
	void setupTime(Product& product);

	string getID_seller();
	void setID_seller(Product& product, string seller);
	
	int getNumber();
	void  setNumber(bool add_or_sub, int num);

	bool getState();
	void setState(bool state);
	string showState();

	string  getDescription();
	void setDescription(string description);

	void show_all_information();
	void show_detail_information();
	
	bool if_repeated(vector<Product> products, string add_product);
		
	
	
};
