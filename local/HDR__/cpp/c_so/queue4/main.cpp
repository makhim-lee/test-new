#include <iostream>
#include "queue.h"
#include "array.h"
#include "rational.h"

int main()
{
	Queue<int> q1;
	q1.push(100);
	q1.push(200);
	q1.push(300);
	
	while (!q1.isEmpty()) {
		std::cout << q1.pop() << std::endl;
	}
	
	Queue<Rational> q2;
	q2.push(Rational(3, 4));
	q2.push(Rational(3));
	q2.push(Rational());
	
	while (!q2.isEmpty()) {
		std::cout << q2.pop() << std::endl;
	}
	return 0;
}


