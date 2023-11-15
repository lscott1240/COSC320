#include <iostream>
#include "d_tnode.h"
#include "d_tnodel.h"
#include "inf2pstf.h"
#include <string>


using namespace std;

tnode<char> *buildExpTree(const string&);

void prefixOutput(tnode<char> *);

int main()
{
	string input = "a*(b+c)";
	string input1 = "a+c/d*e-g*f+r";
	string input2 = "(a+b)/c";

	infix2Postfix infix(input2);

	string Post = infix.postfix();

	tnode<char> * root = buildExpTree(Post);	

	cout << "Prefix Output : ";

	prefixOutput(root);	

	cout << "\n" << "Postfix Output : " << Post;

	cout << "\n\n";

	int length = input.length();

	displayTree(root, length);
}

void prefixOutput(tnode<char> *t)
{
	if (t == nullptr)
		return;
		
	cout << t->nodeValue << " ";
	prefixOutput(t->left);
	prefixOutput(t->right);
}

// build an expression tree from a postfix expression.
// the operands are single letter identifiers in the range from
// 'a' .. 'z' and the operators are selected from the characters
// '+', '-', '*' and '/'
tnode<char> *buildExpTree(const string& exp)
{
	// newnode is the address of the root of subtrees we build
	tnode<char> *newnode, *lptr, *rptr;
	char token;
	// subtrees go into and off the stack
	stack<tnode<char> *> s;
	int i = 0;


	// loop until i reaches the end of the string
	while(i != exp.length())
	{
		// skip blanks and tabs in the expression
		while (exp[i] == ' ' || exp[i] == '\t')
			i++;

		// if the expression has trailing whitespace, we could
		// be at the end of the string
		if (i == exp.length())
			break;

		// extract the current token and increment i
		token = exp[i];
		i++;

		// see if the token is an operator or an operand
		if (token == '+' || token == '-' || token == '*' || token == '/')
		{
			// current token is an operator. pop two subtrees off
			// the stack.
			rptr = s.top();
			s.pop();
			lptr = s.top();
			s.pop();
		
			// create a new subtree with token as root and subtees
			// lptr and rptr and push it onto the stack
			newnode = new tnode<char>(token,lptr,rptr);
			s.push(newnode);
		}
		else // must be an operand
		{
			// create a leaf node and push it onto the stack
			newnode = new tnode<char>(token);
			s.push(newnode);
		}

	}

	if (!s.empty())
		return s.top();
	else
		return NULL;

}

