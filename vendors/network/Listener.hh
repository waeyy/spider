//
// Listener.hh for  in /home/soidik_d/Semestre_05/cpp/Spider/vendors/network
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Sun Nov  1 17:49:29 2015 SOIDIKI Djamil
// Last update Sat Nov 14 20:27:35 2015 SOIDIKI Djamil
//

#ifndef		_LISTENER_HH_
# define	_LISTENER_HH_

#include	<iostream>
#include	<memory>
#include	<boost/asio.hpp>
#include        <boost/bind.hpp>
#include	"Handler.hh"
#include	"ISocket.hh"
#include	"ISSL.hh"
#include	"../exception/Exception.hh"

#define		_PORT_SERVER_	4242

class		Listener : public ISocket {

private:
  boost::shared_ptr<ISSL>			_ssl;
  boost::shared_ptr<boost::asio::io_service>	_ios;
  boost::asio::ip::tcp::acceptor		_acceptor;

public:
  Listener(const boost::shared_ptr<ISSL>& ssl,
	   const boost::shared_ptr<boost::asio::io_service>& ios = 
	   boost::shared_ptr<boost::asio::io_service>(new boost::asio::io_service()));
  virtual ~Listener();
  
  void		bind();
  void		listen();
  void		async_accept();
  
  void		poll();
  void		run();
  void		stop();

private:
  Listener(const Listener& sock);
  Listener& operator=(const Listener& sock);

  void		acceptCallback(const boost::shared_ptr<IHandler>& hand,
			       const boost::system::error_code& e);
};

#endif		/* _ASOCKET_HH_ */
