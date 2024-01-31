
class Dog
{
private:
	char breed[30];
	char name[30];
	int age;
	char photography[50];

public:
	//constructor
	Dog();
	Dog(const char* breed, const char* name, int age, const char* photograph);
	
	//destructor
	~Dog();

	//getters
	const char* getName() const;
	const char* getBreed() const;
	const char* getPhotography() const;
	int getAge() const;

	//overload operator ==
	bool operator==(const Dog& other) const;


};