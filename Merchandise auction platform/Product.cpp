#include"Product.h"

Product::Product(string productName, float price, int number, string  description)
{
	ProductName = productName;
	Price = price;
	Number = number;
	Description = description;
}
void Product::setID_product(string id_product)
{
	ID_product = id_product;
}
void Product::setProductName(string productName)
{
	ProductName = productName;
}
void Product::setPrice(string price)
{
	Price = atof(price.c_str());
}
void Product::setupTime(string uptime)
{
	upTime = uptime;
}
void Product::setID_seller(string id_seller)
{
	ID_seller = id_seller;
}
void Product::setNumber(string number)
{
	Number = atoi(number.c_str());
}
void Product::setState(string state)
{
	if (state == "1")
		State = 1;
	else
		State = 0;
}
string Product::getID_product()
{
	return ID_product;
}
void Product::setID_product(Product& product, vector<Product> products)
{
	if ((products.size() + 1) >= 100)
	{
		string id = "M";
		product.ID_product=id.append(to_string(products.size() + 1));
		
	}
	else if ((products.size() + 1) >= 10)
	{
		string id = "M0";
		product.ID_product = id.append(to_string(products.size() + 1));
	}
	else
	{
		string id = "M00";
		product.ID_product = id.append(to_string(products.size() + 1));
	
	}
	
}
string Product::getProductName()
{
	return ProductName;

}
float Product::getPrice()
{
	return Price;
}
void Product::setPrice(float price)
{
	Price = price;
}
string Product::getupTime()
{
	return upTime;
}

void  Product::setupTime(Product& product)
{
	

	struct tm t;   //tm结构指针
	time_t now;  //声明time_t类型变量
	time(&now);      //获取系统日期和时间
	localtime_s(&t, &now);   //获取当地日期和时间


	string uptime = "";
	uptime.append(to_string(t.tm_year + 1900));
	uptime.append("年");
	uptime.append(to_string(t.tm_mon + 1));
	uptime.append("月");
	uptime.append(to_string(t.tm_mday));
	uptime.append("日");
	product.upTime = uptime;

}
string Product::getID_seller()
{
	return ID_seller;
}
void Product::setID_seller(Product& product, string seller)
{
	product.ID_seller = seller;
}
int Product::getNumber()
{
	return Number;
}
void  Product::setNumber(bool add_or_sub,int num)
{
	if (add_or_sub)	
		Number += num;	
	else
	    Number -= num;
			
}
bool Product::getState()
{
	return State;
}
string Product::showState()
{
	if (getState())
		return "销售中";
	else
		return "已下架";
}
void Product::setState(bool state )
{
	State = state;
}
string  Product::getDescription()
{
	return Description;
}
void Product::setDescription(string description)
{
	Description = description;
}
void Product::show_all_information()
{
	cout << endl;
	cout << std::left << setw(16) << getID_product() 
		 << std::left << setw(16) << getProductName() 
		 << std::left << setw(14) << getPrice() 
		 << std::left << setw(18) << getupTime() 
		 << std::left << setw(16) << getID_seller() 
		 << std::left << setw(16) << getNumber() 
		 << std::left << setw(16) << showState() 
		 << endl<<endl;
}
void Product::show_detail_information()
{
	cout << endl;
	cout <<"商品ID："<<getID_product() << endl 
		 <<"商品名称：" << getProductName() << endl 
		 <<"商品价格：" << getPrice() << endl
		 <<"上架时间：" << getupTime() << endl 
		 <<"商品卖家：" << getID_seller() << endl
		 <<"商品数量：" << getNumber() << endl
		 <<"商品状态：" <<showState() << endl << endl;

}

bool Product::if_repeated(vector<Product> products, string add_product)
{
	if (products.size() == 0)
	{
		return false;
	}
	for (unsigned i = 0; i < products.size(); i++)
	{
		if (products[i].getProductName() == add_product)
		{
			return true;
		}
		if (i == products.size() - 1)
		{
			return false;
		}
	}

}
