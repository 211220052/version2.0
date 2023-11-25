#include"Order.h"


//构造函数：订单ID和交易时间后面确定
Order::Order(string id_product, float price, int number,  string id_seller, string id_buyer)
{
	
	ID_product = id_product;
	Price = price;
	Number = number;
	ID_seller = id_seller;
	ID_buyer = id_buyer;
}

string Order::getID_order()
{
	return ID_order;
}
string Order::getID_product()
{
	return ID_product;
}
float Order::getPrice()
{
	return Price;
}

int Order::getNumber()
{
	return Number;
}
string Order::getTrade_time()
{
	return Trade_time;
}
string Order::getID_seller()
{
	return  ID_seller;
}
string Order::getID_buyer()
{
	return ID_buyer;
}


void Order::setID_order(string id_order)
{
	ID_order = id_order;
}
void Order::setID_product(string id_product)
{
	ID_product = id_product;
}
void Order::setPrice(string price)
{
	Price = atof(price.c_str());
}
void Order::setNumber(string number)
{
	Number = atoi(number.c_str());
}
void Order::setTrade_time(string trade_time)
{
	Trade_time = trade_time;
}
void Order::setID_seller(string id_seller)
{
	ID_seller = id_seller;
}
void Order::setID_buyer(string id_buyer)
{
	ID_buyer = id_buyer;
}



//展示一个订单对象的信息
void Order::Show_order_information()
{
	cout << endl;
	cout << std::left << setw(16) <<ID_order
		 << std::left << setw(16) << ID_product 
		 << std::left << setw(16) << Price 
		 << std::left << setw(16) << Number
		 << std::left << setw(16) << Trade_time
		 << std::left << setw(16) << ID_seller
		 << std::left << setw(16) << ID_buyer
		 <<endl;
}

//展示所有订单对象的信息
void Order::View_all_order(vector<Order> orders)
{
	for (unsigned i = 0; i < orders.size(); i++)
	{
		orders[i].Show_order_information();
	}
}

//确定订单的交易时间
void  Order::SettradeTime(Order& order)
{
	struct tm t;   //tm结构指针
	time_t now;  //声明time_t类型变量
	time(&now);      //获取系统日期和时间
	localtime_s(&t, &now);   //获取当地日期和时间
	string tradetime = "";
	tradetime.append(to_string(t.tm_year + 1900));
	tradetime.append("年");
	tradetime.append(to_string(t.tm_mon + 1));
	tradetime.append("月");
	tradetime.append(to_string(t.tm_mday));
	tradetime.append("日");
	order.Trade_time = tradetime;
}

//确定订单的ID并将其加入订单队列
void Order::SetID_and_Addorder(vector<Order>& orders, Order order)
{
	if ((orders.size() + 1) >= 100)
	{
		string id = "U";
		order.ID_order = id.append(to_string(orders.size() + 1));
	}
	else if ((orders.size() + 1) >= 10)
	{
		string id = "U0";
		order.ID_order = id.append(to_string(orders.size() + 1));
	}
	else
	{
		string id = "U00";
		order.ID_order = id.append(to_string(orders.size() + 1));
	}
	orders.push_back(order);

}


