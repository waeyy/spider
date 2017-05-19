//
// Secure.cpp for  in /home/soidik_d/Semestre_05/cpp/Spider/vendors/network
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Mon Nov  2 23:17:45 2015 SOIDIKI Djamil
// Last update Tue Nov  3 00:39:56 2015 SOIDIKI Djamil
//

#include	"../exception/Exception.hh"
#include	"Secure.hh"

Secure::Secure() : _context(ssl::context::sslv23)
{
  this->initialize();
}

Secure::~Secure()
{
}

void		Secure::initialize()
{
  this->_context.set_default_verify_paths();
  this->_context.set_options(ssl::context::default_workarounds
			     | ssl::context::no_sslv2
			     | ssl::context::single_dh_use);

  /*this->_context.set_password_callback(boost::bind(&server::get_password, 
    this));*/
  try 
    {
      
      this->_context.use_certificate_chain_file("security/certs/cert.pem");
      this->_context.use_private_key_file("security/certs/key.pem", 
					  ssl::context::pem);
    }
  catch (const boost::system::system_error& e)
    {
      std::cout << "Failed to load certificate or key file: " << 
	e.what() << std::endl;
      exit(0);
    }
  //  this->_context.use_tmp_dh_file("dh512.pem");
}

ssl::context&	Secure::getContext()
{
  return (this->_context);
}
