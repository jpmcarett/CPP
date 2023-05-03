#include <iostream>
#include "Toy.h"

using namespace std;
namespace sdds {
	Toy::Toy(const std::string& toy)
	{
		string _helper{};
		string _helper2{};
		int position{};
		_helper = toy;
		position = _helper.find(":");
		order_id = stoi(_helper.substr(0, position));
		_helper.erase(0, position+1);
		position = _helper.find(":");
		name = (_helper.substr(0, position));
		_helper.erase(0, position + 1);
		// first position
		while (name[0] == ' ') {
			name.erase(0, 1);
		}
		//last position
		while (name[name.length()-1] == ' ') {
			name.erase(name.length() - 1,1);
		}
		////delete middle position
		//position = name.find(" ");
		//	if ((position + 1) == ' ') {

		//}
		position = _helper.find(":");
		num_item = stoi(_helper.substr(0, position));
		_helper.erase(0, position + 1);
		price = stod(_helper.substr(0, _helper.length()));


	}
	void Toy::update(int numItems)
	{
		num_item = numItems;


	}
	ostream& operator<<(ostream& out, const Toy& input)
	{
		double total_price{};
		out << "Toy ";
		out.width(5);
		out << input.order_id<<":";
		out.width(18);
		out << input.name;
		out.width(3);
		out << input.num_item;
		out << " items";
		out.width(8);
		out << input.price;
		out << "/item  subtotal:";
		total_price = input.num_item * input.price;
		out.width(7);

		out << total_price;

		out << " tax:";
		out.setf(ios::fixed);
		out.width(6);
		out.precision(2);
		out << (total_price* input.har_tax);
		out << " total:";
		out.width(7);
		out.precision(2);
		out << (total_price + total_price * input.har_tax);
		out << endl;



		


		return out;
		// TODO: insert return statement here
	}
}