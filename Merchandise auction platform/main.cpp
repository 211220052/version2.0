#include <iostream>
#include<string>
#include<vector>
#include <stdlib.h>
#include <ctime>
#include <cstdio>
#include<fstream>
#include"Administrator.h"
#include"file_io.h"
#include"menu.h"
using namespace std;
//��Ʒ
string productID;
string productName;
float productPrice;
string uptime;
string sellerID;
int number;
bool state;
string  description;
//�û�
string ID;
string name;
string phone;
string address;
string password;
bool open;
float account;
string identity;

void read_users_file(vector<User>& users);
void read_products_file(vector<Product>& products);
void read_orders_file(vector<Order>& orders);
void write_users_file(vector<User> users);
void write_products_file(vector<Product> products);
void write_orders_file(vector<Order> orders);


int main()
{
    vector<Product> Products; vector<User> Users; vector<Order> Orders;
     read_users_file(Users);
     read_products_file(Products);
     read_orders_file(Orders);
    string admin = "admin";
    password = "123456";
    Administrator administrator(admin, password);
    while (true)//1.����Ա��¼   2.�û�ע��   3.�û���¼   4.�˳�����
    {
        main_menu();
        cout << "�����������"; string serial; cin >> serial;      
        switch (serial[0])
        {           
//----------------------------------------------                   ����Ա��¼                       ---------------------------------------------- 
        case '1': {//case1          
while (true) { //����Ա��¼          
 cout << "���������Ա������";  cin >> admin;                               
 while (true){//��ȷ��������               //������ȷ��������                .
            if (admin == administrator.getName())
            {
             cout << "���������룺";   cin >> password;  //������ȷ�������Ա����                                  
            if (password == administrator.getPassword())
            {//����Ա����
            administrator.setOpen(1); cout << "����Ա��¼�ɹ���" << endl<<endl; 
            while (true)
            {//�������Ա����
            admin_menu();
            cout <<endl<< "���������Ա������" ; string serial_admin; cin >> serial_admin;
            //1.�鿴������Ʒ  2.������Ʒ  3.�¼���Ʒ  4.�鿴���ж���  5.�鿴�����û�  6.����û�  7.ע��" 
            switch (serial_admin[0])
            {//switch (serial_admin)
            case '1': {
            product_menu();                            
            administrator.Show_all_products( Products);                                                             
            continue;
                      }                               
            case '2': {
            cout << endl << "������Ҫ��������Ʒ������:";
            cin >> productName;
            administrator.search_product(Products, productName);
            continue;
                      }
            case '3': {
            cout << "������Ҫ�¼ܵ���Ʒ��ID:"; 
            cin >> productID;
            administrator.off_product(Products, productID);
            continue;
                      }
            case '4': {
            order_menu();
            administrator.View_all_order(Orders);
            continue;
                       }
            case '5': {
            view_alluser_menu();
            administrator.View_all_user(Users);
            continue;
                       }
            case '6': {
                                
            cout << "������Ҫ������û�ID��";
            cin>>ID;
            administrator.Block_user(Users,ID);
            break;
                      }
            case '7': {                       
            goto main_break;
            break;
                       }
            default:{                            
            cout << "û�д˲�����"<<endl;
            continue;
            }

            }//switch (serial_admin)
            }//�������Ա����
            

            }//����Ա����
            else { cout << "�����������"; }
                 
            }
            else { cout << "����Ա��������!"; break; }
                                
             }//��ȷ��������              
             }//����Ա��¼
             }//case1       
//----------------------------------------------                    �û�ע��                        ---------------------------------------------- 
        case '2': {//case '2'         
        cout << "������Ҫע���û�������:"; cin >> name ;
        cout << "������Ҫע���û��ĵ绰��"; cin >> phone;
        cout << "������Ҫע���û��ĵ�ַ��"; cin >> address ;
        cout << "������Ҫע���û������룺"; cin >> password ;                       
        User user( name, phone, address, password);                
        user.Register_user(Users, user); 
        cout << endl << endl; main_menu();
        continue;
            }//case '2'        
//----------------------------------------------                    �û���¼                        ----------------------------------------------  
        case '3': {//case3           
while (true){//�û���¼               
cout << "�������û�����";  cin >> name;   bool flag = 0;   unsigned i;                                                                          
for ( i = 0; i < Users.size(); i++)
{
if (name == Users[i].getName()&& Users[i].getOpen()){    flag = 1;
while (true) {
    cout << "���������룺";  cin >> password;//������ȷ�����û�����   
    if (password == Users[i].getPassword())
    {//if password == Password
    cout << "�û���¼�ɹ���" << endl;
    user_menu();
    cout << endl;
    while (true) {//ѡ�����
            cout << "��ѡ����ݣ�"; string serial_select; cin >> serial_select;                     
            switch (serial_select[0]){
            
            case'1'://�������
            {//���
                while (true) {
                    buyer_menu(); cout << "��ѡ�������"; string serial_buyer; cin >> serial_buyer;
                    //1.�鿴��Ʒ�б�  2.������Ʒ   3.������Ʒ  4.�鿴��ʷ����  5.�鿴��Ʒ��ϸ��Ϣ  6.�����û�������"
                    switch (serial_buyer[0])
                    {
                    case '1': {
                        product_menu();
                        Users[i].Show_all_products(Products);
                        continue;
                    }
                    case '2': {                   
                        cout << "������Ҫ������Ʒ��ID:";  cin >> productID; 
                        cout<< "������Ҫ������Ʒ�ĸ���:"; cin>> number;
                        state=Users[i].Buy_product(Users[i].getID(), Users[i],Users, Products, productID, number);
                        if (state)
                        {
                            for (unsigned i_ = 0; i_ < Products.size(); i_++)
                            {
                                if (Products[i_].getProductName() == productName)
                                {
                                    productID = Products[i_].getID_product();
                                    productPrice = Products[i_].getPrice();
                                    sellerID = Products[i_].getID_seller();
                                    Order order(productID, productPrice, number, sellerID, Users[i].getID());
                                    order.SettradeTime(order);
                                    order.SetID_and_Addorder(Orders, order);
                                }
                            }
                            
                        }                 
                        continue;
                    }                                     
                    case '3': {
                        cout << "������Ҫ��������Ʒ:"; cin >> productName;
                        Users[i].search_product(Products, productName);
                        continue;
                    }
                    case '4': {
                    order_menu();
                    Users[i].View_historical_order_buyer(Orders,Users[i].getID());
                    continue;
                    }//case4
                    case '5': {
                        cout << "����������Ҫ�鿴����ƷID��";  cin >> productID;
                        Users[i].View_details(Products, productID);
                        continue;
                    }             
                    case '6': { user_menu(); break; }
                    default: { 
                        cout << "û�д˲�����"; 
                        continue; 
                    }   
                    }      
                    break;
                }
            }//���
            continue;//�����û�������
            case'2'://��������
            {// ����
                while (true) {
                    seller_menu();
                    //1.������Ʒ  2.�鿴������Ʒ  3.�޸���Ʒ��Ϣ  4.�¼���Ʒ  5.�鿴��ʷ����  6.�����û�������"
                    cout << "��ѡ�������"; string serial_seller; cin >> serial_seller;
                    switch (serial_seller[0])
                    {
                    case '1': {
                        cout << "��������Ʒ���ƣ�"; cin >> productName;
                        cout << "��������Ʒ�۸�"; cin >> productPrice;
                        cout << "��������Ʒ������"; cin >> number;
                        cout << "��������Ʒ������"; cin >> description;
                        Product product(productName, productPrice, number, description);                     
                        if (/*product.if_repeated(Products, productName) == false &&*/ number >= 1)                           
                                Users[i].Release_products(Products, product, Users[i]);                          
                        else { cout << "�ϼ�ʧ�ܣ�������Ʒ���Ƿ��ظ����ϼ������Ƿ���ȷ���۸��Ƿ���ȷ"<<endl; }  
                        continue;
                    }
                    case '2': {  
                        product_menu();
                        Users[i].View_released_products(Products, Users[i].getID());
                        continue;
                    }
                    case '3': {
                        cout << "�����뱻�޸���Ʒ��ID��"; cin >> productID;  cout << "������Ҫ�޸ĵ���Ϣ��1.�۸� 2.��������"; cin >> number; cout << "������Ҫ�޸ĺ���Ϣ��";
                    switch (number) { case 1:cin >> productPrice; break; case 2:cin >> description; break; }
                        Users[i].Modify_information(Products,productID, Users[i].getID(),number,productPrice,description);                 
                        continue;
                    }
                    case '4': {
                        cout << "�����뱻�¼���Ʒ��ID��"; cin >> productID;
                        Users[i].off_product(Products, productID, Users[i].getID());
                        continue;
                    }
                    case '5': {
                    order_menu();
                    Users[i].View_historical_order_seller(Orders, Users[i].getID());
                    continue;
                    }
                    case '6': { user_menu(); break; }
                    default: { cout << "û�д˲�����"; continue; }  
                    }   
                    break;       
                }               
            }// ����
            continue;//�����û�������
            case'3'://������Ϣ����
            {
                while (true) {
                    PIM_menu();
                    //1.�鿴��Ϣ  2.�޸���Ϣ  3.��ֵ  4.�����û�������
                    cout << "��ѡ�������"; string serial_PIM; cin >> serial_PIM;
                    switch (serial_PIM[0])
                    {
                    case '1': {
                        Users[i].view_PIMinformation(Users[i]);
                        continue;
                    }
                    case '2': {                      
                    cout << "������Ҫ�޸ĵ���Ϣ��1.�û��� 2.��ϵ��ʽ 3.��ַ����"; cin >> number; cout << "������Ҫ�޸ĺ���Ϣ��";
                    switch (number) { case 1:cin >> name; break; case 2:cin >> phone; break; case 3:cin >> address; break; }
                    Users[i].Modify_PIMinformation( Users,Users[i].getID(),number, name,phone,address);
                    continue;
                    }
                    case '3': {
                    cout << "�������ֵ��"; cin >> account;                   
                    Users[i].Modify_PIMaccount(Users,Users[i].getID(),account);
                    continue;
                    }                  
                    case '4': { user_menu(); break; }
                    default: { cout << "û�д˲�����"; continue; }    }    break;  }

            }
            continue;//�����û�������
            case'4'://ע����¼
            {
                goto main_break;
            }
            default: { cout << "û�д˲�����"; continue; }   
                                       }                      }//��ѡ�����

               
    }//if password == Password
    else  cout << "�����������" << endl; }     }  //if name == Users[i].getName()                                         
}     
if(flag==0) { cout << "�޴��û������û��ѱ�����Ա����!" << endl; continue; }      }//�û���¼                      
                  }//case3                              
//----------------------------------------------                    �˳�����                        ---------------------------------------------- 
        case '4': {
            write_users_file(Users);
            write_products_file(Products);
            write_orders_file(Orders);
            cout << "�����˳��ɹ�!  ........";
            return 0;
            }  
//----------------------------------------------                    ��������                        ---------------------------------------------- 
        default:  { cout << "��������ȷ������" << endl;}
        }
        main_break: ;       
    }   // 1.����Ա��¼   2.�û�ע��   3.�û���¼   4.�˳�����     

}


