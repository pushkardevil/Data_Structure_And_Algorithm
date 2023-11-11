#include<iostream>
using namespace std;

class Hero{
	private:
	int health;
	
	public:
	char level;
	
	// default constructer
	Hero(){
		cout<<"Constructer called :"<<endl;
	}
	
	// parameterised constructer
	
	Hero(int health){
		this->health=health;
	}
	
	Hero(int health , char level){
		this->health=health;
		this->level=level;
	}
	
	void print(){
		cout<<level<<endl;
	}
	
	
	// getter
	int getHealth(){
		return health;
	}
	
	char getLevel(){
		return level;
	}
	
	
	// setter
	void setHealth(int h){
		health=h;
	}
	
	void setLevel(char ch){
		level=ch;
	}
};

int main(){
	
	// object created statically
	Hero ramesh(10);
	ramesh.print();
	
	//dynamically
	Hero *h=new Hero(11);
	h->print();
	
	
	Hero temp(22 , 'B');
	temp.print();
	
}
