//
// Exception.cpp for  in /home/soidik_d/Semestre_05/cpp/Spider/vendors/exception
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Tue Oct 27 14:29:20 2015 SOIDIKI Djamil
// Last update Tue Oct 27 14:29:26 2015 SOIDIKI Djamil
//

#include	"Exception.hh"

Exception::Exception(int _errno, int line, const string& file,
		     const string& _message)
{
  std::ostringstream	oss;

  if (_errno)
    {
      oss << "[ERROR] (" << file << ":" << line << ")" << endl 
	  << _message << ": " << strerror(_errno);
    }
  else if (_errno == NO_ERRNO)
    {
      oss << "[ERROR] (" << file << ":" << line << ")" << endl 
	  << _message;
    }
  else
    oss << _message;
  this->_message = oss.str(); 
}

Exception::~Exception() throw()
{
}

const char*	Exception::what() const throw()
{
  return (this->_message.c_str());
}
