#include <bits\stdc++.h>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;


struct Product{
	private:
		int ID;
		string Name;
		int Price;
		int Quantity;
	public:
		void setID(int sID){
			ID = sID;
		}
		void setName(string sName){
			Name = sName;
		}
		void setPrice(int sPrice){
			Price = sPrice;
		}
		void setQuantity(int sQuantity){
			Quantity = sQuantity;
		}
		int getID(){
			return ID;
		}
		string getName(){
			return Name;
		}
		int getPrice(){
			return Price;
		}
		int getQuantity(){
			return Quantity;
		}
		
};




void CompilerScrean(){
	cout << "							You are in main manu\n";
	cout << "Please choose the option\n";
	cout << "1. List\n";
	cout << "2. Search\n";
	cout << "3. Add\n";
	cout << "4. Delete\n";
	cout << "5. Save changes\n";
	cout << "6. Save and exit\n";
}





void Converter(fstream &File,  vector<Product> &vProduct){
	string Line;
	while (getline(File, Line)){
		Product product;
		stringstream stringcoulm(Line);
		string sID, Name, sPrice, sQuantity;
		
		getline(stringcoulm, sID, ',');
		getline(stringcoulm, Name, ',');
		getline(stringcoulm, sPrice, ',');
		getline(stringcoulm, sQuantity, ',');
		
		product.setID(stoi(sID));
		product.setName(Name);
		product.setPrice(stoi(sPrice));
		product.setQuantity(stoi(sQuantity));
		
		vProduct.push_back(product);
		
	}
}




void UserBack(){
	cout << "Enter Y go back" << endl;
	while (true){
	char userBack; cin >> userBack;
	if (userBack == 'Y' || userBack == 'y'){
			system("cls");
			CompilerScrean();
			break;
		} else {
			system("cls");
			cout << "Enter Y go back" << endl;
		}
	}
}



void List_of_product(vector<Product> &vProduct){
	system("cls");
	int TotalPrice = 0, TotalQuantity = 0, TotalValue = 0;
	for (int i=0; i<vProduct.size(); i++){
		TotalPrice = TotalPrice + vProduct[i].getPrice();
		TotalQuantity = TotalQuantity + vProduct[i].getQuantity();
		TotalValue = TotalValue + vProduct[i].getPrice() * vProduct[i].getQuantity();
		cout << "ID: " << vProduct[i].getID() << endl;
		cout << "Name: " << vProduct[i].getName() << endl;
		cout << "Price: " << vProduct[i].getPrice() << endl;
		cout << "Quantity: " << vProduct[i].getQuantity() << endl;
		cout << "------------------" << endl;
	}
	cout << "Total Price: " << TotalPrice << endl;
	cout << "Total Quantity: " << TotalQuantity << endl;
	cout << "Total Value: " << TotalValue << endl << endl;
	UserBack();
}




void Display(){
	cout << "Enter option" << endl;
	cout << "1. ID" << endl;
	cout << "2. Name" << endl;
	cout << "3. Price" << endl;
	cout << "4. Quantity" << endl;
}

template <typename T>

void Boolean_Val(bool &Count, T &userEnter){
		if (Count  == 1){
		cout << "There is no such: " << userEnter << endl;
	}
}




void Search_by_ID(vector<Product> &vProduct){
	system("cls");
	cout << "Enter ID" << endl;
	bool Found = true;
	int userEnter; cin >> userEnter;
	for(int i=0; i<vProduct.size(); i++){
		if (userEnter == vProduct[i].getID()){
			cout << vProduct[i].getID() << " " << vProduct[i].getName() << " " <<
			vProduct[i].getPrice() << " " << vProduct[i].getQuantity() << endl;
			Found = false;
			break;
		}
	}
	Boolean_Val(Found, userEnter);
	UserBack();
}





void Search_by_Name(vector<Product> &vProduct){
	system("cls");
	cout << "Enter Name" << endl;
	bool Found = true;
	string userEnter; cin >> userEnter;
	for(int i=0; i<vProduct.size(); i++){
		if (userEnter == vProduct[i].getName()){
		cout << vProduct[i].getID() << " " << vProduct[i].getName() << " " <<
			vProduct[i].getPrice() << " " << vProduct[i].getQuantity() << endl;
			Found = false;
		}
	}
	Boolean_Val(Found, userEnter);
	UserBack();
}





void Search_by_Price(vector<Product> &vProduct){
	system("cls");
	cout << "Enter Price" << endl;
	bool Found = true;
	int userEnter; cin >> userEnter;
	for(int i=0; i<vProduct.size(); i++){
		if (userEnter == vProduct[i].getPrice()){
		cout << vProduct[i].getID() << " " << vProduct[i].getName() << " " <<
			vProduct[i].getPrice() << " " << vProduct[i].getQuantity() << endl;
			Found = false;
		}
	}
	Boolean_Val(Found, userEnter);
	UserBack();
}





void Search_by_Quantity(vector<Product> &vProduct){
	system("cls");
	cout << "Enter Quantity" << endl;
	bool Found = true;
	int userEnter; cin >> userEnter;
	for(int i=0; i<vProduct.size(); i++){
		if (userEnter == vProduct[i].getQuantity()){
		cout << vProduct[i].getID() << " " << vProduct[i].getName() << " " <<
			vProduct[i].getPrice() << " " << vProduct[i].getQuantity() << endl;
			Found = false;
		}
	}
	Boolean_Val(Found, userEnter);
	UserBack();
}





void Find_product_in_list(vector<Product> &vProduct){
	system("cls");
	Display();
	int userEnter; cin >> userEnter;
	switch(userEnter){
		case 1:
			Search_by_ID(vProduct);
		break;
		case 2:
			Search_by_Name(vProduct);
			break;
		case 3:
			Search_by_Price(vProduct);
			break;
		case 4:
			Search_by_Quantity(vProduct);
			
	}
}


bool compareByID(Product& a,Product& b)
	{
    return a.getID() < b.getID();
}





void Add_product_in_list(vector<Product> &vProduct){
	system("cls");
	cout << "Enter by order \n";
	cout << "ID :: Name :: Price :: Quantity \n";
	
	Product product;
	bool Found = false;
	int ID, Price, Quantity; string Name;
	cin >> ID >> Name >> Price >> Quantity;;
	for (int i=0; i<vProduct.size(); i++){
		if (vProduct[i].getID() == ID){
			cout << "There is such ID: " << ID << " we cant add this \n";
			Found = true;
			break;
		}  
	}
	if (!Found){
		product.setID(ID);
		product.setName(Name);
		product.setPrice(Price);
		product.setQuantity(Quantity);
		vProduct.push_back(product);
	sort(vProduct.begin(), vProduct.end(), compareByID);
	}
	UserBack();
}





void Delete_product_in_list(vector <Product> &vProduct){
	system("cls");
	cout << "Enter ID \n";
	int ID; cin >> ID; 
	bool Found = false;
	for (int i=0; i<vProduct.size(); i++){
		if(vProduct[i].getID() == ID){
			vProduct.erase(vProduct.begin() + i);
			cout << "Product is successfully deleted \n";
			Found = true;
			break;
		}
	}
	if (!Found){
		cout << "We could'nt find such ID " << ID << endl;
	}
	UserBack();
}




void Save_changes(vector <Product> &vProduct){
	 system("cls");
    ofstream File("Product_Menegmant.csv");
    if (!File.is_open())
    {
        cout << "Error opening file!\n";
        UserBack();
        return;
    }
    for (int i = 0; i < vProduct.size(); i++)
    {
        File << vProduct[i].getID() << ","
             << vProduct[i].getName() << ","
             << vProduct[i].getPrice() << ","
             << vProduct[i].getQuantity();

        if (i != vProduct.size() - 1)
        {
            File << '\n';
        }
    }
    File.close();
    cout << "Changes saved successfully!\n";
    UserBack();
}



void Save_exit(vector <Product> &vProduct){
	system("cls");
    ofstream File("Product_Menegmant.csv");
    if (!File.is_open())
    {
        cout << "Error opening file!\n";
        UserBack();
        return;
    }
    for (int i = 0; i < vProduct.size(); i++)
    {
        File << vProduct[i].getID() << ","
             << vProduct[i].getName() << ","
             << vProduct[i].getPrice() << ","
             << vProduct[i].getQuantity();

        if (i != vProduct.size() - 1)
        {
            File << '\n';
        }
    }
    File.close();
    cout << "Changes saved successfully!\n";
    
}
void digitalLogic(vector<Product> &vProduct){
	sort(vProduct.begin(), vProduct.end(), compareByID);
	int UserExit = false;
	while (UserExit != true){
		int userEnter; cin >> userEnter;
		switch(userEnter){
			case 1: 
				List_of_product(vProduct);
				break;
			case 2:
				Find_product_in_list(vProduct);
				break;
			case 3:
				Add_product_in_list(vProduct);
				break;
			case 4:
				Delete_product_in_list(vProduct);
				break;
			case 5:
				Save_changes(vProduct);
				break;
			case 6:
				Save_exit(vProduct);
				UserExit = true;
				break;
		}
	}
}





int main(){
	CompilerScrean();
	fstream File;
	
	File.open("Product_Menegmant.csv", ios::in);
	vector <Product> vProduct;
	Converter(File, vProduct);
	File.close();
	
	digitalLogic(vProduct);
}