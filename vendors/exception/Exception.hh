//
// Exception.hh for  in /home/soidik_d/Semestre_05/cpp/Spider/vendors/exception
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Tue Oct 27 14:29:40 2015 SOIDIKI Djamil
// Last update Tue Oct 27 14:29:41 2015 SOIDIKI Djamil
//

#ifndef		_EXCEPTION_HH_
# define	_EXCEPTION_HH_

#include	<iostream>
#include	<sstream>
#include	<exception>
#include	<cerrno>
#include	<cstring>

#define		USAGE_ERROR	0
#define		CLASSIC_ERROR	1
#define		NO_ERRNO	-42

using		std::string;
using		std::endl;

class		Exception : public std::exception {

protected:
  string	_message;

public:
  Exception(int, int, const string&, const string&);
  virtual ~Exception() throw();

  virtual const char * what() const throw();
};

#endif		/* _EXCEPTION_HH_ */
