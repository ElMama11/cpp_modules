/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SedV2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:57:07 by mverger           #+#    #+#             */
/*   Updated: 2023/02/23 15:52:08 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SedV2.hpp"

SedV2::SedV2(std::string filename) {
	_infile = filename;
	_outfile = filename + ".replace";
}

SedV2::~SedV2(void) {
}

void SedV2::replace(std::string toFind, std::string toReplace) {
	std::ifstream inStream(_infile.c_str());
	if(inStream.is_open()) {
		std::string content;
		if (std::getline(inStream, content, '\0')) {
			std::ofstream outStream(_outfile.c_str());
			size_t pos = content.find(toFind);
			while (pos != std::string::npos) {
				content.erase(pos, toFind.size());
				content.insert(pos, toReplace);
				pos = content.find(toFind);
			}
			outStream << content;
			outStream.close();
		}
		else {
			std::cerr << "File is empty." << std::endl;
		}
	}
	else {
		std::cerr << "Can't open infile." << std::endl;
		exit(1);
	}
}