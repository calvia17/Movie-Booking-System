using namespace std;

#include <iostream>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

struct seat
{
	//defining seat array
	char s[7][10];
};

struct time
{
	//defining time array
	seat t[6];
};

//Function to display welcome page
void disp()
{
	system("cls");
	cout << "\n\n                     WELCOME TO ABC CINEMAS";
	cout << endl << "                    ------------------------\n\n";
	fflush(stdout);
	_getch();
}

void dt(int& q, char(&date)[3][20])
{
	//used to display available dates and take input of preferred date
	int g = 0, n = 3;
	cout << endl << endl << "Available dates: ";
	int i;
	for (i = 0; i < n; i++)
	{
		cout << endl << i + 1 << ". " << date[i];
		//displaying available dates
	}
	/*ensuring that entered choice is among the given choices
	  otherwise, input is taken again*/
	while (g == 0) {
		cout << "\nEnter the number corresponding to your choice: ";
		//taking input of preferred date
		cin >> q;
		for (i = 1; i <= n; i++)
		{
			if (q == i)
			{
				g = 1;
			}
		}
	}

}

//Function to display available movies and take input of preferred movie
void mv(int& q, int& m, char(&movie)[6][25])
{
	int h = 0, k = 0, mm[10];
	cout << "\nAvailable movies:";
	//display movies according to the date entered
	switch (q)
	{
		int i;
	case 1:
		for (i = 1; i < 6; i++)
		{
			if (i % 2 == 0)
			{
				cout << endl << h + 1 << ". " << movie[i];
				h++;
				mm[h] = i;
			}
		}
		break;
	case 2:
		for (i = 1; i < 6; i++)
		{
			if (i % 2 != 0)
			{
				cout << endl << h + 1 << ". " << movie[i];
				h++;
				mm[h] = i;
			}
		}
		break;
	case 3:
		for (i = 1; i < 6; i++)
		{
			cout << endl << h + 1 << ". " << movie[i];
			h++;
			mm[h] = i;
		}
		break;
	}

	//ensuring that the entered choice is among the given choices
	while (k == 0) {
		cout << "\nEnter number corresponding to ur your choice: ";
		cin >> m;

		//taking input of preferred movie
		for (int i = 1; i <= h; i++)
		{
			if (m == i)
			{
				k = 1;
			}
		}
	}

	q--;
	m = mm[m];
}

//Function to display the show timings
void show_time(int& m, int& u, char tm[6][25])
{
	int w = 0, b = 0, uu[10];
	cout << "\nAvailable show timings:";
	// displays different showtimings according to movie selected
	switch (m)
	{
		int i;
	case 1:
		for (i = 1; i < 6; i++)
		{
			if (i % 2 == 0)
			{
				cout << endl << w + 1 << ". " << tm[i];
				w++;
				uu[w] = i;
			}
		}
		break;
	case 2:
		for (i = 1; i < 6; i++)
		{
			if (i % 2 != 0)
			{
				cout << endl << w + 1 << ". " << tm[i];
				w++;
				uu[w] = i;
			}
		}
		break;
	case 3:
		for (i = 1; i < 6; i++)
		{
			if (i % 3 == 0)
			{
				cout << endl << w + 1 << ". " << tm[i];
				w++;
				uu[w] = i;
			}
		}
		break;
	case 4:
		for (i = 1; i < 6;)
		{
			cout << endl << w + 1 << ". " << tm[i];
			w++;
			uu[w] = i;
			i = i + 4;
		}
		break;
	case 5:
		for (i = 1; i < 6; i++)
		{
			if (i % 2 == 0)
			{
				cout << endl << w + 1 << ". " << tm[i];
				w++;
				uu[w] = i;
			}
		}
		break;
	}
	//ensuring that entered choice is among the given choices
	while (b == 0) {
		cout << "\nEnter number corresponding to your choice: ";
		cin >> u;
		//taking input of preferred showtime
		for (int i = 1; i <= w; i++)
		{
			if (u == i)
			{
				b = 1;
			}
		}
	}
	u = uu[u];
	_getch();
}

//Function to display the seats
void seat_map(struct time(&d)[3][6], int q, int m, int u)
{
	int i;
	cout << "     ";
	for (i = 0; i < 10; i++)
	{
		cout << "SEAT" << i + 1 << " ";
	}
	cout << endl;
	for (i = 0; i < 7; i++)
	{
		cout << "ROW" << i + 1;
		for (int j = 0; j < 10; j++)
		{
			cout << "|  " << d[q][m].t[u].s[i][j] << "  ";
		}
		cout << "|" << endl;
	}
}

/* Function to calculate the price -
	seats in different rows have different prices */
void price(float& pr, int r)
{
	if (r == 1 || r == 2)
		pr += 3.0;
	if (r == 3 || r == 4)
		pr += 2.5;
	if (r == 5 || r == 6 || r == 7)
		pr += 2.0;
}

//Function to display the total price
void disp_price(float pr)
{
	cout << "\n\nCost: " << pr << " OMR";
}

//Function to display the booking details
void confirm(int y, float pr, int q, int m, int u, char date[3][20], char movie[5][25], char tm[5][25])
{
	cout << "\n\n                            ABC CINEMAS";
	cout << "\n                            -------------";
	cout << "\n\nBooking confirmed";
	disp_price(pr);
	cout << "\nDate: " << date[q];
	cout << "\nMovie: " << movie[m];
	cout << "\nShow timing: " << tm[u];
	cout << "\nSeats: " << y;
}

//Function to book the seats
void seat_book(struct time(&d)[3][6], int& r, int& y, int q, int m, int u, float& pr)
{
	int n = 0, l = 0, s, cd;
seat:int ab = 0;
	cout << "\nEnter the row u want(1-7): ";
	cin >> r;
	//ensuring that the entered row is available
	if (r > 7 || r < 1)
	{
		goto seat;
	}
	for (int j = 0; j < 10; j++)
	{
		if (d[q][m].t[u].s[r - 1][j] == 'A')
		{
			ab = 1;
		}
	}
	//checking if seats are available in the chosen row
	if (ab == 0)
	{
		cout << "\nNo seats available in this row";
		goto seat;
	}

	//taking input of number of seats
maa:int bc = 0;
	cout << "\nEnter number of seats (max 10) : ";
	cin >> n;
	if (n < 1 || n > 10)
	{
		goto maa;
	}
	//ensuring that the number of seats enetered is available
	int j;
	for (j = 0; j < 10; j++)
	{
		if (d[q][m].t[u].s[r - 1][j] == 'A')
		{
			bc++;
		}
	}
	//ensuring that the number of seats entered is less than or equal to unbooked seats
	if (n > bc)
	{
		cout << "\nNot enough seats available in this row. ";
		cout << "\nEnter 1 to select a new row. Enter 0 to change no. of seats.";
		cin >> cd;
		if (cd == 0)
			goto maa;
		if (cd == 1)
			goto seat;
	}
	int gh = 0;
	for (int i = 0; i < n; i++)
	{
		//taking input of the desired seats
	enter:cout << "\nEnter your seat(1-10): ";
	ent:cin >> s;
		if (s < 1 || s>10)
		{
			cout << "\nEnter a seat from 1 to 10: ";
			goto ent;
		}
		//if the seat is unbooked, it is changed to booked
		else if (d[q][m].t[u].s[r - 1][s - 1] == 'A')
		{
			price(pr, r);
			d[q][m].t[u].s[r - 1][s - 1] = 'B';
			gh = 1;
		}
		//message displayed if seat is already booked
		else
		{
			cout << "\nThe seat is already booked";
			goto enter;
		}
		//message displayed if seat is already booked
		_getch();
	}
	if (gh == 1)
		y += n;
	//calling function to display the seats
	seat_map(d, q, m, u);
	//more seats can be entered if necessary
ag:cout << "\nIf you want to enter more seats, click 1. Otherwise click 0.";
	cin >> l;
	if (l == 1)
		goto seat;
	if (l != 1 && l != 0)
		goto ag;
	cout << "\n\n";
	system("cls");
	_getch();
}

//function to initialize all seats to unbooked
void seat_initialize(struct time(&d)[3][6])
{
	for (int q = 0; q < 3; q++)
	{
		for (int m = 1; m < 6; m++)
		{
			for (int u = 1; u < 6; u++)
			{
				for (int i = 0; i < 7; i++)
				{
					for (int j = 0; j < 10; j++)
					{
						d[q][m].t[u].s[i][j] = 'A';
					}
				}
			}
		}
	}
}

int main()
{
	for (int i = 0;; i++)
	{
		system("cls");

		//defining structure variables
		struct time d[3][6];

		/*q-date no., m-movie no., u-show timing no.,y-total no. of seats,
		 pr-price,r-row no.*/
		int q, m, u, x, y = 0, p, r;
		float pr = 0;

		//defining date array
		char date[3][20] = { {"20th January"},{"21st January"},{"22nd January"} };

		//defining show time array
		char tm[6][25] = { {"  "},{"7:00 am - 8:30 am"},{"9:30 am - 12:00 pm"},
		{"2:30 pm - 5:00 pm"},{"6:00 pm - 9:00 pm"},{"9:00 pm - 11:30 pm"} };

		//defining movie array
		char movie[6][25] = { {"  "},{"Bird Box"},{"Black Mirror"},{"The Nun"},
		{"The Fifth Wave"},{"The Incredibles"} };

		int z, b = 1;
		//calling function to display welcome screen
	xx:disp();
		if (i == 0)
		{
			//calling function to initlize seats to unbooked
			seat_initialize(d);
		}
		//calling function to display and take input of date
		dt(q, date);

		//calling function to display and take input of movie
		mv(q, m, movie);

		//calling function to display and take input of show timings
		show_time(m, u, tm);

		//calling function to display seats
		seat_map(d, q, m, u);

		//checking if user wants to book seats or not
	xxx:cout << "\nIf you want to book seats, click 1. If u want to go to homepage, click 0.";
		cin >> x;
		if (x == 0)
			goto xx;
		if (x != 1 && x != 0)
			goto xxx;

		system("cls");
		//calling function to book the seats
		seat_book(d, r, y, q, m, u, pr);

		//calling function to display booking details
		confirm(y, pr, q, m, u, date, movie, tm);

		//returns to homepage or exits program as per users choice
	pp:cout << "\n\nIf you want to go to homepage, click 1." << endl <<
		"If you want to exit, click 0.";
	cin >> p;
	if (p == 0)
	{
		exit(0);
	}
	if (p != 1 && p != 0)
		goto pp;
	_getch();
	}
	return 0;
}