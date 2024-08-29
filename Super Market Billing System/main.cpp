#include<iostream>
#include<sstream>
#include<fstream>
#include<windows.h>

using namespace std;

class Product {
private:
	string ItemName;
	int ItemRate, ItemQuantity;

public: 
	// inline constructor
	Product() : ItemName(""),ItemRate(0),ItemQuantity(0) {}

	// setter function
	void setName(string name) {
		ItemName = name;
	}
	
	void setRate(int rate) {
		ItemRate = rate;
	}
	void setQuantity(int quantity) {
		ItemQuantity = quantity;
	}

	// getter Functions
	string getName() {
		return ItemName;
	}
	
	int getRate() {
		return ItemRate;
	}
	int getQuantity() {
		return ItemQuantity;
	}

};


void addItem(Product p) {
	bool close = false;
	while (!close) {
		
		int choice;
		cout << "\t1.Add Item" << endl;
		cout << "\t2.Close" << endl << endl;
		cout << "\n\tEnter your choice:";
		cin >> choice;
		
		if (choice == 1) {
			string name;
			int rate, quant;

			cout << "\tEnter the Item name: ";
			cin >> name;
			p.setName(name);

			cout << "\tEnter the Item Rate: ";
			cin >> rate;
			p.setRate(rate);

			cout << "\tEnter the Item Quantity: ";
			cin >> quant;
			p.setQuantity(quant);
			
			
			ofstream outFile("bill.txt", ios::app);
			if (!outFile) {
				cout << "Error: File Can't Open." << endl;
			}
			else {
				outFile << "\t" << p.getName() << " : " << p.getRate() << " : " << p.getQuantity() << endl << endl;
			}
			outFile.close();
			cout << "\tItem Added Succesfully!" << endl;
			//Sleep(1000);
		}//
		else if (choice  == 2) {
			system("cls");
			close = true;
			//cout << "\tBack to the Main Menu!" << endl;
			//Sleep(1000);
		}
		
	}

	ifstream inFile("bill.txt");
	string line;
	while (getline(inFile, line)) {
		stringstream ss;
		ss << line;

		string name;
		int rate, quant;
		char delimiter;

		ss >> name  >> delimiter >> rate >> delimiter >> quant;

		cout << "\t" << name << " : "<< " : " << rate << " : " << quant << endl;
		//cout << line << endl;
		inFile.close();
	}


	
	//ofstream outFile("bill.txt", ios::out);
	//if (!outFile)cout << "Error:File Can't Open!" << endl;
	//outFile.close();
}




void printBill(Product p) {
	system("cls");
	ifstream inFile("bill.txt");

	string line;
	while (getline(inFile, line)) {
		stringstream ss;
		ss << line;

		string name;
		int rate, quant;
		char delimiter;

		ss >> name   >> delimiter >> rate >> delimiter >> quant;

	}

}


int main() {
	Product p;

	bool exit = false;
	while (!exit) {
		system("cls");
		int val;

		cout << "\t\t\t*******************************************************" << endl;;
		cout << "\t\t\t\tWelcome to Super market Billing System"<<endl;
		cout << "\t\t\t*******************************************************" << endl<<endl<<endl;
		cout << "\t1.Create Bill." << endl;
		cout << "\t2.Print Bill." << endl;
		cout << "\t3.Exit." << endl;

		cout << "\n\tEnter your Choice: ";
		cin >> val;
		if (val == 1) {
			system("cls");
			addItem(p);
			Sleep(2000);
		}
		else if (val == 2) {
			printBill(p);
		}

	
	}


}