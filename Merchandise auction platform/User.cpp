#include"User.h"



User::User( string name, string phone, string address, string paword)
{
	Name = name;
	Phone = phone;
	Address = address;
	Password = paword;
	Open = 1;
	Account = 0;
	
}
User::User(string id, string name, string phone, string address, string password, bool open, float account)
{
	ID = id;
	Name = name;
	Phone = phone;
	Address = address;
	Password = password;
	Open = open;
	Account = account;
}


void User::setID(string id)
{
	ID = id;
}

void User::setName(string name)
{
	Name = name;
}

void User::setPhone(string phone)
{
	Phone = phone;
}

void User::setAddress(string address)
{
	Address = address;
}

void User::setPassword(string password)
{
	Password = password;
}

void User::setAccount(string account)
{
	Account = atof(account.c_str());
}

void User::setOpen(string open)
{
	if (open == "1")
		Open = 1;
	else
		Open = 0;
	
}




string User::getID()
{
	return ID;
}

string User::getName()
{
	return Name;
}

string User::getPhone()
{
	return Phone;
}

string User::getAddress()
{
	return Address;
}

string User::getPassword()
{
	return Password;

}

float User::getAccount()
{
	return Account;
}

void  User::setAccount(bool sell_or_buy, int num, float price)
{
	if (sell_or_buy)
	{
		Account += num * price;
	}
	else
	{
		Account -= num * price;
	}
}
bool User::getOpen()
{
	return Open;
}
void User::setOpen(bool o)
{
	Open = o;
}

void User::show_information()
{
	cout << std::left << setw(20) << getID()
		<< std::left << setw(20) << getName()
		<< std::left << setw(20) << getPhone()
		<< std::left << setw(20) << getAddress()
		<< std::left << setw(20) << getAccount()
		<< std::left << setw(20);
	switch (getOpen())
	{
	case 1:cout << "����"; break;
	case 0:cout << "���"; break;
	}
	cout << endl << endl;
	
	
}


bool User::Register_user(vector<User>& users,User user )
{
	for (unsigned i = 0; i < users.size(); i++)
	{
		if (users[i].getName() == user.getName())
		{
			cout << "�û����ظ���";
			return 0;			
		}
	}

    if ((users.size() + 1) >= 100)
	{
		string id = "U";
		user.ID = id.append(to_string(users.size() + 1));

	}
    else if ((users.size() + 1) >= 10)
	{
		string id = "U0";
		user.ID = id.append(to_string(users.size() + 1));
	}
	else
	{
		string id = "U00";
		user.ID = id.append(to_string(users.size() + 1));

	}
	users.push_back(user);
	cout << "�û�ע��ɹ���";
	return 1;
}


//seller
//������Ʒ
void User::Release_products(vector<Product>& Products, Product& product, User user)
{
	product.setID_product(product, Products);
	product.setupTime(product);
	product.setID_seller(product, user.getID());
	product.setState(1);
	Products.push_back(product);
	cout << "�ϼܳɹ���" << endl;
}

//�鿴������Ʒ
void User::View_released_products(vector<Product> Products,string ID_seller)
{
	for (unsigned i = 0; i < Products.size(); i++)
	{
		if (Products[i].getID_seller() == ID_seller)
		{

			Products[i].show_all_information();
			
		}
	
	}

}
//�޸���Ʒ��Ϣ
void User::Modify_information(vector<Product>& Products,string iD_product,string ID_user,int number,float price,string description)
{
	for (unsigned i = 0; i < Products.size(); i++)
	{
		if (Products[i].getID_product() == iD_product && Products[i].getID_seller() == ID_user)
		{
			switch (number)
			{
			case 1:
				if (price > 0)
				{
					Products[i].setPrice(price);
					cout << endl << "��Ʒ��Ϣ�޸ĳɹ�" << endl;
				}
				else
				{
					cout << "error!"<<endl;
				}
				break;
			case 2:
				Products[i].setDescription(description);
				cout << endl << "��Ʒ��Ϣ�޸ĳɹ�" << endl;
				break;
			}		
			break;
		}
		if (i == Products.size() - 1)
		{
			cout << endl << "�����ڴ���Ʒ����Ʒ��Ϣ�޸�ʧ�ܣ�"<<endl;
			break;
		}
	}
}

//�¼���Ʒ
void User::off_product(vector<Product>& Products, string iD_product, string ID_user)
{
	for (unsigned i = 0; i < Products.size(); i++)
	{
		if (Products[i].getID_product() == iD_product && Products[i].getID_seller() == ID_user)
		{
			Products[i].setState(0);
			cout << endl << "��Ʒ�¼ܳɹ���" << endl;
			break;
		}
		if (i == Products.size() - 1)
		{
			cout << endl << "�����ڴ���Ʒ����Ʒ�¼�ʧ�ܣ�"<<endl;
			break;


		}
	}
}
//�鿴��ʷ����
void User::View_historical_order_seller(vector<Order> Orders, string id_seller)
{
	for (unsigned i = 0; i < Orders.size(); i++)
	{
		if (Orders[i].getID_seller() == id_seller)
		{
			Orders[i].Show_order_information();
		}
	}
}




//Buyer
//�鿴��Ʒ�б�
void User::Show_all_products(vector<Product> products)
{
	for (unsigned i = 0; i < products.size(); i++)
	{
		if (products[i].getState())
		{
			products[i].show_all_information();
		}
	}
}
//������Ʒ
void User::search_product(vector<Product> products, string search_product)
{
	for (unsigned i = 0; i < products.size(); i++)
	{
		if (products[i].getProductName() == search_product&& products[i].getState())
		{
			products[i].show_all_information();
			break;
		}
		if (i == products.size() - 1)
		{
			cout << endl << "�����ڴ���Ʒ����Ʒ���¼ܣ�"<<endl;
			break;


		}
	}
}
//������Ʒ
bool User::Buy_product(string id_buyer,User buyer,vector<User>& users,vector<Product>& products, string id_product,int number)
{
	for (unsigned i = 0; i < products.size(); i++)
	{
		if (products[i].getID_product() == id_product &&number<= products[i].getNumber()&& products[i].getState()&&(buyer.getAccount()>= number*products[i].getPrice()))
		{
			products[i].setNumber(0, number);		
			for (unsigned j = 0; j < users.size(); j++)
			{
				if (users[j].getID() ==  id_buyer)
				{
					users[j].setAccount(0, number, products[i].getPrice());
					break;
				}
			}
			for (unsigned j = 0; j < users.size(); j++)
			{
				if (users[j].getID() == products[i].getID_seller())
				{
					users[j].setAccount(1, number, products[i].getPrice());
					break;
				}
			}
			cout << endl << "����ɹ���" << endl;
			return 1;
			
		}
		if (i == products.size() - 1)
		{
			cout << endl << "�����ڴ���Ʒ����Ʒ���¼�,��Ʒ����������˻����㣡"<<endl;
			return 0;
		}
	}
}

//�鿴��ʷ����

void User::View_historical_order_buyer(vector<Order> Orders, string id_buyer)
{
	
	for (unsigned i = 0; i < Orders.size(); i++)
	{
		if (Orders[i].getID_buyer() == id_buyer)
		{
			Orders[i].Show_order_information();
		}
	}
}
//�鿴��Ʒ��ϸ��Ϣ
void User::View_details(vector<Product> products, string view_ID)
{
	for (unsigned i = 0; i < products.size(); i++)
	{
		if (products[i].getID_product() == view_ID)
		{
			products[i].show_detail_information();
			break;
		}
		if (i == products.size() - 1)
		{
			cout << endl << "�����ڴ���Ʒ��"<<endl;
			break;


		}
	}
}


//PIM
void User::view_PIMinformation(User user)
{
	cout << endl;
	cout << "�û�����" << user.getName()<<endl;
	cout << "��ϵ��ʽ��" << user.getPhone()<<endl;
	cout << "��ַ;" << user.getAddress()<<endl;
	cout << "Ǯ�����:" << user.getAccount()<<endl<<endl;
}
bool User::Modify_PIMinformation(vector<User>& users, string id, int number, string name, string phone, string address)
{
	for (unsigned i = 0; i < users.size(); i++)
	{
		if (users[i].getID() == id)
		{
			switch (number)
			{
			case 1:
				for (unsigned j = 0; j < users.size(); j++)
				{
					if (users[j].getName() == name)
					{
						cout << "���û����Ѵ��ڣ�"<<endl;
						return 0;
					}
				}
				users[i].Name = name;
				return 1;
				break;
			case 2:
				users[i].Phone = phone;
				return 1;
				break;
			case 3:
				users[i].Address = address;
				return 1;
				break;
			}
			
		}
		
	}

}
bool User::Modify_PIMaccount(vector<User>& users, string id, float account)
{
	for (unsigned i = 0; i < users.size(); i++)
	{
		if (users[i].getID() == id && account >= 0) 
		{
			users[i].Account += account;
			cout << "��ֵ�ɹ���"<<endl;
			return 1;
		}
	}
	cout << "�����ֵ����Ƿ����!"<<endl;
	return 0;
}