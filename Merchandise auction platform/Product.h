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
	* ˵����
	* ID_product:��ƷID
	* ProductName: ��Ʒ����
	* Price����Ʒ�۸�
	* upTime:�ϼ�ʱ��
	* ID_seller: ����ID
	* ID_buyer:���ID
	* Number:����
	* State:״̬
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

	//���캯������ʼ��Product���󣬳�ʼ��ʱopenĬ��Ϊ��

	Product(string productName, float price,  int number, string  description);
	//��������
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
