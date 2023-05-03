// Name: JUAN PABLO MARTINEZ CARETT
// Seneca Student ID: 112494216
// Seneca email:jpmartinez-carett@myseneca.ca
// Date of completion:04/04/2023 - Update 04/09/2023 
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iomanip>
#include <algorithm>
#include "CustomerOrder.h"


using namespace std;


namespace sdds {

	size_t CustomerOrder::_widthField = 0;


	CustomerOrder::CustomerOrder(const string& src) {

		sdds::Utilities utilObject{};
		bool flag = true;
		size_t index{};
		size_t counter = 0;
		char del = utilObject.getDelimiter();
		_name = utilObject.extractToken(src, index, flag);
		_product = utilObject.extractToken(src, index, flag);

		counter = count(src.begin() + index, src.end(), del);

		_cntItem = counter + 1;
		_lstItem = new Item * [_cntItem];
		for (size_t i = 0; i < _cntItem; i++)
		{
			_lstItem[i] = new Item(utilObject.extractToken(src, index, flag));
		}
		_widthField = max(utilObject.getFieldWidth(), _widthField);;
	}

	CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept :
		_name{}, _product{}, _cntItem{}, _lstItem{ nullptr }
	{
		*this = std::move(src);
	}

	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& sr) noexcept
	{
		if (this != &sr) {
			if (_lstItem) {
				for (size_t i = 0; i < _cntItem; ++i)
					delete _lstItem[i];
				delete[] _lstItem;
			}

			_name = sr._name;
			_product = sr._product;
			_cntItem = sr._cntItem;
			_lstItem = sr._lstItem;

			sr._name = "";
			sr._product = "";
			sr._cntItem = 0;
			sr._lstItem = nullptr;
		}
		return *this;


	}

	CustomerOrder::~CustomerOrder()
	{

		for (size_t i = 0; i < _cntItem; ++i)
			delete _lstItem[i];

		delete[] _lstItem;
		_lstItem = nullptr;

	}

	bool CustomerOrder::isOrderFilled() const
	{
		bool check = true;
		for (auto i = 0u; i < _cntItem; ++i)
			if (!_lstItem[i]->m_isFilled) {
				check = false;
				break;
			}
		return check;
	}

	bool CustomerOrder::isItemFilled(const std::string& item) const
	{

		bool check = true;
		for (auto i = 0u; i < _cntItem; ++i) {
			if ((_lstItem[i]->m_itemName == item)) {
				if (!_lstItem[i]->m_isFilled) {
					check = false;
					break;
				}
			}
		}
		return check;
	
	}

	void CustomerOrder::fillItem(Station& station, std::ostream& os)
	{
		bool checkpoint = true;
		for (size_t i = 0; i < _cntItem&& checkpoint ; i++)
		{
			if (!(_lstItem[i]->m_isFilled) && _lstItem[i]->m_itemName == station.getItemName()) {
				if (station.getQuantity()) {
					station.updateQuantity();
					_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
					_lstItem[i]->m_isFilled = true;
					os << setw(11) << right;
					os << "Filled " << _name << ", " << _product << " [" << _lstItem[i]->m_itemName << "]" << endl;
					checkpoint = false;
				}
				else 
					os << "    Unable to fill " << _name << ", " << _product << " [" << _lstItem[i]->m_itemName << "]" << endl;
				
			}
		}

	}

	void CustomerOrder::display(ostream& os) const {
		os << _name << " - " << _product << endl;
		for (size_t i = 0; i < _cntItem; ++i) {
			os << "[" << right << setw(6) << setfill('0') << _lstItem[i]->m_serialNumber << "] ";
			os << left << setw(CustomerOrder::_widthField) << setfill(' ') << _lstItem[i]->m_itemName;
			os << "   - ";
			os << (isItemFilled(_lstItem[i]->m_itemName) ? "FILLED" : "TO BE FILLED");
			os << endl;
		}
	}



};