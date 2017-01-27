/*Boolean expressions can only hold one of two values, with
true = 1 and false = 0.   If LikePizza is set to true then a value of 1 would be
assigned and vice versa if the bool value is false.  Also, we could change LikesPizza
to hold a string value of YES or NO and and compare that to user input such as
"YES" == "YES", since that evalues as true it would also have a value of one.  If the
user enters "NO" then "YES" == "NO" would evaluate as false and it would be assigned a 
value of 0*/

#include <iostream>
#include <string>

int main() {
	using namespace std;

	bool bLikesPizza = true;
	if (bLikesPizza == true) {
		cout << "Likes pizza.\n";
	}
	else{
		cout << "Doesn't like pizza.\n";
	}
	
	cin.get();
	return 0;
}