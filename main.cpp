#include <iostream>
#include "doubly_linked_list.h"

using namespace std;

void displayMenu(){
	cout << "\n==============================================================================";
	cout << "\n1.create a list";
	cout << "\n2.insert an item into the list";
	cout << "\n3.insert an item at the front of list";
	cout << "\n4.search items in the list";
	cout << "\n5.empty the list";
	cout << "\n6.check if the list is empty or not";
	cout << "\n7.copy a list from origin";
	cout << "\n8.get the length of list"; 
	cout << "\n9.print the list";
	cout << "\n10.print the list in reverse order";
	cout << "\n11.delete items from the list";
	cout << "\nEnter other numbers to exit"; 
	cout << "\n==============================================================================";
	cout << "\n\nEnter choice : ";
}
int main(){
	int flag = 1;
	DL_List<int> list1;
	while (flag > 0 && flag < 12){
		displayMenu();
		cin >>flag;
		switch(flag){
			case 1:
				{
					cout <<"\nA linked list of int was created";
				break;
				}
			case 2:
				{
                    			cout << "\nPlease enter an item:";
                    			int temp;
                    			cin >>temp;
                    			list1.insert_back(temp);
                    			cout <<"\nSuccess!";
					break;
				}
			case 3:
                		{
                        		cout << "\nPlease enter an item:";
                        		int temp;
                        		cin >>temp;
                        		list1.insert_front(temp);
                        		cout <<"\nSuccess!";
					break;
				}
			case 4:
				{
                        		cout << "\nPlease enter an item:";
                        		int temp;
                        		cin >>temp;
                        		list1.search_element(temp);
					break;
				}
			case 5:
                		{
					list1.empty();
					break;
                		}
			case 6:
                		{
					cout <<"\nList is";
					list1.is_empty() ? cout<<" empty." : cout <<" not empty.";
					break;
				}
			case 7: // has problem
                		{
                            DL_List<int> list2(list1);
                            DL_List<int> list3;
                            list3 = list1;
                            list1.print();
                            list2.print();
                            list3.print();
                			break;
				}
			case 8:
				{
					cout<<"\nThe length of the list is "<<list1.get_length()<<endl;
					break;
				}
			case 9:
            			{
					list1.print();
            				break;
				}
			case 10:
            			{
					list1.reverseprint();
					break;
				}
			case 11:
				{
					cout <<"\nPlease enter an item:";
					int item;
					cin >>item;
					list1.delete_element(item);
					break;
				}
		}
	}
	return 0;
}
