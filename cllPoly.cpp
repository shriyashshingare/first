
#include <iostream>
#include<math.h>
using namespace std;
class Polynomial;

class Node {
public :
	int coeff;
	int exp;
	Node *next;
	friend class Polynomial;
};

class Polynomial {
Node *head;
public:
	Polynomial();
	void createPolynomial();
	void displayPolynomial();
	int eval(int x);
        void addPolynomial(Polynomial p1,Polynomial p2);
};

Polynomial::Polynomial()
	{
		head=new Node;
		head->coeff=0;
		head->exp=-1;
		head->next=head;
	}

void Polynomial::createPolynomial() {
		char yn;
		Node *curr;
		Node *temp;

		temp = head;

		do {
			curr = new Node;

			cout<<"\n\t Enter coefficient and exponent - \n";
			cin>>curr->coeff;
			cin>>curr->exp;


 			curr->next = head;
			temp->next = curr;
			temp = curr;

			cout<<"Do you want to add more ? y/1 or n";
			cin>>yn;
		}while(yn == 'y' || yn == '1');

	}

void Polynomial::displayPolynomial() {
		Node *pointerToNode;
		pointerToNode = new Node;
		pointerToNode = head->next;

		cout<<"\n\t";
		while(pointerToNode != head) {
			cout<< pointerToNode->coeff;
			cout<<"x^" << pointerToNode->exp;
			pointerToNode = pointerToNode->next;

			if(pointerToNode != head) {
				cout<<" + ";
			}
		}
	}

int Polynomial::eval(int x)
	{
		int j,val=0;
		Node *temp;
		temp=head->next;

		do
		{
			j=pow(x,temp->exp);
			val=val+temp->coeff*j;
			temp=temp->next;
		}while(temp->exp!=-1);
		return val;
	}

void Polynomial::addPolynomial(Polynomial p1, Polynomial p2)
{
    Node *temp1,*temp2,*temp3;
    temp1=p1.head->next;
    temp2=p2.head->next;
    temp3=this->head->next;

    while(temp1->exp!=-1 || temp2->exp!=-1)
    {
        if(temp1->exp==temp2->exp)
        {
           temp3->exp=temp1->exp;
           temp3->coeff=temp1->coeff+temp2->coeff;
           temp1=temp1->next;
           temp2=temp2->next;
           temp3=temp3->next;
        }
        else if(temp1->exp<temp2->exp)
        {
            temp3->coeff=temp1->coeff;
            temp3->exp=temp1->exp;
            temp1=temp1->next;
            temp3=temp3->next;
        }
        else
        {
            temp3->coeff=temp2->coeff;
            temp3->exp=temp2->exp;
            temp2=temp2->next;
            temp3=temp3->next;
        }

        if(temp1->next!=head)
        {
            temp3->coeff=temp
        }
    }
}
int main() {
        Polynomial poly,p1,p2,p3;
	int x,RES;
	poly.createPolynomial();
	poly.displayPolynomial();
	cout<<"Enter value of X "<<endl;
	cin>>x;
	RES=poly.eval(x);
	cout<<"Result of polynomial"<<RES;
        p3.addPolynomial(p1,p2);
	return 0;
}
