/*  This file is part of rNA.
 *  Copyright (c) 2011 by Cristian Del Fabbro <delfabbro@appliedgenomics.org>,
 *  Francesco Vezzi <vezzi@appliedgenomics.org>,
 *  Alexandru Tomescu <alexandru.tomescu@uniud.it>, and
 *  Alberto Policriti <policriti@uniud.it>
 *
 *   rNA is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.

 *   rNA is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.

 *   You should have received a copy of the GNU General Public License
 *   along with rNA.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef OPTIONS_H_
#define OPTIONS_H_

#include <boost/program_options.hpp>
namespace po = boost::program_options;

#include <string>
#include <iostream>

namespace options {

class Options {
public:
	Options() { set_defaults(); }
	virtual ~Options() { }

	virtual bool process(int argc, char *argv[]) = 0;

	typedef enum 
        { 
            program_unknown,
            program_create_blocks,
            program_merge 
        } __attribute__((packed)) program_mode_t;

	program_mode_t program_mode;

	int argc;
	char **argv;

	// input options
	std::string masterBamFile;
	std::vector< std::string > slaveBamFiles;
        
        std::string masterMpBamFile;
        std::vector< std::string > slaveMpBamFiles;
	
	std::string masterNameSortedBamFile;
	std::string slaveNameSortedBamFile;
	
	std::string blocksFile;
	
	std::string masterFastaFile;
	std::vector< std::string > slaveFastaFiles;
	
	int minBlockSize;
	int threadsNum;
	
	std::string readsPrefix;
	
	// output options
	std::string outputFilePrefix;

protected:
	void set_defaults();

};

} // end of namespace options

#endif /* OPTIONS_H_ */
