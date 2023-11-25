#pragma once
#include <iostream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;

class Order
{
	string ID_order;
	string ID_product;
	float Price;
	int Number;
	string Trade_time;
	string ID_seller;
	string ID_buyer;
public:
	string getID_order();
	string getID_product();
	float getPrice();
	int getNumber();
	string getTrade_time();
	string getID_seller();
	string getID_buyer();

	void setID_order(string id_order);
	void setID_product(string id_product);
	void setPrice(string price);
	void setNumber(string number);
	void setTrade_time(string trade_time);
	void setID_seller(string id_seller);
	void setID_buyer(string id_buyer);


	Order(string id_product, float price, int number,  string id_seller, string id_buyer);
	void Show_order_information();
	void View_all_order(vector<Order> orders);
	void SettradeTime(Order& order);
	void SetID_and_Addorder(vector<Order>& orders, Order order);
};

