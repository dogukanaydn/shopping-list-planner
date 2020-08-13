// Shopping List Planner Console Application

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>


/// <summary>
/// Start of Shopping List Class
/// </summary>


class ShoppingLists {
public:
	ShoppingLists();		// Default Constructor
	ShoppingLists(int, std::string);	// Overloaded Constructor

	int getShoppingId();
	std::string getShoppingName();

protected:
	int shoppingId;
	std::string shoppingName;
};

ShoppingLists::ShoppingLists() {
	shoppingId = 0;
}

ShoppingLists::ShoppingLists(int ID, std::string name) {
	shoppingId = ID;
	shoppingName = name;
}

int ShoppingLists::getShoppingId() {
	return shoppingId;
}

std::string ShoppingLists::getShoppingName() {
	return shoppingName;
}

/// <summary>
/// End of Shopping Class
/// </summary>

//---------------------------------------------------------//

/// <summary>
/// Start of Product Information
/// </summary>

class ProductInformation : public ShoppingLists {
public:
	ProductInformation();		// Default Constructor
	ProductInformation(int, std::string, int, std::string, std::string, int, std::string);		// Overloaded Constructor

	// Accessor Functions
	int getProductId();
	std::string getProductName();
	std::string getProductTitle();
	int getProductAmount();
	std::string getStatus();


private:
	int productId;
	std::string productName;
	std::string productTitle;
	int productAmount;
	std::string status;
};

ProductInformation::ProductInformation() {
	productId = 0;
}

ProductInformation::ProductInformation(int shopId, std::string shopName, int id, std::string proName, std::string proTitle, int proAmount, std::string stat) {
	shoppingId = shopId;
	shoppingName = shopName;
	productId = id;
	productName = proName;
	productTitle = proTitle;
	productAmount = proAmount;
	status = stat;
}

int ProductInformation::getProductId() {
	return productId;
}

std::string ProductInformation::getProductName() {
	return productName;
}

std::string ProductInformation::getProductTitle() {
	return productTitle;
}

int ProductInformation::getProductAmount() {
	return productAmount;
}

std::string ProductInformation::getStatus() {
	return status;
}

/// <summary>
/// End of Product Information Class
/// </summary>

// Vector of Shopping List and Product Information Class 
std::vector<ShoppingLists> newShoppingListInfo;
std::vector<ProductInformation> newProductInfo;
/////////////////////////////////////////////

// Show The All Shopping List
void showList();

// New List Function 
void newList();

// Add Item
void addItem(int shopID, std::string shopName);

// Edit Item Function
void editItem(int shopID, std::string shopName);

// Delete Item Function
void deleteItem(int shopID, std::string shopName);

// Done or Undone
void statusOfProduct(int shopID, std::string shopName);

// Second Menu
void shoppingListMenu(int shopID, std::string shopName);

// "--------------------------------" Thing 
void specialSign();

int main()
{
	int shopID;
	std::string shopName;
	bool isShop = false;

	int choice;
	std::cout << "Main Menu" << std::endl;
	std::cout << "1. Create New List" << std::endl;
	std::cout << "2. Show Shopping Lists" << std::endl;
	std::cout << "3. Exit The Program" << std::endl;


	std::cin >> choice;
	specialSign();
	switch (choice) {
	case 1:
		newList();
		break;
	case 2:
		showList();
		std::cout << "1. Go Back to Main Menu: \n";
		std::cout << "2. Make Changes to Lists: \n";

		int choice2;
		std::cin >> choice2;
		specialSign();
		switch (choice2)
		{
		case 1:
			main();
			break;
		case 2:

			std::cout << "Enter shopping ID in which list you want to make changes: ";
			std::cin >> shopID;
			std::cout << "Enter shopping name in which list you want to make changes: ";
			std::cin >> shopName;
			specialSign();
			if (newProductInfo.size() != 0) {
				for (int i = 0; i < newProductInfo.size(); i++) {
					int currentShopID = newProductInfo[i].getShoppingId();
					std::string currentShopName = newProductInfo[i].getShoppingName();

					if (currentShopID == shopID) {
						if (currentShopName.compare(shopName) == 0) {
							isShop = true;
							std::cout << "Selected List Succesfully \n";
							specialSign();
							shoppingListMenu(shopID, shopName);
						}
						else {
							std::cout << "Wrong Shopping Name !!!\n";
							specialSign();
							main();
						}
					}
				}
				if (isShop == false) {
					std::cout << "There is no list that Shopping ID !!!! \n";
					specialSign();
					main();
				}
			}
			else {
				std::cout << "Empty Lists. \n";
				main();
			}

			break;
		default:
			main();
			break;
		}
		break;
	case 3:
		std::cout << "Bye Bye. See you next time :)\n";
		exit(0);
	default:
		std::cout << "Invalid Choice!!!!! \n";
		specialSign();
		main();
		break;
	}

}

void shoppingListMenu(int shopID, std::string shopName) {
	int choice;
	std::cout << "Shopping List Menu" << std::endl;
	std::cout << "1. Add Item" << std::endl;
	std::cout << "2. Edit Item" << std::endl;
	std::cout << "3. Delete Item" << std::endl;
	std::cout << "4. Mark as Done Undone" << std::endl;
	std::cout << "5. Back to Main Menu" << std::endl;
	std::cout << "6. Exit The Program" << std::endl;
	std::cin >> choice;
	specialSign();

	switch (choice)
	{
	case 1:
		addItem(shopID, shopName);
		showList();
		shoppingListMenu(shopID, shopName);
		break;
	case 2:
		if (newProductInfo.size() != 0) {
			showList();
			editItem(shopID, shopName);
		}
		else {
			std::cout << "Empty List!!!!!\n";
		}
		break;


	case 3:
		if (newProductInfo.size() != 0) {
			showList();
			deleteItem(shopID, shopName);
		}
		else {
			std::cout << "Empty List!!!!!\n";
		}
		break;
	case 4:
		if (newProductInfo.size() != 0) {
			showList();
			statusOfProduct(shopID, shopName);
		}
		else {
			std::cout << "Empty List!!!!!\n";
		}
		break;
	case 5:
		main();
		break;
	case 6:
		exit(0);
	default:
		std::cout << "Invalid Choice!!!\n";
		std::cout << "Try Again!!!!!!!!!!!!!!!!!!!!!!!\n";
		break;
	}

	specialSign();

	shoppingListMenu(shopID, shopName);

}

void showList() {
	bool isList = false;


	std::cout << std::setw(25) << "Shopping ID" << std::setw(25) << "Shopping Name" << std::setw(25) << "Product ID" << std::setw(25) << "Product Name"
		<< std::setw(25) << "Product Title" << std::setw(25) << "Product Amount" << std::setw(25) << "Status \n";
	specialSign();
	if (newProductInfo.size() != 0) {

		for (int i = 0; i < newProductInfo.size(); i++) {


			std::cout << std::setw(25) << newProductInfo[i].getShoppingId() << std::setw(25) << newProductInfo[i].getShoppingName() << std::setw(25) << newProductInfo[i].getProductId() <<
				std::setw(25) << newProductInfo[i].getProductName() << std::setw(25) << newProductInfo[i].getProductTitle() << std::setw(25) << newProductInfo[i].getProductAmount()
				<< std::setw(23) << newProductInfo[i].getStatus() << std::endl;
			specialSign();

		}
	}
	else {
		std::cout << "Empty List. \n";
		specialSign();
		main();
	}

}

void newList() {
	int id;
	std::string name;
	std::cout << "Enter a Shopping List ID: ";
	std::cin >> id;
	std::cout << "Enter a Shopping List Name: ";
	std::cin >> name;
	specialSign();
	bool isList = false;

	if (newShoppingListInfo.size() != 0) {
		for (int i = 0; i < newShoppingListInfo.size(); i++) {
			if (id == newShoppingListInfo[i].getShoppingId()) {
				isList = true;
				std::cout << "There is a shopping list at this number !!!\n";
				specialSign();
				main();
			}
		}
		if (isList == false) {
			std::cout << "Creating New List. \n";
			ShoppingLists newShopList(id, name);
			newShoppingListInfo.push_back(newShopList);
			specialSign();
			shoppingListMenu(id, name);
		}
	}
	else {
		std::cout << "Creating New List. \n";
		ShoppingLists newShopList(id, name);
		newShoppingListInfo.push_back(newShopList);
		specialSign();
		shoppingListMenu(id, name);
	}

}

// Add Item Part Function
void addItem(int shopID, std::string shopName) {
	int proID, proAmount;
	std::string proName, proTitle;
	bool isProduct = false;

	std::cout << "-----------Enter Product Information-----------\n";
	std::cout << "Enter Product ID: ";
	std::cin >> proID;
	std::cout << "Enter Product Name: ";
	std::cin >> proName;
	std::cout << "Enter Product Title: ";
	std::cin >> proTitle;
	std::cout << "Enter Product Amount: ";
	std::cin >> proAmount;
	specialSign();

	if (newProductInfo.size() != 0) {
		for (int i = 0; i < newProductInfo.size(); i++) {
			if (proID == newProductInfo[i].getProductId() && shopID == newProductInfo[i].getShoppingId()) {
				isProduct = true;
				std::cout << "There is a product ID at this list. \n";
				std::cout << "Product could not be added. Sorry :( \n";
				std::cout << "Try Again. \n";
				specialSign();
				showList();
				shoppingListMenu(shopID, shopName);
			}
		}
		if (isProduct == false) {

			ProductInformation newProduct(shopID, shopName, proID, proName, proTitle, proAmount, "UNDONE");
			newProductInfo.push_back(newProduct);
			std::cout << "Item Added Successfully. \n";
			specialSign();
			showList();
			shoppingListMenu(shopID, shopName);
		}
	}
	else {
		ProductInformation newProduct(shopID, shopName, proID, proName, proTitle, proAmount, "UNDONE");
		newProductInfo.push_back(newProduct);
		std::cout << "Item Add Successfully. \n";
		specialSign();
		showList();
		shoppingListMenu(shopID, shopName);
	}
}

void editItem(int shopID, std::string shopName) {
	int productID;
	std::cout << "Enter a Product ID: ";
	std::cin >> productID;
	bool statOfProduct = false;

	for (int i = 0; i < newProductInfo.size(); i++) {
		if (shopID == newProductInfo[i].getShoppingId() && productID == newProductInfo[i].getProductId()) {
			int currentProductID = newProductInfo[i].getProductId();
			std::string currentProductName = newProductInfo[i].getProductName();
			std::string currentProductTitle = newProductInfo[i].getProductTitle();
			newProductInfo.erase(newProductInfo.begin() + i);

			int newAmount;
			std::cout << "Product is found.   \n";
			std::cout << "Enter New Amount: ";
			std::cin >> newAmount;
			ProductInformation newProduct(shopID, shopName, currentProductID, currentProductName, currentProductTitle, newAmount, "UNDONE");

			auto itPos = newProductInfo.begin() + i;
			auto newIt = newProductInfo.insert(itPos, newProduct);
			std::cout << "Changed New Amount Succesfully. \n";
			specialSign();
			statOfProduct = true;
			showList();
		}



	}
	if (statOfProduct == false) {
		std::cout << "You Entered Wrong  Product ID !!!!! \n";
		specialSign();
		showList();
	}

}

void deleteItem(int shopID, std::string shopName) {
	int productID;
	std::cout << "Enter a Product ID: ";
	std::cin >> productID;
	bool findProduct = false;

	for (int i = 0; i < newProductInfo.size(); i++) {
		if (shopID == newProductInfo[i].getShoppingId() && productID == newProductInfo[i].getProductId()) {
			newProductInfo.erase(newProductInfo.begin() + i);
			findProduct = true;
			std::cout << "Item Deleted Successfully !!!\n";
			specialSign();
			showList();
		}
	}
	if (findProduct == false) {
		std::cout << "You Entered Wrong Product ID !!!!! \n";
		specialSign();
		showList();

	}

}

// Status of Product ---- DONE & UNDONE ---- at the beginning of product class all status is UNDONE 

void statusOfProduct(int shopID, std::string shopName) {
	int productID;
	std::cout << "Enter a Product ID: ";
	std::cin >> productID;
	bool statOfProduct = false;

	for (int i = 0; i < newProductInfo.size(); i++) {
		if (shopID == newProductInfo[i].getShoppingId() && productID == newProductInfo[i].getProductId()) {
			int currentShopID = newProductInfo[i].getShoppingId();
			std::string currentShopName = newProductInfo[i].getShoppingName();
			int currentProductID = newProductInfo[i].getProductId();
			std::string currentProductName = newProductInfo[i].getProductName();
			std::string currentProductTitle = newProductInfo[i].getProductTitle();
			int currentProductAmount = newProductInfo[i].getProductAmount();
			newProductInfo.erase(newProductInfo.begin() + i);


			std::cout << "Product is found   \n";
			ProductInformation newProduct(shopID, shopName, currentProductID, currentProductName, currentProductTitle, currentProductAmount, "DONE");

			auto itPos = newProductInfo.begin() + i;
			auto newIt = newProductInfo.insert(itPos, newProduct);
			std::cout << "Status Change Successfully !!!! \n";
			specialSign();
			statOfProduct = true;
			showList();
		}
	}
	if (statOfProduct == false) {
		std::cout << "You Entered Wrong  Product ID !!!!! \n";
		specialSign();
		showList();
	}
}

void specialSign() {
	// Loop for ----------------- sign
	for (int i = 0; i < 188; i++) {
		std::cout << "-";
	}
	std::cout << std::endl;
}
