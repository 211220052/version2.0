#pragma once
#include <iostream>
#include<string>
#include"Product.h"
#include "Order.h"

using namespace std;
class User {
	/**
	* ˵����
	* ID:ID
	* Name: ����
	* Phone:�绰
	* Address:��ַ
	* Password����¼����
	* Open��ȡֵtrue��ʾ�����֤ͨ����false��ʾ�����֤ʧ��
	* Account���˻����
	* Identity:���
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

	//����
	void Release_products(vector<Product>& Products, Product& product, User user);
	//�鿴������Ʒ
	void View_released_products(vector<Product> Products, string seller);
	//�޸���Ʒ��Ϣ
	void Modify_information(vector<Product>& Products, string iD_product, string ID_user,int number, float price, string description);
	//�¼���Ʒ
	void off_product(vector<Product>& Products, string iD_product, string ID_user);
	//�鿴��ʷ����
	void View_historical_order_seller(vector<Order> Orders, string id_seller);
	



	//���
	//�鿴��Ʒ�б�
	void Show_all_products(vector<Product> products);
	//������Ʒ
	void search_product(vector<Product> products, string search_product);
	//������Ʒ
	bool Buy_product(string id_buyer, User buyer, vector<User>& users, vector<Product>& products, string toBuy_product, int number);

	
	//�鿴��ʷ����
	void View_historical_order_buyer(vector<Order> Orders,string id_buyer);
	
	//�鿴��Ʒ��ϸ��Ϣ
	void View_details(vector<Product> products, string view_ID);
	//�����û�������
	
	//PIM
	void view_PIMinformation(User user);
	bool Modify_PIMinformation(vector<User>& users, string id, int number, string name, string phone, string address);
	bool Modify_PIMaccount(vector<User>& users, string id, float account);




};

	





