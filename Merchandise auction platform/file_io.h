#pragma once
void read_users_file(vector<User>& users)
{
    User user("name", "phone", "address", "password");
    ifstream file;
    file.open("users.txt");
    string str;
    if (file.is_open())
    {
        while (getline(file, str))
        {
            user.setID(str);
            getline(file, str);
            user.setName(str);
            getline(file, str);
            user.setPhone(str);
            getline(file, str);
            user.setAddress(str);
            getline(file, str);
            user.setPassword(str);
            getline(file, str);
            user.setOpen(str);
            getline(file, str);
            user.setAccount(str);
            users.push_back(user);
        }
    }
    file.close();
}
void read_products_file(vector<Product>& products)
{

    //    Product(string productName, float price, int number, string  description);
    Product product("productName", 0, 0, "description");
    ifstream file;
    file.open("products.txt");
    string str;
    if (file.is_open())
    {
        while (getline(file, str))
        {
            product.setID_product(str);
            getline(file, str);
            product.setProductName(str);
            getline(file, str);
            product.setPrice(str);
            getline(file, str);
            product.setupTime(str);
            getline(file, str);
            product.setID_seller(str);
            getline(file, str);
            product.setNumber(str);
            getline(file, str);
            product.setState(str);
            getline(file, str);
            product.setDescription(str);
            products.push_back(product);

        }
    }
    file.close();
}
void read_orders_file(vector<Order>& orders)
{

    //Order(string id_product, float price, int number, string id_seller, string id_buyer);
    Order order("id_product", 0, 0, "id_seller", "id_buyer");
    ifstream file;
    file.open("orders.txt");
    string str;
    if (file.is_open())
    {
        while (getline(file, str))
        {
            order.setID_order(str);
            getline(file, str);
            order.setID_product(str);
            getline(file, str);
            order.setPrice(str);
            getline(file, str);
            order.setNumber(str);
            getline(file, str);
            order.setTrade_time(str);
            getline(file, str);
            order.setID_seller(str);
            getline(file, str);
            order.setID_buyer(str);
            orders.push_back(order);
        }
    }
    file.close();
}

void write_users_file(vector<User> users)
{
    ofstream file;
    file.open("users.txt", ios::ate);
    if (file.is_open())
    {
        for (unsigned int i = 0; i < users.size(); i++)
        {
            file << users[i].getID() << endl
                << users[i].getName() << endl
                << users[i].getPhone() << endl
                << users[i].getAddress() << endl
                << users[i].getPassword() << endl
                << to_string(users[i].getOpen()) << endl
                << to_string(users[i].getAccount()) << endl;
        }
    }
    file.close();
}
void write_products_file(vector<Product> products)
{
    ofstream file;
    file.open("products.txt", ios::ate);
    if (file.is_open())
    {
        for (unsigned int i = 0; i < products.size(); i++)
        {
            file << products[i].getID_product() << endl
                << products[i].getProductName() << endl
                << to_string(products[i].getPrice()) << endl
                << products[i].getupTime() << endl
                << products[i].getID_seller() << endl
                << to_string(products[i].getNumber()) << endl
                << to_string(products[i].getState()) << endl
                << products[i].getDescription() << endl;
        }

    }
    file.close();
}
void write_orders_file(vector<Order> orders)
{
    ofstream file;
    file.open("orders.txt", ios::ate);
    if (file.is_open())
    {
        for (unsigned int i = 0; i < orders.size(); i++)
        {
            file << orders[i].getID_order() << endl
                << orders[i].getID_product() << endl
                << to_string(orders[i].getPrice()) << endl
                << to_string(orders[i].getNumber()) << endl
                << orders[i].getTrade_time() << endl
                << orders[i].getID_seller() << endl
                << orders[i].getID_buyer() << endl;
        }
    }
    file.close();
}

