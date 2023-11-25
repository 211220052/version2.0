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
	case 1:cout << "正常"; break;
	case 0:cout << "封禁"; break;
	}
	cout << endl << endl;
	
	
}


bool User::Register_user(vector<User>& users,User user )
{
	for (unsigned i = 0; i < users.size(); i++)
	{
		if (users[i].getName() == user.getName())
		{
			cout << "用户名重复！";
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
	cout << "用户注册成功！";
	return 1;
}


//seller
//发布商品
void User::Release_products(vector<Product>& Products, Product& product, User user)
{
	product.setID_product(product, Products);
	product.setupTime(product);
	product.setID_seller(product, user.getID());
	product.setState(1);
	Products.push_back(product);
	cout << "上架成功！" << endl;
}

//查看发布商品
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
//修改商品信息
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
					cout << endl << "商品信息修改成功" << endl;
				}
				else
				{
					cout << "error!"<<endl;
				}
				break;
			case 2:
				Products[i].setDescription(description);
				cout << endl << "商品信息修改成功" << endl;
				break;
			}		
			break;
		}
		if (i == Products.size() - 1)
		{
			cout << endl << "不存在此商品，商品信息修改失败！"<<endl;
			break;
		}
	}
}

//下架商品
void User::off_product(vector<Product>& Products, string iD_product, string ID_user)
{
	for (unsigned i = 0; i < Products.size(); i++)
	{
		if (Products[i].getID_product() == iD_product && Products[i].getID_seller() == ID_user)
		{
			Products[i].setState(0);
			cout << endl << "商品下架成功！" << endl;
			break;
		}
		if (i == Products.size() - 1)
		{
			cout << endl << "不存在此商品，商品下架失败！"<<endl;
			break;


		}
	}
}
//查看历史订单
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
//查看商品列表
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
//搜索商品
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
			cout << endl << "不存在此商品或商品已下架！"<<endl;
			break;


		}
	}
}
//购买商品
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
			cout << endl << "购买成功！" << endl;
			return 1;
			
		}
		if (i == products.size() - 1)
		{
			cout << endl << "不存在此商品，商品已下架,商品数量不足或账户余额不足！"<<endl;
			return 0;
		}
	}
}

//查看历史订单

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
//查看商品详细信息
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
			cout << endl << "不存在此商品！"<<endl;
			break;


		}
	}
}


//PIM
void User::view_PIMinformation(User user)
{
	cout << endl;
	cout << "用户名：" << user.getName()<<endl;
	cout << "联系方式：" << user.getPhone()<<endl;
	cout << "地址;" << user.getAddress()<<endl;
	cout << "钱包余额:" << user.getAccount()<<endl<<endl;
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
						cout << "此用户名已存在！"<<endl;
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
			cout << "充值成功！"<<endl;
			return 1;
		}
	}
	cout << "请检查充值金额是否合理!"<<endl;
	return 0;
}