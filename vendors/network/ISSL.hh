//
// ISSL.hh for  in /home/soidik_d/Semestre_05/cpp/Spider/vendors/network
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Mon Nov  2 22:45:07 2015 SOIDIKI Djamil
// Last update Tue Nov  3 00:21:37 2015 SOIDIKI Djamil
//

#ifndef		_ISSL_HH_
# define	_ISSL_HH_

#include	<iostream>
#include	<boost/asio.hpp>
#include	<boost/asio/ssl.hpp>

using		boost::asio::ip::tcp;
namespace	ssl = boost::asio::ssl;
typedef		ssl::stream<tcp::socket>	ssl_socket;

class		ISSL {

public:
  virtual ~ISSL() = default;

  virtual ssl::context&	getContext() = 0;

protected:
  virtual void	initialize() = 0;
};

#endif		/* _ISSL_HH_ */
