#include "Sequence.h"
#include <cassert>
#include <iostream>
using namespace std;

int main() {
	return 0; 
	/*Sequence a;
	Sequence b;

	assert(a.size() == 0);
	assert(b.size() == 0);
	assert(a.empty());
	assert(b.empty());

	a.insert(0, 20);
	a.insert(1, 30);
	a.insert(2, 15);
	assert(a.size() == 3); 
	assert(a.erase(2)); 
	assert(a.size() == 2); 
	assert(a.insert(4, 30) == false);
	a.insert(2, 30);
	a.insert(3, 45);
	a.insert(3, 40);

	assert(a.size() == 5);
	assert(a.empty() == false);

	a.insert(a.size(), 44);
	a.insert(a.size(), 55);
	a.insert(a.size(), 30);
	for (int i = 0; i < 50; i++) {// Make sure values are put in ascending order…insert works correctly 
		b.insert(i);
	}
	assert(b.size() == 50); 
	assert(b.insert(50) == 50);


	Sequence c;
	assert(subsequence(a, b) == -1); // Makes sure subsequence returns -1 when seq2 > seq1???
	assert(subsequence(b, c) == -1); // when seq2 is empty, return -1 
	c.insert(0, 44); 
	c.insert(1, 55); 
	c.insert(2, 30); 
	
	b.insert(44); 
	b.insert(55); 
	b.insert(30); 

	assert(subsequence(a, c) == 5); // seq2 is a subsequence of seq1, starting middle of list
	assert(subsequence(b, c) == -1); // seq2 is almost subsequence of seq1, still returns -1 
	
	Sequence d;
	assert(d.empty());
	assert(d.insert(1) == 0); 
	assert(d.insert(4) == 1); 
	assert(d.insert(3) == 1); 
	assert(d.size() == 3); 
	assert(d.insert(44) == 3); 
	assert(d.insert(55) == 4); 
	assert(d.insert(5, 30)); 
	assert(d.size() == 6); 
	assert(d.insert(4) == 2); 
	assert(d.size() == 7);
	assert(d.find(100) == -1); 
	
	assert(subsequence(d, c) == 4);
	
	assert(d.remove(1) == 1); 
	assert(d.remove(0) == 0); 
	assert(d.remove(30) == 1); 
	assert(d.remove(44) == 1); 
	assert(d.remove(4) == 2); 
	assert(d.size() == 2); 
	
	Sequence e; 
	Sequence f; 

	assert(e.insert(0, 1)); 
	assert(e.insert(1, 5)); 
	assert(e.insert(2, 10)); 
	assert(e.insert(3, 15)); 
	assert(e.insert(4, 20));

	assert(f.insert(1) == 0); 
	assert(f.insert(2) == 1); 
	assert(f.insert(3) == 2); 
	assert(f.insert(10) == 3); 
	
	Sequence result; 
	interleave(e, f, result); // Makes sure values input correctly when m > n 
	assert(result.size() == 9); 
	assert(result.find(2) == 3); // Makes sure value 2 is at position 3 
	assert(result.find(20) == 8); 
	
	assert(f.insert(12) == 4); // Making m = n 
	assert(f.find(10) == 3); 
	interleave(e, f, result); // Makes sure a non-empty result passed in will be erased and new values added
	assert(result.find(12) == 9); // Last item in result should be from seq2, should be 12
	assert(result.find(20) == 8); // Earlier values in result should be at same position as before
	assert(result.find(2) == 3); 

	assert(f.insert(2, 5) == true); // Making n > m, with value inserted not at end, but in middle
	assert(f.find(10) == 4); 
	interleave(e, f, result); // Again makes sure result will be erased to 0 items, and refilled 
	assert(result.size() == 11); 
	assert(result.find(12) == 10); // Last item in result from seq2 again, but one index higher...with same value
	assert(result.find(5) == 2); // new item inserted previously into seq2 should be in position 5 in result
	assert(result.find(3) == 7); // this item should be pushed up in seq2, 2 items later in result
	
	cerr << "All Tests Success!" << endl;*/
}