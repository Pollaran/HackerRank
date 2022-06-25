#include <iostream>


/*
	After spending 2 or 3 afternoons getting this to work I found out
	the hard way that these linked lists have a size cap. Implementing
	a class structure with functions to check string input for type int 
	is ideal. Until then, int max 28 sadness
*/


using namespace std;

int main(){
	//<Housekeeping>
	struct node{
		int data;
		node* next;
	};
	
	int l = 0; // list input
	int m; // m(th)-to-last input5
	int len = 0; // list size
	// V V Crashes with anything larger. V V
	const int INPUT_MAX = 29; // Need string and conversion functions in a class, not struct
	// 	const int INPUT_MAX = 2 ^ 32 - 1; //
	// ^^ REQ INT MAX ^^ NEED CLASSES AND STRING CONVERSION? //

	node* n = NULL; // Node pointers for building
	node* h = NULL;
	node* t = NULL;
	// </Housekeeping>

	// Take m(th)-to-last
	cout << "INPUT MAX OF 28 \\\\ CTRL+Z TO EXIT" << endl; // Needs classes for fix, no time :(
	cout << "Pos from last: ";
	cin >> m;
	if (!cin){
		cout << "NOT AN INT!\n";
		system("pause");
		exit(666);
	}

	//Take header node
	cout << "Enter first node: ";
	cin >> l;
	if (!cin){
		cout << "NOT AN INT!\n";
		system("pause");
		exit(666);
	}
	// Create node for linked list
	n = new node; // Point n ptr to new node
	h = n; // Bring head ptr to new node
	t = n; // Bring temp ptr to new node
	t->data = l;// Set data for new node
	t->next = NULL; //Close list incase
	len++; //Update list size

	while(l < INPUT_MAX){
		// Take  input
		cout << "Enter next node: ";
		cin >> l;
		// Catch bad input type
		if (!cin && !cin.eof()){
			cout << "NOT AN INT!\n";
			system("pause");
			exit(666);
		}
		// Catch for ctrl+z
		if (cin.eof()){ // TODO: Add more validation
			break;
		}
		else{
			len++; // Update list size
			//Build node
			n = new node;
			n->data = l; // Insert data into node once validated
			n->next = NULL; //  Close off list
			t->next = n; // Link prev node
			t = n; // Bring pointer forward
		}

	}
	
	if (m > len){ // Check if valid index
		cout << "NIL\n";
		system("pause");
		exit(-666);
	}


	// BUG -- LIST LEN==2 && M==2 GIVES LAST NODE --
	if (len == 2 && m == 2){
		cout << h->data << endl;
	}

	else{ // If list is longer, than begin search
		int itteration = len - m; // Get itteration depth // 1 indexing defeated
		int ctr = 0;
		t = h; //Bring temp back to head
	
		for (int ctr = 0; ctr < itteration; ctr++){
			if (t->next == NULL){
				cout << "\nNULL POINTER\n";
				break; 
			}

			t = t->next;
		}

		cout << t->data << endl;
	}


	system("pause");
}