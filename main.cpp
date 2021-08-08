#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

bool ordered = false, numOrdered;
float TOTprice = 0, orderPrice;
string answer;
int i, j, order[9][2];

struct stuff {
	
	int number;
	float weight, price;
	
} apple, banana, melon;

int writeReciept() {
	
	cout << setprecision(2) << fixed;
	
	for (i = 0; i < 9; i++) {
		
		if (order[i][0] == 0) {
			
			cout << "Apple x" << order[i][1];
			
			if (order[i][1] < 10) {
				
				cout << "............";
			}
			else{
				
				cout << "...........";
			}
			
			orderPrice = order[i][1] * apple.weight * apple.price;
			cout << order[i][1] * apple.weight * apple.price;
			
			if (orderPrice < 10) {
				
				cout << "   BUCKS" << endl;
			}
			else {
				
				cout << "  BUCKS" << endl;
			}
			
			TOTprice = orderPrice + TOTprice;
		}
		else if (order[i][0] == 1) {
			
			cout << "Banana x" << order[i][1];
			
			if (order[i][1] < 10) {
				
				cout << "...........";
			}
			else {
				
				cout << "..........";
			}
			
			orderPrice = order[i][1] * banana.weight * banana.price;
			cout << order[i][1] * banana.weight * banana.price;
			
			if (orderPrice < 10) {
				
				cout << "   BUCKS" << endl;
			}
			else {
				
				cout << "  BUCKS" << endl;
			}
			
			TOTprice = orderPrice + TOTprice;
		}
		else if (order[i][0] == 2) {
			
			cout << "Melon x" << order[i][1];
			
			if (order[i][1] < 10) {
				
				cout << "............";
			}
			else {
				
				cout << "...........";
			}
			
			orderPrice = order[i][1] * melon.weight * melon.price;
			cout << order[i][1] * melon.weight * melon.price;
			
			if (orderPrice < 10) {
				
				cout << "   BUCKS" << endl;
			}
			else if (orderPrice >= 10 && orderPrice < 100) {
				
				cout << "  BUCKS" << endl;
			}
			else {
				
				cout << " BUCKS" << endl;
			}
			
			TOTprice = orderPrice + TOTprice;
		}
	}
	
	cout << "--------------------------------\nTotal price........." << TOTprice << " BUCKS" << endl;
}

int main () {
	
	
	apple.weight = 0.192;
	apple.price = 1.59;
	
	banana.weight = 0.178;
	banana.price = 1.09;
	
	melon.weight = 2.21;
	melon.price = 1.49;
	
	for (i = 0; i < 9; i++) {
		
		order[i][1] = -1;
		order[i][0] = -1;
	}
	
	i = 0;
	
	while (ordered == false && i < 9) {
		
		if (i == 0) {
			
			cout << "[" << i << "/9] What do you want to buy? (apple/banana/melon): ";
		}
		else {
			
			cout << "[" << i << "/9] What do you want to buy? (apple/banana/melon, if you want to finish type 'finish'): ";
		}
		
		cin >> answer;
		numOrdered = false;
		
		if (answer == "apple") {
			
			while (numOrdered == false) {
			
				order[i][0] = 0;
				cout << "How many do you want to buy?: ";
				cin >> order[i][1];
				
				if (order[i][1] < 1 || order[i][1] > 99) {
					
					cout << "ERROR: The number can't be less than 1 or more than 99." << endl;
				}
				else {
					
					numOrdered = true;
					i++;
				}
			}
		}
		else if (answer == "banana") {
			
			while (numOrdered == false) {
			
				order[i][0] = 1;
				cout << "How many do you want to buy?: ";
				cin >> order[i][1];
				
				if (order[i][1] < 1 || order[i][1] > 99) {
					
					cout << "ERROR: The number can't be less than 1 or more than 99." << endl;
				}
				else {
					
					numOrdered = true;
					i++;
				}
			}
		}
		else if (answer == "melon") {
			
			while (numOrdered == false) {
				
				order[i][0] = 2;
				cout << "How many do you want to buy?: ";
				cin >> order[i][1];
				if (order[i][1] < 1 || order[i][1] > 99) {
					
					cout << "ERROR: The number can't be less than 1 or more than 99." << endl;
				}
				else {
					
					numOrdered = true;
					i++;
				}
			}
		}
		else if (i != 0 && answer == "finish") {
			
			ordered = true;
		}
		else {
			
			cout << "ERRORE: Syntax not correct." << endl;
		}
		
	}
	
	cout << "\nRECIEPT:\n" << endl;
	
	writeReciept();
	
	system("pause");
}
