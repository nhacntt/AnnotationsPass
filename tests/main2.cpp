class Base{
	public:
	void hello(){}
};

class Derived: public Base{
	public:
	void hello(){}
};

int main(){
	Derived obj;
	obj.hello();
}
