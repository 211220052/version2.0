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
	//析构函数
	// 
	//查看所有商品
	void Administrator::Show_all_products(vector<Product> products)
	{
		for (unsigned i = 0; i < products.size(); i++)
		{

			products[i].show_all_information();
		}
	}
	//搜索商品
	void Administrator::search_product(vector<Product> products,string search_product)
	{
		cout << std::right << setw(50) << "---搜索商品列表---" << endl;
		string b1 = "------------------------------------------------------------------------------------------------------";
		cout << b1 << endl;
		// "     1.商品ID     2.商品名称     3.商品价格     4.上架时间     5.卖家ID     6.数量     7.商品状态 " 
		cout << std::left << setw(16) << "1.商品ID"
			<< std::left << setw(16) << "2.商品名称"
			<< std::left << setw(16) << "3.商品价格"
			<< std::left << setw(16) << "4.上架时间"
			<< std::left << setw(16) << "5.卖家ID"
			<< std::left << setw(16) << "6.数量"
			<< std::left << setw(16) << "7.商品状态"
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
			cout << endl << "不存在此商品！";
		cout << endl << endl;
			
		
	}
	//下架商品
	void Administrator::off_product(vector<Product>& products, string off_product_id)
	{
		bool flag = 0;
		for (unsigned i = 0; i < products.size(); i++)
		{
			
			if (products[i].getID_product() == off_product_id)
			{
				//auto iter = products.erase(products.begin() + i);
				products[i].setState(0);
				cout << "下架成功！"<<endl;
				flag = 1;
				break;
			}
			
		}
		if (flag == 0)
		{
			cout << "未找到此商品！"<<endl;
			
		}
	}

	//查看所有订单
	void Administrator::View_all_order(vector<Order> orders)
	{
		for (unsigned i = 0; i < orders.size(); i++)
		{
			orders[i].Show_order_information();
		}
	}

	//查看所有用户
	void Administrator::View_all_user(vector<User> users)
	{
		for (unsigned i = 0; i < users.size(); i++)
		{

			users[i].show_information();
		}
	}



	//封禁用户
	void Administrator::Block_user(vector<User>& users,string id_ban)
	{
		bool flag = 0;
		for (unsigned i = 0; i < users.size(); i++)
		{
			if (users[i].getID() == id_ban)
			{
				//auto iter = users.erase(users.begin() + i);
				users[i].setOpen(0);
				cout << "封禁用户成功！"<<endl;
				flag = 1;
				break;
			}
			
		}
		if (flag == 0)
		{
			cout << "未找到此用户！";

		}
	}
	//注销



