#include<iostream>
using namespace std;

class Hero{
	private:
	int health;
	
	public:
	char level;
	
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
	// static allocation
	Hero a;
	
	a.level='A';
	a.setHealth(70);
	
	cout<<"Level is :"<< a.level<<endl;
	cout<<"Health is :"<< a.getHealth()<<endl;
	
	// dynamic allocation
	Hero *b=new Hero;
	b->setHealth(80);
	b->setLevel('B');
	
	cout<<"Level is :"<< b->level<<endl;
	cout<<"Health is :"<< b->getHealth()<<endl;
	
	
}
