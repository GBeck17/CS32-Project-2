#include "Sequence.h"

Sequence::Sequence()
	:m_length(0)
{
	head = nullptr; 
}

Sequence::Sequence(const Sequence & other)
{
	head = other.head; // Setting new head pointer equal to other's head pointer
	int i = 0; 
	m_length = 0; 
	for (Node* current = other.head; i < other.m_length; current = current->m_next) {
		insert(i, current->m_value); 
		i++;
	} 
}

Sequence & Sequence::operator=(const Sequence & other)
{
	if (this != &other) {
		Sequence temp = other; 
		swap(temp); 
	}
	return *this; 
}

Sequence::~Sequence()
{ 
	while (head != nullptr) {
		erase(0); 
	}

}

bool Sequence::empty() const
{
	if (m_length == 0)
		return true;
	else
		return false; 
}

int Sequence::size() const
{
	return m_length; 
}

bool Sequence::insert(int pos, const ItemType & value)
{
	if (pos < 0 || pos > m_length)
		return false; 
	else if (m_length == 0) // if list length is == 0 
	{
		if (pos == 0) // If item is to be inserted into empty list (at position 0) 
		{
			Node* newNode = new Node;
			newNode->m_value = value; 
			head = newNode;
			newNode->m_previous = nullptr;
			newNode->m_next = nullptr; 
			m_length++; 
			return true;
		}
		return false; // return false if pos is not == 0, assuming length of list is 0 
	}
	else if (pos > 0 && pos < m_length) // Pos is somewhere in middle 
	{ 
		Node* current = head;
		int i = 0; 
		while (i < pos) {
			current = current->m_next;
			i++; 
		}
		Node* newNode = new Node;
		newNode->m_value = value;
		newNode->m_next = current;
		newNode->m_previous = current->m_previous;
		current->m_previous->m_next = newNode;
		current->m_previous = newNode;
		m_length++;
		return true;
	}
	else //pos must == m_length
	{
		Node* current = head; 
		while (current->m_next != nullptr) {
			current = current->m_next; 
		}
		Node* newNode = new Node;
		current->m_next = newNode; 
		newNode->m_value = value;
		newNode->m_previous = current;  
		newNode->m_next = nullptr;
		m_length++; 
		return true; 
	}
}

int Sequence::insert(const ItemType & value)
{
	// if list is empty 
	if (m_length == 0) {
		Node* newNode = new Node;
		newNode->m_value = value; 
		head = newNode;
		newNode->m_previous = nullptr;
		m_length++; 
		return 0; 
	}
	// If value belongs in front, but list isn't empty 
	else if (value < head->m_value) {
		Node* newNode = new Node; 
		newNode->m_value = value; 
		newNode->m_next = head; 
		head->m_previous = newNode; 
		newNode->m_previous = nullptr; 
		head = newNode; 
		m_length++; 
		return 0; 
	}
	// If value is somewhere in middle or end of list 
	else {
		Node* current = head; 
		if (m_length == 1) {
			Node* newNode = new Node; 
			newNode->m_value = value; 
			newNode->m_next = nullptr; 
			newNode->m_previous = current; 
			current->m_next = newNode; 
			m_length++; 
			return 1; 
		}
		int i = 0; 
		// this loop checks to see if it should be inserted in middle 
		while (current->m_next != nullptr) {
			if (value <= (current->m_value)) {
				insert(i, value); // this increments m_length already, so no need to do that here
				return i;
			}
			current = current->m_next; 
			i++; 
		}
		if (current->m_next == nullptr && value <= current->m_value) // value <= LAST item in list
		{
			Node* newNode = new Node; 
			newNode->m_value = value; 
			newNode->m_next = current; 
			newNode->m_previous = current->m_previous;
			current->m_previous->m_next = newNode; 
			current->m_previous = newNode; 
			m_length++; 
			return i; 
		}
		if (current->m_next == nullptr && value > current->m_value) // value greater than all others in list, so add it at end (m_length)
		{
			i = m_length;
			Node* newNode = new Node;
			newNode->m_value = value;
			current->m_next = newNode;
			newNode->m_previous = current;
			newNode->m_next = nullptr;
			m_length++;
			return i;
		}
		return 0; 
	}
	return 0; 
}

bool Sequence::erase(int pos)
{ 
	if (m_length == 0) {
		return false; 
	}
	else if (pos >= 0 && pos < m_length) {
		if (pos == 0) {
			if (m_length > 1) {
				Node* deleteNode = head;
				head = deleteNode->m_next;
				deleteNode->m_next->m_previous = nullptr;
				delete deleteNode;
				m_length--;
				return true; 
			}
			if (m_length == 1) // No need to see previous or next to anything with deleteNode, since it will be deleted anyway 
			{
				Node* deleteNode = head; 
				head = nullptr;
				delete deleteNode; 
				m_length--;
				return true; 
			}
		}
		else // pos is not equal to 0 
		{
			int i = 0; 
			Node* x = head;
			while (i < pos) {
				x = x->m_next;
				i++; 
			}
			// i has reached pos, thus x has reached the node to delete
			Node* deleteNode = x; 
			if (deleteNode->m_next == nullptr) // Deals with case where pos = length - 1
			{
				deleteNode->m_previous->m_next = nullptr; 
				delete deleteNode; 
				m_length--; 
				return true; 
			}
			// Otherwise pos != length - 1, delete in middle strategy 
			x->m_previous->m_next = deleteNode->m_next;
			x->m_next->m_previous = deleteNode->m_previous;
			delete deleteNode;
			m_length--; 
			return true; 
		}
	}
	return false; 
}

int Sequence::remove(const ItemType & value)
{
	int count = 0; 
	if (m_length == 0) {
		return 0; 
	}
	if (m_length == 1 && value == head->m_value) {
		Node* deleteNode = head;
		head = nullptr;
		delete deleteNode;
		m_length--;
		return 1;
	}
	// Deals with case where value(s) are possibly somewhere in middle/end 
	Node* x = head; 
	while (x->m_next != nullptr) {
		if (head->m_value == value) {
			Node* deleteNode = head; 
			head->m_next->m_previous = nullptr;
			head = deleteNode->m_next; 
			x = deleteNode->m_next; 
			delete deleteNode;  
			m_length--; 
			count++; 
		}
		else if (x->m_value == value) {
			Node* deleteNode = x;
			x->m_previous->m_next = deleteNode->m_next;
			x->m_next->m_previous = deleteNode->m_previous;
			x = x->m_next; // MUST do this BEFORE deleting node
			delete deleteNode;
			m_length--; 
			count++; 
		}
		else {
			x = x->m_next; 
		}
	}
	// We have reached either last OR only item left in list 
	if (x->m_value == value) {
		if (m_length == 1) {
			Node* deleteNode = head;
			head = nullptr;
			delete deleteNode;
			m_length--;
		} 
		else {
			Node* deleteNode = x; 
			x->m_previous->m_next = nullptr; 
			delete deleteNode; 
			m_length--; 
			count++; 
		}
	}
	return count; 
}

bool Sequence::get(int pos, ItemType & value) const
{
	if (pos < 0 || pos >= m_length) {
		return false; 
	}
	else {
		Node* current = head; 
		for (int i = 0; i < pos; i++) {
			current = current->m_next; 
		}
		// Assume that i == pos 
		value = current->m_value; 
		return true; 
	}
}

bool Sequence::set(int pos, const ItemType & value)
{
	if (pos < 0 || pos >= m_length)
		return false; 
	else {
		Node* current = head; 
		for (int i = 0; i < pos; i++) {
			current = current->m_next; 
		}
		// Assume that i == pos 
		current->m_value = value; 
		return true; 
	}
}

int Sequence::find(const ItemType & value) const
{
	Node* current = head; 
	int p(0); 
	while (p < m_length && current->m_value != value) {
		current = current->m_next; 
		p++; 
	}
	if (p == m_length)
		return -1;
	else
		return p; 
}

void Sequence::swap(Sequence & other) 
{
	Node* temp = other.head; // This swaps the contents by switching head pointers 
	other.head = head; 
	head = temp; 

	int tempLength = other.m_length; 
	other.m_length = m_length; 
	m_length = tempLength; 
}

int subsequence(const Sequence & seq1, const Sequence & seq2) // returns position where subsequence STARTS, else return -1 
{
	if (seq2.empty() || seq2.size() > seq1.size()) {
		return -1; 
	}
	int seqBegin; 
	ItemType value1; 
	ItemType value2; 
	bool result = false; 
	for (int i = 0; i < seq1.size(); i++) {
		seq1.get(i, value1); 
		seq2.get(0, value2); 
		if (value1 == value2) {
			result = true; 
			seqBegin = i; 
			for (int iNew = i, j = 0; iNew < seq1.size(), j < seq2.size(); iNew++, j++) {
				seq1.get(iNew, value1); 
				seq2.get(j, value2); 
				if (value1 != value2) {
					result = false; 
					break; 
				}
			}
			if (result) {
				return seqBegin; 
			}
		}
	}
	return -1; 
	
}

void interleave(const Sequence & seq1, const Sequence & seq2, Sequence & result) // 
{
	Sequence result1(result); // Copy constructor called for result to deal with aliasing issue
	while (!result1.empty()) // Makes sure result1 will start with 0 values
	{
		result1.erase(0); 
	}
	if (seq1.empty()) { 
		result1 = seq2; 
	}
	else if (seq2.empty()) {
		result1 = seq1; 
	}
	
	else {
		int i(0), j(0), count(0); // count is needed to iterate/insert values into the result list 
		ItemType value1; 
		ItemType value2; 
		while (i < seq1.size() && j < seq2.size()) {
			seq1.get(i, value1); 
			result1.insert(count, value1); 
			seq2.get(j, value2); 
			result1.insert(count + 1, value2); 
			i++, j++; 
			count += 2;
		}
		// Loop breaks one or both sequences have been iterated through 
		if (i == seq1.size() && j == seq2.size()) // Deals with case where both sequences are of equal length
		{
			;// No need to do anything 
		}
		else {
			if (i == seq1.size()) {
				while (j < seq2.size()) {
					seq2.get(j, value2); 
					result1.insert(count, value2); 
					j++; 
					count++; 
				}
			}
			else if (j == seq2.size()) {
				while (i < seq1.size()) {
					seq1.get(i, value1); 
					result1.insert(count, value1);  
					i++; 
					count++; 
				}
			}
		}
	}
	result = result1; 
}
