#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
# include <iostream>
# include <fstream>
# include <sstream>
# include <map>

class BitcoinExchange {

	public:
		BitcoinExchange();
		BitcoinExchange(const std::string &databaseFile);
		BitcoinExchange(const BitcoinExchange &cpy);
		~BitcoinExchange();

		BitcoinExchange &operator=(const BitcoinExchange &rhs);

		float getExchangeRate(const std::string &date, float value);

		class databaseError : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Error: could not open bitcoin price database file.");
				}
		};

		class invalidArgument : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Error: no exchange rate found for given date.");
				}
		};

		class negativeValue : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Error: not a positive number.");
				}
		};

		class tooLargeNumber : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Error: too large a number.");
				}
		};

		class inexistentDate : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Error: inexistent date.");
				}
		};

	private:
		bool							_isValidDate(const std::string& dateStr);
		std::map<std::string, float>	_exchangeRates;
};


#endif