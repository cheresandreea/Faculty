#include <string>

class Bill
{
private:
	std::string name;
	std::string number;
	float sum;
	bool isPaid;
public:
	Bill();

	Bill(const std::string& name, const std::string& number, const float sum, const bool& isPaid);

	~Bill();

	std::string getName() const { return name; }
	std::string getNumber() const { return number; }
	float getSum() const { return sum; }
	bool getIsPaid() const { return isPaid; }


};

