//
// Secure.hh for  in /home/soidik_d/Semestre_05/cpp/Spider/vendors/network
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Mon Nov  2 23:01:38 2015 SOIDIKI Djamil
// Last update Tue Nov  3 00:05:14 2015 SOIDIKI Djamil
//

#ifndef		_SECURE_HH_
# define	_SECURE_HH_

#include	"ISSL.hh"

#define		_PATH_TO_CERTS_ "security/certs/"

class		Secure : public ISSL {

private:
  ssl::context	_context;

protected:
  void		initialize();

public:
  Secure();
  virtual ~Secure();

  ssl::context&	getContext();
};

#endif		/* _SECURE_HH_ */
