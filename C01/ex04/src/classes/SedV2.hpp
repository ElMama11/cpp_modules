#ifndef SEDV2_HPP
# define SEDV2_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <stdlib.h>

class SedV2
{
	public:
		SedV2(std::string filename);
		~SedV2(void);
		void replace(std::string s1, std::string s2);
		
	private:
		std::string _infile;
		std::string _outfile;
};

#endif