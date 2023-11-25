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
	* ˵����
	* AdministratorName: ���������ƣ����磺"Admin"
	* password�������ߵ�¼����
	* open��ȡֵtrue��ʾ����Ա�����֤ͨ����false��ʾ����Ա�����֤ʧ��
	*/
	string AdministratorName;
	string password;
	bool open;
public:
	//���캯������ʼ��Administrator���󣬳�ʼ��ʱopenĬ��Ϊ��
	Administrator(string AdminiName, string paword);
	string getName();
	string getPassword();
	bool getOpen();
	void setOpen(bool o);
	//�鿴������Ʒ
	void Show_all_products(vector<Product> products);
	//������Ʒ
	void search_product(vector<Product> products, string search_product);
	//�¼���Ʒ
	void off_product(vector<Product>& products, string off_product_id);
	//�鿴���ж���
	void View_all_order(vector<Order> orders);
	//�鿴�����û�
	void View_all_user(vector<User> users);
	//����û�
	void Block_user(vector<User>& users, string id_ban);
	
	
	
};
