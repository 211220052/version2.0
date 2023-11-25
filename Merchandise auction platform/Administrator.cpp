#include "Administrator.h"

    Administrator::Administrator(string AdminName,string paword)
	{
	   AdministratorName = AdminName;
	   password = paword;
	   open = 0;
	}

	string Administrator::getName()
	{
		return AdministratorName;
	}
	string Administrator::getPassword()
	{
		return password;
	}
	bool Administrator::getOpen()
	{
		return open;
	}
	void Administrator::setOpen(bool o)
	{
		open = o;
	}
	//��������
	// 
	//�鿴������Ʒ
	void Administrator::Show_all_products(vector<Product> products)
	{
		for (unsigned i = 0; i < products.size(); i++)
		{

			products[i].show_all_information();
		}
	}
	//������Ʒ
	void Administrator::search_product(vector<Product> products,string search_product)
	{
		cout << std::right << setw(50) << "---������Ʒ�б�---" << endl;
		string b1 = "------------------------------------------------------------------------------------------------------";
		cout << b1 << endl;
		// "     1.��ƷID     2.��Ʒ����     3.��Ʒ�۸�     4.�ϼ�ʱ��     5.����ID     6.����     7.��Ʒ״̬ " 
		cout << std::left << setw(16) << "1.��ƷID"
			<< std::left << setw(16) << "2.��Ʒ����"
			<< std::left << setw(16) << "3.��Ʒ�۸�"
			<< std::left << setw(16) << "4.�ϼ�ʱ��"
			<< std::left << setw(16) << "5.����ID"
			<< std::left << setw(16) << "6.����"
			<< std::left << setw(16) << "7.��Ʒ״̬"
			<< endl << endl;
		bool flag = 0;
		for (unsigned i = 0; i < products.size(); i++)
		{
			if (products[i].getProductName() == search_product)
			{
				flag = 1;
				products[i].show_all_information();
			}
		}
		if(!flag) 
			cout << endl << "�����ڴ���Ʒ��";
		cout << endl << endl;
			
		
	}
	//�¼���Ʒ
	void Administrator::off_product(vector<Product>& products, string off_product_id)
	{
		bool flag = 0;
		for (unsigned i = 0; i < products.size(); i++)
		{
			
			if (products[i].getID_product() == off_product_id)
			{
				//auto iter = products.erase(products.begin() + i);
				products[i].setState(0);
				cout << "�¼ܳɹ���"<<endl;
				flag = 1;
				break;
			}
			
		}
		if (flag == 0)
		{
			cout << "δ�ҵ�����Ʒ��"<<endl;
			
		}
	}

	//�鿴���ж���
	void Administrator::View_all_order(vector<Order> orders)
	{
		for (unsigned i = 0; i < orders.size(); i++)
		{
			orders[i].Show_order_information();
		}
	}

	//�鿴�����û�
	void Administrator::View_all_user(vector<User> users)
	{
		for (unsigned i = 0; i < users.size(); i++)
		{

			users[i].show_information();
		}
	}



	//����û�
	void Administrator::Block_user(vector<User>& users,string id_ban)
	{
		bool flag = 0;
		for (unsigned i = 0; i < users.size(); i++)
		{
			if (users[i].getID() == id_ban)
			{
				//auto iter = users.erase(users.begin() + i);
				users[i].setOpen(0);
				cout << "����û��ɹ���"<<endl;
				flag = 1;
				break;
			}
			
		}
		if (flag == 0)
		{
			cout << "δ�ҵ����û���";

		}
	}
	//ע��



